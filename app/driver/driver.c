#include "driver.h"



void Driver_Init( void )
{
    //����GPIO16(�ص�����ҵ����)
    gpio16_output_conf();
    gpio16_output_set(0);

    Uart0_Init();
    d_printf( "\n\nstart...." );

}





