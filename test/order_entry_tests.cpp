#include "option_test_fixture.h"

#include <gtest/gtest.h>

TEST_F(OptionApiTestFixture, OrderCancel) {
  OesOrdReqT order_req{NULLOBJ_OES_ORD_REQ};
  order_req.clSeqNo = ++api_.defaultClSeqNo;
  order_req.mktId = OES_MKT_SH_OPTION;
  order_req.ordType = OES_ORD_TYPE_LMT;
  order_req.bsType = OES_BS_TYPE_BUY_OPEN;
  strncpy(order_req.securityId, option_.securityId,
          sizeof(order_req.securityId) - 1);
  // invAcctId is optional
  order_req.ordQty = 3;

  // 1754 is the close price
  order_req.ordPrice = 1500;
  // insertion succeeds
  EXPECT_EQ(0, sync_.start_transaction(
                   [this, &order_req] { return api_.SendOrder(&order_req); }));
  sync_.wait();

  if (spi_.last_order_insert_report.clOrdId == 0) {
    // it must be rejected
    EXPECT_EQ(spi_.last_order_reject_report.clSeqNo, order_req.clSeqNo);
    return;
  }

  // insertion accepted by exchange
  EXPECT_EQ(spi_.last_order_insert_report.clSeqNo, order_req.clSeqNo);
  EXPECT_NE(spi_.last_order_insert_report.clOrdId, 0);

  // cancel the previous order
  OesOrdCancelReqT order_cancel_req{NULLOBJ_OES_ORD_CANCEL_REQ};
  order_cancel_req.origClSeqNo = api_.defaultClSeqNo;
  order_cancel_req.origClOrdId = spi_.last_order_insert_report.clOrdId;
  order_cancel_req.clSeqNo = ++api_.defaultClSeqNo;
  order_cancel_req.mktId = OES_MKT_SH_OPTION;

  // cancellation succeeds
  EXPECT_EQ(0, api_.SendCancelOrder(&order_cancel_req));
}
