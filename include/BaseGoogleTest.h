/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @file      MagicSquareGoogleTest.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */


#ifndef MSU_CSC232_TEST_H
#define MSU_CSC232_TEST_H

#include "gtest/gtest.h"
#include "csc232.h"
#include "GradeAccumulator.h"

namespace {
    class BaseGoogleTest : public ::testing::Test {
    public:
    protected:
        void SetUp() override {
            GradeAccumulator::Instance().IncrementPossiblePointsBy(1);
        }

        void TearDown() override {
            if (!HasFailure())
            {
                GradeAccumulator::Instance().IncrementEarnedPointsBy(1);
            }
        }
    };

} // end namespace

#endif //MSU_CSC232_TEST_H
