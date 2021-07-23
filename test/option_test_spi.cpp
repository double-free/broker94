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
  receivedRequestID = requestId;
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
  sync_.end_transaction();
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
                                   int32 requestId) {}
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
  receivedRequestID = requestId;
  EXPECT_STREQ(pOption->securityId, expected_option_item.securityId);
  EXPECT_EQ(pOption->exercisePrice, expected_option_item.exercisePrice);
  sync_.end_transaction();
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
