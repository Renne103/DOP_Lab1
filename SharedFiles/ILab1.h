/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   ILab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс ILab1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_LAB1_H__
#define __I_LAB1_H__

#include "IEcoBase1.h"

/* ILab1 IID = {F4BD807F-5F56-4C4E-9F2E-F387961D4F49} */
#ifndef __IID_ILab1
static const UGUID IID_ILab1 = {0x01, 0x10, 0xF4, 0xBD, 0x80, 0x7F, 0x5F, 0x56, 0x4C, 0x4E, 0x9F, 0x2E, 0xF3, 0x87, 0x96, 0x1D, 0x4F, 0x49};
#endif /* __IID_ILab1 */

typedef struct ILab1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct ILab1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct ILab1* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct ILab1* me);

    /* ILab1 */
	void (ECOCALLMETHOD *bublesort)(void* arr, int asize, int size_t, int (ECOCDECLMETHOD* compmethod)(const void*, const void*));

} ILab1VTbl, *ILab1VTblPtr;

interface ILab1 {
    struct ILab1VTbl *pVTbl;
} ILab1;


#endif /* __I_LAB1_H__ */
