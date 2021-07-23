#include "option_test_spi.h"
#include "gtest/gtest.h"
#include <sutil/logger/spk_log.h>

/* 委托拒绝回报 */
void OptionTestSpi::OnBusinessReject(const OesRptMsgHeadT *pRptMsgHead,
                                     const OesOrdRejectT *pOrderReject) {}
/* 委托已收回报 */
void OptionTestSpi::OnOrderInsert(const OesRptMsgHeadT *pRptMsgHead,
                                  const OesOrdCnfmT *pOrderInsert) {}
/* 委托确认回报 */
void OptionTestSpi::OnOrderReport(const OesRptMsgHeadT *pRptMsgHead,
                                  const OesOrdCnfmT *pOrderReport) {}
/* 成交确认回报 */
void OptionTestSpi::OnTradeReport(const OesRptMsgHeadT *pRptMsgHead,
                                  const OesTrdCnfmT *pTradeReport) {}
/* 资金变动通知 */
void OptionTestSpi::OnCashAssetVariation(
    const OesCashAssetReportT *pCashAssetRpt) {}
/* 股票持仓变动通知 */
void OptionTestSpi::OnStockHoldingVariation(
    const OesStkHoldingReportT *pStkHoldingRpt) {}
/* 期权持仓变动通知 (适用于期权业务) */
void OptionTestSpi::OnOptionHoldingVariation(
    const OesOptHoldingReportT *pOptHoldingRpt) {}
/* 期权标的持仓变动通知 (适用于期权业务) */
void OptionTestSpi::OnOptionUnderlyingHoldingVariation(
    const OesOptUnderlyingHoldingReportT *pUnderlyingHoldingRpt) {}
/* 期权结算单确认回报 (适用于期权业务) */
void OptionTestSpi::OnSettlementConfirmedRpt(
    const OesRptMsgHeadT *pRptMsgHead,
    const OesOptSettlementConfirmReportT *pCnfmSettlementRpt) {}
/* 出入金委托拒绝回报 */
void OptionTestSpi::OnFundTrsfReject(
    const OesRptMsgHeadT *pRptMsgHead,
    const OesFundTrsfRejectT *pFundTrsfReject) {}
/* 出入金委托执行回报 */
void OptionTestSpi::OnFundTrsfReport(
    const OesRptMsgHeadT *pRptMsgHead,
    const OesFundTrsfReportT *pFundTrsfReport) {}
/* 市场状态信息通知 */
void OptionTestSpi::OnMarketState(const OesMarketStateItemT *pMarketStateItem) {
}
/* 通知消息回报 */
void OptionTestSpi::OnNotifyReport(const OesNotifyInfoReportT *pNotifyInfoRpt) {
}
/* 回报同步请求的响应 */
void OptionTestSpi::OnReportSynchronizationRsp(
    const OesReportSynchronizationRspT *pReportSynchronization) {}

/* 查询委托信息回调 */
void OptionTestSpi::OnQueryOrder(const OesOrdItemT *pOrder,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) {}
/* 查询成交信息回调 */
void OptionTestSpi::OnQueryTrade(const OesTrdItemT *pTrade,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) {}
/* 查询资金信息回调 */
void OptionTestSpi::OnQueryCashAsset(const OesCashAssetItemT *pCashAsset,
                                     const OesQryCursorT *pCursor,
                                     int32 requestId) {
  SLOG_INFO(
      ">>> 查询到资金信息: index[%d], isEnd[%c], "
      "资金账户代码[%s], 客户代码[%s], 币种[%" __SPK_FMT_HH__ "u], "
      "资金类型[%" __SPK_FMT_HH__ "u], 期初余额[%" __SPK_FMT_LL__ "d], "
      "期初可用[%" __SPK_FMT_LL__ "d], 期初可取[%" __SPK_FMT_LL__ "d], "
      "不可用[%" __SPK_FMT_LL__ "d], 累计存入[%" __SPK_FMT_LL__ "d], "
      "累计提取[%" __SPK_FMT_LL__ "d], 当前提取冻结[%" __SPK_FMT_LL__ "d], "
      "累计卖出[%" __SPK_FMT_LL__ "d], 累计买入[%" __SPK_FMT_LL__ "d], "
      "当前买冻结[%" __SPK_FMT_LL__ "d], 累计费用[%" __SPK_FMT_LL__ "d], "
      "当前费用冻结[%" __SPK_FMT_LL__ "d], 日初持仓保证金[%" __SPK_FMT_LL__
      "d], "
      "行权累计待交收冻结[%" __SPK_FMT_LL__
      "d], 当前维持保证金[%" __SPK_FMT_LL__ "d], "
      "当前保证金冻结[%" __SPK_FMT_LL__
      "d], 未对冲实时价格保证金[%" __SPK_FMT_LL__ "d], "
      "已对冲实时价格保证金[%" __SPK_FMT_LL__
      "d], 待追加保证金[%" __SPK_FMT_LL__ "d], "
      "当前余额[%" __SPK_FMT_LL__ "d], 当前可用[%" __SPK_FMT_LL__ "d], "
      "当前可取[%" __SPK_FMT_LL__ "d]\n",
      pCursor->seqNo, pCursor->isEnd ? 'Y' : 'N', pCashAsset->cashAcctId,
      pCashAsset->custId, pCashAsset->currType, pCashAsset->cashType,
      pCashAsset->beginningBal, pCashAsset->beginningAvailableBal,
      pCashAsset->beginningDrawableBal, pCashAsset->disableBal,
      pCashAsset->totalDepositAmt, pCashAsset->totalWithdrawAmt,
      pCashAsset->withdrawFrzAmt, pCashAsset->totalSellAmt,
      pCashAsset->totalBuyAmt, pCashAsset->buyFrzAmt, pCashAsset->totalFeeAmt,
      pCashAsset->feeFrzAmt, pCashAsset->optionExt.initialMargin,
      pCashAsset->optionExt.totalExerciseFrzAmt, pCashAsset->marginAmt,
      pCashAsset->marginFrzAmt, pCashAsset->optionExt.totalMarketMargin,
      pCashAsset->optionExt.totalNetMargin,
      pCashAsset->optionExt.pendingSupplMargin, pCashAsset->currentTotalBal,
      pCashAsset->currentAvailableBal, pCashAsset->currentDrawableBal);
  handle_message_received_event(pCursor, requestId);
}

/* 查询股票持仓信息回调 */
void OptionTestSpi::OnQueryStkHolding(const OesStkHoldingItemT *pStkHolding,
                                      const OesQryCursorT *pCursor,
                                      int32 requestId) {}
/* 查询配号、中签信息回调 */
void OptionTestSpi::OnQueryLotWinning(const OesLotWinningItemT *pLotWinning,
                                      const OesQryCursorT *pCursor,
                                      int32 requestId) {}
/* 查询客户信息回调 */
void OptionTestSpi::OnQueryCustInfo(const OesCustItemT *pCust,
                                    const OesQryCursorT *pCursor,
                                    int32 requestId) {}
/* 查询股东账户信息回调 */
void OptionTestSpi::OnQueryInvAcct(const OesInvAcctItemT *pInvAcct,
                                   const OesQryCursorT *pCursor,
                                   int32 requestId) {
  SLOG_INFO(">>> 查询到证券账户信息: index[%d], isEnd[%c], "
            "证券账户[%s], 市场代码[%" __SPK_FMT_HH__ "u], "
            "客户代码[%s], 账户状态[%" __SPK_FMT_HH__ "u], "
            "主板权益[%d], 科创板权益[%d]\n",
            pCursor->seqNo, pCursor->isEnd ? 'Y' : 'N', pInvAcct->invAcctId,
            pInvAcct->mktId, pInvAcct->custId, pInvAcct->status,
            pInvAcct->subscriptionQuota, pInvAcct->kcSubscriptionQuota);
  handle_message_received_event(pCursor, requestId);
}
/* 查询佣金信息回调 */
void OptionTestSpi::OnQueryCommissionRate(
    const OesCommissionRateItemT *pCommissionRate, const OesQryCursorT *pCursor,
    int32 requestId) {}
/* 查询出入金流水信息回调 */
void OptionTestSpi::OnQueryFundTransferSerial(
    const OesFundTransferSerialItemT *pFundTrsf, const OesQryCursorT *pCursor,
    int32 requestId) {}
/* 查询证券发行信息回调 */
void OptionTestSpi::OnQueryIssue(const OesIssueItemT *pIssue,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) {}
/* 查询证券信息回调 */
void OptionTestSpi::OnQueryStock(const OesStockItemT *pStock,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) {}
/* 查询ETF产品信息回调 */
void OptionTestSpi::OnQueryEtf(const OesEtfItemT *pEtf,
                               const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询ETF成份证券信息回调 */
void OptionTestSpi::OnQueryEtfComponent(
    const OesEtfComponentItemT *pEtfComponent, const OesQryCursorT *pCursor,
    int32 requestId) {}
/* 查询市场状态信息回调 */
void OptionTestSpi::OnQueryMarketState(const OesMarketStateItemT *pMarketState,
                                       const OesQryCursorT *pCursor,
                                       int32 requestId) {}
/* 查询期权产品信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOption(const OesOptionItemT *pOption,
                                  const OesQryCursorT *pCursor,
                                  int32 requestId) {
  SLOG_INFO(
      ">>> 查询到期权产品信息: index[%d], isEnd[%c], "
      "证券代码[%s], 合约交易代码[%s], 合约名称[%s], 标的证券[%s], "
      "市场代码[%" __SPK_FMT_HH__ "u], 产品类型[%" __SPK_FMT_HH__ "u], "
      "证券类型[%" __SPK_FMT_HH__ "u], 证券子类型[%" __SPK_FMT_HH__ "u], "
      "合约类型[%" __SPK_FMT_HH__ "u], 行权方式[%" __SPK_FMT_HH__ "u], "
      "交割方式[%" __SPK_FMT_HH__ "u], 当日回转[%" __SPK_FMT_HH__ "u], "
      "限制开仓[%" __SPK_FMT_HH__ "u], 连续停牌[%" __SPK_FMT_HH__ "u], "
      "临时停牌[%" __SPK_FMT_HH__ "u], 合约单位[%d], 期权行权价[%d], "
      "交割日期[%08d], 交割月份[%08d], 上市日期[%08d], 最后交易日[%08d], "
      "行权起始日[%08d], 行权结束日[%08d], 持仓量[%" __SPK_FMT_LL__ "d], "
      "前收盘价[%d], 前结算价[%d], 标的前收[%d], 报价单位[%d], 涨停价[%d], "
      "跌停价[%d], 买单位[%d], 限价买上限[%d], 限价买下限[%d], 市价买上限[%d], "
      "市价买下限[%d], 卖单位[%d], 限价卖上限[%d], 限价卖下限[%d], "
      "市价卖上限[%d], 市价卖下限[%d], 卖开保证金[%" __SPK_FMT_LL__ "d], "
      "保证金参数一[%d](万分比), 保证金参数二[%d](万分比), "
      "保证金上浮比例[%d](万分比), 合约状态[%c%c%c%c%c%c%c%c]\n",
      pCursor->seqNo, pCursor->isEnd ? 'Y' : 'N', pOption->securityId,
      pOption->contractId, pOption->securityName, pOption->underlyingSecurityId,
      pOption->mktId, pOption->productType, pOption->securityType,
      pOption->subSecurityType, pOption->contractType, pOption->exerciseType,
      pOption->deliveryType, pOption->isDayTrading, pOption->limitOpenFlag,
      pOption->suspFlag, pOption->temporarySuspFlag, pOption->contractUnit,
      pOption->exercisePrice, pOption->deliveryDate, pOption->deliveryMonth,
      pOption->listDate, pOption->lastTradeDay, pOption->exerciseBeginDate,
      pOption->exerciseEndDate, pOption->contractPosition,
      pOption->prevClosePrice, pOption->prevSettlPrice,
      pOption->underlyingClosePrice, pOption->priceTick,
      pOption->upperLimitPrice, pOption->lowerLimitPrice, pOption->buyQtyUnit,
      pOption->lmtBuyMaxQty, pOption->lmtBuyMinQty, pOption->mktBuyMaxQty,
      pOption->mktBuyMinQty, pOption->sellQtyUnit, pOption->lmtSellMaxQty,
      pOption->lmtSellMinQty, pOption->mktSellMaxQty, pOption->mktSellMinQty,
      pOption->sellMargin, pOption->marginRatioParam1,
      pOption->marginRatioParam2, pOption->increasedMarginRatio,
      pOption->securityStatusFlag[0], pOption->securityStatusFlag[1],
      pOption->securityStatusFlag[2], pOption->securityStatusFlag[3],
      pOption->securityStatusFlag[4], pOption->securityStatusFlag[5],
      pOption->securityStatusFlag[6], pOption->securityStatusFlag[7]);

  EXPECT_STREQ(pOption->securityId, expected_option_item.securityId);
  EXPECT_EQ(pOption->exercisePrice, expected_option_item.exercisePrice);
  handle_message_received_event(pCursor, requestId);
}
/* 查询期权持仓信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOptHolding(const OesOptHoldingItemT *pOptHolding,
                                      const OesQryCursorT *pCursor,
                                      int32 requestId) {}
/* 查询期权标的持仓信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOptUnderlyingHolding(
    const OesOptUnderlyingHoldingItemT *pUnderlyingHld,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权限仓额度信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOptPositionLimit(
    const OesOptPositionLimitItemT *pPositionLimit,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权限购额度信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOptPurchaseLimit(
    const OesOptPurchaseLimitItemT *pPurchaseLimit,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权行权指派信息回调 (适用于期权业务) */
void OptionTestSpi::OnQueryOptExerciseAssign(
    const OesOptExerciseAssignItemT *pExerciseAssign,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询通知消息回调 */
void OptionTestSpi::OnQueryNotifyInfo(const OesNotifyInfoItemT *pNotifyInfo,
                                      const OesQryCursorT *pCursor,
                                      int32 requestId) {}
