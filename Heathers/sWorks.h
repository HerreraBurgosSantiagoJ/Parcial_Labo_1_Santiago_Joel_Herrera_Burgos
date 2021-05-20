#ifndef SWORKS_H_INCLUDED
#define SWORKS_H_INCLUDED

#include "../Heathers/input_lib.h"
#include "../Heathers/sServices.h"
#define BRAND_LENGTH 25

typedef struct{

 int id;
 char brand[BRAND_LENGTH];
 int wheelSize;
 int idService;
 sDate date;
 int isEmpty;

}sWork;

#endif // SWORKS_H_INCLUDED

int work_init(sWork* list, int len );

int work_add(sWork* list, int len, int id, char* brand, int wheelSize, int idService, sDate date);

int work_findById(sWork* list, int len,int id);

int work_remove(sWork* list, int len, int id);

int work_swap( sWork* workA, sWork* workB );

int work_sort(sWork* list, int len, int order);

int work_list(sWork* list, int workLength, sService* services, int servicesLength);

int work_generateID(sWork* list, int len);

float work_totalGain(sWork* list, int workLen, sService* services, int servLen);

char work_hasSpace(sWork* list, int len);

int work_isNotEmpty( sWork* list, int length );

int work_findEmpty( sWork* list, int length );

int work_findGreaterID( sWork* list, int length );

int work_findMinorID( sWork* list, int length );
