#pragma once

//#pragma comment(lib, "winmn")
#pragma comment(lib, "dsound.lib")
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <chrono>
#include <Digitalv.h>
#include <mmsystem.h>
#include <mutex>

using namespace std;
using namespace chrono;

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime() * TimeScale


#ifdef _DEBUG
void DEBUG_LOG(LPCSTR fmt, ...);
#endif

#define GetNowTime system_clock::now()

const int WINSIZEX = 1600;
const int WINSIZEY = 900;

static float TimeScale = 1;
static bool isWindowed = true;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;

//¸Å´ÏÀú
#include "ImageManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "Math.h"
#include "ObjectManager.h"
#include "Timer.h"