#include "option_spi.h"

/* 委托拒绝回报 */
void OptionSpi::OnBusinessReject(const OesRptMsgHeadT *pRptMsgHead,
                                 const OesOrdRejectT *pOrderReject) {}
/* 委托已收回报 */
void OptionSpi::OnOrderInsert(const OesRptMsgHeadT *pRptMsgHead,
                              const OesOrdCnfmT *pOrderInsert) {}
/* 委托确认回报 */
void OptionSpi::OnOrderReport(const OesRptMsgHeadT *pRptMsgHead,
                              const OesOrdCnfmT *pOrderReport) {}
/* 成交确认回报 */
void OptionSpi::OnTradeReport(const OesRptMsgHeadT *pRptMsgHead,
                              const OesTrdCnfmT *pTradeReport) {}
/* 资金变动通知 */
void OptionSpi::OnCashAssetVariation(const OesCashAssetReportT *pCashAssetRpt) {
}
/* 股票持仓变动通知 */
void OptionSpi::OnStockHoldingVariation(
    const OesStkHoldingReportT *pStkHoldingRpt) {}
/* 期权持仓变动通知 (适用于期权业务) */
void OptionSpi::OnOptionHoldingVariation(
    const OesOptHoldingReportT *pOptHoldingRpt) {}
/* 期权标的持仓变动通知 (适用于期权业务) */
void OptionSpi::OnOptionUnderlyingHoldingVariation(
    const OesOptUnderlyingHoldingReportT *pUnderlyingHoldingRpt) {}
/* 期权结算单确认回报 (适用于期权业务) */
void OptionSpi::OnSettlementConfirmedRpt(
    const OesRptMsgHeadT *pRptMsgHead,
    const OesOptSettlementConfirmReportT *pCnfmSettlementRpt) {}
/* 出入金委托拒绝回报 */
void OptionSpi::OnFundTrsfReject(const OesRptMsgHeadT *pRptMsgHead,
                                 const OesFundTrsfRejectT *pFundTrsfReject) {}
/* 出入金委托执行回报 */
void OptionSpi::OnFundTrsfReport(const OesRptMsgHeadT *pRptMsgHead,
                                 const OesFundTrsfReportT *pFundTrsfReport) {}
/* 市场状态信息通知 */
void OptionSpi::OnMarketState(const OesMarketStateItemT *pMarketStateItem) {}
/* 通知消息回报 */
void OptionSpi::OnNotifyReport(const OesNotifyInfoReportT *pNotifyInfoRpt) {}
/* 回报同步请求的响应 */
void OptionSpi::OnReportSynchronizationRsp(
    const OesReportSynchronizationRspT *pReportSynchronization) {}

/* 查询委托信息回调 */
void OptionSpi::OnQueryOrder(const OesOrdItemT *pOrder,
                             const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询成交信息回调 */
void OptionSpi::OnQueryTrade(const OesTrdItemT *pTrade,
                             const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询资金信息回调 */
void OptionSpi::OnQueryCashAsset(const OesCashAssetItemT *pCashAsset,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) {}
/* 查询股票持仓信息回调 */
void OptionSpi::OnQueryStkHolding(const OesStkHoldingItemT *pStkHolding,
                                  const OesQryCursorT *pCursor,
                                  int32 requestId) {}
/* 查询配号、中签信息回调 */
void OptionSpi::OnQueryLotWinning(const OesLotWinningItemT *pLotWinning,
                                  const OesQryCursorT *pCursor,
                                  int32 requestId) {}
/* 查询客户信息回调 */
void OptionSpi::OnQueryCustInfo(const OesCustItemT *pCust,
                                const OesQryCursorT *pCursor, int32 requestId) {
}
/* 查询股东账户信息回调 */
void OptionSpi::OnQueryInvAcct(const OesInvAcctItemT *pInvAcct,
                               const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询佣金信息回调 */
void OptionSpi::OnQueryCommissionRate(
    const OesCommissionRateItemT *pCommissionRate, const OesQryCursorT *pCursor,
    int32 requestId) {}
/* 查询出入金流水信息回调 */
void OptionSpi::OnQueryFundTransferSerial(
    const OesFundTransferSerialItemT *pFundTrsf, const OesQryCursorT *pCursor,
    int32 requestId) {}
/* 查询证券发行信息回调 */
void OptionSpi::OnQueryIssue(const OesIssueItemT *pIssue,
                             const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询证券信息回调 */
void OptionSpi::OnQueryStock(const OesStockItemT *pStock,
                             const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询ETF产品信息回调 */
void OptionSpi::OnQueryEtf(const OesEtfItemT *pEtf,
                           const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询ETF成份证券信息回调 */
void OptionSpi::OnQueryEtfComponent(const OesEtfComponentItemT *pEtfComponent,
                                    const OesQryCursorT *pCursor,
                                    int32 requestId) {}
/* 查询市场状态信息回调 */
void OptionSpi::OnQueryMarketState(const OesMarketStateItemT *pMarketState,
                                   const OesQryCursorT *pCursor,
                                   int32 requestId) {}
/* 查询期权产品信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOption(const OesOptionItemT *pOption,
                              const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权持仓信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOptHolding(const OesOptHoldingItemT *pOptHolding,
                                  const OesQryCursorT *pCursor,
                                  int32 requestId) {}
/* 查询期权标的持仓信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOptUnderlyingHolding(
    const OesOptUnderlyingHoldingItemT *pUnderlyingHld,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权限仓额度信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOptPositionLimit(
    const OesOptPositionLimitItemT *pPositionLimit,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权限购额度信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOptPurchaseLimit(
    const OesOptPurchaseLimitItemT *pPurchaseLimit,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询期权行权指派信息回调 (适用于期权业务) */
void OptionSpi::OnQueryOptExerciseAssign(
    const OesOptExerciseAssignItemT *pExerciseAssign,
    const OesQryCursorT *pCursor, int32 requestId) {}
/* 查询通知消息回调 */
void OptionSpi::OnQueryNotifyInfo(const OesNotifyInfoItemT *pNotifyInfo,
                                  const OesQryCursorT *pCursor,
                                  int32 requestId) {}
