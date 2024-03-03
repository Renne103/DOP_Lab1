/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CBubleSort_B4ED74BE
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CBubleSort_B4ED74BE
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
#include "CBubleSort.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IBubleSort
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBubleSort_B4ED74BE_QueryInterface(/* in */ struct IBubleSort* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBubleSort) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBubleSort;
        pCMe->m_pVTblIBubleSort->AddRef((IBubleSort*)pCMe);
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
 *   Функция AddRef для интерфейса IBubleSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_AddRef(/* in */ struct IBubleSort* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;

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
 *   Функция Release для интерфейса IBubleSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBubleSort_B4ED74BE_Release(/* in */ struct IBubleSort* me) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBubleSort_B4ED74BE((IBubleSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CBubleSort_B4ED74BE_MyFunction(/* in */ struct IBubleSort* me, void * first, size_t size, size_t sizeType, int (ECOCDECLMETHOD * comparator ) (const void * , const void * )) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
	size_t i = 0, j = 0, k = 0;
	byte* arr = (byte*)first;
	void * temp;
	temp = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeType);
	

	for (i = 0; i < size - 1; ++i) {
		for (j = 0; j < size - 1 - i; ++j){
			if (comparator(arr + j*sizeType, arr + (j + 1)*sizeType)){
				
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, temp, (arr + j*sizeType), sizeType);
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, (arr + j*sizeType), (arr + (j + 1)*sizeType), sizeType);
				pCMe->m_pIMem->pVTbl->Copy(pCMe->m_pIMem, (arr + (j + 1)*sizeType), temp, sizeType);

			}
		}
	}

	pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, temp);
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
int16_t ECOCALLMETHOD initCBubleSort_B4ED74BE(/*in*/ struct IBubleSort* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)me;
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

/* Create Virtual Table IBubleSort */
IBubleSortVTbl g_x87CE395400A14271A107EB2788B31103VTbl_B4ED74BE = {
    CBubleSort_B4ED74BE_QueryInterface,
    CBubleSort_B4ED74BE_AddRef,
    CBubleSort_B4ED74BE_Release,
    CBubleSort_B4ED74BE_MyFunction
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
int16_t ECOCALLMETHOD createCBubleSort_B4ED74BE(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IBubleSort** ppIBubleSort) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CBubleSort_B4ED74BE* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIBubleSort == 0 || pIUnkSystem == 0) {
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
    pCMe = (CBubleSort_B4ED74BE*)pIMem->pVTbl->Alloc(pIMem, sizeof(CBubleSort_B4ED74BE));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IBubleSort */
    pCMe->m_pVTblIBubleSort = &g_x87CE395400A14271A107EB2788B31103VTbl_B4ED74BE;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIBubleSort = (IBubleSort*)pCMe;

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
void ECOCALLMETHOD deleteCBubleSort_B4ED74BE(/* in */ IBubleSort* pIBubleSort) {
    CBubleSort_B4ED74BE* pCMe = (CBubleSort_B4ED74BE*)pIBubleSort;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIBubleSort != 0 ) {
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
