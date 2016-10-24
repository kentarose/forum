#include "Option.h"
#include "SimpleAudioEngine.h"

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
	

	auto BLayer = Layer::create();
	this->addChild(BLayer);


	auto BG = Sprite::create("Main.png");
	BG->setAnchorPoint(Vec2::ZERO);
	BG->setPosition(Vec2::ZERO);
	BLayer->addChild(BG);


	//42,152

	auto MLayer = Layer::create();
	this->addChild(MLayer);

	//게임종료
	auto Game_Exit = MenuItemImage::create("Game_Exit.png", "Game_Exit.png", CC_CALLBACK_1(Option::Go_Option, this));
	Game_Exit->setAnchorPoint(Vec2::ZERO);
	Game_Exit->setPosition(Vec2(42, 62));

	//설정
	auto option = MenuItemImage::create("Option.png", "Option.png", CC_CALLBACK_1(Option::Go_Option, this));
	option->setAnchorPoint(Vec2::ZERO);
	option->setPosition(Vec2(42, 192));

	//스맛폰

	auto sumaho = MenuItemImage::create("smart_phone.png", "smart_phone.png", CC_CALLBACK_1(Option::Go_Option, this));
	sumaho->setAnchorPoint(Vec2::ZERO);
	sumaho->setPosition(Vec2(42, 322));

	//업무 진행

	auto Game_Go = MenuItemImage::create("game_go.png", "game_go.png", CC_CALLBACK_1(Option::Go_Option, this));
	Game_Go->setAnchorPoint(Vec2::ZERO);
	Game_Go->setPosition(Vec2(42, 452));
	


	
	//메뉴 활성화

	auto menu = Menu::create(Game_Exit, option, sumaho,Game_Go,NULL);
	menu->setAnchorPoint(Vec2(0, 0));
	menu->setPosition(Vec2(0, 0));
	//   menu->alignItemsVertically();
	MLayer->addChild(menu, 100);
	
	
	return true;
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
	Director::getInstance()->end();
}