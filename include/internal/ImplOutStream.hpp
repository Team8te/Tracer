#pragma once

#include "IOutStream.hpp"

#include <string>

namespace lazyant
{
namespace internal
{

class ImplOutStream : public IOutStream
{
public:
    explicit ImplOutStream(const std::string &filePath);

    IOutStream& operator<< (const ITrace &trace) override;

private:
    std::string _filePath;
};

}
}