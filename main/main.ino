
const int AirValue = 840;
const int WaterValue = 520;
int intervals = (AirValue - WaterValue)/3;   
int soilMoistureValue = 0;

void setup() {
  Serial.begin(115200); // serial port setup
  pinMode(5, OUTPUT); // GREEN
  pinMode(0, OUTPUT); // BLUE 
  pinMode(4, OUTPUT); // RED
  
}

void loop() {
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.println("Hallo ich bin Lukas und dumm und ein HS: " + String(soilMoistureValue));
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) {
  Serial.println("Very Wet");
            digitalWrite(5, LOW);
            digitalWrite(4, LOW);
            digitalWrite(0, HIGH);
  } else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Wet");
            digitalWrite(4, LOW);
            digitalWrite(0, LOW);
            digitalWrite(5, HIGH);
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  Serial.println("Dry");
            digitalWrite(5, LOW);
            digitalWrite(0, LOW);
            digitalWrite(4, HIGH);
}
delay(100);
}


/*          RED
 *          Serial.println("Dry");
            digitalWrite(5, LOW);
            digitalWrite(4, LOW);
            digitalWrite(0, HIGH);
            GREEN
            Serial.println("Wet");
            digitalWrite(4, LOW);
            digitalWrite(0, LOW);
            digitalWrite(5, HIGH);
            BLUE
            Serial.println("Very Wet");
            digitalWrite(5, LOW);
            digitalWrite(0, LOW);
            digitalWrite(4, HIGH);
*/
