#define ledPin 13
int data = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.print(78);
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0){
    data = Serial.read(); 
 
          if (data == '0') {
            digitalWrite(ledPin, LOW);
          }
          else if (data == '1') {
          Serial.print(78); 
          digitalWrite(ledPin, HIGH);
          } 
  }
}
