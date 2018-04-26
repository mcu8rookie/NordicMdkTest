#ifndef __USER_IIC_C__
#define __USER_IIC_C__


#include "test_config.h"
#if MODULE_IIC == 1
#include "user_iic.h"
#include "twi_master.h"
#include "stdio.h"


void user_iic_init(void)
{
	twi_master_init();
}
void user_iic_loop(void)
{
	{
		static unsigned char i=0,j=0;
    	unsigned char w2_data[2];

    	w2_data[0] = i;
    	w2_data[1] = 255-i+1;
    	//return twi_master_transfer(m_device_address, w2_data, 2, TWI_ISSUE_STOP);
    	j = twi_master_transfer(0x68, w2_data, 2, TWI_ISSUE_STOP);
    	printf("\r\nb1 = %d,	b2 = %d,	ret = 	%d\r\n",w2_data[0],w2_data[1],j);
    	if(true == 1)printf("true == 1");
    	else printf("true == 0");
    	test_delay(1000);
    	i++;
	}
}




#endif



#endif // #ifndef __USER_IIC_C__

