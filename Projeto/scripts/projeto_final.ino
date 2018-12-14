// MPU-6050 Short Example Sketch
// Adapatado do usuario JohnChi
// Por Frederico, Leonardo e Pedro Paulo
// 12 de Dezembro de 2018
// Public Domain

#include<Wire.h>

//--------------------------------------
//------Declaracao variaveis------------
//--------------------------------------
const int analogInPin = A4; // acelerometro esta ligado ao pino A4
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ;
int16_t AcX0,AcY0,AcZ0;
int flag = 0;
long int contador = 0;
int iniciaColeta = 1;

//------------------------------
//------Funcao setup------------
//------------------------------
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200, SERIAL_8N1); //LAB08 4.2.4 linha 7 (listing 2)
}


//----------------------------
//------Funcao loop-----------
//----------------------------
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  
  if (flag == 0)
  {
    flag = 1;
    AcX0 = AcX;
    AcY0 = AcY;
    AcZ0 = AcZ;
  }
  
  float AX = (float)(AcX-AcX0)/32768.0f;
  float AY = (float)(AcY-AcY0)/32768.0f;
  float AZ = (float)(AcZ-AcZ0)/32768.0f;
  
  if (AX > 0.65 || AX < -0.65 ) { 
     //Serial.print("Queda lateral: Entre em contato imediatamente!!!"); 
    Serial.write(1); delay(300); exit(0); } //eixo X
  if (AY > 0.65 || AY < -0.65 ) { 
    //Serial.print("Queda lateral: Entre em contato imediatamente!!!"); 
    Serial.write(1); delay(300); exit(0); } // eixo Y
  if (AZ > 0.65 || AZ < -0.65 ) { 
  //Serial.print("Queda frontal: Entre em contato imediatamente!!!");
     Serial.write(1); delay(300); exit(0); } // eixo Z
  //Serial.println("Esta tudo bem!"); 
  Serial.write(2);

  delay(500);
}
