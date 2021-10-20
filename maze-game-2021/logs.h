#pragma once

//Libraries
#include <iostream>
#include <fstream>

//Structures
struct Logger
{
	void err(std::string msg)
	{
		std::ofstream out("logfile.log");

		// Get the rdbuf of clog.
		auto old_rdbuf = std::clog.rdbuf();

		// Set the rdbuf of clog.
		std::clog.rdbuf(out.rdbuf());

		// Write to clog.
		std::clog << "Error: " << msg << std::endl;

		// Reset the rdbuf of clog.
		std::clog.rdbuf(old_rdbuf);
	}

	void log(std::string msg)
	{
		std::ofstream out("logfile.log");

		// Get the rdbuf of clog.
		auto old_rdbuf = std::clog.rdbuf();

		// Set the rdbuf of clog.
		std::clog.rdbuf(out.rdbuf());

		// Write to clog..
		std::clog << "Log: " << msg << std::endl;

		// Reset the rdbuf of clog.
		std::clog.rdbuf(old_rdbuf);
	}
};