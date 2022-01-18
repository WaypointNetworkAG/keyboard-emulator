/* Author: Noa Sendlhofer - noa.sendlhofer@wpn.ch
 * Desc: Controllino code main file
 */

#include <Controllino.h>
#include "button.h"
#include "keyboard.h"

bool g_status_flag = true;

Button* button1;
Button* button2;
Button* button3;
Button* button4;
Button* button_shutdown;

void setup() {
    auto keyboard = std::make_shared<Keyboard>();
    button1 = new Button(keyboard, g_status_flag, CONTROLLINO_A0, KEY_1);
    button2 = new Button(keyboard, g_status_flag, CONTROLLINO_A1, KEY_2);
    button3 = new Button(keyboard, g_status_flag, CONTROLLINO_A2, KEY_3);
    button4 = new Button(keyboard, g_status_flag, CONTROLLINO_A3, KEY_4);
    button_shutdown = new Button(keyboard, g_status_flag, CONTROLLINO_IN0, KEY_NUM_0);
}

void loop() {
    button1->update();
    button2->update();
    button3->update();
    button4->update();
    button_shutdown->update();

    delay(50);
}