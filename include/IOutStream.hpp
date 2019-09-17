#pragma once

#include "Trace.hpp"

namespace lazyant
{

class IOutStream
{
public:
    virtual ~IOutStream() = default;

    virtual void operator<< (Trace &trace) const = 0;
};

}