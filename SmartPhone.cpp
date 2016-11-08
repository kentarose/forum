#include"Title.h"
#include "SimpleAudioEngine.h"
#include "SmartPhone.h"
#include "Option.h"
#define TRANSITION_TIME 1
USING_NS_CC;

Scene* SmartPhone::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SmartPhone::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}
bool SmartPhone::init()
{
	if (!LayerColor::init())
	{
		return false;
	}
	isPosition = false;
	
	isOut = false;
	ising = false;

	auto MLayer = Layer::create();
	this->addChild(MLayer);

	auto SLayer = Layer::create();
	this->addChild(SLayer);

	//퀘스트
	auto Quest = MenuItemImage::create("quest.png", "quest.png", CC_CALLBACK_1(SmartPhone::Go_Option, this));
	Quest->setPosition(Vec2(88, 290));

	//가게 목록

	auto List = MenuItemImage::create("List.png", "List.png", CC_CALLBACK_1(SmartPhone::Go_Option, this));
	List->setPosition(Vec2(88, 240));


	//검사 규정
	auto check = MenuItemImage::create("check.png", "check.png", CC_CALLBACK_1(SmartPhone::Go_Option, this));
	check->setPosition(Vec2(88, 190));

	//상품 번호 조회
	
	auto item_Check = MenuItemImage::create("Item-Number-check.png", "Item-Number-check.png", CC_CALLBACK_1(SmartPhone::Go_Option, this));
	item_Check->setPosition(Vec2(88, 140));

	//최종 확인

	auto final = MenuItemImage::create("Final-check.png", "Final-check.png", CC_CALLBACK_1(SmartPhone::Go_Option, this));
	final->setPosition(Vec2(88, 90));

	//-------------------------------------------------------------------------------------------------------------------------------------------------------------
	Smart = Sprite::create("sumaho.png");
	Smart->setPosition(Vec2(140, -135));
	SLayer->addChild(Smart, 1);



	auto menu = Menu::create(Quest, List, check, item_Check, final, NULL);
	menu->setAnchorPoint(Vec2(0, 0));
	menu->setPosition(Vec2(0, 0));
	//   menu->alignItemsVertically();
	Smart->addChild(menu, 100);

	this->setTouchEnabled(true);//터치 활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);//멀티 터치 활성화     //ONE_BY_ON
	return true; 
}

void SmartPhone::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool SmartPhone::onTouchBegan(Touch* touch, Event* unsued_event)
{
	TouchPosx = touch->getLocation().x;
	TouchPosy = touch->getLocation().y;

	log("%f %f",TouchPosx, TouchPosy);
	if (isPosition == false)
	{//스마트폰 위로 승천
		if (TouchPosx > 50 && TouchPosx < 225)
			if (TouchPosy > 0 && TouchPosy < 40)
			{
				auto UP = MoveTo::create(0.2f, Vec2(140, 190));
				Smart->runAction(UP);
				isPosition = true;

			}
	}
	else
		//홈버튼 눌렀을 때 스마트폰 내려감
		if (TouchPosx > 120 && TouchPosx < 155)
			if (TouchPosy > 20 && TouchPosy < 30)
			{
				

				auto DOWN = MoveTo::create(0.2f, Vec2(140, -135));
				Smart->runAction(DOWN);
				

				isPosition = false;
			}
	return true;
}

void SmartPhone::Go_Option(Ref* pSender)
{
	auto scene = Option::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
