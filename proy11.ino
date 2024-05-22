#include <SoftwareSerial.h> //Incluimos la libreria Software Serial

//Creado por youtube/ElTallerDeTD
//eltallerdetd@gmail.com

SoftwareSerial SIM800L(2,3); //Instanciamos el objeto SIM800L y le pasamos los parametros de los pines TX y RX
String valor;  //Declaramos la variable de tipo String valor.
void setup() {
  pinMode(13, OUTPUT); //Declarar el pin 13 como salida.
  Serial.begin(9600); //Inicializamos la primera comunicacion Serial.
  SIM800L.begin(9600); //Inicializamos la segunda comunicacion Serial.
  SIM800L.println("AT+CMGF=1"); //Vamos utilizar los SMS.
  delay(100); //Delay de 0.1 sec
  SIM800L.println("AT+CNMI=1,2,0,0,0"); //Configurar el SIM800L p/ que muestre msm por com. serie.
}

void loop() {
  //Lograr que nos muestre lo que nos llega de mensaje por el monitor serial.
  if(SIM800L.available()){
    valor = SIM800L.readString(); //Guardar en la var valor el sms que recibe el Arduino
    //Serial.println("Nuevo SMS: "+ valor); //Imprime ese SMS en el monitor Serial
  }
  if(valor.indexOf("ON")>=0){  //Si la var valor tiene la palabra ON hace esto:
    digitalWrite(13, HIGH);    //Se enciende el pin 13.
    Serial.println("El Led se encendio");  //Immprime el mensaje
    delay(15000);
  }else{
    digitalWrite(13, LOW);    //Se apaga el pin 13.
    Serial.println("El Led se apago");  //Immprime el mensaje
    delay(15000);
  
  }
  
}