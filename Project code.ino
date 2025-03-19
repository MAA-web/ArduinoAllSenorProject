#include <DHT.h>
#include <Servo.h>

#define DHTPIN 2          
#define DHTTYPE DHT11     
#define FAN 3             
#define HEATER 4         
#define LIGHT 5           
#define LDR A0            
#define WATER_LEVEL A1    
#define LIGHT_THRESHOLD 500 

DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

void setup() {
    Serial.begin(9600);
    dht.begin();
    myServo.attach(6); 
    pinMode(FAN, OUTPUT);
    pinMode(HEATER, OUTPUT);
    pinMode(LIGHT, OUTPUT);
    pinMode(LDR, INPUT);
    pinMode(WATER_LEVEL, INPUT);
}

void loop() {
    float temp = dht.readTemperature();
    int ldrValue = analogRead(LDR);
    int waterLevel = analogRead(WATER_LEVEL);
    
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");
    
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);
    
    Serial.print("Water Level: ");
    Serial.println(waterLevel);
    
    
    if (temp > 25) {
        digitalWrite(FAN, HIGH);
        Serial.println("Fan: ON");
    } else {
        digitalWrite(FAN, LOW);
        Serial.println("Fan: OFF");
    }
    
    if (temp < 10) {
        digitalWrite(HEATER, HIGH);
        Serial.println("Heater: ON");
    } else {
        digitalWrite(HEATER, LOW);
        Serial.println("Heater: OFF");
    }
    
   
    if (ldrValue < LIGHT_THRESHOLD) {
        digitalWrite(LIGHT, HIGH);
        Serial.println("Light: ON");
    } else {
        digitalWrite(LIGHT, LOW);
        Serial.println("Light: OFF");
    }
    
    
    myServo.write(180);
    delay(500);
    myServo.write(0);
    delay(500);
    
    Serial.println("----------------------");
    delay(2000); 
}
