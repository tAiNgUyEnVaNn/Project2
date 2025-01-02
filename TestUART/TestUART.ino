void setup() {
  Serial.begin(9600); // Initialize UART with baud rate 9600
}

void loop() {
  if (Serial.available() > 0) {
    String tempData = "";  // Buffer to store received data
    while (Serial.available() > 0) {
      char c = Serial.read(); // Read each character from ATmega16
      tempData += c;         // Append to buffer
      delay(10);             // Small delay to ensure data stability
    }
    Serial.println(tempData); // Display received temperature on Serial Monitor
  }
}
