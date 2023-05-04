/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO GARELERIEL MANSILLA DIEGUEZ y PABLO DAVID HERNANDEZ AJIATAZ
CARNETS: 2022380 y 2022472
PRACTICA 4 DISEÑO DE FIRMWARE
*/
#include <LiquidCrystal.h> //Incluimos la libreria Liquid Crystal.

#define PHIGH(pin)   digitalWrite(pin, HIGH)//Definimos una pequeña funcion, para abreviar el DigitalWrite HIGH.
#define PLOW(pin)   digitalWrite(pin, LOW)//Definimos una pequeña funcion, para abreviar el DigitalWrite LOW.
#define buzzer 9 //Definimos el pin del buzzer.
#define CDOM 1047 //Definimos el sonido del BUZZER.
LiquidCrystal ANGELLO(7, 6, 5, 4, 3, 2); //Definimos los pines de la LCD.

byte among1[8] = { //SPRITE 1
  B00000,
  B01111,
  B11000,
  B11000,
  B11111,
  B11111,
  B01111,
  B01001
};

byte among2[8] = { //SPRITE 2
  B00000,
  B01010,
  B01110,
  B00100,
  B11111,
  B11111,
  B01111,
  B01001
};


void  PENTRADA(void); //Definimos una funcion para salidas y entradas de los pines.
void  PSALIDA(void); 

int TRIG = 11; //Definimos El Pin 2 para Triger.
int ECHO = 12; //Definimos El Pin 3 para Echo.
int DURATION; //Definimos una variable de duracion.
int DISTANCE; //Definimos una variable distancia.
int CONT=0; //Definimos una variable para contar.


void setup() {
  
  ANGELLO.begin(16, 2); //Iniciamos la LCD.
  Serial.begin(9600); //Iniciamos la comunicacion Serial.
  ANGELLO.createChar(0, among1); //Definimos los char de las sprites.
  ANGELLO.createChar(1, among2);
  
PENTRADA(); //Hacemos el llamado a las funciones de Configuracion.
PSALIDA();  

}

void loop() {

SENSCONFIG(); //Llamamos la configuracion del Sensor.
if (CONT>=16) CONT=16; //Definimos que cuando el contador llegue a 16 o mas, valga 16 siempre, para que no suba infinitamente.
if (CONT>=16) BUZZERCON(); //Definimos que cuando el contador llegue a 16 o mas, inicie la configuracion del buzzer.

switch(CONT){ //Abrimos un switch case para almacenar los casos.
          
          case(0): //0
          ANGELLO.setCursor(0,0);
          ANGELLO.write("NO HAY NADIE");
          delay(500);
          ANGELLO.clear(); 
          ANGELLO.setCursor(0,1);
          ANGELLO.write("INTENTA PASAR");      
            break;
          case(1): //1             
          ANGELLO.setCursor(0,0);
          ANGELLO.write(byte(0));
          ANGELLO.setCursor(0,1);         
          ANGELLO.write("HAY 1 PERSONA");
         break;
           case(2): //2
          ANGELLO.setCursor(1,0);
          ANGELLO.write(byte(0));
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 2 PERSONAS");
         break;
          case(3): //3
          ANGELLO.setCursor(2,0);
          ANGELLO.write(byte(0));
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 3 PERSONAS");
         break;
          case(4): //4
          ANGELLO.setCursor(3,0);
          ANGELLO.write(byte(0));
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 4 PERSONAS");          
         break;                
          case(5): //5
          ANGELLO.setCursor(4,0);
          ANGELLO.write(byte(0));    
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 5 PERSONAS");  
         break;       
          case(6): //6
          ANGELLO.setCursor(5,0);
          ANGELLO.write(byte(0));   
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 6 PERSONAS");           
         break;        
          case(7): //7
          ANGELLO.setCursor(6,0);
          ANGELLO.write(byte(0)); 
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 7 PERSONAS");          
         break;
          case(8): //8
          ANGELLO.setCursor(7,0);
          ANGELLO.write(byte(0));   
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 8 PERSONAS");            
         break;
           case(9): //9           
          ANGELLO.setCursor(8,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 9 PERSONAS");                 
         break; 
           case(10): //10 
          ANGELLO.setCursor(9,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 10 PERSONAS");
         break;   
           case(11): //11
          ANGELLO.setCursor(10,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 11 PERSONAS");
         break;     
           case(12): //12
          ANGELLO.setCursor(11,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 12 PERSONAS");
         break;     
           case(13): //13
          ANGELLO.setCursor(12,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 13 PERSONAS");
         break;     
           case(14): //14
          ANGELLO.setCursor(13,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 14 PERSONAS");
         break;     
           case(15): //15
          ANGELLO.setCursor(14,0);
          ANGELLO.write(byte(0));  
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 15 PERSONAS");
         break;     
           case(16): //16
          ANIMFINAL();          
          ANGELLO.setCursor(0,1);  
          ANGELLO.write("HAY 16 PERSONAS");           
         break;                                     
    }
           
             
}

 void PENTRADA(void){ //Setup de entradas.
  pinMode(ECHO, INPUT);
  
 }

void PSALIDA(void) //Setup de salidas.

{
     pinMode(TRIG, OUTPUT);    
                     
}

void BUZZERCON(void){ //Configuracion del buzzer.
            tone(buzzer, CDOM, 1500);   
           delay(750);
           noTone(buzzer);
}

void SENSCONFIG(void){ //Configuracion del Sensor.
   digitalWrite(TRIG, LOW); //Apaga el Pin de Trig.
  delay(60); 
  digitalWrite(TRIG, HIGH);//Enciende el Pin Trig. 
  delay(60);
  digitalWrite(TRIG, LOW);//Apaga el Pin Trig.
   DURATION = pulseIn(ECHO, HIGH); /* Lee la informacion del pin eco,
  y la guarda en la variable duracion */
  
  DISTANCE= DURATION*0.034/2;  //Convierte la distancia en centimetros . 
  Serial.print(String(DISTANCE)); // La variable String guarda tipo de datos en cadenas
  Serial.println(" cm");
  delay(400);
    if(DISTANCE>=6 && DISTANCE <=10) //Si la distancia es entre 6cm o 10cm Ejecutara lo de las llaves.
  {

    CONT++;

    } 
  else  //Lo contrario...
  {

    }  
}

void ANIMFINAL(void){ //Secuencia de animacion final.
          ANGELLO.setCursor(0,0);
          ANGELLO.write(byte(0));

          ANGELLO.setCursor(1,0);
          ANGELLO.write(byte(0));

          ANGELLO.setCursor(2,0);
          ANGELLO.write(byte(0));

          ANGELLO.setCursor(3,0);
          ANGELLO.write(byte(0));

          ANGELLO.setCursor(4,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(5,0);
          ANGELLO.write(byte(0)); 

          ANGELLO.setCursor(6,0);
          ANGELLO.write(byte(0)); 

          ANGELLO.setCursor(7,0);
          ANGELLO.write(byte(0));            
                    
          ANGELLO.setCursor(8,0);
          ANGELLO.write(byte(0));

          ANGELLO.setCursor(9,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(10,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(11,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(12,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(13,0);
          ANGELLO.write(byte(0));  

          ANGELLO.setCursor(14,0);
          ANGELLO.write(byte(0));    

          ANGELLO.setCursor(15,0);
          ANGELLO.write(byte(0));    

          delay(400);

          ANGELLO.setCursor(0,0);
          ANGELLO.write(byte(1));

          ANGELLO.setCursor(1,0);
          ANGELLO.write(byte(1));

          ANGELLO.setCursor(2,0);
          ANGELLO.write(byte(1));

          ANGELLO.setCursor(3,0);
          ANGELLO.write(byte(1));

          ANGELLO.setCursor(4,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(5,0);
          ANGELLO.write(byte(1)); 

          ANGELLO.setCursor(6,0);
          ANGELLO.write(byte(1)); 

          ANGELLO.setCursor(7,0);
          ANGELLO.write(byte(1));            
                    
          ANGELLO.setCursor(8,0);
          ANGELLO.write(byte(1));

          ANGELLO.setCursor(9,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(10,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(11,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(12,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(13,0);
          ANGELLO.write(byte(1));  

          ANGELLO.setCursor(14,0);
          ANGELLO.write(byte(1));    
          
          ANGELLO.setCursor(15,0);
          ANGELLO.write(byte(1));    
  
}
