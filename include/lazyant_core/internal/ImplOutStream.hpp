#pragma once

#include "lazyant_core/IOutStream.hpp"

#include <string>

namespace lazyant
{
namespace core
{
namespace internal
{

class ImplOutStream : public IOutStream
{
public:
    explicit ImplOutStream(const std::string& filePath);

    IOutStream& operator<< (const ITrace& trace) override;

private:
    std::string _filePath;
};

}
}
}