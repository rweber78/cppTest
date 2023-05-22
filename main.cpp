#include "Chrono.h"
#include "Logger.h"

#include <algorithm>
#include <array>
#include <assert.h>
// #include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <math.h>
#include <memory>
#include <random>
#include <set>
#include <stdio.h>
#include <stdint.h> // uintx_t
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<uint8_t> ByteVector;
typedef std::set<uint8_t> ByteSet;
typedef std::map<uint8_t, uint8_t> ByteCounts;

//-----------------------------------------------------------------------------

void precisionTest()
{
    printf("Precision test:\n");
    std::ostringstream sMult;
    double mult = 3.0;
    sMult << "  " << std::fixed << std::setprecision(1) << std::to_string(mult);
    printf("  mult = %s\n", sMult.str().c_str());

    char cBuf[128];
    sprintf(cBuf, "%.1f", mult);
    printf("  mult = %s\n", cBuf);
}

//-----------------------------------------------------------------------------

void triteTest()
{
    printf("Trite parts:\n");
    uint8_t b1, b2, b3;
    b1 = 0x7F;
    b2 = 0x99;
    b3 = 0xAD;
    uint32_t trite = (b1 << 16) | (b2 << 8) | b3;
    printf("  %02x  %02x  %02x  %06x\n", b1, b2, b3, trite);
}

//-----------------------------------------------------------------------------

void arrayTest()
{
    printf("Array initialization:\n");
    std::array<uint32_t, 10> floorStats = {1};
    for (uint16_t f = 0; f < floorStats.size(); f++)
    {
        printf("  floor[%d] = %d\n", f, floorStats[f]);
    }
}

//-----------------------------------------------------------------------------

void vectorInsertTest()
{
    printf("Vector insertion test:\n");

    ByteVector bytes = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    bytes.insert(bytes.begin(), 0);

    printf("  1st byte = %d\n", bytes[0]);
}

//-----------------------------------------------------------------------------

void stringFormatTest()
{
    std::ostringstream msg;

    std::string m1 = "12345678901234567890";
    std::string m2 = "1234567890";
    msg << std::left << std::setw(15) << m1;
    printf("%15s\n", msg.str().c_str());

    std::cout << std::setw(5) << m1 << std::endl;

    size_t n = m1.length() - 15;
    std::cout << m1.substr(n, 15) << std::endl;

    n = (m2.length() > 15) ? m2.length() - 15 : 0;
    std::cout << m2.substr(n, 15) << std::endl;
}

//-----------------------------------------------------------------------------

void fileNameTest()
{
    std::string name = "/users/home/rweber/testFile.dat";
    std::string baseName = name;

    std::filesystem::path filePath = std::filesystem::path(name);
    if (filePath.has_parent_path())
    {
        std::filesystem::path parentPath = filePath.parent_path();
        LOG_DEBUG("parent directory = %s", parentPath.string().c_str());
        filePath = filePath.filename();
        baseName = filePath.string();
    }
}

//-----------------------------------------------------------------------------

void testBitShift()
{
    // uint8_t byte = 255;
    // uint8_t byte2 = byte + 1;
    // std::cout << "byte = " << std ::to_string(byte) << ", + 1 = "
    //   << std::to_string(byte2) << std::endl;

    ByteCounts counts1;
    ByteVector segs;
    ByteVector newSegs;
    for (uint16_t i = 0; i < 10000; i++)
    {
        uint8_t seg = (uint8_t)std::rand() % 32;
        segs.push_back(seg);
        counts1[seg]++;
        uint8_t mask = seg % 2;
        // uint8_t mask = (imod == 0) ? 2 : 3;
        uint8_t segNew = seg ^ mask;
        newSegs.push_back(segNew);
        // std::cout << "seg = " << std::to_string(seg)
        //     << ",\t mask = " << std::to_string(mask)
        //     << ",\t segNew = " << std::to_string(segNew) << std::endl;
    }

    ByteCounts counts2;
    ByteVector origSegs;
    for (uint16_t i = 0; i < newSegs.size(); i++)
    {
        uint8_t segNew = newSegs[i];
#if 1
        uint8_t tryMask = 0;
        uint8_t seg = segNew ^ tryMask;
        uint8_t mask = seg % 2;
        if (mask != tryMask)
        {
            mask = 1;
            seg = segNew ^ mask;
        }
#else
        uint8_t mask = i % 2;
        uint8_t seg = segNew ^ mask;
#endif

        origSegs.push_back(seg);
        counts2[segNew]++;
        // std::cout << "segNew = " << std::to_string(segNew)
        //     << ",\t mask = " << std::to_string(mask)
        //     << ",\t seg = " << std::to_string(seg) << std::endl;
    }

    assert(segs == origSegs);

    uint16_t maxC1 = 0;
    uint16_t maxC2 = 0;
    uint16_t minC1 = 1000;
    uint16_t minC2 = 1000;
    std::cout << "Seg \t C1 \t C2" << std::endl
              << "--- \t -- \t --" << std::endl;
    for (uint8_t i = 0; i < 32; i++)
    {
        std::cout << std::to_string(i) << "\t"
                  << std::to_string(counts1[i]) << "\t"
                  << std::to_string(counts2[i]) << std::endl;
        if (counts1[i] > maxC1)
            maxC1 = counts1[i];
        if (counts2[i] > maxC1)
            maxC2 = counts2[i];
        if (counts1[i] < maxC1)
            minC1 = counts1[i];
        if (counts2[i] < maxC1)
            minC2 = counts2[i];
    }
    LOG_CONSOLE("Max C1 = %2d,   MaxC2 = %2d", maxC1, maxC2);
    LOG_CONSOLE("Min C1 = %2d,   MinC2 = %2d", minC1, minC2);
}

void testVectorErase()
{
    ByteVector bytes;

    for (uint16_t x = 0; x < 100; x++)
    {
        bytes.push_back(x);
    }
    LOG_CONSOLE("vector size before erase: %ld", bytes.size());

    bytes.erase(bytes.begin(), bytes.end() - 50);
    LOG_CONSOLE("vector size after erase: %ld", bytes.size());
    for (auto vi = bytes.begin(); vi != bytes.end(); vi++)
    {
        LOG_CONSOLE("%d", *vi);
    }
}

void testLoopCount()
{
    int x = 1;
    while (x++ < 100)
    {
        x *= x;
        if (x < 10)
            continue;
        if (x > 50)
            break;
    }
}

void testUniquePtr()
{
    typedef std::unique_ptr<std::vector<int32_t>> UniqueType;
    class Unique
    {
    public:
        Unique()
        {
            fUp = std::make_unique<std::vector<int32_t>>();
            fUp = std::make_unique<std::vector<int32_t>>();
            //         fUp.reset(new std::vector<int32_t>);
            fUp->resize(45);
        }

        void showSize() const
        {
            printf("unique ptr vector size = %zd\n", fUp->size());
        }

        UniqueType &getPtr()
        {
            return fUp;
        }

        void setPtr(UniqueType &p)
        {
            fUp.reset(p.get());
        }

        UniqueType fUp;
    };

    Unique unique;
    unique.showSize();

    UniqueType unP;
    unP = std::make_unique<std::vector<int32_t>>();
    //   unP.reset(new std::vector<int32_t>);

    unique.setPtr(unP);

    unique.showSize();

    {
        UniqueType &up = unique.getPtr();
        unique.showSize();
    }

    unique.showSize();
}

class BaseItem
{
public:
    BaseItem() { printf("in BaseItem()\n"); };
    ~BaseItem() = default;

    // virtual bool operator<(BaseItem &other) = 0;
    // virtual bool operator==(BaseItem &other) = 0;
};

class RealItem : public BaseItem
{
public:
    RealItem(int a, int b)
    {
        v1 = a;
        v2 = b;
    };
    RealItem() { printf("in RealItem()\n"); };
    ~RealItem() = default;

    int v1{0};
    int v2{0};

    bool operator<(const RealItem other) const
    {
        return (v1 < other.v1 && v2 < other.v2);
    }
};

using RealMap = std::map<const RealItem, int, std::less<RealItem>>;
// using RealMap = std::map<RealItem, int>;

void testOperator()
{
    RealMap realMap;

    for (int i = 0; i < 10; i++)
    {
#if 1
        RealItem r1;
        r1.v1 = i + 1;
        r1.v2 = i * 10;
        realMap.insert(std::make_pair(r1, i + 10));
#else
        RealItem *r1 = new RealItem;
        r1->v1 = i + 1;
        r1->v2 = i * 10;
        realMap.insert(std::pair<RealItem *, int>(r1, i + 10));
#endif
    }
    RealItem r2(3, 20);
    auto it = std::find_if(realMap.cbegin(), realMap.cend(), [&r2](std::pair<RealItem, int> const &other)
                           { return r2.v1 == other.first.v1 && r2.v2 == other.first.v2; });
    RealMap::iterator rmi = realMap.find(r2);
    if (rmi != realMap.end())
    {
        printf("Found r2\n");
    }
    else
    {
        printf("Did not find r2\n");
    }
}

void testDynamicCast()
{
    class IShape
    {
    public:
        virtual double getArea() = 0;
        virtual std::string name() = 0;
    };
    class Square : public IShape
    {
    public:
        double getArea() override
        {
            return 2.2;
        }
        std::string name() override
        {
            return "Square";
        }
    };
    class Circle : public IShape
    {
    public:
        double getArea() override
        {
            return 3.14159;
        }
        std::string name() override
        {
            return "Circle";
        }
    };

    IShape *shape = new Circle();

    uint32_t max = 100000000;
    std::string sMax = std::to_string(max);

    {
        Chrono dynamicCast(sMax + " Dynamic Casts");
        for (uint32_t i = 0; i < max; i++)
        {
            Circle *circle = dynamic_cast<Circle *>(shape);
        }
    }
    {
        Chrono staticCast(sMax + " Static Casts");
        for (uint32_t i = 0; i < max; i++)
        {
            Circle *circle = static_cast<Circle *>(shape);
        }
    }
}

//-----------------------------------------------------------------------------

using AllowedCommands = std::set<std::string>;
using SelectedCommands = std::set<std::string>;

namespace
{
    AllowedCommands allowed{"trites", "typeErasure", "uniquePtr", "vectorErase", "Operator", "dynamicCast", "bitShift"};
}

int main(int argc, char **argv)
{
    Logger::setConfiguredLoggingLevel(LEVEL_DEBUG);

    Chrono mainChrono("main");

    SelectedCommands selected;

    LOG_CONSOLE("Input parameters:");
    for (auto i = 0; i < argc; i++)
    {
        char *p = *argv++;
        std::string cmd = p;
        LOG_CONSOLE("  param[%d] = %s", i, p);
        if (allowed.find(cmd) != allowed.end())
        {
            selected.emplace(cmd);
        }
    }

    std::cout << std::to_string(3.1415987) << std::endl;

    // if (selected.find("uniquePtr") != selected.end())
    // {
    //     testUniquePtr();
    // }

    // testOperator();

    // testDynamicCast();

    // testVectorErase();

    // testLoopCount();

    // testBitShift();

    // precisionTest();

    // triteTest();

    // arrayTest();

    // vectorInsertTest();

    // stringFormatTest();

    // printf("Execute file name test\n");
    // fileNameTest();

    return 0;
}
