#include "internal/ImplTracer.hpp"

namespace lazyant
{
namespace internal
{

ImplTracer::ImplTracer(std::unique_ptr<IOutStream> ostream)
    : _ostream(std::move(ostream))
{
}

void ImplTracer::AddTrace(std::unique_ptr<ITrace> trace)
{
    _history.push_back(std::move(trace));
}

void ImplTracer::Clear()
{
    _history.clear();
}

void ImplTracer::Commit() const
{
    for (const auto& element : _history) {
        *_ostream << *(element.get());
    }
}

}
}