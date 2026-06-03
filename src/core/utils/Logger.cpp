//
//  Logger.cpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#include "Logger.hpp"

void Logger::debug(std::string s) {
   std::cout << "["
      << rang::fgB::gray << "DEBUG"
      << rang::style::reset << "] "
      << s
      << std::endl;
}

void Logger::debug(std::string source, std::string s) {
   std::cout << "["
      << rang::fgB::gray << "DEBUG"
      << rang::style::reset << "] ("
      << rang::style::dim
      << source
      << rang::style::reset
      << ") "
      << s
      << std::endl;
}

void Logger::info(std::string s) {
   std::cout << "["
      << rang::fgB::cyan << "INFO"
      << rang::style::reset << "] "
      << s
      << std::endl;
}

void Logger::info(std::string source, std::string s) {
   std::cout << "["
      << rang::fgB::cyan << "INFO"
      << rang::style::reset << "] ("
      << rang::style::dim
      << source
      << rang::style::reset
      << ") "
      << s
      << std::endl;
}

void Logger::warn(std::string s) {
   std::cout << "["
      << rang::fgB::yellow << "WARN"
      << rang::style::reset << "] "
      << s
      << std::endl;
}

void Logger::warn(std::string source, std::string s) {
   std::cout << "["
      << rang::fgB::yellow << "WARN"
      << rang::style::reset << "] ("
      << rang::style::dim
      << source
      << rang::style::reset
      << ") "
      << s
      << std::endl;
}

void Logger::error(std::string s) {
   std::cout << "["
      << rang::fgB::red << "ERROR"
      << rang::style::reset << "] "
      << s
      << std::endl;
}

void Logger::error(std::string source, std::string s) {
   std::cout << "["
      << rang::fgB::red << "ERROR"
      << rang::style::reset << "] ("
      << rang::style::dim
      << source
      << rang::style::reset
      << ") "
      << s
      << std::endl;
}
