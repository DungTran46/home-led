#ifndef LED_H
#define LED_H
#endif

#ifdef __cplusplus
extern "C" {
#endif
//LED definition
#define LED_RED 22
#define LED_BLUE 23

//timing
#define DEFALT__BLINK_TIME 1000
#define TIMEOUT_LIMIT 10

void normalMode(int t);


/*
 * blink the red led
 * @t time in minisecond
 *  return nothing
 */
void blink_red(int t);


/*
 * blink the red blue
 * @t time in minisecond
 *  return nothing
 */
 void blink_blue(int t);


/*
 * blink the red and the blue
 * @t time in minisecond
 *  return nothing
 */
void blink_both(int t);


void off_both(int t);

#ifdef __cplusplus
}
#endif