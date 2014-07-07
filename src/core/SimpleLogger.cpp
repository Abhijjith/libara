/*
 * $FU-Copyright$
 */

#include "SimpleLogger.h"

#include <cstdio>
#include <iostream>

using namespace std;

namespace ARA {


// TODO: we should fix this since 'va_start' has undefined behavior with reference types
void SimpleLogger::performLoggingAction(const std::string &logMessage, Level level, va_list args) const {
    char buffer[512]; // FIXME a dynamic buffer size would be awesome
    vsprintf(buffer, logMessage.c_str(), args);
    //cout << instanceName << "  [" << getLevelString(level) << "] " << buffer << "\n";
    cerr << instanceName << "  [" << getLevelString(level) << "] " << buffer << "\n";
}

} /* namespace ARA */
