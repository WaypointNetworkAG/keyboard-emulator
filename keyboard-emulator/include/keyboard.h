/* Author: Noa Sendlhofer - noa.sendlhofer@wpn.ch
 * Desc: Keyboard class header
 */

#ifndef KEYBOARD_EMULATOR_KEYBOARD_
#define KEYBOARD_EMULATOR_KEYBOARD_

#include "Arduino.h"
#include <ArxSmartPtr.h>
#include "hid_keys.h"

typedef int KEY;

class Keyboard
{
    public:
        Keyboard();
        void pressKey(KEY key);

    private:
        void _releaseKey();

        uint8_t _buf[8] = { 0 };
};

#endif // KEYBOARD_EMULATOR_KEYBOARD_