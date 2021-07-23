#include "option_test_fixture.h"

#include <gtest/gtest.h>

TEST_F(OptionApiTestFixture, ApiVersion) {
  EXPECT_STREQ(api_.GetVersion(), "0.16.1.9");
}
