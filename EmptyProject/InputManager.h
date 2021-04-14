#pragma once
#include "singleton.h"
class InputManager :
    public singleton<InputManager>
{
public:
    InputManager();
    virtual ~InputManager();

    void Update();

    bool Current[256];
    bool Last[256];
    bool KeyDown(BYTE key);
    bool KeyUp(BYTE key);
    bool KeyPress(BYTE key);
};

#define INPUT InputManager::GetInstance()