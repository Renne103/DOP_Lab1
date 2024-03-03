/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   Lab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdLab1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

int ECOCDECLMETHOD intcomp(const int* i, const int* j) {
    if (*i > *j) {
        return 1;
    } else if (*i < *j) {
        return -1;
    }
    return 0;
}

int ECOCDECLMETHOD doublecomp(const double* i, const double* j) {
    if (*i - *j > -DBL_EPSILON) {
        return 1;
    } else if (*i - *j < DBL_EPSILON) {
        return -1;
    }
    return 0;
}

int rndint(int lower, int upper) {
    return (rand() % (upper + 1 - lower) + lower);
}

double rnddouble(double lower, double upper) {
    return lower + (rand() / (RAND_MAX / (upper - lower)));
}


int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
	/* Указатель на тестируемый интерфейс */
    ILab1* pILab1 = 0;

    int* intarr = 0;
	int* temp = 0;
    double* doublearr = 0;
    int i = 0, j = 0;
	int initarr[] = {1000, 10000, 12500, 25000};
    clock_t heaptimestamp1;
    clock_t heaptimestamp2;
    clock_t qsorttimestamp1;
    clock_t qsorttimestamp2;
    srand(time(0));

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_Lab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_C02D201CE0BB44109F1C55C4FFBBD9A6);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }
	
    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_Lab1, 0, &IID_ILab1, (void**) &pILab1);
    if (result != 0 || pILab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

	printf("Unit test:\n\n");

    printf("Int:\n	");
    intarr = (int*) pIMem->pVTbl->Alloc(pIMem, sizeof(int) * SIZE);
    for (i = 0; i < SIZE; i++)
        ((int*) intarr)[i] = rndint(-1000, 1000);
    for (i = 0; i < SIZE; i++)
        printf("%d ", ((int*) intarr)[i]);

    pILab1->pVTbl->bublesort(intarr, SIZE, sizeof(int), intcomp);

    printf("\nRes:\n	");
    for (i = 0; i < SIZE; i++)
        printf("%d ", ((int*) intarr)[i]);
    pIMem->pVTbl->Free(pIMem, intarr);
    printf("\n\n");

    printf("Double:\n	");
    doublearr = (double*) pIMem->pVTbl->Alloc(pIMem, sizeof(double) * SIZE);
    for (i = 0; i < SIZE; i++)
        ((double*) doublearr)[i] = rnddouble(-1000,1000);
    for (i = 0; i < SIZE; i++)
        printf("%f ", ((double*) doublearr)[i]);

    pILab1->pVTbl->bublesort(doublearr, SIZE, sizeof(double), doublecomp);

    printf("\nRes:\n	");
    for (i = 0; i < SIZE; i++)
        printf("%f ", ((double*) doublearr)[i]);
    pIMem->pVTbl->Free(pIMem, doublearr);
    printf("\n\n////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

	printf("Time test:\n\n");
    for (i = 0; i < 4; i++) {
        printf("Arr size = %d:\n", initarr[i]);
        intarr = (int*) pIMem->pVTbl->Alloc(pIMem, sizeof(int) * initarr[i]);

        for (j = 0; j < initarr[i]; j++) {
            ((int*) intarr)[j] = rndint(-1000, 1000);
        }
		temp = intarr;

        heaptimestamp1 = clock();
        pILab1->pVTbl->bublesort(intarr, initarr[i], sizeof(int), intcomp);
        heaptimestamp2 = clock();

        qsorttimestamp1 = clock();
        qsort(temp, initarr[i], sizeof(int), intcomp);
        qsorttimestamp2 = clock();

        printf("Bublesort time: %8.2f ms | Qsort time: %8.2f ms | Time diff: %8.2f ms\r",
                (heaptimestamp2 - heaptimestamp1) * 1000.0 / CLOCKS_PER_SEC,
                (qsorttimestamp2 - qsorttimestamp1) * 1000.0 / CLOCKS_PER_SEC,
                fabs(((heaptimestamp2 - heaptimestamp1) * 1000.0 / CLOCKS_PER_SEC) - ((qsorttimestamp2 - qsorttimestamp1) * 1000.0 / CLOCKS_PER_SEC)));

        pIMem->pVTbl->Free(pIMem, intarr);
		printf("\n\n");
    }
	scanf("%d",i);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pILab1 != 0) {
        pILab1->pVTbl->Release(pILab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}
