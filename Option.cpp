﻿#include "Option.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

Scene* Option::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Option::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}
bool Option::init()
{
	if (!LayerColor::init())
	{
		return false;
	}
	isoption = false;
	/*auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);


	SimpleAudioEngine::getInstance()->playBackgroundMusic("mercy.wav", true);


	if (UserDefault::getInstance()->getBoolForKey("bgm") == true)
		//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.0f);

    SLayer = Layer::create();
	this->addChild(SLayer, 2);

	auto BLayer = Layer::create();
	this->addChild(BLayer);

	auto MLayer = Layer::create();
	this->addChild(MLayer);

	UserDefault::getInstance()->setIntegerForKey("money", 1000);
	UserDefault::getInstance()->flush();
	int mon = UserDefault::getInstance()->getIntegerForKey("money");

	isbgmoff = UserDefault::getInstance()->getBoolForKey("bgm");
	isegmoff = UserDefault::getInstance()->getBoolForKey("eff");
	
	auto Game_Exit = MenuItemImage::create("Game_Exit.png", "Game_Exit.png", CC_CALLBACK_1(Option::Go_Option, this));
	//Game_Exit->setAnchorPoint(Vec2::ZERO);
	Game_Exit->setScale(0.8);
	Game_Exit->setPosition(Vec2(640, 200));

	auto Game_Go2 = MenuItemImage::create("game_go.png", "game_go.png", CC_CALLBACK_1(Option::Go_Option, this));
	//Game_Go2->setAnchorPoint(Vec2::ZERO);
	Game_Go2->setScale(0.6);
	Game_Go2->setPosition(Vec2(200, 50));
	
	auto option = MenuItemImage::create("Option.png", "Option.png", CC_CALLBACK_1(Option::Option_on, this));
	//option->setAnchorPoint(Vec2::ZERO);
	option->setScale(0.6);
	option->setPosition(Vec2(640, 50));

	auto sumaho = MenuItemImage::create("smart_phone.png", "smart_phone.png", CC_CALLBACK_1(Option::Go_Option, this));
	//sumaho->setAnchorPoint(Vec2::ZERO);
	sumaho->setScale(0.6);
	sumaho->setPosition(Vec2(1080, 50));

	//--------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------

	backsound_off = Sprite::create("sound_off.png");
	backsound_off->setPosition(420, 400);
	SLayer->addChild(backsound_off, 1);

	backsound_on = Sprite::create("sound_on1.png");
	backsound_on->setPosition(490,400);
	if (isbgmoff == true)
		backsound_on->setVisible(false);
	SLayer->addChild(backsound_on, 1);

	effectsound_off = Sprite::create("sound_off.png");
	effectsound_off->setPosition(860,400);
	SLayer->addChild(effectsound_off, 1);

	effectsound_on = Sprite::create("sound_on1.png");
	effectsound_on->setPosition(930, 400);
	if (isegmoff == true)
		effectsound_on->setVisible(false);
	SLayer->addChild(effectsound_on, 1);

	auto exit = MenuItemImage::create("exit.png", "exit.png", CC_CALLBACK_1(Option::Option_off, this));

	auto BG = Sprite::create("Set_BG.png");
	BG->setPosition(640, 360);
	BG->setScale(1.5, 1.0);
	SLayer->addChild(BG, 0);

	SLayer->setVisible(false);
	SLayer->setScale(0.8);
	SLayer->setPosition(Vec2(0, 0));

	//--------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------

	auto S_menu = Menu::create(exit, NULL);
	S_menu->setPosition(1050, 580);
	SLayer->addChild(S_menu, 1);

	auto menu = Menu::create(Game_Exit, option, sumaho, Game_Go2, NULL);
	menu->setAnchorPoint(Vec2(0, 0));
	menu->setPosition(Vec2(0, 0));
	//   menu->alignItemsVertically();
	MLayer->addChild(menu, 100);
	

	return true;
}

bool Option::onTouchBegan(Touch* touch, Event* unsued_event)
{
	TouchPosx = touch->getLocation().x;
	TouchPosy = touch->getLocation().y;
	log("%f %f", TouchPosx, TouchPosy);
	if (isbgmoff == true)
	{
		if (TouchPosx > 345 && TouchPosx < 585)
			if (TouchPosy>275 && TouchPosy < 505)
			{
				isbgmoff = false;
				backsound_on->setVisible(true);
				//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0f);
				SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
				UserDefault::getInstance()->setBoolForKey("bgm", isbgmoff);
			}
	}
	else
		if (TouchPosx > 345 && TouchPosx < 585)
			if (TouchPosy>275 && TouchPosy < 505)
			{
				isbgmoff = true;
				backsound_on->setVisible(false);
				//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.0f);
				SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
				UserDefault::getInstance()->setBoolForKey("bgm", isbgmoff);
			}

	if (isegmoff == true)
	{
		if (TouchPosx > 695&& TouchPosx < 935)
			if (TouchPosy>275&& TouchPosy < 505)
			{
				isegmoff = false;
				effectsound_on->setVisible(true);
				UserDefault::getInstance()->setBoolForKey("eff", isegmoff);

			}
	}
	else
		if (TouchPosx > 695 && TouchPosx < 930)
			if (TouchPosy>275 && TouchPosy < 505)
			{
				isegmoff = true;
				effectsound_on->setVisible(false);
				UserDefault::getInstance()->setBoolForKey("eff", isegmoff);

			}

	UserDefault::getInstance()->flush();
	return true;
}

void Option::onTouchMoved(Touch* touch, Event* unsued_event)
{
	Vec2 point = touch->getLocation();
	TouchPosx = touch->getLocation().x;
	TouchPosy = touch->getLocation().y;
}

void Option::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void Option::Go_Option(Ref* pSender)
{
	if (!isoption)
		Director::getInstance()->end();
}

void Option::Option_on(Ref* pSender)
{
	SLayer->setVisible(true);
	isoption = true;
}

void Option::Option_off(Ref* pSender)
{
	SLayer->setVisible(false);
	isoption = false;
}