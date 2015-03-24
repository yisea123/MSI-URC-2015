void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(A9));
  Serial.print("\t");
  Serial.print(analogRead(A4));
  Serial.print("\t");
  Serial.print(analogRead(A10));
  Serial.print("\t");
  Serial.print(analogRead(A3));
  Serial.print("\n");
  delay(100);
}
