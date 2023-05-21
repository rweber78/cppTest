// *********************************************************
// Copyright © 2020 BitGen. All rights reserved.
//
// The copyright to the computer program(s) herein is the
// sole property of BitGen Technology. The program(s) may
// be used and/or copied only with the written permission of
// BitGen Technology or in accordance with the terms and
// conditions stipulated in the agreement/contract under
// which the program(s) have been supplied. This copyright
// notice must not be removed.
// *********************************************************

#include "Chrono.h"

Chrono::Chrono(std::string title, LogLevel logLevel)
: m_title(title)
, m_startTime(std::chrono::high_resolution_clock::now())
, m_markTime(m_startTime)
, m_logLevel(logLevel)
{
    //Logger::log(m_logLevel, "CHRONO BEGIN: %s", title.c_str());
}

double Chrono::getElapseTime()
{
    return getElapseTime(m_startTime);
}

double Chrono::getElapseTime(std::chrono::high_resolution_clock::time_point referenceTime)
{
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = endTime - referenceTime;
    return elapsed.count();
}

Chrono::~Chrono()
{
    double elapsedSeconds = getElapseTime(m_startTime);

    Logger::log(m_logLevel, "CHRONO END: %s : duration = %f s", m_title.c_str(), elapsedSeconds);
}

void Chrono::mark(std::string title)
{
    double elapsedSeconds = getElapseTime(m_markTime);

    Logger::log(m_logLevel, "CHRONO MARK: %s : duration = %f s", title.c_str(), elapsedSeconds);

    m_markTime = std::chrono::high_resolution_clock::now();
}
