#include "Logger.h"

#include "StringUtil.h"

#include <stdio.h>
#include <chrono>
#include <cstdarg>
#include <cstdint>
#include <iomanip> // put_time
#include <sstream>
#include <fstream>
#include <thread>

using namespace std;

const char* LogFileName = "logger.log";

bool Logger::hasInitialized = false;
ofstream Logger::logFile;
std::mutex Logger::logLock;
std::string Logger::fileName(LogFileName);
LogLevel Logger::configuredLoggingLevel = LEVEL_WARNING;
bool Logger::isLoggingThreadId = false;


void Logger::setConfiguredLoggingLevel(LogLevel confLogLevel)
{
    configuredLoggingLevel = confLogLevel;
}

void Logger::setFileName(std::string fn)
{
    fileName = fn;
}

void Logger::setUseLoggingThreadId(bool value)
{
    isLoggingThreadId = value;
}

void Logger::clear()
{
    bool haveLock(false);
    //logLock.lock();
    if (logLock.try_lock())
    {
        haveLock = true;
    }
    else
    {
        haveLock = false;
    }

    if (hasInitialized)
    {
        logFile.close();
    }

    logFile.open(fileName, std::ios::trunc);
    hasInitialized = true;

    if (haveLock)
    {
        logLock.unlock();
    }
}

static char outputBuffer[100*1024];  // Protected by lock

void Logger::log(LogLevel logLevel, const char *format, ...)
{
    if (logLevel > configuredLoggingLevel)
    {
        return;
    }

    bool haveLock(false);
    //logLock.lock();
    if (logLock.try_lock())
    {
        haveLock = true;
    }
    else
    {
        haveLock = false;
    }

    va_list ap;
    va_start(ap, format);
    vsnprintf(outputBuffer, sizeof(outputBuffer), format, ap);
    va_end(ap);

    if (logLevel == LEVEL_CONSOLE
        || logLevel == LEVEL_FATAL
        || logLevel == LEVEL_ERROR
        || logLevel == LEVEL_WARNING)
    {
        printf("%s\n\r", outputBuffer);
    }

    std::thread::id tid = std::this_thread::get_id();
    ostringstream logFileMsg;
    logFileMsg << StringUtil::getCurrentDateTime(false, true).c_str() << " ";

    if (isLoggingThreadId)
    {
        logFileMsg << std::setw(5) << tid << " ";
    }

    switch (logLevel)
    {
    case LEVEL_FATAL:
    {
        logFileMsg << "*****  FATAL:  ";
        break;
    }
    case LEVEL_ERROR:
    {
        logFileMsg << "***  ERROR:  ";
        break;
    }
    case LEVEL_WARNING:
    {
        logFileMsg << "*  WARNING: ";
        break;
    }
    case LEVEL_FILE:
    {
        logFileMsg << "  FILE: ";
        break;
    }
    case LEVEL_CHUNK:
    {
        logFileMsg << " CHUNK: ";
        break;
    }
    case LEVEL_PHASE:
    {
        logFileMsg << " PHASE: ";
        break;
    }
    case LEVEL_CHRONO:
    {
        logFileMsg << " CHRON: ";
        break;
    }
    case LEVEL_DEBUG:
    {
        logFileMsg << " DEBUG: ";
        break;
    }
    default:
    {
        break;
    }
    }

    logFileMsg << outputBuffer << endl;

    if (!hasInitialized)
    {
        logFile.open(fileName, std::ios::app);
        hasInitialized = true;
    }

    logFile << logFileMsg.str();
    logFile.flush();

    if (haveLock)
    {
        logLock.unlock();
    }

    if (logLevel == LEVEL_FATAL)
    {
        std::string e(outputBuffer);
        throw e;
    }
}

template<typename T>
void Logger::logBuffer(LogLevel logLevel, const char* title, const std::vector<T>& buffer)
{
#ifdef _DEBUG
    if (logLevel == LEVEL_DEBUG)
    {
        return;
    }
#endif
    uint8_t typeSize = sizeof(T);
    const char* format;
    if (typeSize == 1)
    {
        format = "%02x ";
    }
    else if (typeSize == 2)
    {
        format = "%04x ";
    }
    else
    {
        format = "%0x ";
    }

    const char* prefix = "     ";
    std::stringstream bufferStream;
    bufferStream << title << "(" << buffer.size() << ")" << endl << prefix;

    uint8_t bytesOnLine = 0;
    char byteBuf[128];
    for (uint16_t i = 0; i < buffer.size(); i++)
    {
        sprintf(byteBuf, format, buffer[i]);
        bufferStream << byteBuf;
        bytesOnLine++;
        if (bytesOnLine >= 16)
        {
            bufferStream << endl << prefix;
            bytesOnLine = 0;
        }
    }
    log(logLevel, "", 0, "%s", bufferStream.str().c_str());
}

template void Logger::logBuffer(LogLevel logLevel, const char* title, const std::vector<uint8_t>& buffer);
template void Logger::logBuffer(LogLevel logLevel, const char* title, const std::vector<uint16_t>& buffer);

void Logger::close()
{
    logLock.lock();
    if (hasInitialized)
    {
        logFile.close();
        hasInitialized = false;
    }
    logLock.unlock();
}
