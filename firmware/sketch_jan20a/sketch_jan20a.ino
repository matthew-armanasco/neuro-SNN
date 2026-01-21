void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for(int i = 2; i <= 11; i++) pinMode(i, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() >= 10){
    for(int i = 0; i <= 10; i++){
      char c = Serial.read();
      digitalWrite(i+2, (c=='1') ? HIGH : LOW);
    }
  }
}
