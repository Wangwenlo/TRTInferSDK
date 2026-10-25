#include "trtinfer/TrtLogger.h"

#include <iostream>

namespace trtinfer
{

    void TrtLogger::log(
        Severity severity,
        const char* msg) noexcept
    {
        if (msg == nullptr)
        {
            return;
        }

        switch (severity)
        {
        case Severity::kINTERNAL_ERROR:
            std::cerr << "[FATAL] " << msg << '\n';
            break;

        case Severity::kERROR:
            std::cerr << "[ERROR] " << msg << '\n';
            break;

        case Severity::kWARNING:
            std::cerr << "[WARNING] " << msg << '\n';
            break;

        case Severity::kINFO:
            std::cout << "[INFO] " << msg << '\n';
            break;

        case Severity::kVERBOSE:
            std::cout << "[VERBOSE] " << msg << '\n';
            break;

        default:
            std::cerr << "[UNKNOWN] " << msg << '\n';
            break;
        }
    }
}