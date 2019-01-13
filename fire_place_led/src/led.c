#include "../led.h"
#include <Arduino.h>

void normalMode(int t)
{
    // put your main code here, to run repeatedly:
    blink_red(t);
    blink_blue(t);
    blink_both(t);
    off_both(t);
}
/*
 * blink the red led
 * @t time in minisecond
 *  return nothing
 */
void blink_red(int t)
{
  digitalWrite(LED_RED, HIGH);
  delay(t);
  digitalWrite(LED_RED, LOW);
}

/*
 * blink the red blue
 * @t time in minisecond
 *  return nothing
 */
 void blink_blue(int t)
{
  digitalWrite(LED_BLUE, HIGH);
  delay(t);
  digitalWrite(LED_BLUE, LOW);
}
/*
 * blink the red and the blue
 * @t time in minisecond
 *  return nothing
 */
void blink_both(int t)
{
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  delay(t);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
}

void off_both(int t)
{  
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  delay(t);
}