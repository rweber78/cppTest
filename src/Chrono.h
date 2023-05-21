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

