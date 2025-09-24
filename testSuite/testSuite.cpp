#include <gtest/gtest.h>
#include "programTimer.h"
#include <limits.h>

TEST(checkForCMDargumentsTests, numericInputs) {
    EXPECT_EQ(checkForCMDArguments(2), true);
    // EXPECT_EQ(checkForCMDArguments(3), false);
    // EXPECT_EQ(checkForCMDArguments(INT_MAX), false);
}