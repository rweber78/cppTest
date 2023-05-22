#pragma once

#include "Logger.h"

#include <chrono>
#include <string>

class Chrono
{
public:

	explicit Chrono(std::string title, LogLevel logLevel=LEVEL_CHRONO);

	~Chrono();

	double getElapseTime(std::chrono::high_resolution_clock::time_point referenceTime);

	double getElapseTime();

	void mark(std::string title);

private:

	std::string m_title;
	std::chrono::high_resolution_clock::time_point m_startTime;
	std::chrono::high_resolution_clock::time_point m_markTime;
	LogLevel m_logLevel;
};

