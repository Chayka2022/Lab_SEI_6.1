#include "dd_fsm.h"


fsm_t button_led_fsm[] = 
{
    {LED_OFF, PRESSED, 0, {STATE_2, STATE_1}}, 
    {LED_ON, PRESSED, 5000, {STATE_3, STATE_1}},
    {LED_HALF, PRESSED, 5000, {STATE_4, STATE_1}},
    {LED_BLINK, PRESSED, 0, {STATE_1, STATE_1}},
};

static fsm_t *current_state;

void fsm_run(void)
{
    static uint32_t last_time_debounce = 0;
    static uint32_t timeout = 0;

    if (digitalRead(BUTTON_PIN == LOW))
    {
        if (millis() > last_time_debounce)
        {
            last_time_debounce = millis() + DEBOUNCE_TIME;

            if(timeout > current)
        }
    }
}

void fsm_init()
{
    current_state = STATE_RESET;

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void fsm_run