#pragma once

#include "export.hpp"

#include "IOutStream.hpp"
#include "ITrace.hpp"

#include <memory>

namespace lazyant
{

class LAZYANT_API ITracer
{
public:
    virtual ~ITracer() = default;

    virtual void AddTrace(std::unique_ptr<ITrace> trace) = 0;

    virtual void Commit() const = 0;

    virtual void Clear() = 0;
};

std::unique_ptr<ITracer> LAZYANT_API make_tracer(std::unique_ptr<IOutStream> stream);

}