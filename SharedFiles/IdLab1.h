/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdLab1
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

#ifndef __ID_LAB1_H__
#define __ID_LAB1_H__

#include "IEcoBase1.h"
#include "ILab1.h"

/* Lab1 CID = {C02D201C-E0BB-4410-9F1C-55C4FFBBD9A6} */
#ifndef __CID_Lab1
static const UGUID CID_Lab1 = {0x01, 0x10, 0xC0, 0x2D, 0x20, 0x1C, 0xE0, 0xBB, 0x44, 0x10, 0x9F, 0x1C, 0x55, 0xC4, 0xFF, 0xBB, 0xD9, 0xA6};
#endif /* __CID_Lab1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_C02D201CE0BB44109F1C55C4FFBBD9A6;
#endif

#endif /* __ID_LAB1_H__ */
