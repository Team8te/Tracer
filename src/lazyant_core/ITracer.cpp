#include "lazyant_core/ITracer.hpp"

#include "lazyant_core/internal/ImplTracer.hpp"

#include <memory>

namespace lazyant
{
namespace core
{

std::unique_ptr<ITracer> LAZYANT_API make_tracer(std::unique_ptr<IOutStream> stream)
{
    return std::make_unique<internal::ImplTracer>(std::move(stream));
}

}
}