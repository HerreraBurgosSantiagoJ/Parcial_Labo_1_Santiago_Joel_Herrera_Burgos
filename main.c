
#include <stdio_ext.h>
#include "../Heathers/aux_main.h"
#include "../Heathers/steart.h"
#include "../Heathers/my_system.h"
#include "Heathers/sWorks.h"

int main()
{
	int returnAux = -1;
	sWork worksList[MAX_WORKS];
	sService servicesList[MAX_SERVICES];
    if( work_init( worksList, MAX_WORKS ) == 0 && serv_init( servicesList, MAX_SERVICES) == 0 && serv_hardcode(servicesList, MAX_SERVICES) == 0 )
    {
    	returnAux = main_menu( worksList, MAX_WORKS, servicesList, MAX_SERVICES);
    }
    if( returnAux != 0 )
    {
    	progHeader( TITLE );
    	subHeader( SUB_TITLE_ERROR );
    }
    if( returnAux == -1 )
    {
    	printf( MAIN_ERROR_MALFUNCTION_EXIT );
    	sys_pause();
    }
    if( returnAux == -2 )
    {
    	printf( MAIN_ERROR_MISUSE_EXIT );
    	sys_pause();
    }
    return returnAux;
}
