//COM 5

#include "max6675.h"

//Resistencia 1
int ktcSO1 = 5;
int ktcCS1 = 6;
int ktcSCK1 = 7;

//Resistencia 2
int ktcSO2 = 2;
int ktcCS2 = 3;
int ktcSCK2 = 4;

//Resistencia 3
int ktcSO3 = 31;
int ktcCS3 = 29;
int ktcSCK3 = 27;

//Resistencia 4
int ktcSO4 = 37;
int ktcCS4 = 35;
int ktcSCK4 = 33;

//Estados reles
int ReleOn = 0;
int ReleOff = 1;

//Temperatura
int rele1 = 53;
int rele2 = 51;
int rele3 = 49;
int rele4 = 47;

//Motor y Valvula
int Motor = 45;
int Valvula = 43;

//Variables Temperaturas
int temp1;
int temp2;
int temp3;
int temp4;

//Valores offset temperatura tiempo
int sen;
int mot;
int mic;

//Declarar Max6675
MAX6675 ktc1(ktcSCK1, ktcCS1, ktcSO1);
MAX6675 ktc2(ktcSCK2, ktcCS2, ktcSO2);
MAX6675 ktc3(ktcSCK3, ktcCS3, ktcSO3);
MAX6675 ktc4(ktcSCK4, ktcCS4, ktcSO4);

void setup()
{
  Serial.begin(9600);

  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(Motor, OUTPUT);
  pinMode(Valvula, OUTPUT);
  digitalWrite(rele1, ReleOff);
  digitalWrite(rele2, ReleOff);
  digitalWrite(rele3, ReleOff);
  digitalWrite(rele4, ReleOff);
  digitalWrite(Motor, ReleOff);
  digitalWrite(Valvula, ReleOff);

  //Serial.setTimeout(2000);
}

void loop()
{
  if (Serial.available ()) {
    while (Serial.available () > 0)
    {
      //Lectura temperatura
      temp1 = (ktc1.readCelsius());
      temp2 = (ktc2.readCelsius());
      temp3 = (ktc3.readCelsius());
      temp4 = (ktc4.readCelsius());
      //Redondea el valor de la temperatura
      temp1 = round(temp1);
      temp2 = round(temp2);
      temp3 = round(temp3);
      temp4 = round(temp4);
      //Imprime el valor de la temperatura en el serial
      Serial.print(temp1);
      Serial.print(",");
      Serial.print(temp2);
      Serial.print(",");
      Serial.print(temp3);
      Serial.print(",");
      Serial.println(temp4);

      //Lee el valor del serial y los separa en offset de temperatura y tiempo
      int sen = Serial.parseInt();
      int mot = Serial.parseInt();
      int mic = Serial.parseInt();
      if (Serial.read() == '\n') {
      }

      //Condiciona on off de temperatura

      //Temperatura 1
      if (temp1 < sen) {
        digitalWrite(rele1, ReleOn);
      }
      else if (temp1 >= sen) {
        digitalWrite(rele1, ReleOff);
      }

      //Temperatura 2
      if (temp2 < sen) {
        digitalWrite(rele2, ReleOn);
      }
      else if (temp2 >= sen) {
        digitalWrite(rele2, ReleOff);
      }

      //Temperatura 3
      if (temp3 < sen) {
        digitalWrite(rele3, ReleOn);
      }
      else if (temp3 >= sen) {
        digitalWrite(rele3, ReleOff);
      }

      //Temperatura 4
      if (temp4 < sen) {
        digitalWrite(rele4, ReleOn);
      }
      else if (temp4 >= sen) {
        digitalWrite(rele4, ReleOff);
      }

      //Control Motor
      if (mot == 1){
        digitalWrite(Motor, ReleOn);
      }
      if (mot == 0){
        digitalWrite(Motor,ReleOff);
      }

      //Control Valvula
      if (mic == 1){
        digitalWrite(Valvula, ReleOn);
      }
      if (mic == 0){
        digitalWrite(Valvula, ReleOff);
      } 
    }
  }
}
