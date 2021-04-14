#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
    memcpy(Last, Current, sizeof(Current));

    for (int i = 0; i < 256; i++)
    {
        Current[i] = false;
        if (GetAsyncKeyState(i))
        {
            Current[i] = true;
        }
    }
}

bool InputManager::KeyDown(BYTE key)
{
    return Current[key] && !Last[key];
}

bool InputManager::KeyUp(BYTE key)
{
    return !Current[key] && Last[key];

}

bool InputManager::KeyPress(BYTE key)
{
    return Current[key] && Last[key];

}