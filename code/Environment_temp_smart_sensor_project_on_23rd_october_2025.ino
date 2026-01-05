#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temp_reading;
int ledpin = 10;
int buzzpin = 9;
int delay_time = 250;
int pho_res = A0;
int pho_res_reading;

void setup() {
  // put your setup code here, to run once:
dht.begin();
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
pinMode(buzzpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

temp_reading = dht.readTemperature();
pho_res_reading = analogRead(pho_res);

Serial.print("The current temperature reading of the environment is: \t");
Serial.print(temp_reading);
Serial.print(" The current reading from the photoresistor is: \t");
Serial.println(pho_res_reading);

if(isnan(temp_reading)){
  Serial.print("Failed to read from the temperature sensor");
  return;
}

if(temp_reading >= 38){
  digitalWrite(buzzpin, HIGH);
  for(int i = 0; i < 5; i++){
  digitalWrite(ledpin, HIGH);
  delay(delay_time);
  digitalWrite(ledpin, LOW);
}
digitalWrite(buzzpin, LOW);
 }
 else{digitalWrite(uint8_t pin, uint8_t val)
  digitalWrite(9ledpin, LOW);
 }

 if(pho_res_reading < 150){
  digitalWrite(ledpin, HIGH);
 }
 else{
  digitalWrite(ledpin, LOW);
 }
 
delay(delay_time);

}
