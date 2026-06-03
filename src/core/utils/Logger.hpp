//
//  Logger.hpp
//  MazeEscape
//
//  Created by Christopher Anderson on 6/2/2026.
//

#pragma once

#include <string>

#include "rang.hpp"

class Logger {
public:
   /**
    * Log debug messages to console
    * 
    * @param s Message to log
    */
   static void debug(std::string s);

   /**
    * Log debug messages to console
    * 
    * @param source The class which calls the logging method
    * @param s Message to log
    */
   static void debug(std::string source, std::string s);

   /**
    * Log info messages to console
    * 
    * @param s Message to log
    */
   static void info(std::string s);

   /**
    * Log info messages to console
    * 
    * @param source The class which calls the logging method
    * @param s Message to log
    */
   static void info(std::string source, std::string s);

   /**
    * Log warning messages to console
    * 
    * @param s Message to log
    */
   static void warn(std::string s);

   /**
    * Log warning messages to console
    * 
    * @param source The class which calls the logging method
    * @param s Message to log
    */
   static void warn(std::string source, std::string s);

   /**
    * Log error messages to console
    * 
    * @param s Message to log
    */
   static void error(std::string s);

   /**
    * Log error messages to console
    * 
    * @param source The class which calls the logging method
    * @param s Message to log
    */
   static void error(std::string source, std::string s);
};