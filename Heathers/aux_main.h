/*
 * aux_main.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_AUX_MAIN_H_
#define HEATHERS_AUX_MAIN_H_


#endif /* HEATHERS_AUX_MAIN_H_ */

//Program Title
#define TITLE "ABM"
#define SUB_TITLE_MAIN "Menu Principal"
#define SUB_TITLE_REG "ALTAS"
#define SUB_TITLE_MOD "MODIFICAR"
#define SUB_TITLE_DEL "BAJAS"
#define SUB_TITLE_INF "INFORME"
#define SUB_TITLE_ERROR "Error"

//Output Menu(Main)
#define MENU_MAIN_ONE "\nA. ALTA TRABAJO."
#define MENU_MAIN_TWO "\nB. MODIFICACAR TRABAJO."
#define MENU_MAIN_THREE "\nC. BAJA TRABAJO."
#define MENU_MAIN_FOUR "\nD. LISTAR TRABAJOS."
#define MENU_MAIN_FIVE "\nE. LISTAR SERVICIOS."
#define MENU_MAIN_SIX "\nF. TOTAL."
#define MENU_MAIN_SEVEN "\nG. Salir."

//Outut Modify Menu
#define MENU_MOD_ONE "\n1. Cambiar Marca."
#define MENU_MOD_TWO "\n2. Cambiar Servicio."
#define MENU_MOD_FIVE "\n3. Modificar otro Trabajo."
#define MENU_MOD_SIX "\n4. Volver al Menu Principal"

//Output
#define TXT_FULL_DATABASE "\nNo es posible, base de datos llena."
#define TXT_EMPTY_DATABASE "\nNo es posible, base de datos vacia."
#define TXT_NEW_ID "\nEl Legajo del nuevo empleado es %d."
#define TXT_WORK_DATA "\nLegajo: %05d\nNombre: %s, %s.\nSalario: %.02f\nSector: %d."
#define TXT_REMOVAL_SUCCESES "\nEl empleado fue dado de BAJA con exito."
#define TXT_INFORM "\nLa suma del sueldo de los empleados es %0.2f\nSiendo el promedio %0.2f\nY la cantidad de empleados cuyo sueldo supera el promedio es %d"
#define GOODBYE "\nHasta Luego! :D"

//Output Errors
#define MAIN_ERROR_MALFUNCTION_EXIT "\nEl programa parece estar funcionando mal, este se cerrará."
#define MAIN_ERROR_MISUSE_EXIT "\nEl usuario no es apto para el uso del programa, este se cerrará"

//Input options
#define INP_TXT_OPTION "\nOpción: "

#define INP_TXT_DATA_OK "\nSon estos datos correctos? (Si=1/No=0): "
#define INP_TXT_MORE_REG "\nDesea dar de ALTA a otro empleado? (Si=1/No=0): "
#define INP_TXT_MORE_DEL "\nDesea dar de BAJA a otro empleado? (Si=1/No=0): "

#define INP_TXT_DEL_ID "\nIngrese el legajo del empleado que desea borrar( Para cancelar ingrese 0 ): "

//Input employee data
#define INP_TXT_BRAND "\nIngrese el nombre: "
#define INP_TXT_WHEEL_SIZE "\nIngrese el nuevo nombre: "
#define INP_TXT_SERVICE_ID "\nIngrese el apellido: "
#define INP_TXT_DATE "\nIngrese el nuevo apellido: "

//Input errors
#define INP_ERROR_MAIN_OPTION "\nError! Lo ingresado no corresponde con ninguna de las opciones del menu principal.\nIntentos Restantes: %d"
#define INP_ERROR_MOD_OPTION "\nError! Lo ingresado no corresponde con ninguna de las opciones de este menu.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_EXPECTED_INT "\nError! El numero ingresado no corresponde con los valores esperados.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_NUMBER "\nError! Lo ingresado no es un numero.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_BRAND "\nError! Lo ingresado contiene caracteres no esperados en una marca.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_SECTOR "\nError! Lo ingresado contiene caracteres no esperados en una marca.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_DATE "\nError! Lo ingresado no es un numero.\nIntentos Restantes: %d"

//Numerical constants
#define MAX_WORKS 11
#define MAX_SERVICES 4
#define MAX_SERVICES_ID 20003
#define MIN_SERVICES_ID 20000
#define MAX_TRYS 3
#define LEN_MAIN_OPT 7
#define LEN_MODY_OPT 6
#define LEN_INT_YN_OPT 2

int main_registerWork( sWork* list, int worksLength, sService* services, int servicesLen )
