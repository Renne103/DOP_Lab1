/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_LAB1_H__
#define __C_LAB1_H__

#include "ILab1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CLab1_FFBBD9A6 {

    /* Таблица функций интерфейса ILab1 */
    ILab1VTbl* m_pVTblILab1;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

} CLab1_FFBBD9A6, *CLab1_FFBBD9A6Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCLab1_FFBBD9A6(/*in*/ struct ILab1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCLab1_FFBBD9A6(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ ILab1** ppILab1);
/* Удаление */
void ECOCALLMETHOD deleteCLab1_FFBBD9A6(/* in */ ILab1* pILab1);

#endif /* __C_LAB1_H__ */
