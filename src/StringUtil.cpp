#include "StringUtil.h"

#include <cctype>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <stdarg.h>
#include <string.h>     // for strerror on Linux
#include <vector>

std::string StringUtil::format(const char* inFormat, ...)
{
    char temp[4096];
    
    va_list args;
    va_start (args, inFormat);
    
    vsnprintf(temp, 4096, inFormat, args);

    return std::string(temp);
}

bool StringUtil::strequi(const std::string& str1, const std::string& str2)
{
    return ((str1.size() == str2.size()) && std::equal(str1.begin(), str1.end(), str2.begin(), [](const char& c1, const char& c2) {
        return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
        }));
}

char* StringUtil::errorToString(int errNum)
{
    return strerror(errNum);
}

std::string StringUtil::getCurrentDateTime(bool withYear, bool withMs)
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream dateString;

    if (withYear)
    {
        dateString << std::put_time(std::localtime(&in_time_t), "%b %d %Y %X");
    }
    else
    {
        dateString << std::put_time(std::localtime(&in_time_t), "%b %d %X");
    }

    if (withMs)
    {
        auto duration = now.time_since_epoch();
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 1000;
        char msBuf[16];
        sprintf(msBuf, "%03d", millis);
        dateString << "." << msBuf;
    }

    return dateString.str();
}
