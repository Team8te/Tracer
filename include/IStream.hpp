#pragma once

#include "Trace.hpp"

class IStream
{
public:
    virtual ~IStream() = default;

    virtual void operator<< (Trace &trace) const = 0;
};