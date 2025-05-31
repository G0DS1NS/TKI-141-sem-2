#pragma once
#include <iostream>
#include <string>

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assert failed: " << message << " (" << #condition << ")" \
                      << " in " << __FILE__ << ":" << __LINE__ << std::endl; \
            return false; \
        } \
    } while (false)

class TestCase
{
public:
    virtual ~TestCase() = default;
    virtual bool run() = 0;
    std::string name;
};

void RunTest(TestCase* test);

