#include <SoftwareSerial.h> //  libreria Software Serial
char phone[]="1161855716";
int pulsador=8;
int led=13;
SoftwareSerial SIM800L(1,2); //Instancia el objeto SIM800L y le pasamos los parametros de los pines TX y RX
String valor;  //Declaro la variable de tipo String valor.

void setup() {
  pinMode(13, OUTPUT); //Declaro el pin 13 como salida.
  Serial.begin(9600); //Inicio la primera comunicacion Serial.
  SIM800L.begin(9600); //Inicializo la segunda comunicacion Serial.
  SIM800L.println("AT+CMGF=1"); //para utilizar los SMS.
  delay(100); //Delay de 0.1 sec
  SIM800L.println("AT+CNMI=1,2,0,0,0"); //Configurar el SIM800L p/ que muestre msm por com. serie.
}

void loop() {
 digitalWrite(led,LOW); 

//if(valor.length()>=0){ 

    //valor = SIM800L.readString(); //Guardar en la var valor el sms que recibe el Arduino
//    Serial.println("Nuevo SMS: "+ valor.length()); //Imprime ese SMS en el monitor Serial
//    digitalWrite(led,HIGH);
//  }



if(SIM800L.available()){

    valor = SIM800L.readString(); //Guardar en la var valor el sms que recibe el Arduino
    Serial.println("Nuevo SMS: "+ valor.length()); //Imprime ese SMS en el monitor Serial
    digitalWrite(led,HIGH);
  }

if (digitalRead(pulsador)==HIGH){
  digitalWrite(led,HIGH);
Serial.begin(9600);
  delay(2000);
  Serial.println("AT");
  delay(2000);
  Serial.print("ATD");
  Serial.print(phone);
   
  Serial.println(";");
  delay(80000);
  Serial.println("ATH");
  digitalWrite(led,LOW);
 }


  }