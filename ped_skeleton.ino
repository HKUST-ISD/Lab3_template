
#include <Wire.h>


/***************** Lab2 **********************/
#define IMU_I2C_ADDR        0b1101010
#define SENSOR_DATA_LEN     12

typedef struct imuData_t {
  int16_t gyro[3];
  int16_t accel[3];
} imuData_t;

typedef struct imuDataScaled_t {
  float gyro[3];
  float accel[3];
} imuDataScaled_t;

byte rawData[SENSOR_DATA_LEN];
imuData_t imuData;
imuDataScaled_t imuDataScaled;

void writeByteToRegister(byte devAddr, byte regAddr, byte data) {
  uint8_t txPacket[2];
  txPacket[0] = regAddr;
  txPacket[1] = data;
  Wire.beginTransmission(devAddr);
  Wire.write(txPacket, 2);
  Wire.endTransmission();
}

void readBytesFromRegisters(byte devAddr, byte regAddr, byte *data, int length) {
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);
  Wire.endTransmission(false);            // Setting to false sends restart instead of stop on i2c bus
  Wire.requestFrom(devAddr, length);
  Wire.readBytes(data, length);
}

byte readByteFromRegister(byte devAddr, byte regAddr) {
  byte result;
  readBytesFromRegisters(devAddr, regAddr, &result, 1);
  return result;
}
/***************** Lab2 **********************/


/***************** Task 0 *****************/
/**
 * @brief Check whether a new sample of accelerations is available 
 *        Please refer to STATUS_REG(Table 83)
 * @return 1 if it is available, else 0
 */
int dataAccAvailable()
{
    // TODO: Complete this function
}

const int UPDATE_AFTER_SAMPLE = ??;                   // TODO: How many samples before updating the dynamic threshold
const float INITIAL_MIN_ACC = 100.0f;                 
const float INITIAL_MAX_ACC = -100.0f;
const float DYNAMIC_PRECISION_COEFF = ??;             // TODO: dynamicPrecision = DYNAMIC_PRECISION_COEFF * (maxAcc - minAcc)

/******************  Internal variables ******************/
float normAcc = 0;
unsigned int numHaveSampled = 0;
float minAcc = INITIAL_MIN_ACC;
float maxAcc = INITIAL_MAX_ACC;
float dynamicThreshold = 0;
float dynamicPrecision = 0;
int stepCount = 0;
float timeElapsed;
unsigned long lastCountTime = 0;
float sampleNew, sampleOld;
/******************  Internal variables ******************/


void setup() {
  Serial.begin(9600);
  Wire.begin();
  while (!Serial);

  if (readByteFromRegister(IMU_I2C_ADDR, 0x0F) != 0x69) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // In Lab 2, the sampling rate is configured to be 6.66kHz. It is far beyond the 
  // natural frequency of walking or even running. In Lab 3, it is better to use a
  // lower sampling rate together with a low pass filter to reduce unexpected noise.
  // TODO: Set the Accelerometer control register to work at 104 Hz, 4G and default Anti-aliasing filter.
  writeByteToRegister(IMU_I2C_ADDR, 0x10, );  
  writeByteToRegister(IMU_I2C_ADDR, 0x11, 0b10000100);
  
  /******************  Bonus Task ******************/
  // TODO: Configure `CTRL8_XL` and `CTRL10_C` to setup low pass filter with cutoff frequency to be `ODR_XL/9`.
  // writeByteToRegister(IMU_I2C_ADDR, 0x17, );
  // writeByteToRegister(IMU_I2C_ADDR, 0x19, );
}

void loop() {

  if (dataAccAvailable())
  {

    // TODO: Read the latest acceleration data from the imu and store the norm into `normAcc`.
    // Once you finish, try to plot `normAcc` to see whether the code is correct.
    normAcc = ??;

    /***************** Task 1, Task 2, Task 3, Task 4 *****************/
  }

}