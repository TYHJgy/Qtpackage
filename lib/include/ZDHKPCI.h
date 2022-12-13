#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ZDHKPCILIB_EXPORTS
#define ZDHKPCI_API __declspec(dllexport)
#else
#define ZDHKPCI_API __declspec(dllimport)
#if defined(_M_X64)
#pragma comment(lib, "../x64/Release/ZDHKPCILIB.lib")
#elif defined(_M_IX86)
#pragma comment(lib, "../Release/ZDHKPCILIB.lib")
#else
#error "undefination compile platform width"
#endif
#endif

#define MAX_DEVICE_NUMBER           (16)

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef _STDINT
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#endif

#include "interface.h"

/*
 * list { id, slot, no }
 */
ZDHKPCI_API void ZDHK_Find(OUT uint32_t list[][3], IN OUT uint32_t *num);
ZDHKPCI_API void ZDHK_ReloadFind(OUT uint32_t list[][3], IN OUT uint32_t *num);

/*
 * list { slot, no }
 */
ZDHKPCI_API void ZDHK_FindById(IN uint32_t id, OUT uint32_t list[][2], OUT uint32_t *num);

/*
 * isSlotMode
 *      true - use is slot number
 *      false - use is index
 */
ZDHKPCI_API void ZDHK_SetOpenMode(IN uint32_t isSlotMode);

ZDHKPCI_API int ZDHK_Open(IN uint32_t id, IN uint32_t val);
ZDHKPCI_API int ZDHK_Close(IN uint32_t id, IN uint32_t val);
ZDHKPCI_API int ZDHK_Init(IN uint32_t id, IN uint32_t val, OUT PSHARE_INFORMATION *info);
ZDHKPCI_API int ZDHK_BarR(IN uint32_t id, IN uint32_t val, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, OUT uint8_t *bytes);
ZDHKPCI_API int ZDHK_BarW(IN uint32_t id, IN uint32_t val, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, IN uint8_t *bytes);
ZDHKPCI_API int ZDHK_MapBarR(IN uint32_t id, IN uint32_t val, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, OUT uint8_t *bytes);
ZDHKPCI_API int ZDHK_MapBarW(IN uint32_t id, IN uint32_t val, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, IN uint8_t *bytes);
ZDHKPCI_API int ZDHK_BindSemaphore(IN uint32_t id, IN uint32_t val, OUT PVOID *pSem);
ZDHKPCI_API int ZDHK_BindNodeSemaphore(IN uint32_t id, IN uint32_t val, IN uint32_t node, OUT PVOID *pSem);
ZDHKPCI_API int ZDHK_DmaNew(IN uint32_t id, IN uint32_t val, IN uint32_t size, OUT PVOID *user, OUT PVOID *phys, OUT PVOID *pHandle);
ZDHKPCI_API int ZDHK_DmaDel(IN uint32_t id, IN uint32_t val, IN PVOID handle);
ZDHKPCI_API int ZDHK_ReadIntStat(IN uint32_t id, IN uint32_t val, OUT uint32_t *intStat);
ZDHKPCI_API int ZDHK_ReadNodeIntStat(IN uint32_t id, IN uint32_t val, IN uint32_t node, OUT uint32_t *intStat);

ZDHKPCI_API int ZDHK_OpenEx(IN uint32_t id, IN uint32_t val, OUT PVOID *hdev);
ZDHKPCI_API int ZDHK_CloseEx(IN PVOID hdev);
ZDHKPCI_API int ZDHK_InitEx(IN PVOID hdev, OUT PSHARE_INFORMATION *info);
ZDHKPCI_API int ZDHK_BarREx(IN PVOID hdev, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, OUT uint8_t *bytes);
ZDHKPCI_API int ZDHK_BarWEx(IN PVOID hdev, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, IN uint8_t *bytes);
ZDHKPCI_API int ZDHK_MapBarREx(IN PVOID hdev, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, OUT uint8_t *bytes);
ZDHKPCI_API int ZDHK_MapBarWEx(IN PVOID hdev, IN uint32_t chan, IN uint32_t offs, IN uint32_t nBytes, IN uint8_t *bytes);
ZDHKPCI_API int ZDHK_BindSemaphoreEx(IN PVOID hdev, OUT PVOID *pSem);
ZDHKPCI_API int ZDHK_BindNodeSemaphoreEx(IN PVOID hdev, IN uint32_t node, OUT PVOID *pSem);
ZDHKPCI_API int ZDHK_DmaNewEx(IN PVOID hdev, IN uint32_t size, OUT PVOID *user, OUT PVOID *phys, OUT PVOID *pHandle);
ZDHKPCI_API int ZDHK_DmaDelEx(IN PVOID hdev, IN PVOID handle);
ZDHKPCI_API int ZDHK_ReadIntStatEx(IN PVOID hdev, OUT uint32_t *intStat);
ZDHKPCI_API int ZDHK_ReadNodeIntStatEx(IN PVOID hdev, IN uint32_t node, OUT uint32_t *intStat);

#ifdef __cplusplus
}
#endif
