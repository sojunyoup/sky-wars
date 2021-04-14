#pragma once
#include "Object.h"
#include "Collider.h"
#include "singleton.h"

class Collider;
class ObjectManager : public singleton<ObjectManager>
{
    friend class Object;

    friend class cObject;

    list<Object*> ObjList[Tag::END];
    list<Collider*> ColliderList;

public:
    bool collisionTag[Tag::END + 1][Tag::END + 1];
    ObjectManager();

    virtual ~ObjectManager();

    Object* AddObject(const string& _Key, Object* _obj, Vector2 m_Pos, Tag _objTag)
    {
        _obj->Init();
        _obj->m_Tag = _objTag;
        _obj->vPos = m_Pos;
        _obj->m_Key = _Key;
        ObjList[_objTag].emplace_back(_obj);
        return _obj;
    }
    Object* FindObject(const string& _Key)
    {
        for (auto iter1 = 0; iter1 != Tag::END; iter1++)
            for (auto& iter2 : ObjList[iter1])
            {
                if (iter2->m_Key == _Key)
                {
                    return iter2;
                }
            }
    }

    void AddCollision(Collider* _collider) { ColliderList.emplace_back(_collider); }

    Vector2 vPos;
    float score;
    int option = 0;
    float pHp;
    int playchoice = 0;
    bool isoff = false;
    bool isguideon = false;

    //스킬
    float isskill1 = 0;
    float isskill2 = 1;
    float isskill3 = 1;

    //가이드 페이지 체크
    bool isguide = false;
    
    //아이템
    float item = 3;
    float hilltem = 3;

    bool isBoss = false;

    bool pause = false;

    int EnemyCount = 0;

    void Update();
    void Render();
    void Release();
    void CollisionCheck(Object* Object);


    int IsMapOut(Object* obj)
    {
        if (obj->m_Tag == MOUSE || obj->m_Tag == UI)
        {
            return false;
        }
        else {
            return (obj->vPos.x < -10
                || obj->vPos.x  > 1400
                || obj->vPos.y < -300
                || obj->vPos.y  > WINSIZEY + 50);
        }
    }
    void ObjectManager::ClearAllObjects();


};

#define OBJECT ObjectManager::GetInstance()