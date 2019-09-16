#pragma once

class ITracer
{
public:
    virtual ~ITracer() = default;

    virtual void AddTrace() = 0;

    virtual void SaveTrace() const = 0;

    virtual void Clear() = 0;
};