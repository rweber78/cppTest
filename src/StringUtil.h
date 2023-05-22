#pragma once

#include <cstdarg>
#include <iomanip>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// OUT_Z_ARRAY indicates an output array that will be null-terminated.
#if _MSC_VER >= 1600
    // Include the annotation header file.
    #include <sal.h>
    #if _MSC_VER >= 1700
        // VS 2012+
        #define OUT_Z_ARRAY _Post_z_
    #else
        // VS 2010
        #define OUT_Z_ARRAY _Deref_post_z_
    #endif
#else
    // gcc, clang, old versions of VS
    #define OUT_Z_ARRAY
#endif

class StringUtil
{
public:
    template<typename T>
    static T stringToNumber(const std::string &str, T defVal = 0)
    {
        std::stringstream ss(str);
        T value;
        if ((ss >> value).fail())
        {
            return defVal;
        }
        
        return value;
    }

    template <typename T>
    static std::string vectorToString(std::vector<T>& data, uint8_t width=5)
    {
        std::stringstream buf;

        size_t i(0);
        for (auto value : data)
        {
            if (i > 0)
            {
                buf << ", ";
            }
            buf << std::setw(width) << std::to_string(value);
            i++;
        }
        return buf.str();
    }

    static std::string format(const char* inFormat, ...);

    static std::string getCurrentDateTime(bool withYear, bool withMs);

    //* Case-insensitive comparison of 2 strings.
    //* @return true if strings are the same.
    static bool strequi(const std::string& str1, const std::string& str2);

    static char*errorToString(int errNum);

private:
    // ctor, copy ctor, and assignment should be private in a Static Utility Class
    StringUtil();
    ~StringUtil();
    StringUtil(const StringUtil&);
    StringUtil& operator=(const StringUtil&);
};
