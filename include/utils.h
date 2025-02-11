#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <string>

#define LOG(...) utils::LogWrapper(__func__, __VA_ARGS__)

namespace utils {

template <typename T>
void Log(T t) 
{
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void Log(T t, Args... args) 
{
    std::cout << t << " ";
    Log(args...);
}

template<typename... Args>
void LogWrapper(const char* funcName, Args... args)
{
    std::cout << "[" << funcName << "] ";
    Log(args...);
}

}

#endif