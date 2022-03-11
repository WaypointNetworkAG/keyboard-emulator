/* Author: Noa Sendlhofer - noa.sendlhofer@wpn.ch
 * Desc: Button class header
 */

#ifndef KEYBOARD_EMULATOR_BUTTON_
#define KEYBOARD_EMULATOR_BUTTON_

#include "keyboard.h"

class Button
{
    public:
        Button(std::shared_ptr<Keyboard> &keyboard, bool &g_status_flag, int port, int key);
        Button(std::shared_ptr<Keyboard> &keyboard, bool &g_status_flag, int port, int *keys, int length);
        void update();

    private:
        std::shared_ptr<Keyboard> keyboard;

        void _sendCommand();

        int port;
        int *keys;

        int _key_idx = 0;
        int _key_length;
        bool _multi_key;

        bool _pressed;
        bool* g_status_flag;
};


#endif //KEYBOARD_EMULATOR_BUTTON_