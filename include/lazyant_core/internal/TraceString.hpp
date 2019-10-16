#pragma once

#include "lazyant_core/ITrace.hpp"

namespace lazyant
{
namespace core
{
namespace internal
{

class TraceString : public ITrace
{
public:
    TraceString() = default;

    ~TraceString() = default;

    std::string to_string() const override;
};

}
}
}