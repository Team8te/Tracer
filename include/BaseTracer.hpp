#pragma once

#include "ITracer.hpp"

#include "IStream.hpp"

#include <memory>

class BaseTracer : public ITracer
{
public:
    BaseTracer(std::unique_ptr<IStream> outStream);

    virtual ~BaseTracer() override = default;
};