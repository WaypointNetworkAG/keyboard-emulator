#include "keyboard.h"

Keyboard::Keyboard()
{
    Serial.begin(9600);
}

void Keyboard::pressKey(KEY key)
{
    this->_buf[2] = key;
    Serial.write(this->_buf, 8);
    _releaseKey();
}

void Keyboard::_releaseKey()
{
    this->_buf[0] = 0;
    this->_buf[2] = 0;
    Serial.write(this->_buf, 8);
}