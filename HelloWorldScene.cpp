#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x-50 + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y+50 + closeItem->getContentSize().height/2));
	closeItem->setScale(3);
	closeItem->setTag(5);
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Set UP", "fonts/Marker Felt.ttf", 100);
    
    // position the label on the center of the screen
	label->setPosition(Vec2(150, 650));

    // add the label as a child to this layer
    this->addChild(label, 1);

	UserDefault::getInstance()->setIntegerForKey("money", 1000);
	UserDefault::getInstance()->flush();
	int mon = UserDefault::getInstance()->getIntegerForKey("money");

	isbgmoff = UserDefault::getInstance()->getBoolForKey("bgm");
	isegmoff = UserDefault::getInstance()->getBoolForKey("eff");


	backsound_off = Sprite::create("sound_off.png");
	backsound_off->setPosition(Vec2(420, visibleSize.height / 2 + origin.y));
	this->addChild(backsound_off, 0);

	backsound_on = Sprite::create("sound_on1.png");
	backsound_on->setPosition(Vec2(490, visibleSize.height / 2 + origin.y));
	if(isbgmoff == true)
		backsound_on->setVisible(false);
	this->addChild(backsound_on, 0);

    effectsound_off = Sprite::create("sound_off.png");
	effectsound_off->setPosition(Vec2(860, visibleSize.height / 2 + origin.y));
	this->addChild(effectsound_off, 0);

	effectsound_on = Sprite::create("sound_on1.png");
	effectsound_on->setPosition(Vec2(930, visibleSize.height / 2 + origin.y));
	if (isegmoff == true)
		effectsound_on->setVisible(false);
	this->addChild(effectsound_on, 0);

    // add "HelloWorld" splash screen"
 //   auto backgroundsound = Sprite::create("sound off.png");

 //   // position the sprite on the center of the screen
	//backgroundsound->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

 //   // add the sprite as a child to this layer
	//this->addChild(backgroundsound, 0);
    
    return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unsued_event)
{
	TouchPosx = touch->getLocation().x;
	TouchPosy = touch->getLocation().y;
	log("%f %f", TouchPosx, TouchPosy);
	if (isbgmoff == true)
	{
		if (TouchPosx > backsound_off->getPosition().x - 152 && TouchPosx < backsound_off->getPosition().x + 152)
			if (TouchPosy>backsound_off->getPosition().y - 152 && TouchPosy < backsound_off->getPosition().y + 152)
			{
				isbgmoff = false;
				backsound_on->setVisible(true);
				UserDefault::getInstance()->setBoolForKey("bgm", isbgmoff);

			}
	}
	else
		if (TouchPosx > backsound_off->getPosition().x - 152 && TouchPosx < backsound_off->getPosition().x + 152)
			if (TouchPosy>backsound_off->getPosition().y - 152 && TouchPosy < backsound_off->getPosition().y + 152)
			{
				isbgmoff = true;
				backsound_on->setVisible(false);
				UserDefault::getInstance()->setBoolForKey("bgm", isbgmoff);
			}

	if (isegmoff==true)
	{
		if (TouchPosx > effectsound_off->getPosition().x - 152 && TouchPosx < effectsound_off->getPosition().x + 152)
			if (TouchPosy>effectsound_off->getPosition().y - 152 && TouchPosy < effectsound_off->getPosition().y + 152)
			{
				isegmoff = false;
				effectsound_on->setVisible(true);
				UserDefault::getInstance()->setBoolForKey("eff", isegmoff);

			}
	}
	else
		if (TouchPosx > effectsound_off->getPosition().x - 152 && TouchPosx < effectsound_off->getPosition().x + 152)
			if (TouchPosy>effectsound_off->getPosition().y - 152 && TouchPosy < effectsound_off->getPosition().y + 152)
			{
				isegmoff = true;
				effectsound_on->setVisible(false);
				UserDefault::getInstance()->setBoolForKey("eff", isegmoff);

			}


	UserDefault::getInstance()->flush();
	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* unsued_event)
{
	Vec2 point = touch->getLocation();
	TouchPosx = touch->getLocation().x;
	TouchPosy = touch->getLocation().y;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	if (((Node*)pSender)->getTag() == 5)
		Director::getInstance()->end();
	//else if (((Node*)pSender)->getTag() == 1)
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
