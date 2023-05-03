#include "lib.hpp"
#include "gtest/gtest.h"

TEST(Test_lib,Coorect){
    EXPECT_GT(current_version(),100);
}