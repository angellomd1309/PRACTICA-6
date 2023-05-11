/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GARELERIEL MABSILLA DIEGUEZ y PABLO DAVID HERNANDEZ AJIATAZ
CARNETS: 2022380 y 2022472
PRACTICA 4 DISEÑO DE FIRMWARE
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C crystal(0x27,20,4);

byte BLOQUE[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte VACIO[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void);


int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable DISTANCE.


void setup() {
  crystal.init();
  crystal.backlight();
  crystal.createChar(0, BLOQUE);
  crystal.createChar(1, VACIO);

  pinMode (TRIG, OUTPUT);
  pinMode (ECHO, INPUT);

  PENTRADA(); //Hacemos el llamado a las funciones de Configuracion.
  PSALIDA();  

 
}

void loop() {
  SENSCONFIG();
  Serial.print(String(DISTANCE)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");

  
 if(DISTANCE>=30){
  crystal.setCursor(0,0);
  crystal.write(byte(0));
  crystal.setCursor(1,0);
  crystal.write(byte(0));
  crystal.setCursor(2,0);
  crystal.write(byte(0));
  crystal.setCursor(3,0);
  crystal.write(byte(1));
  crystal.setCursor(4,0);
  crystal.write(byte(1));
  crystal.setCursor(5,0);
  crystal.write(byte(1));
  crystal.setCursor(6,0);
  crystal.write(byte(1));
  crystal.setCursor(7,0);
  crystal.print("30");
  crystal.setCursor(15,0);
  crystal.write(byte(0));
  crystal.setCursor(14,0);
  crystal.write(byte(0));
  crystal.setCursor(13,0);
  crystal.write(byte(0));
  crystal.setCursor(12,0);
  crystal.write(byte(1));
  crystal.setCursor(11,0);
  crystal.write(byte(1));
  crystal.setCursor(10,0);
  crystal.write(byte(1));
  crystal.setCursor(9,0);
  crystal.write(byte(1));
  crystal.setCursor(0,1);
  crystal.print("      LIBRE     ");
 }
 if(DISTANCE>=20 && DISTANCE <=29){
  crystal.setCursor(0,0);
  crystal.write(byte(0));
  crystal.setCursor(1,0);
  crystal.write(byte(0));
  crystal.setCursor(2,0);
  crystal.write(byte(0));
  crystal.setCursor(3,0);
  crystal.write(byte(0));
  crystal.setCursor(4,0);
  crystal.write(byte(0));
  crystal.setCursor(5,0);
  crystal.write(byte(1));
  crystal.setCursor(6,0);
  crystal.write(byte(1));
  crystal.setCursor(7,0);
  crystal.print("20");
  crystal.setCursor(15,0);
  crystal.write(byte(0));
  crystal.setCursor(14,0);
  crystal.write(byte(0));
  crystal.setCursor(13,0);
  crystal.write(byte(0));
  crystal.setCursor(12,0);
  crystal.write(byte(0));
  crystal.setCursor(11,0);
  crystal.write(byte(0));
  crystal.setCursor(10,0);
  crystal.write(byte(1));
  crystal.setCursor(9,0);
  crystal.write(byte(1));
  crystal.setCursor(0,1);
  crystal.print("    CUIDADO     ");
 }
 if(DISTANCE>=10 && DISTANCE <=20){
  crystal.setCursor(0,0);
  crystal.write(byte(0));
  crystal.setCursor(1,0);
  crystal.write(byte(0));
  crystal.setCursor(2,0);
  crystal.write(byte(0));
  crystal.setCursor(3,0);
  crystal.write(byte(0));
  crystal.setCursor(4,0);
  crystal.write(byte(0));
  crystal.setCursor(5,0);
  crystal.write(byte(0));
  crystal.setCursor(6,0);
  crystal.write(byte(0));
  crystal.setCursor(7,0);
  crystal.print("10");
  crystal.setCursor(15,0);
  crystal.write(byte(0));
  crystal.setCursor(14,0);
  crystal.write(byte(0));
  crystal.setCursor(13,0);
  crystal.write(byte(0));
  crystal.setCursor(12,0);
  crystal.write(byte(0));
  crystal.setCursor(11,0);
  crystal.write(byte(0));
  crystal.setCursor(10,0);
  crystal.write(byte(0));
  crystal.setCursor(9,0);
  crystal.write(byte(0));
  crystal.setCursor(0,1);
  crystal.print("      ALTO      ");
 }
}

 void PENTRADA(void){
  pinMode(ECHO, INPUT);
  
 }
 void PSALIDA(void)
{

     pinMode(TRIG, OUTPUT);  
            
                     
}
 int SENSCONFIG(){ //Configuracion del Sensor.
   digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(50); 
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig. 
  delay(50);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
   DURATION = pulseIn(ECHO, HIGH); /* Lee la informacion del pin eco,
  y la guarda en la variable duracion */  
  DISTANCE= DURATION*0.034/2;  //Convierte la distancia en centimetros . 
  delay(400);
  return DISTANCE;
}












            
     
