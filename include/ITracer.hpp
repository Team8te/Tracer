#pragma once

#include "export.hpp"
#include "ITrace.hpp"

namespace lazyant
{

class LAZYANT_API ITracer
{
public:
    virtual ~ITracer() = default;

    virtual void AddTrace(const ITrace& trace) = 0;

    virtual void Commit() const = 0;

    virtual void Clear() = 0;
};

}