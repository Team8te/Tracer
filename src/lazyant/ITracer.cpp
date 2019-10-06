#include "ITracer.hpp"

#include "internal/ImplTracer.hpp"

#include <memory>

namespace lazyant
{

std::unique_ptr<ITracer> make_tracer(std::unique_ptr<IOutStream> stream)
{
    return std::make_unique<internal::ImplTracer>(std::move(stream));
}

}