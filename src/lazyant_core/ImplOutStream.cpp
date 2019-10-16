#include "lazyant_core/internal/ImplOutStream.hpp"

#include <fstream>

namespace lazyant
{
namespace core
{
namespace internal
{

ImplOutStream::ImplOutStream(const std::string& filePath)
    : _filePath(filePath)
{
}

IOutStream& ImplOutStream::operator<< (const ITrace& trace)
{
    return *this;
}

}
}
}