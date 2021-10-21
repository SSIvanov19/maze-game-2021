/*! @file logs.h
*   @brief A header file for the logs.
*/

#pragma once

//Libraries
#include <iostream>
#include <fstream>
#include <ctime>

/**
 * @brief A struct that holds the functions for logging.
*/
struct Logger
{
	/// @brief A function for error logging
	/// @param msg The message to be logged
	void err(std::string msg)
	{
		//Get the time, return the seconds from 1 Jan 1970
		time_t rawtime = time(0);

		//Struct that contains a calendar date and time broken down into its components.
		struct tm timeinfo;

		//Convert the time to the structure
		localtime_s(&timeinfo, &rawtime);

		// create an output stream
		std::ofstream trace_log("logfile.log", std::fstream::app);

		// connect stream buffers
		std::streambuf* cerrbuf = std::cerr.rdbuf();
		std::cerr.rdbuf(trace_log.rdbuf());

		// log 
		std::cerr << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << " " << timeinfo.tm_mday << "-" << 1 + timeinfo.tm_mon << "-" << 1900 + timeinfo.tm_year << " Error at " << msg << std::endl;

		// restore
		std::cerr.flush();
		std::cerr.rdbuf(cerrbuf);
	}

	/// @brief A function for logging
	/// @param msg The message to be logged 
	void log(std::string msg)
	{
		//Get the time, return the seconds from 1 Jan 1970
		time_t rawtime = time(0);

		//Struct that contains a calendar date and time broken down into its components.
		struct tm timeinfo;

		//Convert the time to the structure
		localtime_s(&timeinfo, &rawtime);

		// create an output stream
		std::ofstream trace_log("logfile.log", std::fstream::app);

		// connect stream buffers
		std::streambuf* clogbuff = std::clog.rdbuf();
		std::clog.rdbuf(trace_log.rdbuf());

		// log 
		std::clog << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << " " << timeinfo.tm_mday << "-" << 1 + timeinfo.tm_mon << "-" << 1900 + timeinfo.tm_year << " Log: " << msg << std::endl;

		// restore
		std::clog.flush();
		std::clog.rdbuf(clogbuff);
	}
};