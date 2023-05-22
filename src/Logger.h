#pragma once

#include <fstream>
#include <mutex>
#include <string>
#include <vector>

enum LogLevel
{
    LEVEL_CONSOLE = -2,
    LEVEL_FATAL = -1,
    LEVEL_ERROR = 0,
    LEVEL_WARNING = 1,
    LEVEL_FILE = 2,
    LEVEL_CHUNK = 3,
    LEVEL_PHASE = 4,
    LEVEL_CHRONO = 5,
    LEVEL_DEBUG = 6,
};


class Logger
{
public:

    static void log(LogLevel logLevel, const char* format, ...);

    template<typename T>
    static void logBuffer(LogLevel logLevel, const char* title, const std::vector<T>& buffer);

    static void clear();

    static void close();

    static void setConfiguredLoggingLevel(LogLevel confLogLevel);

    static void setFileName(std::string fn);

    static void setUseLoggingThreadId(bool value);

private:

    static std::mutex logLock;
    static bool hasInitialized;
    static std::ofstream logFile;
    static std::string fileName;
    static LogLevel configuredLoggingLevel;
    static bool isLoggingThreadId;

    Logger();
    ~Logger();
    Logger(Logger& logger);

};


#ifdef _DEBUG
#define LOG_DEBUG(...) Logger::log(LogLevel::LEVEL_DEBUG, __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#endif

#define LOG_PHASE(...) Logger::log(LogLevel::LEVEL_PHASE, __VA_ARGS__)
#define LOG_CHUNK(...) Logger::log(LogLevel::LEVEL_CHUNK, __VA_ARGS__)
#define LOG_FILE(...) Logger::log(LogLevel::LEVEL_FILE, __VA_ARGS__)
#define LOG_WARNING(...) Logger::log(LogLevel::LEVEL_WARNING, __VA_ARGS__)
#define LOG_ERROR(...) Logger::log(LogLevel::LEVEL_ERROR, __VA_ARGS__)
#define LOG_FATAL(...) Logger::log(LogLevel::LEVEL_FATAL, __VA_ARGS__);
#define LOG_CONSOLE(...) Logger::log(LogLevel::LEVEL_CONSOLE, __VA_ARGS__);
