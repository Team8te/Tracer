#include "internal/ImplOutStream.hpp"

#include <fstream>

namespace lazyant
{
namespace internal
{

ImplOutStream::ImplOutStream(const std::string &filePath)
    : _filePath(filePath)
{
}

IOutStream& ImplOutStream::operator<< (const ITrace &trace)
{
    return *this;
}

}
}