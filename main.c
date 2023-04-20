#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/bootrom.h"

const uint LED_PIN = 25;
const uint START_BUTTON_PIN = 18;
const uint RESET_BUTTON_PIN = 19;

int main() {

    bi_decl(bi_program_description("First Blink"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    gpio_init(LED_PIN);
    gpio_init(START_BUTTON_PIN);
    gpio_init(RESET_BUTTON_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(START_BUTTON_PIN, GPIO_IN);
    gpio_set_dir(RESET_BUTTON_PIN, GPIO_IN);

    // Enable internal pull-up for buttons
    gpio_pull_up(START_BUTTON_PIN);
    gpio_pull_up(RESET_BUTTON_PIN);

    while (1) {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        // Check if start button is pressed
        if (gpio_get(START_BUTTON_PIN) == 0) {
            // Reboot the board
            reset_usb_boot(0,0);
        }
    }
}