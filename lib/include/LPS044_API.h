#ifndef _LPD042_API_HEADER_H_
#define _LPD042_API_HEADER_H_
#pragma   once
#if defined(__cplusplus)
extern "C" {
#endif

#include "LPS044_def.h"
#include "LPS044_Addr.h"

#if defined(_MSC_VER)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <windows.h>
#include <winioctl.h>

#include "stdafx.h"
#include "winbase.h"
#include <malloc.h>
#include <setupapi.h>
#include <initguid.h>
#include <process.h>
#include <WinNT.h>
#ifdef LPS044_DLL_EXPORTS
#define LPS044_DLL_API __declspec(dllexport) int
#else
#define LPS044_DLL_API __declspec(dllimport) int
#endif

#ifndef AS5657_DLL_EXPORTS
#define AS5657_DLL_API __declspec(dllexport) int
#else
#define AS5657_DLL_API __declspec(dllimport) int
#endif
#elif defined(__GNUC__)
#define LPS044_DLL_API int
#define AS5657_DLL_API int
#endif

        LPS044_DLL_API MIL1394_Find_Device(PUINT32 pBoardsPresent,PUINT32 CardList);
        //LPS044_DLL_API MIL1394_Find_ALL(PUINT32 pBoardsPresent); //打开设备,打开所有符合要求设备,并返回对应板卡句柄号以及板卡数量,最大支持3板卡,可根据返回插槽号进行Open操作
        LPS044_DLL_API MIL1394_Transmit_Quadlet(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pMsg,UINT32 startPositionInMsg,UINT32 numQuadletsToReplace);
        LPS044_DLL_API MIL1394_Init_CC(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394CCProperty *PropertyOfNode);
        LPS044_DLL_API MIL1394_Init_RN(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394RNProperty *PropertyOfNode);
        LPS044_DLL_API MIL1394_Init_BM(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394BMProperty *PropertyOfNode);
        //LPS044_DLL_API MIL1394_Init_BM(UINT32 Card_Instance,UINT32 Node_Instance,BMNodeProperty *CfgFile);
        LPS044_DLL_API MIL1394_Init_TxMsg(UINT32 Card_Instance,UINT32 Node_Instance, MIL1394TxMsgProperty *TxMsgCfg,PUINT32 MsgContent);
        LPS044_DLL_API MIL1394_Init_RxMsg(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394RxMsgProperty *RxMsgCfg);
        LPS044_DLL_API MIL1394_Clear_RcvMsg_Fw( UINT32 Card_Instance,UINT32 Node_Instance);
        LPS044_DLL_API MIL1394_Clear_XmitMsg_Fw( UINT32 Card_Instance,UINT32 Node_Instance);
        //LPS044_DLL_API MIL1394_Error_Set( UINT32 Card_Instance,UINT32 Node_Instance,Error_Generate *ErrorControl);
    LPS044_DLL_API MIL1394_Set_Msg_Destination(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 Destination);


        /*	API	*/
        LPS044_DLL_API MIL1394_Close(UINT32 Card_Instance);
        LPS044_DLL_API MIL1394_Open(UINT32 Card_Instance ,PUINT32 CardHandle);
        LPS044_DLL_API MIL1394_Receive(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pRcvMessage,PUINT32 MsgLength,PUINT32 MessgeID,PUINT32 NoNewMessage);
        LPS044_DLL_API MIL1394_Transmit(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,PUINT32 PacketSend);
        LPS044_DLL_API MIL1394_Set_InterruptMask (UINT32 Card_Instance,UINT32 Node_Instance, UINT32 interruptMask);
        LPS044_DLL_API MIL1394_ReadMsg(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32* MsgLength,UINT32* Msg);
        LPS044_DLL_API MIL1394_TimeTag_Reset(UINT32 Card_Instance,UINT32 Node_Instance);
        //linux user old dll
        #ifdef linux
        LPS044_DLL_API MIL1394_SetIntHandle(UINT32 Card_Instance,void isr(UINT32,UINT32,UINT32));
        #endif
        #ifdef _WIN32
        //windows user new dll
        LPS044_DLL_API MIL1394_SetIntHandle(UINT32 Card_Instance,UINT32 Node_Instance,void _stdcall isr(UINT32,UINT32,UINT32));
        #endif

        LPS044_DLL_API MIL1394_Set_GlobalInterruptMask (UINT32 Card_Instance,UINT32 InterruptValue);
        LPS044_DLL_API MIL1394_Set_Stof_TH_Low (UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MinStofThreshold);
        LPS044_DLL_API MIL1394_Set_Stof_TH_High (UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MaxStofThreshold);
        LPS044_DLL_API MIL1394_Set_CCFail_Threshold(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 FailThreshold);
        /**********统计函数**************/

        LPS044_DLL_API MIL1394_Get_CCFail_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pCCFailCounter);
        LPS044_DLL_API MIL1394_Get_MaxStof (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pMaxStofValue);
        LPS044_DLL_API MIL1394_Get_MinStof (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pMinStofValue);
        LPS044_DLL_API MIL1394_Get_BusReset_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 BusResetCounter);
        LPS044_DLL_API MIL1394_Get_RcvMsg_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 RcvCounter);
        LPS044_DLL_API MIL1394_Get_SendMsg_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 SendCounter);
        LPS044_DLL_API MIL1394_Get_RcvErrorMsg_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 RcvErrorCounter);
        LPS044_DLL_API MIL1394_Get_SendErrorMsg_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 SendErrorCounter);

        LPS044_DLL_API MIL1394_Get_NodeTotal (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 NodeTotal);
        LPS044_DLL_API MIL1394_Get_DisCardMsg_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 DisCardCounter);
        LPS044_DLL_API MIL1394_Get_Stof_Counter (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pStofCounter);

        LPS044_DLL_API MIL1394_Get_AvailableNodes(UINT32 Card_Instance,UINT32* pNodesPresent);
    LPS044_DLL_API MIL1394_Get_STOFCycle(UINT32 Card_Instance,UINT32 Node_Instance,UINT32* pStofCycle);

        /**********统计函数**************/
    LPS044_DLL_API MIL1394_Force_Root(UINT32 Card_Instance,UINT32 Node_Instance,UINT32  NodeID);
        /***********状态查询函数********************/
        LPS044_DLL_API MIL1394_Get_CoreVersion(UINT32 Card_Instance,UINT32 Node_Instance,UINT32* pCoreVersion);
        LPS044_DLL_API MIL1394_Get_GlobalInterruptMask (UINT32 Card_Instance,PUINT32 InterruptValue);
        LPS044_DLL_API MIL1394_Get_Topo(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 BUFF);
        LPS044_DLL_API MIL1394_Get_Speed (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 SpeedFlag);
        LPS044_DLL_API MIL1394_Get_Driver_Version(PUINT32 ver,PUINT32 date);
        LPS044_DLL_API MIL1394_Get_NodeID (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 NodeID);
        LPS044_DLL_API MIL1394_Get_PortStatus (UINT32 Card_Instance,UINT32 Node_Instance,UINT32 PortNumber,UINT32* pPortStatus);
        LPS044_DLL_API MIL1394_Get_InterruptMask (UINT32 Card_Instance,UINT32 Node_Instance,UINT32 * pInterruptMask);
    LPS044_DLL_API MIL1394_Get_Firmware_Version (UINT32 Card_Instance,PUINT32 pFirmwareDate);
    LPS044_DLL_API MIL1394_Get_Firmware_Type (UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pFirmwareDate);
        LPS044_DLL_API MIL1394_Get_Hardware_Version (UINT32 Card_Instance,PUINT32 pHardware);
        LPS044_DLL_API MIL1394_Get_WorkingState(UINT32 Card_Instance,UINT32 Node_Instance,UINT32* WorkingStatus);
        /***********状态查询函数********************/

        /********自测试函数**********/
        LPS044_DLL_API MIL1394_Bit(UINT32 Card_Instance,UINT32 Node_Instance);
        LPS044_DLL_API MIL1394_BusTopology_Bit(UINT32 Card_Instance,UINT32 Node_Instance);
        LPS044_DLL_API MIL1394_LLC_Bit(UINT32 Card_Instance,UINT32 Node_Instance);
        LPS044_DLL_API MIL1394_PHY_Bit(UINT32 Card_Instance,UINT32 Node_Instance);
        LPS044_DLL_API MIL1394_BPI_Flash_Bit(UINT32 Card_Instance);
        LPS044_DLL_API MIL1394_DPRAMAccess_Bit(UINT32 Card_Instance);
        LPS044_DLL_API MIL1394_HostInterface_Bit(UINT32 Card_Instance);
        /********自测试函数**********/

        LPS044_DLL_API MIL1394_Rcv_Inquiry(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 pMsg,PUINT32 MsgLength);
        LPS044_DLL_API MIL1394_Set_Special_MsgID(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID);
        LPS044_DLL_API MIL1394_Check_Root(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 RootNode);


	LPS044_DLL_API MIL1394_PHY_Reset (UINT32 Card_Instance,UINT32 PortSpeed);
        LPS044_DLL_API MIL1394_Reset_Node (UINT32 Card_Instance,UINT32 Node_Instance);


        LPS044_DLL_API MIL1394_Get_Stof_Msg(UINT32 Card_Instance,UINT32 Node_Insatnce,UINT32 *pStofMsg);
        LPS044_DLL_API MIL1394_Set_Stof_Msg(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 *pStofMsg);
        LPS044_DLL_API MIL1394_Start(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 RunTimes);
        LPS044_DLL_API MIL1394_Synch_Start(UINT32 Card_Instance,UINT32 NodeSelected,UINT32 RunTimes);
        LPS044_DLL_API MIL1394_Stop(UINT32 Card_Instance,UINT32 Node_Insatnce);
        LPS044_DLL_API MIL1394_Synch_Stop(UINT32 Card_Instance,UINT32 NodeSelected);
        LPS044_DLL_API MIL1394_Asynch_Time(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 DelayTimeInUs);
        LPS044_DLL_API MIL1394_Send_AsyPacket(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394AsyncPackProperty* PacketProperty);
        LPS044_DLL_API MIL1394_Send_Stream(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394StreamPackProperty* PacketProperty,UINT32 VPCEn);
        LPS044_DLL_API MIL1394_Send_CCDL(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394CCDLPackProperty* PacketProperty,UINT32 SVPCEn);

        /*****错误注入*****/
        LPS044_DLL_API MIL1394_ERR_BusReset(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 BusResetType,UINT32 BusResetCycle);
        LPS044_DLL_API MIL1394_ERR_Msg_CRC(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32 CRCErrType,UINT32 ErrTimes);
        LPS044_DLL_API MIL1394_ERR_Msg_SVPC(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32 SVPCErrType,UINT32 ErrTimes);
        LPS044_DLL_API MIL1394_ERR_Msg_VPC(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32 VPCErrType,UINT32 ErrTimes);
        LPS044_DLL_API MIL1394_ERR_STOF_CRC(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 CRCErrType,UINT32 ErrImportCycle);
        LPS044_DLL_API MIL1394_ERR_STOF_VPC(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 VPCErrType,UINT32 ErrImportCycle);
        LPS044_DLL_API MIL1394_ERR_STOF_Cycle(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 CycleValue,UINT32 ErrImportCycle);
        /*****错误注入*****/

        LPS044_DLL_API MIL1394_Set_HeartBeat(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32 HeartBeatMode,UINT32 HeartBeatStep,UINT32 HeartBeatCycle,UINT32 HeartBeatValue);
        LPS044_DLL_API MIL1394_Set_ASMHeader(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32 NewMsgID,UINT32 Security,UINT32 NodeID,UINT32 PayLoadLength);
        LPS044_DLL_API MIL1394_Set_HealthWord(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 NewHealthWord) ;


        LPS044_DLL_API MIL1394_Clear_RcvBuff(UINT32 Card_Instance,UINT32 Node_Instance) ;
LPS044_DLL_API Mil1394_Get_Rcv_PacketNum(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 MsgID,UINT32* PacketNum);



        LPS044_DLL_API MIL1394_Send_UnkownPacket(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 PacketLengthInQuad,UINT32* PacketContent);
        LPS044_DLL_API MIL1394_Send_PhyPacket(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 PhyPacketContent);//发送物理层包

/*RN多通道模拟新增函数*/
LPS044_DLL_API  Mil1394_RN_Set_MutiChannel(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 SimChannelHigh,UINT32 SimChannelLow);



LPS044_DLL_API Recorder_Start(UINT32 Card_Instance,UINT32 NodeSelected);
LPS044_DLL_API Recorder_Stop(UINT32 Card_Instance);
LPS044_DLL_API Recorder_Clear(UINT32 Card_Instance);
LPS044_DLL_API Recorder_Get_Length(UINT32 Card_Instance,UINT32* DataLength);
LPS044_DLL_API Monitor_Stop(UINT32 Card_Instance);
LPS044_DLL_API Monitor_Clear(UINT32 Card_Instance,UINT32 NodeSelected);
LPS044_DLL_API Monitor_UpdateCycle_Set(UINT32 Card_Instance,UINT32 UpdateCycle);
LPS044_DLL_API Recorder_Trigger_Set(UINT32 Card_Instance,UINT32 Node_Instance,MIL1394_Recorder_Trigger_Setting TriggerSetting);


/*add define*/
LPS044_DLL_API MIL1394_Rx_SendMsgEn(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 RcvFlag);
LPS044_DLL_API MIL1394_Set_RcvMode(UINT32 Card_Instance,UINT32 Node_Instance,UINT32 RcvPayLoadOnly);
LPS044_DLL_API MIL1394_Disable_Port(UINT32 Card_Instance,UINT32 Node_Instance,UINT32  NodeID,UINT32 PortID);
LPS044_DLL_API MIL1394_Enable_Port(UINT32 Card_Instance,UINT32 Node_Instance,UINT32  NodeID,UINT32 PortID);
LPS044_DLL_API MIL1394_Suspend_Port(UINT32 Card_Instance,UINT32 Node_Instance,UINT32  NodeID,UINT32 PortID);
LPS044_DLL_API MIL1394_Resume_Port(UINT32 Card_Instance,UINT32 Node_Instance,UINT32  NodeID,UINT32 PortID);
/***************/


/*as5657*/
AS5657_DLL_API AS5657_Get_Lctrl(UINT32 Card_Instance,UINT32 Node_Instance,PUINT32 Lctrl);

LPS044_DLL_API MIL1394_Get_PhyRegister (UINT32 Card_Instance,UINT32 Node_Instance,UINT32 BaseType,UINT32 PageNumber,UINT32 PortNumber,UINT32 RegisterNumber,UINT32* pPortStatus);


/*flash */
LPS044_DLL_API MIL1394_BPI_Flash_Bit(UINT32 Card_Instance);
LPS044_DLL_API MIL1394_BPI_Flash_Read(UINT32 Card_Instance,UINT32 FlashAddress,UINT32 DataLength ,UINT16* DataRead,UINT32 *DataLegnthReturn) ;
LPS044_DLL_API MIL1394_BPI_Flash_ISP(UINT32 Card_Instance,UINT16 * DataWrite ,UINT32 FlashAddress,UINT32 DataLength);
LPS044_DLL_API MIL1394_BPI_Flash_ISPWord(UINT32 Card_Instance,UINT16 DataWrite ,UINT32 FlashAddress);
LPS044_DLL_API MIL1394_BPI_Flash_EraseBlock(UINT32 Card_Instance,UINT32 BlockNum) ;
LPS044_DLL_API MIL1394_BPI_Flash_WriteCommand(UINT32 Card_Instance,UINT32 FlashAddress,UINT32 FlashData,UINT32 FlashCmd);
LPS044_DLL_API MIL1394_BPI_Flash_CheckStatus(UINT32 Card_Instance);

LPS044_DLL_API MIL1394_SPI_Flash_Read(UINT32 Card_Instance,UINT8 * DataRead ,UINT32 FlashAddress,UINT32 DataLength,PUINT32 ReadLength) ;
LPS044_DLL_API MIL1394_SPI_Flash_ISP(UINT32 Card_Instance,UINT8 * DataWrite ,UINT32 FlashAddress,UINT32 DataLength); //以字节为单位，每次写入256字节;
LPS044_DLL_API MIL1394_SPI_Flash_Erase(UINT32 Card_Instance,UINT32 BlockNum);
LPS044_DLL_API MIL1394_SPI_Flash_CheckStatus(UINT32 Card_Instance);
LPS044_DLL_API MIL1394_Register_Read(UINT32 Card_Instance,UINT32 Barindex,UINT32 Offset,PUINT32 RegisterValue);


#ifdef __cplusplus
}
#endif


#endif

