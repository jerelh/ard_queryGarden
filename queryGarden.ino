
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connecting DHT22
#define SOILPIN1 A0  // what analog pin we're connecting to soil monitor 1
#define SOILPIN2 A1  // what analog pin we're connecting to soil monitor 1
#define SOILPIN3 A2  // what analog pin we're connecting to soil monitor 1
#define SOILPIN4 A3  // what analog pin we're connecting to soil monitor 1
#define SOILPIN5 A4  // what analog pin we're connecting to soil monitor 1
#define WATERLEVEL A5   // what analog pin we're connecting to water level sensor

// Specifics for the DHT22 to work right
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  pinMode(DHTPIN, INPUT); //set up analog pin 1 to be input
  pinMode(SOILPIN1, INPUT); //set up analog pin 1 to be input
  pinMode(SOILPIN2, INPUT); //set up analog pin 1 to be input
  pinMode(SOILPIN3, INPUT); //set up analog pin 1 to be input
  pinMode(SOILPIN4, INPUT); //set up analog pin 1 to be input
  pinMode(SOILPIN5, INPUT); //set up analog pin 1 to be input
  pinMode(WATERLEVEL, INPUT); //set up analog pin 1 to be input

  dht.begin();

}

//dht.begin();

//char query[10];

void boxTemp() {
  float f = dht.readTemperature(true);
  if (isnan(f)) {
     Serial.println("Temperature read failed");
     return;
  }
  Serial.print("T:  ");
  Serial.print(f);
}

void boxHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
     Serial.println("Humidity read failed");
     return;
  }
  Serial.print("H:  ");
  Serial.print(h);
  
}

void soilMoisture1() {
  int s1 = analogRead(SOILPIN1);
  if (isnan(s1)) {
     Serial.println("Soil read failed");
     return;
  }
  Serial.print("S1:  ");
  Serial.print(s1);
  
}

void soilMoisture2() {
  int s2 = analogRead(SOILPIN2);
  if (isnan(s2)) {
     Serial.println("Soil read failed");
     return;
  }
  Serial.print("S2:  ");
  Serial.print(s2);
  
}

void soilMoisture3() {
  int s3 = analogRead(SOILPIN3);
  if (isnan(s3)) {
     Serial.println("Soil read failed");
     return;
  }
  Serial.print("S3:  ");
  Serial.print(s3);
  
}

void soilMoisture4() {
  int s4 = analogRead(SOILPIN4);
  if (isnan(s4)) {
     Serial.println("Soil read failed");
     return;
  }
  Serial.print("S4:  ");
  Serial.print(s4);
  
}

void soilMoisture5() {
  int s5 = analogRead(SOILPIN5);
  if (isnan(s5)) {
     Serial.println("Soil read failed");
     return;
  }
  Serial.print("S5:  ");
  Serial.print(s5);
  
}

void waterLevel() {
  int w = analogRead(WATERLEVEL);
  if (isnan(w)) {
     Serial.println("Water leavel read failed");
     return;
  }
  Serial.print("W:  ");
  Serial.print(w);
}




void loop() {
  if (Serial.available()) {
    int query = Serial.read();
    switch (query) {
      case 1:
        boxTemp();
        break;
      case 2:
        boxHumidity();
        break;
      case 3:
        soilMoisture1();
        break;
      case 4:
        soilMoisture2();
        break;
      case 5:
        soilMoisture3();
        break;
      case 6:
        soilMoisture4();
        break;
      case 7:
        soilMoisture5();
        break;
      case 8:
        waterLevel();
        break;
    }

  }

delay(1000);

}



