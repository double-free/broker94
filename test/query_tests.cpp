#include "option_test_fixture.h"

#include <gtest/gtest.h>

TEST_F(OptionApiTestFixture, GeneralInformation) {
  EXPECT_STREQ(api_.GetVersion(), "0.16.1.9");
  EXPECT_EQ(sync_.start_transaction(
                [this] { return api_.QueryCashAsset(nullptr, 12345); }),
            1);
  sync_.wait();
  EXPECT_EQ(api_.QueryCashAsset(nullptr, 12345), 1);
  // call back received
  EXPECT_EQ(spi_.receivedRequestID, 12345);

  EXPECT_EQ(sync_.start_transaction(
                [this] { return api_.QueryInvAcct(nullptr, 12346); }),
            2);
  sync_.wait();
  // call back received
  EXPECT_EQ(spi_.receivedRequestID, 12346);
}

TEST_F(OptionApiTestFixture, QueryOption) {
  // query option information
  OesQryOptionFilterT option_filter;
  strncpy(option_filter.securityId, option_.securityId,
          sizeof(option_filter.securityId) - 1);
  option_filter.mktId = OES_MKT_UNDEFINE;

  // expect 1 option in query result
  EXPECT_EQ(1, api_.QueryOption(&option_filter, 12345));

  // TODO: why we don't need sync here?
  // call back received
  EXPECT_EQ(spi_.receivedRequestID, 12345);
  EXPECT_STREQ(spi_.last_option.securityId, option_.securityId);
  EXPECT_EQ(spi_.last_option.exercisePrice, option_.exercisePrice);
  EXPECT_EQ(spi_.last_option.mktId, option_.mktId);
}

TEST_F(OptionApiTestFixture, QueryOptionPosition) {
  OesQryOptHoldingFilterT qry_filter{NULLOBJ_OES_QRY_OPT_HOLDING_FILTER};
  qry_filter.mktId = option_.mktId;
  qry_filter.positionType = OES_OPT_POSITION_TYPE_LONG;
  strncpy(qry_filter.securityId, option_.securityId,
          sizeof(qry_filter.securityId) - 1);

  // no position, return 0 items
  EXPECT_EQ(0, api_.QueryOptHolding(&qry_filter, 12345));

  // query option long position position
  // EXPECT_EQ(0, sync_.start_transaction([this, &qry_filter] {
  //   return api_.QueryOptHolding(&qry_filter, 12345);
  // }));
  // sync_.wait();

  // call back received
  // EXPECT_EQ(spi_.receivedRequestID, 12345);
  // EXPECT_STREQ(spi_.last_option_holding.securityId, qry_filter.securityId);
  // EXPECT_EQ(spi_.last_option_holding.positionType, qry_filter.positionType);

  // we do not have any trade on it
  // EXPECT_EQ(spi_.last_option_holding.originalQty, 0);
  // EXPECT_EQ(spi_.last_option_holding.closeAvlQty, 0);
  // EXPECT_EQ(spi_.last_option_holding.exerciseAvlQty, 0);
  // EXPECT_EQ(spi_.last_option_holding.sumQty, 0);
}

TEST_F(OptionApiTestFixture, QueryOptionUnderlyingPosition) {
  OesQryOptUnderlyingHoldingFilterT qryFilter = {
      NULLOBJ_OES_QRY_OPT_UNDERLYING_HOLDING_FILTER};

  qryFilter.mktId = OES_MKT_UNDEFINE;
  strncpy(qryFilter.underlyingSecurityId, option_.underlyingSecurityId,
          sizeof(qryFilter.underlyingSecurityId) - 1);

  EXPECT_EQ(1, sync_.start_transaction([this, &qryFilter] {
    return api_.QueryOptUnderlyingHolding(&qryFilter, 12345);
  }));
  sync_.wait();

  EXPECT_EQ(spi_.receivedRequestID, 12345);
  EXPECT_EQ(spi_.last_option_underlying_holding.underlyingMktId,
            OES_MKT_SH_ASHARE);
  EXPECT_STREQ(spi_.last_option_underlying_holding.underlyingSecurityId,
               "510050");
  EXPECT_EQ(spi_.last_option_underlying_holding.originalHld, 1000000);
  EXPECT_EQ(spi_.last_option_underlying_holding.originalAvlHld, 1000000);
  EXPECT_EQ(spi_.last_option_underlying_holding.originalCoveredQty, 500000);
  EXPECT_EQ(spi_.last_option_underlying_holding.sumHld, 1000000);
}

TEST_F(OptionApiTestFixture, QueryOptionLimits) {
  // position limit
  OesQryOptPositionLimitFilterT qryFilter = {
      NULLOBJ_OES_QRY_OPT_UNDERLYING_HOLDING_FILTER};
  qryFilter.mktId = OES_MKT_SH_OPTION;
  strncpy(qryFilter.underlyingSecurityId, option_.underlyingSecurityId,
          sizeof(qryFilter.underlyingSecurityId) - 1);

  EXPECT_EQ(spi_.receivedRequestID, 0);
  EXPECT_EQ(1, api_.QueryOptPositionLimit(&qryFilter, 12345));

  EXPECT_EQ(spi_.receivedRequestID, 12345);
  EXPECT_STREQ(spi_.last_option_position_limit.underlyingSecurityId, "510050");
  EXPECT_EQ(spi_.last_option_position_limit.totalPositionLimit, 10000);
  EXPECT_EQ(spi_.last_option_position_limit.longPositionLimit, 5000);
  EXPECT_EQ(spi_.last_option_position_limit.availableTotalPositionLimit, 10000);
  EXPECT_EQ(spi_.last_option_position_limit.availableLongPositionLimit, 5000);
  EXPECT_EQ(spi_.last_option_position_limit.availableDailyBuyOpenLimit, 2000);

  // purchase limit
  OesQryOptPurchaseLimitFilterT qry_purchase_filter = {
      NULLOBJ_OES_QRY_OPT_PURCHASE_LIMIT_FILTER};

  qry_purchase_filter.mktId = OES_MKT_SH_OPTION;
  EXPECT_EQ(1, api_.QueryOptPurchaseLimit(&qry_purchase_filter, 12346));

  EXPECT_EQ(spi_.receivedRequestID, 12346);
  EXPECT_EQ(spi_.last_option_purchase_limit.purchaseLimit, 500000000000);
  EXPECT_EQ(spi_.last_option_purchase_limit.originalUsedPurchaseAmt,
            3174000000);
  EXPECT_EQ(spi_.last_option_purchase_limit.availablePurchaseLimit, 0);
}

TEST_F(OptionApiTestFixture, QueryOptionExerciseAssignment) {
  OesQryOptExerciseAssignFilterT qryFilter = {
      NULLOBJ_OES_QRY_OPT_EXERCISE_ASSIGN_FILTER};
  qryFilter.mktId = OES_MKT_SH_OPTION;
  strncpy(qryFilter.securityId, option_.securityId,
          sizeof(qryFilter.securityId) - 1);

  // no assigment, return 0
  EXPECT_EQ(0, api_.QueryOptExerciseAssign(&qryFilter, 12345));
  // EXPECT_EQ(0, sync_.start_transaction([this, &qryFilter] {
  //   return api_.QueryOptExerciseAssign(&qryFilter, 12345);
  // }));
  // sync_.wait();

  // EXPECT_EQ(spi_.receivedRequestID, 12345);
  // EXPECT_STREQ(spi_.last_option_exercise_assignment.securityName,
  //              option_.contractId);
  //
  // EXPECT_EQ(spi_.last_option_exercise_assignment.deliveryType, 0);
  // EXPECT_EQ(spi_.last_option_exercise_assignment.exercisePrice, 3500);
  // EXPECT_EQ(spi_.last_option_exercise_assignment.exerciseQty, 0);
}
