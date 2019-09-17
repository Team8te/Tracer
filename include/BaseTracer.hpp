#pragma once

#include "ITracer.hpp"

#include "IOutStream.hpp"

#include <memory>

namespace lazyant
{

class BaseTracer : public ITracer
{
public:
    BaseTracer(std::unique_ptr<IOutStream> ostream);

    virtual ~BaseTracer() override = default;

protected:
    std::unique_ptr<IOutStream> _ostream;
};

}