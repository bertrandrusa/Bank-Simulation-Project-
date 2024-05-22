//
// Created by James Daehn on 11/23/19.
//

#include "gtest/gtest.h"
#include "BaseGoogleTest.h"
#include "GradeAccumulator.h"

static const int CATEGORY_COLUMN_WIDTH{21};
static const int VALUE_COLUMN_WIDTH{5};
static const int VALUE_PRECISION{2};
static const int DEFAULT_UNTESTED_GRADE{0};
static const int DEFAULT_ASSIGNMENT_GRADE{2};

class StandardOutputTestFixture : public BaseGoogleTest {
public:
    StandardOutputTestFixture() : buffer{std::stringstream{}}, sbuf{nullptr} {
        // intentionally empty
    }

protected:
    std::stringstream buffer;
    std::streambuf *sbuf;

    static void SetUpTestSuite() {
        testing::internal::CaptureStdout();
    }

    static void TearDownTestSuite() {
        std::string output = testing::internal::GetCapturedStdout();
        std::cout << output << std::endl;
    }

    void SetUp() override {
        BaseGoogleTest::SetUp();
        // Save cout's buffer here
        sbuf = std::cout.rdbuf();
        // Redirect cout to our stringstream buffer or any other ostream
        std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        BaseGoogleTest::TearDown();
        // When done redirect cout to its old self
        std::cout.rdbuf(sbuf);
    }

    std::string getBufferedOutput() const {
        return buffer.str();
    }

    // Reusable objects for each unit test in this test fixture
};

#if SIMULATE_FUNCTION_IMPLEMENTED
TEST_F( StandardOutputTestFixture, SimulateTest )
{
    csc232::simulate( "test_data.txt" );
    std::string bufferedOutput = getBufferedOutput( );
    const char* actual = bufferedOutput.c_str( );
    const char* expected = "Simulation Begins\n"
                           "Processing an arrival event at time:   1\n"
                           "Processing an arrival event at time:   2\n"
                           "Processing an arrival event at time:   4\n"
                           "Processing a departure event at time:  6\n"
                           "Processing a departure event at time: 11\n"
                           "Processing a departure event at time: 16\n"
                           "Processing an arrival event at time:  20\n"
                           "Processing an arrival event at time:  22\n"
                           "Processing an arrival event at time:  24\n"
                           "Processing a departure event at time: 25\n"
                           "Processing an arrival event at time:  26\n"
                           "Processing an arrival event at time:  28\n"
                           "Processing an arrival event at time:  30\n"
                           "Processing a departure event at time: 30\n"
                           "Processing a departure event at time: 35\n"
                           "Processing a departure event at time: 40\n"
                           "Processing a departure event at time: 45\n"
                           "Processing a departure event at time: 50\n"
                           "Processing an arrival event at time:  88\n"
                           "Processing a departure event at time: 91\n"
                           "Simulation Ends\n"
                           "\n"
                           "Final Statistics:\n"
                           "\tTotal number of people processed: 10\n"
                           "\tAverage amount of time spent waiting: 5.6\n";
    EXPECT_STREQ( actual, expected );
}
#endif

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result{RUN_ALL_TESTS()};
    std::cout << std::fixed << std::setprecision(VALUE_PRECISION);
    std::cout << "\n\n";
    int earnPoints{GradeAccumulator::Instance().GetEarnedPoints()};
    int possiblePoints{GradeAccumulator::Instance().GetPossiblePoints()};
    std::cout << std::left << std::setw(CATEGORY_COLUMN_WIDTH) << "Earned Points:"
              << std::right << std::setw(VALUE_COLUMN_WIDTH) << static_cast<double>(earnPoints) << std::endl;
    std::cout << std::left << std::setw(CATEGORY_COLUMN_WIDTH) << "Possible Points:"
              << std::right << std::setw(VALUE_COLUMN_WIDTH) << static_cast<double>(possiblePoints) << std::endl;
    double correctnessPoints{GradeAccumulator::Instance().GetPossiblePoints() != DEFAULT_UNTESTED_GRADE
                             ? (static_cast<double>(earnPoints) / possiblePoints) * DEFAULT_ASSIGNMENT_GRADE
                             : DEFAULT_UNTESTED_GRADE};
    std::cout << std::left << std::setw(CATEGORY_COLUMN_WIDTH) << "Correctness Points:"
              << std::right << std::setw(VALUE_COLUMN_WIDTH) << correctnessPoints << std::endl;
    return result;
}
