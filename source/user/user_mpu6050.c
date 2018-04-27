#ifndef __USER_MPU6050_C__
#define __USER_MPU6050_C__

#include "test_config.h"
#if MODULE_MPU6050 == 1

#include "user_mpu6050.h"
#include "twi_master.h"
#include "MPU6050.h"
#include "stdio.h"

#if 1

void MPU6050_Initialize(void);
bool MPU6050_TestConnection(void);

// GYRO_CONFIG register
uint8_t MPU6050_GetFullScaleGyroRange(void);
void MPU6050_SetFullScaleGyroRange(uint8_t range);
// ACCEL_CONFIG register
uint8_t MPU6050_GetFullScaleAccelRange(void);
void MPU6050_SetFullScaleAccelRange(uint8_t range);

// PWR_MGMT_1 register
bool MPU6050_GetSleepModeStatus(void);
//void MPU6050_SetSleepModeStatus(FunctionalState NewState);
void MPU6050_SetSleepModeStatus(unsigned char);
void MPU6050_SetClockSource(uint8_t source);
// WHO_AM_I register
uint8_t MPU6050_GetDeviceID(void);

void MPU6050_GetRawAccelGyro(int16_t* AccelGyro);

void MPU6050_WriteBits(uint8_t slaveAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data);
void MPU6050_WriteBit(uint8_t slaveAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data);
void MPU6050_ReadBits(uint8_t slaveAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data);
void MPU6050_ReadBit(uint8_t slaveAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data);

//void MPU6050_I2C_Init(void);
void MPU6050_I2C_ByteWrite(uint8_t slaveAddr, uint8_t* pBuffer, uint8_t writeAddr);
void MPU6050_I2C_BufferRead(uint8_t slaveAddr,uint8_t* pBuffer, uint8_t readAddr, uint16_t NumByteToRead);

#endif

unsigned char user_mpu6050_init(void)
{
	twi_master_init();
	MPU6050_Initialize();
	printf("\r\nMPU6050_Initialize finished.");
	printf("\r\nMPU6050_GetDeviceID = 0x%x",MPU6050_GetDeviceID());
	printf("\r\nMPU6050_GetFullScaleGyroRange = 0x%x",MPU6050_GetFullScaleGyroRange());
	printf("\r\nMPU6050_GetFullScaleAccelRange = 0x%x",MPU6050_GetFullScaleAccelRange());
	printf("\r\nMPU6050_GetSleepModeStatus = 0x%x",MPU6050_GetSleepModeStatus());
	printf("\r\n");
	return 0;
}

unsigned char user_mpu6050_loop(void)
{
	//MPU6050_I2C_ByteWrite();
	//uint8_t i = 0x55;
	//MPU6050_I2C_ByteWrite(0x68<<1,&i,0x75);
	//MPU6050_Initialize();
	int16_t tmp[10]={0,};
	uint8_t i=0;
	MPU6050_GetRawAccelGyro(tmp);
	printf("\r\n");
	for(i=0;i<10;i++)
	{
		printf("%d,\t",tmp[i]);
	}
	return 0;
}

#endif
#endif //#ifndef __USER_MPU6050_C__


