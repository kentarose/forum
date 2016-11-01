#include "cocos2d.h"

USING_NS_CC;
class Title : public cocos2d::LayerColor
{

public:
	virtual bool init();
    static cocos2d::Scene* createScene();
	void menuCloseCallback(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Title);
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	Sprite* TITLE; 
};
