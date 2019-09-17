#include "BaseTracer.hpp"

namespace lazyant
{

BaseTracer::BaseTracer(std::unique_ptr<IOutStream> ostream)
    : _ostream(std::move(ostream))
{}

}