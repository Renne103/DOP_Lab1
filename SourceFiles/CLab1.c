/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CLab1_FFBBD9A6
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CLab1_FFBBD9A6
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CLab1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса ILab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CLab1_FFBBD9A6_QueryInterface(/* in */ struct ILab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CLab1_FFBBD9A6* pCMe = (CLab1_FFBBD9A6*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_ILab1) ) {
        *ppv = &pCMe->m_pVTblILab1;
        pCMe->m_pVTblILab1->AddRef((ILab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblILab1;
        pCMe->m_pVTblILab1->AddRef((ILab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса ILab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CLab1_FFBBD9A6_AddRef(/* in */ struct ILab1* me) {
    CLab1_FFBBD9A6* pCMe = (CLab1_FFBBD9A6*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса ILab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CLab1_FFBBD9A6_Release(/* in */ struct ILab1* me) {
    CLab1_FFBBD9A6* pCMe = (CLab1_FFBBD9A6*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCLab1_FFBBD9A6((ILab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

void swap(char* a, char* b, int size) {
    while(size > 0)
	{
        char temp = *a;
        *a = *b;
        *b = temp;
		size--;a++;b++;
    }
}

char* get(void* a, int size, int pos) {
    return (char*) a + (size * pos);
}

void ECOCALLMETHOD CLab1_FFBBD9A6_bublesort(void* arr, int asize, int size_t, int (ECOCDECLMETHOD* compmethod)(const void*, const void*)) {
    int i = 0,j = 0;
	for(i = 0; i < asize; i++)
		for(j = 0; j < asize - 1; j++)
			if(((*compmethod) (get(arr, size_t, j),get(arr, size_t, j+1))) > 0)
				swap(get(arr, size_t, j),get(arr, size_t, j+1),size_t);
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCLab1_FFBBD9A6(/*in*/ struct ILab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CLab1_FFBBD9A6* pCMe = (CLab1_FFBBD9A6*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table ILab1 */
ILab1VTbl g_xF4BD807F5F564C4E9F2EF387961D4F49VTbl_FFBBD9A6 = {
    CLab1_FFBBD9A6_QueryInterface,
    CLab1_FFBBD9A6_AddRef,
    CLab1_FFBBD9A6_Release,
    CLab1_FFBBD9A6_bublesort
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCLab1_FFBBD9A6(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ ILab1** ppILab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CLab1_FFBBD9A6* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppILab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CLab1_FFBBD9A6*)pIMem->pVTbl->Alloc(pIMem, sizeof(CLab1_FFBBD9A6));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса ILab1 */
    pCMe->m_pVTblILab1 = &g_xF4BD807F5F564C4E9F2EF387961D4F49VTbl_FFBBD9A6;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppILab1 = (ILab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCLab1_FFBBD9A6(/* in */ ILab1* pILab1) {
    CLab1_FFBBD9A6* pCMe = (CLab1_FFBBD9A6*)pILab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pILab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
