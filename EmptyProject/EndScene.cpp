#include "DXUT.h"
#include "EndScene.h"

EndScene::EndScene()
{
	i = 0;
	j = 0;
	x = 0;
}

EndScene::~EndScene()
{
}

void EndScene::Init()
{
	color = {
		255,255,255,255
	};
	scoreCH++;
	score2 = (int)OBJECT->score;
}

void EndScene::Update()
{
	if (scoreCH == 1) {
		i = score2;
	}
	else if (scoreCH == 2) {
		j = score2;
	}
	else if (scoreCH == 3) {
		x = score2;
	}
	if (scoreCH == 4) {
		i = 0;
	}
	if (i > j && i > x) {
		sprintf(oneT, "%d", i);
		if (j > x) {
			sprintf(twoT, "%d", j);
			sprintf(threeT, "%d", x);
		}
		else {
			sprintf(twoT, "%d", x);
			sprintf(threeT, "%d", j);
		}
	}
	else if (j > i&& j > x) {
		sprintf(oneT, "%d", j);
		if (i > x) {
			sprintf(twoT, "%d", i);
			sprintf(threeT, "%d", x);
		}
		else {
			sprintf(twoT, "%d", x);
			sprintf(threeT, "%d", i);
		}
	}
	else if (x > j&& x > i) {
		sprintf(oneT, "%d", x);
		if (i > j) {
			sprintf(twoT, "%d", i);
			sprintf(threeT, "%d", j);
		}
		else {
			sprintf(twoT, "%d", j);
			sprintf(threeT, "%d", i);
		}
	}
	if (INPUT->KeyDown(VK_RETURN)) {
		SCENE->ChangeScene("title");
	}
	CAMERA->SetCamera({ WINSIZEX / 2,WINSIZEY / 2 });
}

void EndScene::Render()
{
	IMAGE->FindImage("Main_BG")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->FindImage("Ranking")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->drawText(oneT, one, 100, color, false);
	IMAGE->drawText(twoT, two, 100, color, false);
	IMAGE->drawText(threeT, three, 100, color, false);

}

void EndScene::Release()
{
}
