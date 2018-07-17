/* Arduino A0 nolu analog girişine uygulanan voltajın (max. 5 v.)
 * yaklaşık olarak değerini ekranda gösterecektir.
 * Ayrıca volume level simgeleri şiddete göre ayarlanacaktır.
 *
 *                       *** DİKKAT!! ***
 * ARDUINO GİRİŞLERİNE 5 VOLTTAN DAHA YÜKSEK BİR GERİLİM UYGULAMAYINIZ.
 */

#include <PT6523.h>

PT6523 lcd;

char ss[2];
char sss[2];
int val = 0;
float volt;

void setup() {
  lcd.begin(10, 130);
  lcd.volumeStartValue(0);
  lcd.volumeEndValue(1023);
}

void loop() {
  lcd.speed(100);
  val = analogRead(0);
  volt = val * 0.005;
  dtostrf(volt, 4, 2, ss);
  sprintf(sss, "%s V", ss);
  lcd.text(sss);
  lcd.volumeLevel(val);
  // delay(70);
}
