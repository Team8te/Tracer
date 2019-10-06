#pragma once 

#include "ITrace.hpp"

namespace lazyant
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