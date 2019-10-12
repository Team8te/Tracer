#pragma once

#include "export.hpp"

#include "ITrace.hpp"

namespace lazyant
{

class LAZYANT_API IOutStream
{
public:
    virtual ~IOutStream() = default;

    virtual IOutStream& operator<< (const ITrace& trace) = 0;
};

}