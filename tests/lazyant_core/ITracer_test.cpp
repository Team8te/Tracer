#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <lazyant_core/ITracer.hpp>

using ::testing::Throw;
using ::testing::HasSubstr;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Invoke;
using ::testing::_;

namespace
{
using namespace lazyant::core;

class MockStream : public IOutStream
{
public:
    MockStream() = default;

    IOutStream& operator<< (const ITrace& trace) override
    {
        Output(trace.to_string());
        return *this;
    }

    MOCK_METHOD1(Output, void(const std::string &stringTrace));
};

class FakeTrace : public ITrace
{
public:
    FakeTrace(const std::string& data)
        : _data(data)
    {}

    std::string to_string() const override
    {
        return _data;
    }

private:
    std::string _data;
};

}

TEST(ITracer, make_tracer)
{
    auto stream = std::make_unique<MockStream>();
    ASSERT_NO_THROW(make_tracer(std::move(stream)));
}

TEST(ITracer, AddTrace)
{
    auto stream = std::make_unique<MockStream>();
    std::unique_ptr<ITracer> tracer;
    ASSERT_NO_THROW(tracer = make_tracer(std::move(stream)));

    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data")));
}

TEST(ITracer, AddSeveralTrace)
{
    auto stream = std::make_unique<MockStream>();
    std::unique_ptr<ITracer> tracer;
    ASSERT_NO_THROW(tracer = make_tracer(std::move(stream)));

    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data0")));
    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data1")));
    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data2")));
    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data3")));
    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data4")));
}

TEST(ITracer, CommitTrace)
{
    auto stream = std::make_unique<MockStream>();
    const std::string trace_value = "test data";

    EXPECT_CALL(*stream, Output(trace_value)).WillOnce(Return());
    std::unique_ptr<ITracer> tracer;
    ASSERT_NO_THROW(tracer = make_tracer(std::move(stream)));

    ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>("test data")));
    ASSERT_NO_THROW(tracer->Commit());
}

TEST(ITracer, CommitSeveralTrace)
{
    auto stream = std::make_unique<MockStream>();
    const std::string trace_value = "test data";

    for (int i = 0; i < 5; ++i) {
        EXPECT_CALL(*stream, Output(trace_value + std::to_string(i))).WillOnce(Return());
    }
    std::unique_ptr<ITracer> tracer;
    ASSERT_NO_THROW(tracer = make_tracer(std::move(stream)));

    for (int i = 0; i < 5; ++i) {
        const auto data = trace_value + std::to_string(i);
        ASSERT_NO_THROW(tracer->AddTrace(std::make_unique<FakeTrace>(data)));
    }

    ASSERT_NO_THROW(tracer->Commit());
}