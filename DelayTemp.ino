#include <TimerOne.h>

void Timer1_ISR(void)
{
  digitalWrite(13, !digitalRead(13));
}

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);  /*Temperature sensor LM35 pin*/ 
  pinMode(13, OUTPUT); /*The LED BULTIN is 13th pin*/

}

void loop() {
  int Adc_temp;
  float temp;
  Adc_temp = analogRead(A0);  /* To read Temperature for LM35 sensor */
  temp = (Adc_temp* 4.88); /* Convert adc value to equivalent voltage */
  temp = (temp/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("°C\n");

 /* Blink LED with 250ms delay */
  if(temp<30)
  {
  Timer1.initialize(250000);    /* An Interrupt for every 250ms */
  Timer1.attachInterrupt(Timer1_ISR);
  }
 /* Blink LED with 500ms delay */
  if(temp>30)
  {
  Timer1.initialize(500000);  /* An Interrupt for every 500ms */
  Timer1.attachInterrupt(Timer1_ISR);
  }
  
}
