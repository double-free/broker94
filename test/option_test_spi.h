#pragma once
#include "synchronizer.h"
#include <oes_client_sample.h>

class OptionTestSpi final : public Quant360::OesClientSpi {
  /* 委托拒绝回报 */
  void OnBusinessReject(const OesRptMsgHeadT *pRptMsgHead,
                        const OesOrdRejectT *pOrderReject) override;
  /* 委托已收回报 */
  void OnOrderInsert(const OesRptMsgHeadT *pRptMsgHead,
                     const OesOrdCnfmT *pOrderInsert) override;
  /* 委托确认回报 */
  void OnOrderReport(const OesRptMsgHeadT *pRptMsgHead,
                     const OesOrdCnfmT *pOrderReport) override;
  /* 成交确认回报 */
  void OnTradeReport(const OesRptMsgHeadT *pRptMsgHead,
                     const OesTrdCnfmT *pTradeReport) override;
  /* 资金变动通知 */
  void OnCashAssetVariation(const OesCashAssetReportT *pCashAssetRpt) override;
  /* 股票持仓变动通知 */
  void
  OnStockHoldingVariation(const OesStkHoldingReportT *pStkHoldingRpt) override;
  /* 期权持仓变动通知 (适用于期权业务) */
  void
  OnOptionHoldingVariation(const OesOptHoldingReportT *pOptHoldingRpt) override;
  /* 期权标的持仓变动通知 (适用于期权业务) */
  void OnOptionUnderlyingHoldingVariation(
      const OesOptUnderlyingHoldingReportT *pUnderlyingHoldingRpt) override;
  /* 期权结算单确认回报 (适用于期权业务) */
  void OnSettlementConfirmedRpt(
      const OesRptMsgHeadT *pRptMsgHead,
      const OesOptSettlementConfirmReportT *pCnfmSettlementRpt) override;
  /* 出入金委托拒绝回报 */
  void OnFundTrsfReject(const OesRptMsgHeadT *pRptMsgHead,
                        const OesFundTrsfRejectT *pFundTrsfReject) override;
  /* 出入金委托执行回报 */
  void OnFundTrsfReport(const OesRptMsgHeadT *pRptMsgHead,
                        const OesFundTrsfReportT *pFundTrsfReport) override;
  /* 市场状态信息通知 */
  void OnMarketState(const OesMarketStateItemT *pMarketStateItem) override;
  /* 通知消息回报 */
  void OnNotifyReport(const OesNotifyInfoReportT *pNotifyInfoRpt) override;
  /* 回报同步请求的响应 */
  void OnReportSynchronizationRsp(
      const OesReportSynchronizationRspT *pReportSynchronization) override;

  /* 查询委托信息回调 */
  void OnQueryOrder(const OesOrdItemT *pOrder, const OesQryCursorT *pCursor,
                    int32 requestId) override;
  /* 查询成交信息回调 */
  void OnQueryTrade(const OesTrdItemT *pTrade, const OesQryCursorT *pCursor,
                    int32 requestId) override;
  /* 查询资金信息回调 */
  void OnQueryCashAsset(const OesCashAssetItemT *pCashAsset,
                        const OesQryCursorT *pCursor, int32 requestId) override;
  /* 查询股票持仓信息回调 */
  void OnQueryStkHolding(const OesStkHoldingItemT *pStkHolding,
                         const OesQryCursorT *pCursor,
                         int32 requestId) override;
  /* 查询配号、中签信息回调 */
  void OnQueryLotWinning(const OesLotWinningItemT *pLotWinning,
                         const OesQryCursorT *pCursor,
                         int32 requestId) override;
  /* 查询客户信息回调 */
  void OnQueryCustInfo(const OesCustItemT *pCust, const OesQryCursorT *pCursor,
                       int32 requestId) override;
  /* 查询股东账户信息回调 */
  void OnQueryInvAcct(const OesInvAcctItemT *pInvAcct,
                      const OesQryCursorT *pCursor, int32 requestId) override;
  /* 查询佣金信息回调 */
  void OnQueryCommissionRate(const OesCommissionRateItemT *pCommissionRate,
                             const OesQryCursorT *pCursor,
                             int32 requestId) override;
  /* 查询出入金流水信息回调 */
  void OnQueryFundTransferSerial(const OesFundTransferSerialItemT *pFundTrsf,
                                 const OesQryCursorT *pCursor,
                                 int32 requestId) override;
  /* 查询证券发行信息回调 */
  void OnQueryIssue(const OesIssueItemT *pIssue, const OesQryCursorT *pCursor,
                    int32 requestId) override;
  /* 查询证券信息回调 */
  void OnQueryStock(const OesStockItemT *pStock, const OesQryCursorT *pCursor,
                    int32 requestId) override;
  /* 查询ETF产品信息回调 */
  void OnQueryEtf(const OesEtfItemT *pEtf, const OesQryCursorT *pCursor,
                  int32 requestId) override;
  /* 查询ETF成份证券信息回调 */
  void OnQueryEtfComponent(const OesEtfComponentItemT *pEtfComponent,
                           const OesQryCursorT *pCursor,
                           int32 requestId) override;
  /* 查询市场状态信息回调 */
  void OnQueryMarketState(const OesMarketStateItemT *pMarketState,
                          const OesQryCursorT *pCursor,
                          int32 requestId) override;
  /* 查询期权产品信息回调 (适用于期权业务) */
  void OnQueryOption(const OesOptionItemT *pOption,
                     const OesQryCursorT *pCursor, int32 requestId) override;
  /* 查询期权持仓信息回调 (适用于期权业务) */
  void OnQueryOptHolding(const OesOptHoldingItemT *pOptHolding,
                         const OesQryCursorT *pCursor,
                         int32 requestId) override;
  /* 查询期权标的持仓信息回调 (适用于期权业务) */
  void OnQueryOptUnderlyingHolding(
      const OesOptUnderlyingHoldingItemT *pUnderlyingHld,
      const OesQryCursorT *pCursor, int32 requestId) override;
  /* 查询期权限仓额度信息回调 (适用于期权业务) */
  void OnQueryOptPositionLimit(const OesOptPositionLimitItemT *pPositionLimit,
                               const OesQryCursorT *pCursor,
                               int32 requestId) override;
  /* 查询期权限购额度信息回调 (适用于期权业务) */
  void OnQueryOptPurchaseLimit(const OesOptPurchaseLimitItemT *pPurchaseLimit,
                               const OesQryCursorT *pCursor,
                               int32 requestId) override;
  /* 查询期权行权指派信息回调 (适用于期权业务) */
  void
  OnQueryOptExerciseAssign(const OesOptExerciseAssignItemT *pExerciseAssign,
                           const OesQryCursorT *pCursor,
                           int32 requestId) override;
  /* 查询通知消息回调 */
  void OnQueryNotifyInfo(const OesNotifyInfoItemT *pNotifyInfo,
                         const OesQryCursorT *pCursor,
                         int32 requestId) override;
private:
  Synchronizer& sync_;

  void handle_message_received_event(const OesQryCursorT* cursor, int32_t requestId) {
    receivedRequestID = requestId;
    if (cursor == nullptr || cursor->isEnd) {
      sync_.end_transaction();
    }
  }

public:
  explicit OptionTestSpi(Synchronizer& sync): sync_(sync) {}

  int32_t receivedRequestID{0};
  OesOptionItemT expected_option_item;
};
