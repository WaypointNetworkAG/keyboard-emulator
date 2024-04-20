/* Author: Noa Sendlhofer - noa.sendlhofer@wpn.ch
 * Desc: Button class implementation
 */

#include "button.h"

Button::Button(std::shared_ptr<Keyboard>& keyboard, bool& g_status_flag, int port, int key)
{
    this->keyboard = keyboard;
    this->g_status_flag = &g_status_flag;
    this->port = port;
    this->key1 = key;
    this->_multi_key = false;

    pinMode(this->port, INPUT);
}

Button::Button(std::shared_ptr<Keyboard> &keyboard, bool &g_status_flag, int port, int key1, int key2, int key3, int key4)
{
    this->keyboard = keyboard;
    this->g_status_flag = &g_status_flag;
    this->port = port;
    this->key1 = key1;
    this->key2 = key2;
    this->key3 = key3;
    this->key4 = key4;
    this->_multi_key = true;

    pinMode(this->port, INPUT);
}

void Button::update()
{
    int status = digitalRead(this->port);

    if (status == HIGH && *this->g_status_flag)
    {
        _sendCommand();
        *this->g_status_flag = false;
        this->_pressed = false;
    } 
    else if (status == LOW && !this->_pressed)
    {
        *this->g_status_flag = true;
        this->_pressed = true;
    }
}



void Button::_sendCommand()
{
    /*
    if (this->_multi_key)
    {
        if (this->_key_idx >= this->_key_length)
        {
            this->_key_idx = 0;
        }
        //this->keyboard->pressKey(*(this->keys + this->_key_idx));
        Serial.println(String(*(this->keys + this->_key_idx)));
        this->_key_idx++;
    }
    else
    {
        //this->keyboard->pressKey(*this->keys);
        Serial.println(String(*(this->keys)));
    }
    */

    if (this->_multi_key)
    {
        if (this->_key_idx >= this->_key_length)
        {
            this->_key_idx = 0;
        }

        if(this->_key_idx == 0)
        {
            this->keyboard->pressKey(key1);
        }
        else if (this->_key_idx == 1)
        {
            this->keyboard->pressKey(key2);
        }
        else if (this->_key_idx == 2)
        {
            this->keyboard->pressKey(key3);
        }
        else if (this->_key_idx == 3)
        {
            this->keyboard->pressKey(key4);
        }
        
        this->_key_idx++;
    }
    else
    {
        this->keyboard->pressKey(key1);
    }
}
