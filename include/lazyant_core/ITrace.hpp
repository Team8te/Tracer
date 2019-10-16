#pragma once

#include "export.hpp"

#include <string>

namespace lazyant
{
namespace core
{

class LAZYANT_API ITrace
{
public:
    virtual ~ITrace() = default;

    virtual std::string to_string() const = 0;
};

}
}