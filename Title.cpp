#include"Title.h"
#include "SimpleAudioEngine.h"
#include "Option.h"
#define TRANSITION_TIME 1
USING_NS_CC;

Scene* Title::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Title::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}
bool Title::init()
{
	if (!LayerColor::init())
	{
		return false;
	}
	auto TLayer = Layer::create();
	this->addChild(TLayer);

	TITLE = Sprite::create("title.png");
	TITLE->setAnchorPoint(Vec2::ZERO);
	TITLE->setPosition(Vec2::ZERO);
	TLayer->addChild(TITLE);


	this->setTouchEnabled(true);//터치 활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);//멀티 터치 활성화     //ONE_BY_ONE은 싱글 터치

	return true;
}

void Title::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool Title::onTouchBegan(Touch* touch, Event* unused_event)
{
	//Option is GameMainScene
	auto scene = Option::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	return true;
}

