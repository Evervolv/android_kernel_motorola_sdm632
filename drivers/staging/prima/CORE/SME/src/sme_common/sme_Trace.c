/*
 * Copyright (c) 2013-2015 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/************************************************************************
   smeTrace.c

  \brief implementation for trace related APIs

  \author Kiran Kumar Reddy CH L V

  ========================================================================*/
#include "aniGlobal.h" //for tpAniSirGlobal
#include "smsDebug.h"
#include "macTrace.h"
#include "sme_Trace.h"
#include "smeInternal.h"
#include "smeInside.h"

#ifndef SME_TRACE_RECORD
void smeTraceInit(tpAniSirGlobal pMac)
{
    return;
}
#endif
#ifdef SME_TRACE_RECORD


static tANI_U8* smeTraceGetRxMsgString( tANI_U32 code )
{
    switch(code)
    {
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_REQ);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_GET_RESULTS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_CONNECT);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SET_11DINFO);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_GET_SOFTAP_DOMAIN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SET_REGINFO);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_UPDATE_CHANNEL_CONFIG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_UPDATE_CONFIG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_HDDREADYIND);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_FLUSH_RESULTS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_FLUSH_P2PRESULTS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_GETFIRST);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_GETNEXT);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_PURGE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_REASSOC);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_DISCONNECT);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_GET_CONNECTPROFILE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_FREE_CONNECTPROFILE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_SET_PMKIDCACHE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_DEL_PMKIDCACHE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CONFIGPARAM);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_MODPROFFIELDS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CONFIG_PWRSAVE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CONFIG_PWRSAVE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ENABLE_PWRSAVE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DISABLE_PWRSAVE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_START_AUTO_BMPSTIMER);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_STOP_AUTO_BMPSTIMER);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_IS_PWRSAVE_ENABLED);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_FULLPOWER);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_BMPS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_DHCP_FLAG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_STANDBY);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_WOWL_ADDBCAST_PATTERN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_WOWL_DELBCAST_PATTERN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ENTER_WOWL);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXIT_WOWL);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_KEY);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REMOVE_KEY);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_STATS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CNTRYCODE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CNTRYCODE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CHANGE_CNTRYCODE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_BTC_SIGNALEVENT);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_BTC_SETCONFIG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_BTC_GETCONFIG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CFGPRIVACY);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_NEIGHBOR_REPORTREQ);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_READREG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_WRITEREG);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_READMEM);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_WRITEMEM);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_OPEN_SESSION);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CLOSE_SESSION);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_HOSTOFFLOAD);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_GTKOFFLOAD);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_GTKOFFLOAD);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_POWERPARAMS);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ABORT_MACSCAN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REGISTER_MGMTFR);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DEREGISTER_MGMTFR);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REMAIN_ONCHAN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SEND_ACTION);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CANCEL_REMAIN_ONCHAN);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_RXPFIL);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_SUSPENDIND);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_RESUMEREQ);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_MAXTXPOW);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_TXPOW);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_TMLEVEL);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CAPS_EXCH);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DISABLE_CAP);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_DEFCCNV);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CURCC);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_RESET_PW5G);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_RP5G);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_ROAMIBAND);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_ROAMIBAND);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_RSSIDIFF);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_IMMRSSIDIFF);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_FTENABLED);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_WESMODE);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_SCANCTRL);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_DEAUTH_STA);
#ifdef FEATURE_WLAN_TDLS
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_LINK_ESTABLISH_PARAM);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_CHAN_SWITCH_REQ);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_SEND_MGMT_FRAME);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_CHANGE_PEER_STA);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_ADD_PEER_STA);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_DEL_PEER_STA);
#endif
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_PREF_NET_LIST);
#ifdef FEATURE_WLAN_LPHB
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_LPHB_CONFIG_REQ);
#endif /* FEATURE_WLAN_LPHB */
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXTSCAN_START);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXTSCAN_STOP);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXTSCAN_SET_BSS_HOTLIST);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXTSCAN_RESET_BSS_HOTLIST);
        CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXTSCAN_GET_CACHED_RESULTS);
        default:
            return( "UNKNOWN" );
            break;
    }
}
static tANI_U8* smeTraceGetCommandString( tANI_U32 command )
{
    switch(command)
    {
        CASE_RETURN_STRING(eSmeNoCommand);
        CASE_RETURN_STRING(eSmeDropCommand);
        CASE_RETURN_STRING(eSmeCsrCommandMask);
        CASE_RETURN_STRING(eSmeCommandScan);
        CASE_RETURN_STRING(eSmeCommandRoam);
        CASE_RETURN_STRING(eSmeCommandWmStatusChange);
        CASE_RETURN_STRING(eSmeCommandSetKey);
        CASE_RETURN_STRING(eSmeCommandRemoveKey);
        CASE_RETURN_STRING(eSmeCommandAddStaSession);
        CASE_RETURN_STRING(eSmeCommandDelStaSession);
        CASE_RETURN_STRING(eSmeCommandPnoReq);
        CASE_RETURN_STRING(eSmeCommandMacSpoofRequest);
        CASE_RETURN_STRING(eSmeCommandGetFrameLogRequest);
#ifdef FEATURE_WLAN_TDLS
        CASE_RETURN_STRING(eSmeCommandTdlsSendMgmt);
        CASE_RETURN_STRING(eSmeCommandTdlsAddPeer);
        CASE_RETURN_STRING(eSmeCommandTdlsDelPeer);
        CASE_RETURN_STRING(eSmeCommandTdlsLinkEstablish);
        CASE_RETURN_STRING(eSmeCommandTdlsChannelSwitch);
#endif
        CASE_RETURN_STRING(eSmeCommandNanReq);
        CASE_RETURN_STRING(eSmePmcCommandMask);
        CASE_RETURN_STRING(eSmeCommandEnterImps);
        CASE_RETURN_STRING(eSmeCommandExitImps);
        CASE_RETURN_STRING(eSmeCommandEnterBmps);
        CASE_RETURN_STRING(eSmeCommandExitBmps);
        CASE_RETURN_STRING(eSmeCommandEnterUapsd);
        CASE_RETURN_STRING(eSmeCommandExitUapsd);
        CASE_RETURN_STRING(eSmeCommandEnterWowl);
        CASE_RETURN_STRING(eSmeCommandExitWowl);
        CASE_RETURN_STRING(eSmeCommandEnterStandby);
        CASE_RETURN_STRING(eSmeQosCommandMask);
        CASE_RETURN_STRING(eSmeCommandAddTs);
        CASE_RETURN_STRING(eSmeCommandDelTs);
#ifdef FEATURE_OEM_DATA_SUPPORT
        CASE_RETURN_STRING(eSmeCommandOemDataReq);
#endif
        CASE_RETURN_STRING(eSmeCommandRemainOnChannel);
        CASE_RETURN_STRING(eSmeCommandNoAUpdate);
        default:
            return( "UNKNOWN" );
            break;
    }
}
static void smeTraceDump(tpAniSirGlobal pMac, tpvosTraceRecord pRecord,
                                                            tANI_U16 recIndex)
{
    switch (pRecord->code) {
        case TRACE_CODE_SME_COMMAND:
            smsLog(pMac, LOG1, "%04d %012u S%d %-14s %-30s(0x%x)",
                recIndex, pRecord->time, pRecord->session, "SME COMMAND:",
                 smeTraceGetCommandString(pRecord->data), pRecord->data);
            break;
        case TRACE_CODE_SME_TX_WDA_MSG:
            smsLog(pMac, LOG1, "%04d %012u S%d %-14s %-30s(0x%x)",
                recIndex, pRecord->time, pRecord->session, "TX WDA Msg:",
                macTraceGetWdaMsgString((tANI_U16)pRecord->data),
                                              pRecord->data);
            break;
        case TRACE_CODE_SME_RX_WDA_MSG:
            smsLog(pMac, LOG1, "%04d %012u S%d %-14s %-30s(0x%x)",
                recIndex, pRecord->time, pRecord->session, "RX WDA Msg:",
                macTraceGetSmeMsgString((tANI_U16)pRecord->data),
                                              pRecord->data);
            break;
        default:
            smsLog(pMac, LOG1, "%04d %012u S%d %-14s %-30s(0x%x)",
                recIndex, pRecord->time, pRecord->session, "RX HDD MSG:",
                smeTraceGetRxMsgString(pRecord->code), pRecord->data);
        break;
    }
}

void smeTraceInit(tpAniSirGlobal pMac)
{
    vosTraceRegister(VOS_MODULE_ID_SME, (tpvosTraceCb)&smeTraceDump);
}

/**
 * sme_state_info_dump() - prints state information of sme layer
 */
static void sme_state_info_dump(void)
{
    tANI_U32  session_id = 0;
    tHalHandle hal;
    tpAniSirGlobal mac;
    v_CONTEXT_t vos_ctx_ptr;

    /* get the global voss context */
    vos_ctx_ptr = vos_get_global_context(VOS_MODULE_ID_VOSS, NULL);

    if (NULL == vos_ctx_ptr) {
        VOS_ASSERT(0);
        return;
    }

    hal = vos_get_context(VOS_MODULE_ID_SME, vos_ctx_ptr);
    if (NULL == hal) {
        VOS_ASSERT(0);
        return;
    }

    mac = PMAC_STRUCT(hal);

    session_id = sme_get_sessionid_from_activeList(mac);
    smsLog( mac, LOG1, FL(" SessionId %d for active command"), session_id);

    smsLog(mac, LOG1, FL("NeighborRoamState: %d RoamState: %d"
           "RoamSubState: %d ConnectState: %d pmcState: %d PmmState: %d"),
           mac->roam.neighborRoamInfo.neighborRoamState,
           mac->roam.curState[session_id], mac->roam.curSubState[session_id],
           mac->roam.roamSession[session_id].connectState, mac->pmc.pmcState,
           mac->pmm.gPmmState);
}

/**
 * sme_register_debug_callback() - registration function sme layer
 * to print sme state information
 */
void sme_register_debug_callback(void)
{
    vos_register_debug_callback(VOS_MODULE_ID_SME, &sme_state_info_dump);
}
#endif
