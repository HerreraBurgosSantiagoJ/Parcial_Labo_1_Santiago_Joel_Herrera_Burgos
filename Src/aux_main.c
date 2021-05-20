/*
 * aux_main.c
 *
 *  Created on: 13 may. 2021
 *      Author: plainsight
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "../Heathers/aux_main.h"
#include "../Heathers/steart.h"
#include "../Heathers/input_lib.h"
#include "../Heathers/my_system.h"
#include "../Heathers/sServices.h"
#include "../Heathers/sWorks.h"
//#include "../Heathers/"

int main_registerWork( sWork* works, int worksLength, sService* services, int servicesLen )
{
	int returnAux = -1;
	int allOk = 1;
	int options[LEN_INT_YN_OPT] = {0,1};
	int keepOn;
	int auxServiceId;
	sWork auxWork;
	if( works != NULL && worksLength > 0 )
	{
		do
		{
			progHeader(TITLE);
			subHeader( SUB_TITLE_REG );
			keepOn = 0;
			if( allOk && work_hasSpace(works, worksLength) )
			{
				auxWork.id = work_generateID( works, worksLength);
				auxWork.isEmpty = 0;
				printf( TXT_NEW_ID, auxWork.id );
			}
			else if( allOk )
			{
				printf( TXT_FULL_DATABASE );
				returnAux = 0;
				sys_pause();
				break;
			}

			if( inp_getName( auxWork.brand, INP_TXT_BRAND, BRAND_LENGTH,
							MAX_TRYS, INP_ERROR_NOT_BRAND)== 0 &&
				inp_getInt(&auxWork.wheelSize, INP_TXT_WHEEL_SIZE, MAX_TRYS, INP_ERROR_NOT_NUMBER ) == 0 &&
				serv_list(services, servicesLen) == 0 &&
				inp_getIntRange(&auxWork.idService, INP_TXT_SERVICE_ID, MAX_TRYS, MIN_SERVICES_ID, MAX_SERVICES_ID, INP_ERROR_NOT_EXPECTED_INT, INP_ERROR_NOT_NUMBER)== 0 &&
				inp_getDate( &auxWork.date, INP_TXT_DATE, MAX_TRYS, 2020, INP_ERROR_NOT_NUMBER, INP_ERROR_NOT_DATE) == 0 )
			{
				auxServiceId = serv_findByID(services, servicesLen, auxWork.idService);
				printf( TXT_WORK_DATA, auxWork.id, auxWork.brand,
						auxWork.wheelSize, services[auxServiceId].description , auxWork.date.day, auxWork.date.month, auxWork.date.year );
				returnAux = inp_getIntConcrete( &allOk, INP_TXT_DATA_OK,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER );
			}
			else
			{
				returnAux = -2;
				break;
			}

			if( allOk && returnAux == 0 )
			{
				returnAux = work_add(works, worksLength, auxWork.id, auxWork.brand, auxWork.wheelSize, auxWork.idService, auxWork.date );
				returnAux = inp_getIntConcrete( &keepOn, INP_TXT_MORE_REG,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER );
			}
			else if( returnAux == 0 )
			{
				keepOn = 1;
			}


		}while( keepOn && returnAux != -2 );
	}
	return returnAux;
}

int main_deleteWork( sWork* works, int length, sService* services, int servicesLen )
{
	int returnAux = -1;
	int options[LEN_INT_YN_OPT] = {0,1};
	int auxID;
	int auxService;
	int auxMax;
	int keepOn;
	int position;
	int allOk = 1;
	int trys = MAX_TRYS;
	if( works != NULL && length > 0 )
	{
		do
		{
			keepOn = 0;
			progHeader( TITLE );
			subHeader( SUB_TITLE_DEL );

			if( work_isNotEmpty( works, length ) )
			{
				work_list(works, length, services, servicesLen);
			}
			else
			{
				printf( TXT_EMPTY_DATABASE );
				sys_pause();
				returnAux = 0;
				break;
			}

			auxMax = work_findGreaterID(works, length);

			if( inp_getIntRange( &auxID, INP_TXT_DEL_ID, trys, 0, auxMax,
								INP_ERROR_NOT_EXPECTED_INT,
								INP_ERROR_NOT_NUMBER) == 0
				&& auxID != 0
				&& (position = work_findById(works, length, auxID)) != -1 )
			{
				auxService = serv_findByID(services, servicesLen, works[position].idService);
				progHeader( TITLE );
				subHeader( SUB_TITLE_DEL );
				printf( TXT_WORK_DATA, works[position].id,
						works[position].brand, works[position].wheelSize,
						services[auxService].description,
						works[position].date.day, works[position].date.month,
						works[position].date.year );
				returnAux = inp_getIntConcrete(&allOk, INP_TXT_DATA_OK,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER);
			}
			else if( auxID == 0 )
			{
				returnAux = 0;
				break;
			}
			else if( position == -1 && trys > 0 )
			{
				trys--;
				printf( INP_ERROR_NOT_EXPECTED_INT, trys );
				sys_pause();
				keepOn = 1;
				continue;
			}
			else if( position == -1 )
			{
				returnAux = -2;
				break;
			}

			if( allOk )
			{
				returnAux = work_remove(works, length, auxID);
				printf( TXT_REMOVAL_SUCCESES );
			}
			else
			{
				keepOn = 1;
				continue;
			}

			returnAux = inp_getIntConcrete( &keepOn, INP_TXT_MORE_DEL, MAX_TRYS,
											LEN_INT_YN_OPT, options,
											INP_ERROR_NOT_EXPECTED_INT,
											INP_ERROR_NOT_NUMBER );

		}while( keepOn && returnAux == 0 );
	}
	return returnAux;
}

void mody_menuShow( void )
{
	printf( MENU_MOD_ONE );
	printf( MENU_MOD_TWO );
	printf( MENU_MOD_THREE );
	printf( MENU_MOD_FOUR );
}

int mody_menu( sWork* work, int* keepOn, sService* services, int servicesLen )
{
	int returnAux = -1;
	int options[LEN_MODY_OPT] = {1, 2, 3, 4};
	int option = 0;
	int auxService;
	if( work != NULL )
	{
		do
		{
			progHeader(TITLE);
			subHeader(SUB_TITLE_MOD);
			auxService = serv_findByID(services, servicesLen, work->idService);
			printf( TXT_WORK_DATA, work->id, work->brand,
					work->wheelSize,
					services[auxService].description,
					work->date.day, work->date.month,
					work->date.year );
			mody_menuShow();
			if( inp_getIntConcrete(&option, INP_TXT_OPTION, MAX_TRYS,
											LEN_MODY_OPT, options,
											INP_ERROR_MOD_OPTION,
											INP_ERROR_NOT_NUMBER) != 0 )
			{
				returnAux = -2;
				break;
			}
			switch ( option )
			{
			case 1:
				returnAux = inp_getName( work->brand, INP_TXT_BRAND, BRAND_LENGTH, MAX_TRYS, INP_ERROR_NOT_BRAND);
				break;
			case 2:
				serv_list(services, servicesLen);
				returnAux = inp_getIntRange(&work->idService, INP_TXT_SERVICE_ID, MAX_TRYS, MIN_SERVICES_ID, MAX_SERVICES_ID, INP_ERROR_NOT_EXPECTED_INT, INP_ERROR_NOT_NUMBER);
				break;
			case 3:
				*keepOn = 1;
				returnAux = 0;
				break;
			case 4:
				returnAux = 0;
				break;
			}
		}while( returnAux != -2 && option != 3 && option != 4 );
	}
	return returnAux;
}

int main_modifyWork( sWork* works, int length, sService* services, int servicesLen )
{
	int returnAux = -1;
	int keepOn;
	int auxMax;
	int auxID;
	int position;
	if( works != NULL && length > 0 )
	{
		do
		{
			keepOn = 0;
			progHeader( TITLE );
			subHeader( SUB_TITLE_MOD );

			if( work_isNotEmpty(works, length) )
			{
				work_list(works, length, services, servicesLen);
			}
			else
			{
				printf( TXT_EMPTY_DATABASE );
				sys_pause();
				returnAux = 0;
				break;
			}

			auxMax = work_findGreaterID(works, length);

			if( inp_getIntRange( &auxID, INP_TXT_DEL_ID, MAX_TRYS, 0,
								auxMax, INP_ERROR_NOT_EXPECTED_INT,
								INP_ERROR_NOT_NUMBER) == 0 &&
				auxID != 0)
			{
				position = work_findById(works, length, auxID);
				returnAux = mody_menu( &works[position], &keepOn, services, servicesLen);
			}
			else if( auxID == 0 )
			{
				returnAux = 0;
			}
			else
			{
				returnAux = -2;
			}

		}while( keepOn && returnAux == 0 );
	}
	return returnAux;
}

int main_listWorks( sWork* works, int worksLen, sService* services, int servicesLen )
{
	int returnAux = -1;
	if( works != NULL &&
		services != NULL &&
		worksLen > 0 &&
		servicesLen > 0 )
	{
		progHeader(TITLE);
		subHeader(SUB_TITLE_LIST_WORKS);
		if( work_sort(works, worksLen, 1) == 0 )
		{
			returnAux = work_list(works, worksLen, services, servicesLen);
		}
	}
	return returnAux;
}

int main_listServices( sService* services, int servicesLen )
{
	int returnAux = -1;
	if( services != NULL && servicesLen > 0 )
	{
		progHeader(TITLE);
		subHeader(SUB_TITLE_LIST_SERV);
		returnAux = serv_list(services, servicesLen);
	}
	return returnAux;
}

void main_menuShow( void )
{
	printf( MENU_MAIN_ONE );
	printf( MENU_MAIN_TWO );
	printf( MENU_MAIN_THREE );
	printf( MENU_MAIN_FOUR );
	printf( MENU_MAIN_FIVE );
	printf( MENU_MAIN_SIX );
	printf( MENU_MAIN_SEVEN );
}

int main_menu( sWork* works, int worksLength, sService* services, int servLength )
{
	int returnAux = -1;
	char option = 'H';
	char options[LEN_MAIN_OPT] = "ABCDEFG";
	if( works != NULL && worksLength > 0 )
	{
		do
		{
			progHeader( TITLE );
			subHeader( SUB_TITLE_MAIN );
			main_menuShow();
			returnAux = inp_getCharConcrete( &option, INP_TXT_OPTION, MAX_TRYS, LEN_MAIN_OPT, options, INP_ERROR_MAIN_OPTION);
			if( returnAux == -2 )
			{
				break;
			}
			switch(option)
			{
			case 'A':
				if( work_hasSpace( works, worksLength ) )
				{
					returnAux = main_registerWork(works, worksLength, services, servLength);
				}
				else
				{
					printf( TXT_FULL_DATABASE );
					sys_pause();
				}
				break;
			case 'B':
				if( work_isNotEmpty(works, worksLength) == 1 )
				{
					returnAux = main_modifyWork(works, worksLength, services, servLength);
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 'C':
				if( work_isNotEmpty(works, worksLength) == 1 )
				{
					returnAux = main_deleteWork(works, worksLength, services, servLength);
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 'D':
				if( work_isNotEmpty(works, worksLength) == 1 )
				{
					returnAux = main_listWorks(works, worksLength, services, servLength);
					sys_pause();
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 'E':
				returnAux = main_listServices(services, servLength);
				sys_pause();
				break;
			case 'G':
				printf( GOODBYE );
				returnAux = 0;
				break;
			}
		}while( option != 'G' && returnAux == 0 );
	}
	return returnAux;
}
