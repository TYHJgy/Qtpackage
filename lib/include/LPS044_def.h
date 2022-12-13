#ifndef _LPD042_DEF_H
#define _LPD042_DEF_H
#pragma   once
#if defined(__cplusplus)
extern "C" {
#endif

#if defined(_MSC_VER)
#elif defined(__GNUC__)
#include <stdint.h>
#include <pthread.h>
typedef void* PVOID;
typedef PVOID HANDLE;
#endif

#define   PCI2Node
#define   ENTX_RCV      0x210112
#define   EN_MULTIMODE  0x210803

/*数据类型定义*/
#define     INT64               signed long long    /*  有符号64bit         */
#define     UINT64              unsigned long long  /*  无符号64bit         */
#define     INT32               signed int          /*  有符号32bit         */
#define     UINT32              unsigned int        /*  无符号32bit         */
#define     INT16               signed short        /*  有符号16bit         */
#define     UINT16              unsigned short      /*  无符号16bit         */
#define     INT8                signed char         /*  有符号8bit          */
#define     UINT8               unsigned char       /*  无符号8bit          */
#define     PINT32              INT32*              /*  有符号32bit指针类型 */
#define     PUINT32             UINT32*             /*  无符号32bit指针类型 */
#define     PINT16              INT16*              /*  有符号16bit指针类型 */
#define     PUINT16             UINT16*             /*  无符号16bit指针类型 */
#define     PINT8               INT8*               /*  有符号8bit指针类型  */
#define     PUINT8              UINT8*              /*  无符号8bit指针类型  */
#define     BOOL                UINT32              /*  布尔类型            */
#define     TIC_HANDLE          PINT32              /*  设备句柄            */


//#define PXI

/*定义驱动版本*/
        /*定义驱动版本*/
#define LPD042_DRV_VERSION  0x03020201
#define LPD042_DRV_DATE     0x20210911
#define LPD042_CORE_VERSION 0X20161219
//0x20201231
//增加监控功能，允许接收本节点发送数据
//0x2f211112
//增加对发送消息进行接收的开关函数对应驱动版本20210115
//MIL1394_Rx_SendMsgEn

//0x20210116
//把stof包syscount和rtc字段改为自动增加，不受用户控制
//MIL1394_Rx_SendMsgEn

//0x20210810
//增加了sTOF包内容控制函数MIL1394_Stof_Control
//增加了CC/RN同时运行控制函数MIL1394_Init_MultiMode

//0x20210828
//修正了MIL_1394_RcvMode设定为接收纯负载时，底层对消息包头判断没有与 0xffff相与的错误

        //0x202109011
        //板卡关闭，增加了判断，判断线程是否退出，如果退出，再释放资源，THREADRUNNING 变量增加volatile声明

        //0x20211122zq
        //初始化multirn程序中，去掉了判断63通道的限制
        //初始化multiMode程序中，去掉了判断63通道的限制
        //用户可以配置63通道消息

        //20220331
        /* 初始化发送消息增加了消息负载长度是否为4字节整数倍的判断
                if((TxMsgProperty->PayLoadLength % 4) !=0)
        {
                return INVALID_MSGLENGTH;
        }
        */
#define     ReturnCode  INT32

#define     False   0x5555
#define     True    0xaaaa

#define     ENABLE  0x0001
#define     DISABLE 0x0000

#define    IDLE      0
#define    BUSY      1
#define    EMPTY     0XFFFFFFFF
#define    HOSTUSE   2
#define    DLLUSE    3

#define MAXBOARD              16
#define MAXNODE               4
#define MODEBOTH              4
#define MODECC                2
#define MODERN                1
#define MODEBM                3
#define MODENONE              0
#define BUFFERSIZE            (2100 / 4)
#define MSGDESTINATION_FIFO   0
#define MSGDESTINATION_DPRAM  1
        typedef struct
        {
                UINT32* RcvFlag;
                UINT32* RcvMsgID;
                UINT32* RxBuff;
                UINT32  TotalRxMsg;
                //UINT32  NewFlag;
                UINT32 *RxOffset;
        }MIL1394RcvBuff;

        typedef struct
        {
                UINT32* SendMsgID;
                UINT32* AddressInHostMem;
                UINT32* SendMsgLength;
                UINT32  TotalTxMsg;
                UINT32*  MsgType;
        UINT32* HEARTBEAT;
        UINT32* ERRIMP;
        UINT32* VPC_IMPORT;
        UINT32* SVPC_IMPORT;
        }MIL1394SendBuff;

typedef struct
{
        UINT32* RcvFlag;
        UINT32* RxBuff;
}MIL1394STOFBuff;
        typedef struct {

                UINT32  Node_Stat[MAXBOARD];		//最低8位：最大节点个数，次低8位,可用节点标志
                UINT32  Max_Node_Number[MAXBOARD];		//最低8位：最大节点个数，次低8位,可用节点标志

                uintptr_t	DMATxSrcAddr[MAXBOARD][MAXNODE];					//Node A 物理内存首地址
        UINT32  BASE_PHY_MEMORY_FOR_USER[MAXBOARD];
                uintptr_t	DMARxSrcAddr[MAXBOARD][MAXNODE];					//Node A 物理内存首地址
                UINT32  DMARxLength[MAXBOARD][MAXNODE];
                UINT32  DMATxLength[MAXBOARD][MAXNODE];
        uintptr_t  baseMem[MAXBOARD][MAXNODE];
#if defined(_MSC_VER)
                HANDLE  RxLock[MAXBOARD][MAXNODE];
#elif defined(__GNUC__)
                pthread_mutex_t *RxLock[MAXBOARD][MAXNODE];
#endif

                UINT32 MostRecentMsgForSoft[MAXBOARD][MAXNODE];			//当前最新消息指针
                UINT32 LeastRecentMsgForSoft[MAXBOARD][MAXNODE];		//当前最老消息指针

                UINT32  softIntStatus[MAXBOARD][MAXNODE];				//通知回调函数使用

                UINT32  PerPackSize ;

                UINT32 hostPointer[MAXBOARD][MAXNODE];
                UINT32 logicPointer[MAXBOARD][MAXNODE];
                UINT32 SLOTList[MAXBOARD];
                HANDLE  hDevice[MAXBOARD] ;
                HANDLE  hEvent0[MAXBOARD] ;
                HANDLE  hEvent1[MAXBOARD] ;
                HANDLE  hEvent2[MAXBOARD] ;
                HANDLE  hEvent3[MAXBOARD] ;
                MIL1394RcvBuff* Rcv2Buff[MAXBOARD][MAXNODE];
                //MIL1394RcvBuff* Rcv2Buff[MAXBOARD][MAXNODE];
        MIL1394STOFBuff * STOF2Buff[MAXBOARD][MAXNODE];
                MIL1394SendBuff* SendBuff[MAXBOARD][MAXNODE];
                UINT32  STOF_Period[MAXBOARD][MAXNODE];
                UINT32  MsgDestination[MAXBOARD][MAXNODE];
                UINT32   RcvMsgPayLoadOnly[MAXBOARD][MAXNODE] ;
                UINT32  TxCount[MAXBOARD][MAXNODE];

        UINT32 RxCount[MAXBOARD][MAXNODE];

        UINT32  Monitor_Base_Address[MAXBOARD][MAXNODE];
        UINT32  Recorder_Base_Address[MAXBOARD];
        UINT32  Recorder_Length;
                //UINT32  NODE_EN[MAXBOARD][MAXNODE];//for JIGUANG

        } GlobalVarity;

  //  extern GlobalVarity GlobalVar;
  //  extern volatile BOOL ThreadRunning;// = FALSE;


     //   typedef void (*ISR_Drv) (UINT32,UINT32,UINT32); //for c++
//	typedef void (*ISR_Drv )  (UINT32,UINT32,UINT32); //for c#
  //      ISR_Drv myISR[MAXBOARD];

#if defined(_MSC_VER)
                HANDLE hThread;
        // {f55f9d75-12dc-4804-b28f-3676d6ce5a10}
        //DEFINE_GUID(guidWdm,
        //0xf55f9d75, 0x12dc, 0x4804, 0xb2, 0x8f, 0x36, 0x76, 0xd6, 0xce, 0x5a, 0x10);
//	GUID  guidWdm= {0x90296911, 0xf8cf, 0x451a, {0x8d, 0x3f, 0x49, 0x99, 0x24, 0x1, 0x76, 0xc5}};

//	{0xe7ef0eb8, 0xe54e, 0x4a14, {0xb2, 0x84, 0x90, 0x93, 0xdb, 0x7, 0xd3, 0xbc}};
//	DEFINE_GUID(guidWdm, 0x5805cbb7, 0x6586, 0x47e2, 0xa3, 0xaa, 0x53, 0xd1, 0x23, 0x30, 0x3d, 0x14);

        DEFINE_GUID(guidWdm,0xe28b8cf6, 0x4b, 0x4fe1, 0xac, 0xc3, 0xb0, 0x5d, 0xc1, 0x39, 0xee, 0x4f);/*双节点仿真卡*/
#endif

#define IOCTL_READ_BAR							CTL_CODE( FILE_DEVICE_UNKNOWN, 0x913, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_WRITE_BAR							CTL_CODE( FILE_DEVICE_UNKNOWN, 0x914, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_GET_DMA_RESOURCE					CTL_CODE( FILE_DEVICE_UNKNOWN, 0x916, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_GET_CLEAR_INTERRUPT_STATUS   	    CTL_CODE( FILE_DEVICE_UNKNOWN, 0x922, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_GET_CLEAR_INTERRUPT_B   	        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x92C, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_GET_CLEAR_INTERRUPT_C   	        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x92D, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_GET_CLEAR_INTERRUPT_D   	        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x92E, METHOD_BUFFERED, FILE_READ_ACCESS )

#define IOCTL_CLEAR_INTERRUPT_STATUS_BIT    	CTL_CODE( FILE_DEVICE_UNKNOWN, 0x921, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_SET_INT_EVENT0					CTL_CODE( FILE_DEVICE_UNKNOWN, 0x927 ,METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_SET_INT_EVENT1					CTL_CODE( FILE_DEVICE_UNKNOWN, 0x928 ,METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_SET_INT_EVENT2					CTL_CODE( FILE_DEVICE_UNKNOWN, 0x929 ,METHOD_BUFFERED, FILE_READ_ACCESS)

#define MACRO_NODE_A 0
#define MACRO_NODE_B 1




#define MACRO_SPACE_NODE_A			0
#define MACRO_SPACE_NODE_B			1
#define MACRO_SPACE_NODE_C			2
#define MACRO_SPACE_NODE_D			3
#define MACRO_SPACE_MEMORY          4
#define MACRO_SPACE_GLOBAL_REG		5

#define MACRO_PCI_BAR_0             0
#define MACRO_PCI_BAR_1             1
#define MACRO_PCI_BAR_2             2

#define UINT32						unsigned int

#define S100						0
#define S200						1
#define S400						2
#define S800						3
#define MAX_SPEED					S800

#define NORMAL_TX_MSG_BASE   0x10000				//发送消息存放位置



#define  INVALID_PARAMETER    -2
#define  FAIL			      -1
#define  NODE_MODE_INIT        0
#define  NODE_MODE_RN          1
#define  NODE_MODE_CC          2
#define  NODE_MODE_BM          3

#define  TxBuff_Reserved       0//0x20

#define  FILTER_MSGID          1
#define  FILTER_SRC_DST        3
#define  FILTER_NONE           4
#define  FILTER_SRC_MSGNUM     2



//#define MT25QL128
#define MX25QL128

#ifdef MT25QL128
#define BLOCKSIZE 64*1024
#endif
#ifdef MX25QL128
#define BLOCKSIZE 64*1024
#endif
#define SPIFLASHSIZE  128 / 8 * 1024 * 1024
        /************************************************************************/
        /* 返回值定义                                                           */
        /************************************************************************/

#define  SUCCESSFUL_COMPLETION_LP						0
#define  DEVICE_OPEN_FAILED								-102
#define  DEVICE_CLOSE_FAILED							-103
#define  DEVICE_NOT_OPEN								-104
#define  NO_ENOUGH_TX_BUFF								-106
#define UNSUPPORTED_SPEED_CODE_LP					    -107
#define GET_DMA_RESOURCE_ERROR                          -108
#define  DEVICE_IO_CONTROL_ERR							-109
#define INVALID_NODE                                    -121
#define INVALID_MSGCONTENT                              -122
#define TOOMUCH_CARD_IN_SYSTEM                          -123
#define DEVICE_ALREADY_OPENED							-124
#define DEVICE_ALREADY_CLOSED							-125
#define NO_ENOUGH_SPACE                                 -126
#define INVALID_MSGNUM                                  -127
#define INVALID_MSGLENGTH                               -128
#define CHANNEL_NUMBER_ERROR_LP                         -129
#define PORT_SECLCT_ERROR                                 -130
#define BIT_TOPO_ERROR                                    -131
#define BIT_LLC_ERROR                                      -132
#define BIT_PHY_ERROR                                      -133
#define HOSTINTERFACE_BIT_ERROR                            -134
#define INTERRUPT_SET_ERROR                                -135
#define GET_TOPO_ERROR                                     -136
#define INVALID_MODE                                       -137
#define UNSUPPORTED_WHILE_NODE_RUNNING                     -138
#define INVALID_FILTER_TYPE                                -139
#define INVALID_MSGNUMBER                                  -140
#define INVALID_MSGID                                      -141
#define INVALID_HEARTBEAT_STEP                             -142
#define INVALID_HEARTBEAT_CYCLE                            -143
#define INVALID_MSGPERIOD                                  -144
#define INVALID_MSGTYPE                                    -145
#define INCORRECT_MSGID                                    -146
#define PHY_ACCESS_ERROR                                   -147
#define NO_AVALIABLE_BUFF_LP                               -152
#define MSG_RECEIVE_ERROR_LP                               -154
#define INVALID_MSG_MAX_PAYLOAD_LP                         -155
#define MAX_TX_NUM_EXCEED                                  -157
#define INVALID_CARD                                       -159
#define NO_NEW_RECEIVED_MESSAGES_LP                        -160
#define READ_LINK_ERROR                                    -161
#define WRITE_LINK_ERROR                                   -162
#define ATF_NOT_EMPTY                                      -163
#define INVALID_FIRMWAREVERSION                            -164
#define INVALID_NODEID                                     -199
#define NODE_ALREADY_ROOT                                  -198
#define INVALID_PORT                                       -200
#define  ERROR_FLASH_ERASE                                 -200
#define  ERROR_FLASH_BIT                                   -201
#define  ERROR_FLASH_ACCESS                                -202
#define  ERROR_FLASH_ERASE_LENGTH                          -203
#define  FIFO_EMPTY                                        -204
#define  FIFO_NOT_EMPTY                                    -205
#define  INVALID_SPEED                                     -206
        /*--------------------used in Pack Tx---------------*/
#define FAIL                 -1

#define RETRY_1              0
#define RETRY_X              1
#define RETRY_A              2
#define RETRY_B              3

#define CH0                  0
#define CH1                  1
#define CH2                  2
#define CH3                  3
#define CH4                  4
#define CH5                  5
#define CH6                  6
#define CH7                  7
#define CH8                  8
#define CH9                  9
#define CH10                10
#define CH11                11
#define CH12                12
#define CH13                13
#define CH14                14
#define CH15                15
#define CH16                16
#define CH17                17
#define CH18                18
#define CH19                19
#define CH20                20
#define CH21                21
#define CH22                22
#define CH23                23
#define CH24                24
#define CH25                25
#define CH26                26
#define CH27                27
#define CH28                28
#define CH29                29
#define CH30                30
#define CH31                31
#define SY0                  0
#define SY1                  1
#define SY2                  2
#define SY3                  3
#define SY4                  4
#define SY5                  5
#define SY6                  6
#define STOF_SIZE            4*10

#define TCODE0        0x00
#define TCODE1        0x01
#define TCODE2        0x02
#define TCODE3        0x03
#define TCODE4        0x04
#define TCODE5        0x05
#define TCODE6        0x06
#define TCODE7        0x07
#define TCODE8        0x08
#define TCODE9        0x09
#define TCODEa        0x0a
#define TCODEb        0x0b
#define TCODEc        0x0c
#define TCODEd        0x0d
#define TCODEe        0x0e
#define TCODEf        0x0f
#define BIT31                           (1<<31)
#define BIT30                           (1<<30)
#define BIT29                           (1<<29)
#define BIT28                           (1<<28)
#define BIT27                           (1<<27)
#define BIT26                           (1<<26)
#define BIT25                           (1<<25)
#define BIT24                           (1<<24)
#define BIT23                           (1<<23)
#define BIT22                           (1<<22)
#define BIT21                           (1<<21)
#define BIT20                           (1<<20)
#define BIT19                           (1<<19)
#define BIT18                           (1<<18)
#define BIT17                           (1<<17)
#define BIT16                           (1<<16)

#define BIT15                           (1<<15)
#define BIT14                           (1<<14)
#define BIT13                           (1<<13)
#define BIT12                           (1<<12)
#define BIT11                           (1<<11)
#define BIT10                           (1<<10)
#define BIT9                            (1<<9)
#define BIT8                            (1<<8)
#define BIT7                            (1<<7)
#define BIT6                            (1<<6)
#define BIT5                            (1<<5)
#define BIT4                            (1<<4)
#define BIT3                            (1<<3)
#define BIT2                            (1<<2)
#define BIT1                            (1<<1)
#define BIT0                            (1<<0)

#define OK  			0

#define REG_HW_Reset_Node							0x00000004

#define EVENTMSG           1
#define CYCLEMSG           2

/*---------------------------------API 参数宏定义-----------------------------------------------------------------*/
#define PORT_SPEED_S100     0
#define PORT_SPEED_S200     1
#define PORT_SPEED_S400     2


#define tCodeWrReq    0
#define tCodeWrBReq   1
#define tCodeWrRes    2
#define tCodeRdReq    4
#define tCodeRdBReq   5
#define tCodeRdRes    6
#define tCodeRdBRes   7
#define tCodeLockReq  9
#define tCodeStream   10
#define tCodeLockRes  11


typedef struct
{
        UINT32 BusNumber;
        UINT32 DestNodeID;
        UINT32 DestOffsetHigh;
        UINT32 DestOffsetLow;
        UINT32 tLabel;
        UINT32 respCode;
        UINT32 nBytesToTx;
        UINT32 exCode;
        UINT32 tCode;
        UINT32 payload[2048];
}MIL1394AsyncPackProperty;
typedef struct
{
        UINT32 dstChannel;
        UINT32 nBytesToTx;
        UINT32 tag;
        UINT32 sy;
        UINT32 Speed;
        UINT32 payload[2048];
}MIL1394StreamPackProperty;
typedef struct
{
        unsigned int dstChannel;
        unsigned int PayLoadLength;
        unsigned int MsgID;
//	unsigned int Health;
//	unsigned int HeartBeat;
        unsigned int tag;
        unsigned int sy;
        unsigned int Speed;
        unsigned int Security;
        unsigned int NodeID;
        unsigned int TxOffset;
        unsigned int RxOffset;
        unsigned int PHPOffset;
        unsigned int payload[2048];
}MIL1394CCDLPackProperty;
typedef struct
{
        unsigned int Channel;
        unsigned int Speed;
        unsigned int Stof_Cycle;
        unsigned int TxMsgTotal;
        unsigned int RxMsgTotal;
        unsigned int BMEnable;
        unsigned int RxWindowEN;
        unsigned int RxWindowStart;
        unsigned int RxWindowEnd;
        unsigned int SvpcEn;
        unsigned int FilterType;
        unsigned int TxOffset;
        unsigned int RxOffset;
        unsigned int PhpOffset;
}MIL1394CCProperty;


typedef struct
{
        unsigned int Channel;
        unsigned int Speed;
        unsigned int Stof_Cycle;
        unsigned int TxMsgTotal;
        unsigned int RxMsgTotal;
        unsigned int BMEnable;
        unsigned int RxWindowEN;
        unsigned int RxWindowStart;
        unsigned int RxWindowEnd;
        unsigned int SvpcEn;
        unsigned int OffsetModifySel;/*RN*/
        unsigned int FilterType;
        unsigned int RcvStofEn;/*RN*/
        unsigned int TxOffset;
        unsigned int RxOffset;
        unsigned int PhpOffset;
}MIL1394RNProperty;


        /*
        //old define
        typedef struct
        {
                unsigned int Speed;
                unsigned int Stof_Cycle;
                unsigned int RcvStofEn;
                unsigned int FilterType;
                unsigned int FilterNumber;
                unsigned int RxWindowEN;
                unsigned int RxWindowStart;
                unsigned int RxWindowEnd;
                unsigned int FilterDetail[20];
                unsigned int SvpcEn;
                unsigned int Channel0_31;
                unsigned int Channel32_63;
        }MIL1394BMProperty;
        */
        /// change 2022 06 28
        typedef struct
        {
                //unsigned int Speed;
                unsigned int Stof_Cycle;
                unsigned int RcvStofEn;
                unsigned int SvpcEn;
                //unsigned int FilterType;
                //unsigned int FilterNumber;
                unsigned int RxWindowEN;
                unsigned int RxWindowStart;
                unsigned int RxWindowEnd;
                //unsigned int FilterDetail[20];

                unsigned int Channel0_31;
                unsigned int Channel32_63;
        }MIL1394BMProperty;

        typedef struct
        {
                UINT32 StofCycle;
                UINT32 StofRcvEn;
                UINT32 SVPCEn;
                UINT32 RxWindowEN;
                UINT32 RxWindowStart;
                UINT32 RxWindowEnd;
            unsigned int Channel0_31;
            unsigned int Channel32_63;
        } MIL1394BMProperty1;

typedef struct
{
        unsigned int ChannelHigh;//要模拟的通道按位对应高32个通道
        unsigned int ChannelLow;//低32个通道
        unsigned int Speed;
        unsigned int Stof_Cycle;
        unsigned int TxMsgTotal;
        unsigned int RxMsgTotal;
        unsigned int BMEnable;
        unsigned int RxWindowEN;
        unsigned int RxWindowStart;
        unsigned int RxWindowEnd;
        unsigned int SVPCEn;
        unsigned int OffsetModifySel;/*RN*/
        unsigned int FilterType;
        unsigned int RcvStofEn;/*RN*/
}MIL1394MultiRNProperty;

typedef struct
{
        unsigned int ChannelHigh;//要模拟的通道按位对应高32个通道
        unsigned int ChannelLow;//低32个通道
        unsigned int Speed;
        unsigned int Stof_Cycle;
        unsigned int TxMsgTotal;
        unsigned int RxMsgTotal;
        unsigned int SVPCEn;
        unsigned int OffsetModifySel;/*RN*/
        unsigned int FilterType;
        unsigned int RcvStofEn;/*RN*/
}MIL1394MultiModeProperty;

typedef struct
{
        UINT32 MsgID;
        UINT32 DstChannel;
        UINT32 PayLoadLength;
        UINT32 MsgType;
        UINT32 MsgPeriod;
        UINT32 HeartBeatStep;
        UINT32 HeartBeatCycle;
        UINT32 TxOffset;
        UINT32 RxOffset;
        UINT32 PhpOffset;
        UINT32 RealTxOffset;
        UINT32 TxMsgSVPCEN;
}MIL1394TxMsgProperty;

typedef struct
{
        UINT32 MsgID;
        UINT32 DstChannel;
        UINT32 SrcChannel;
        //unsigned int RxOffset;
}MIL1394RxMsgProperty;



typedef struct
{
        UINT32 WriteReq;
        UINT32 WriteBlockREeq;
        UINT32 WriteResp;
        UINT32 ReadReq;
        UINT32 ReadBlockReq;
        UINT32 ReadResp;
        UINT32 ReadBlockRes;
        UINT32 CycleStart;
        UINT32 LockReq;
        UINT32 Stream;
        UINT32 LockResp;
        UINT32 PhyConfig;
        UINT32 PhyLinkon;
        UINT32 PhySelfID;
        UINT32 PhyAcknoledge;
        UINT32 Unknown;
        UINT32 Other;
        UINT32 BusReset;
        UINT32 Voltage;
}MIL1394_Monitor_Counter;

typedef struct
{
        UINT32 Complete;
        UINT32 Pending;
        UINT32 BusyX;
        UINT32 BusyA;
        UINT32 BusyB;
        UINT32 Tardy;
        UINT32 ConflictError;
        UINT32 DataError;
        UINT32 TypeError;
        UINT32 AddressError;
}MIL1394_Monitor_Ack;

typedef struct
{
        UINT32 Speed100;
        UINT32 Speed200;
        UINT32 Speed400;
        UINT32 Speed800;
        UINT32 SpeedUnknown;
}MIL1394_Monitor_Speed;


typedef struct
{
        UINT32 HeaderCRC;
        UINT32 DataCRC;
        UINT32 Ack;
        UINT32 Size;
        UINT32 tCode;
        UINT32 InvalidPHY;
        UINT32 InvalidAck;
        UINT32 InvalidVPC;
        UINT32 InvalidSVPC;
}MIL1394_Monitor_Error;




typedef struct
{
        UINT32 AutoTrigger:1;
        UINT32 AckPacket:1;
    UINT32 PhyPacket:1;
        UINT32 Stof:1;
        UINT32 Busreset:1;
        UINT32 TcodeErr:1;
    UINT32 Tcode11:1;
        UINT32 Tcode10:1;
    UINT32 Tcode9:1;
        UINT32 Tcode8:1;
        UINT32 Tcode7:1;
        UINT32 Tcode6:1;
        UINT32 Tcode5:1;
        UINT32 Tcode4:1;
        UINT32 Tcode2:1;
        UINT32 Tcode1:1;
        UINT32 Tcode0:1;
        UINT32 VPCErr:1;
        UINT32 DataCRC:1;
        UINT32 HeaderCRC:1;
        UINT32 RSV:12;
}MIL1394_Recorder_Trigger_Setting;

#ifdef __cplusplus
}
#endif
#endif
