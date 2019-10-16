#pragma once

#include "lazyant_core/ITracer.hpp"

#include "lazyant_core/IOutStream.hpp"

#include <list>
#include <memory>

namespace lazyant
{
namespace core
{
namespace internal
{

class ImplTracer : public ITracer
{
public:
    explicit ImplTracer(std::unique_ptr<IOutStream> _ostream);

    void AddTrace(std::unique_ptr<ITrace> trace) override;

    void Commit() const override;

    void Clear() override;

private:
    std::unique_ptr<IOutStream> _ostream;
    std::list<std::unique_ptr<ITrace>> _history;
};

}
}
}