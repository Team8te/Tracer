#pragma once

#include <string>

namespace lazyant
{

class ITrace
{
public:
    virtual ~ITrace() = default;

    virtual std::string to_string() const = 0;
};

}