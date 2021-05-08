const int AirValue = 520;   
const int WaterValue = 260;  
int intervals = (AirValue - WaterValue)/3;   
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600); // serial port setup
  pinMode(5, OUTPUT); // GREEN
  pinMode(0, OUTPUT); // BLUE 
  pinMode(4, OUTPUT); // RED
  
}

void loop() {
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) { 
      Serial.println("Very Wet");
      digitalWrite(5, LOW);
      digitalWrite(0, LOW);
      digitalWrite(4, HIGH);
       
    } else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals)){
         Serial.println("Wet");
        digitalWrite(4, LOW);
        digitalWrite(0, LOW);
        digitalWrite(5, HIGH);
         
      } else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals)){
            Serial.println("Dry");
            digitalWrite(5, LOW);
            digitalWrite(4, LOW);
            digitalWrite(0, HIGH);
          }
  delay(100);
  digitalWrite(5, HIGH);
}
