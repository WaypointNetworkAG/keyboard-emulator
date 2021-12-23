/* Author: Noa Sendlhofer - noa.sendlhofer@wpn.ch
 * Desc: Button class header
 */

#ifndef KEYBOARD_EMULATOR_BUTTON_
#define KEYBOARD_EMULATOR_BUTTON_

#include "keyboard.h"

typedef int PORT;

class Button
{
    public:
        Button(std::shared_ptr<Keyboard>& keyboard, bool& g_status_flag, PORT port, KEY key);
        void update();

    private:
        std::shared_ptr<Keyboard> keyboard;

        PORT port;
        KEY key;

        bool _pressed;
        bool* g_status_flag;
};


#endif //KEYBOARD_EMULATOR_BUTTON_