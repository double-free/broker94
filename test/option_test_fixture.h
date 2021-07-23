#include "../src/option_spi.h"
#include "gtest/gtest.h"

class OptionApiTestFixture: public testing::Test {
protected:
  void SetUp() override {
    api_.RegisterSpi(&spi_);
    ASSERT_TRUE(api_.LoadCfg("sim_env.conf"));
    ASSERT_TRUE(api_.Start());
  }

  Quant360::OesClientApi api_;
  OptionSpi spi_;
};
