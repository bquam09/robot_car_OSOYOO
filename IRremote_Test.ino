//Use the IRremote_Test code to view IR signals from other remotes.
//The code writes the HEX value in the serial monitor at baud rate 9600.

#include <IRremote.h>

int IRPIN = 2;

IRrecv irrecv(IRPIN);

decode_results result;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&result))
  {
    Serial.print("Value: ");
    Serial.println(result.value, HEX);
    irrecv.resume();
  }
  delay(500);
}
