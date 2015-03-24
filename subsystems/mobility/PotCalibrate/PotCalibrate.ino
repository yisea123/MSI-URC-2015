void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating Front Left");
   ma = 0; mi = 255;
}

int ma, mi;
void loop() {
 
  int ch;
  ch = analogRead(A9);
  ma = max(ch,ma) ;
  mi = min(ch,mi);
  Serial.print(ch);
  Serial.print("\t");
  Serial.print(ma);
  Serial.print("\t");
  Serial.print(mi);
  Serial.print("\n");
  delay(100);
}
