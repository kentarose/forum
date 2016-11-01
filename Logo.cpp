#include"Title.h"
#include "SimpleAudioEngine.h"
#include "Option.h"
#include "Logo.h"
#define TRANSITION_TIME 1
USING_NS_CC;
using namespace CocosDenshion;

Scene* Logo::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Logo::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}
bool Logo::init()
{
	if (!LayerColor::init())
	{
		return false;
	}

	auto TLayer = Layer::create();
	this->addChild(TLayer);

	auto GLayer = Layer::create();
	this->addChild(GLayer);

	LOGO = Sprite::create("igo.png");
	//LOGO->setAnchorPoint(Vec2(0.5,0.5));
	LOGO->setPosition(Vec2(640,560));
	LOGO->setOpacity(0);
	TLayer->addChild(LOGO);


	LOGO_2 = Sprite::create("fucking.png");
	LOGO_2->setPosition(Vec2(640, 260));
	LOGO_2->setOpacity(0);
	GLayer->addChild(LOGO_2);


	
	count = 0;

	this->schedule(schedule_selector(Logo::Go_main), 1.0f);
//	this->scheduleOnce(schedule_selector(Logo::Go_main),0.0f);
	return true;
}

void Logo::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void Logo::Go_main(float f)
{

	count++;

	switch (count)
	{
	case 1:
		LOGO->runAction(FadeIn::create(1.4f));
		break;
	case 2:
		LOGO_2->runAction(FadeIn::create(1.4f));
		break;
	case 3:
		break;
	case 4:
		LOGO->runAction(FadeOut::create(0.5f));
		LOGO_2->runAction(FadeOut::create(0.5f));
		break;
	case 5:
		auto scene = Title::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		break;
	}
}
