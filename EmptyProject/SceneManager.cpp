#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager()
	: m_nowScene(nullptr), m_nextScene(nullptr)
{
}


SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::Release()
{
	if (m_nowScene) {
		m_nowScene->Release();
		OBJECT->Release();
	}

	for (auto iter : m_scenes)
	{
		SAFE_DELETE(iter.second);
	}
	m_scenes.clear();
}
Scene * SceneManager::AddScene(const string & key, Scene * scenePtr)
{
	if (!scenePtr)//� ������ ���� ���� �־����� �߰����� �ʴ´�
		return nullptr;

	if (m_scenes.find(key) != m_scenes.end())//�̸��� ��ġ�� �ص� �߰����� �ʴ´�
		return nullptr;

	m_scenes.insert(make_pair(key, scenePtr));//���� ������ ������� ������ �߰��Ѵ�
	return scenePtr;
}

Scene * SceneManager::ChangeScene(const string & key)
{
	auto find = m_scenes.find(key);
	if (find == m_scenes.end())
		return nullptr;//���� �����δ� �ٲ��� �ʴ´�

	OBJECT->ClearAllObjects();
	m_nextScene = find->second;//�ٲ� ���� �����صд�
	return m_nextScene;
}

void SceneManager::Update()
{
	if (m_nextScene)//������� ���� �ִ��� Ȯ���غ���
	{
		if (m_nowScene) {//���� ���� ������
			m_nowScene->Release();//����ְ�
			OBJECT->Release();
		}
		m_nextScene->Init();
		m_nowScene = m_nextScene;//���� �ٲ��ش�
		m_nextScene = nullptr;
	}
	if (m_nowScene)
		m_nowScene->Update();
}

void SceneManager::Render()
{
	if (m_nowScene)
		m_nowScene->Render();
}
