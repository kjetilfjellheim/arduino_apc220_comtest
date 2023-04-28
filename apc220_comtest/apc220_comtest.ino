
char* COMMAND = "Command\0";
char* RESPONSE = "OK\0";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  if (Serial1.availableForWrite()) {
    Serial1.write(COMMAND);
    Serial1.flush();
    Serial.println("Command sent");
  }
  delay(100);
  if (Serial2.available()) {
    String received = Serial2.readStringUntil('\0');
    if (received.equals(COMMAND)) {
      Serial.println("Command received");
      Serial2.write(RESPONSE);
      Serial2.flush();
      Serial.println("Response sent");
    }    
  }
  delay(100);
  if (Serial1.available()) {
    String received = Serial1.readStringUntil('\0');
    Serial.println(received);
    if (received.equals(RESPONSE)) {
      Serial.println("Response was received"); 
    }       
  }
}
