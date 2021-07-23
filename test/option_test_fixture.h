#include "option_test_spi.h"
#include "synchronizer.h"
#include "gtest/gtest.h"

class OptionApiTestFixture : public testing::Test {
protected:
  void SetUp() override {
    api_.RegisterSpi(&spi_);
    ASSERT_TRUE(api_.LoadCfg("sim_env.conf"));
    ASSERT_TRUE(api_.Start());
  }

  Synchronizer sync_;
  Quant360::OesClientApi api_;
  OptionTestSpi spi_{sync_};
};
