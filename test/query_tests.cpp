#include "option_test_fixture.h"

#include <gtest/gtest.h>

TEST_F(OptionApiTestFixture, GeneralInformation) {
  EXPECT_STREQ(api_.GetVersion(), "0.16.1.9");
  sync_.start_transaction(
      [this] { return api_.QueryCashAsset(nullptr, 12345); });
  sync_.wait();
  // call back received
  EXPECT_EQ(spi_.receivedRequestID, 12345);
}

TEST_F(OptionApiTestFixture, QueryOption) {
  strncpy(spi_.expected_option_item.securityId, "10001229",
          sizeof(spi_.expected_option_item.securityId) - 1);
  OesQryOptionFilterT option_filter;
  strncpy(option_filter.securityId, spi_.expected_option_item.securityId,
          sizeof(option_filter.securityId) - 1);
  option_filter.mktId = OES_MKT_ID_UNDEFINE;

  api_.QueryOption(&option_filter, 12345);
  // call back received
  EXPECT_EQ(spi_.receivedRequestID, 12345);
}
