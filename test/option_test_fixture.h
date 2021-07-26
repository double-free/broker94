#pragma once

#include "option_test_spi.h"
#include "synchronizer.h"
#include "gtest/gtest.h"

class OptionApiTestFixture : public testing::Test {
protected:
  void SetUp() override {
    strncpy(option_.securityId, "10003206", sizeof(option_.securityId) - 1);
    strncpy(option_.underlyingSecurityId, "510050",
            sizeof(option_.contractId) - 1);
    strncpy(option_.contractId, "510050C2109M03500",
            sizeof(option_.contractId) - 1);
    option_.exercisePrice = 35000;
    option_.mktId = OES_MKT_SH_OPTION;

    api_.RegisterSpi(&spi_);
    ASSERT_TRUE(api_.LoadCfg("sim_env.conf"));
    ASSERT_TRUE(api_.Start());
    ASSERT_EQ(confirm_option_settlement(), 0);
  }

  void TearDown() override { api_.Stop(); }

  OesOptionItemT option_;

  Synchronizer sync_;
  Quant360::OesClientApi api_;
  OptionTestSpi spi_{sync_};

  // a sync call to confirm option settlement
  // must be called before send any order
  // return 0 on success
  int32_t confirm_option_settlement() {
    OesOptSettlementConfirmReqT optSettleCnfmReq = {
        NULLOBJ_OES_OPT_SETTLEMENT_CONFIRM_REQ};
    OesOptSettlementConfirmRspT optSettleCnfmRsp = {
        NULLOBJ_OES_OPT_SETTLEMENT_CONFIRM_RSP};

    strncpy(optSettleCnfmReq.custId, "A1888000541",
            sizeof(optSettleCnfmReq.custId) - 1);
    return api_.SendOptSettlementConfirm(&optSettleCnfmReq, &optSettleCnfmRsp);
  }
};
