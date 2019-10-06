#pragma once

#include "ITrace.hpp"

namespace lazyant
{

class IOutStream
{
public:
    virtual ~IOutStream() = default;

    virtual IOutStream& operator<< (const ITrace &trace) = 0;
};

}