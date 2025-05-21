#ifndef DD_FSM_H
#define DD_FSM_H

#include <Arduino.h>

#define TIMEOUT 5000u

#define STATE_1 &button_led_fsm[0]
#define STATE_2 &button_led_fsm[1]
#define STATE_3 &button_led_fsm[2]
#define STATE_4 &button_led_fsm[3]

#define STATE_RESET STATE_1

typedef enum
{
    LED_OFF = 0u,
    LED_ON,
    LED_HALF,
    LED_BLINK
} fsm_out_t;

typedef struct fsm 
{
    uint8_t RED_EAST_WEST : 1;
    uint8_t YELLOW_EAST_WEST : 1;
    uint8_t GREEN_EAST_WEST : 2;
    uint8_t RED_NORD_SOUTH : 1;
    uint8_t YELLOW_NORD_SOUTH : 1;
    uint8_t GREEN_NORD_SOUTH : 2;
} trafic_light_t;

typedef enum
{
    PRESSED = 0u,
    RELEASED
} fsm_input_t;

typedef struct fsm
{
    fsm_out_t teaffic_light_ew;
    fsm_out_t traffic_light_ns;
    fsm_out_t GREEN
    struct fsm *next_state[2];
} fsm_t;

void fsm_init(void);
void fsm_run(void);
void fsm_set_output(uint8_t led, fsm_out_t led_state);

#endif DD_FSM_H