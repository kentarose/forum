#include "Quest.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
#pragma execution_character_set("utf-8")

USING_NS_CC;

Scene* Quest::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = Quest::create();
	// add layer as a child to scene
	scene->addChild(layer);
	return scene;
}

bool Quest::onTouchBegan(Touch * touch, Event * unsued_event)
{
	log("%f %f", touch->getLocation().x, touch->getLocation().y);
	return true;
}

bool Quest::init()
{
	if (!LayerColor::init())	
	{
		return false;
	}
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	quest_shit = RandomHelper::random_int(0, 2);

	auto work_ready = Label::createWithTTF("업무 준비", "NanumGothic.ttf", 50);
	work_ready->setPosition(Vec2(150, 670));
	this->addChild(work_ready, 1);

	auto quest = Label::createWithTTF("퀘스트", "NanumGothic.ttf", 80);
	quest->setPosition(Vec2(640, 650));
	this->addChild(quest, 1);

	auto Box = Sprite::create("Box.png");
	Box->setPosition(Vec2(640, 360));
	Box->setScale(1.5, 3);
	this->addChild(Box, 0);

	auto yes = MenuItemImage::create("btn.png", "btn_c.png", CC_CALLBACK_1(Quest::menuCloseCallback, this));
	yes->setScale(1);
	
	auto Q_mydragon = Label::createWithTTF("null", "NanumGothic.ttf", 40, Size::ZERO, TextHAlignment::CENTER);
	Q_mydragon->setPosition(Vec2(640, 360));
	Q_mydragon->setColor(Color3B::BLACK);
	Q_mydragon->setWidth(755);
	this->addChild(Q_mydragon, 3);
	switch (2)
	{
	case 0:
		Q_mydragon->setString("잘못 검사 하지 않기");
		break;
	case 1:
		Q_mydragon->setString("하루 안에 일정 개수 이상의 가게 검사하기");
		break;
	case 2:
		Q_mydragon->setString("일정 시간 안까지 일정 개수 이상의 가게 정상적으로 검사하기");
		break;
	}



	auto menu = Menu::create(yes, NULL);
	menu->setPosition(Vec2(640, 50));
	this->addChild(menu, 2);

	UserDefault::getInstance()->setIntegerForKey("quest", quest_shit);
	UserDefault::getInstance()->flush();

	return true;
}

void Quest::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}