#pragma once

#include <string>

namespace lazyant
{

class ITrace
{
public:
    ITrace() = default;

    ~ITrace() = default;

    virtual std::string to_string() const = 0;
};

}