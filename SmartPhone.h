#include "cocos2d.h"

USING_NS_CC;
class SmartPhone : public cocos2d::LayerColor
{

public:
	virtual bool init();
    static cocos2d::Scene* createScene();
	void menuCloseCallback(Ref* pSender);
    CREATE_FUNC(SmartPhone);
	bool onTouchBegan(Touch* touch, Event* unsued_event);
	float TouchPosx;
	float TouchPosy;
	void Go_Option(Ref* pSender);
	bool isPosition;
	bool isOut;
	bool ising;
	Sprite* Smart; 
};
