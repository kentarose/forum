#include "cocos2d.h"

USING_NS_CC;
class Logo : public cocos2d::LayerColor
{

public:
	virtual bool init();
    static cocos2d::Scene* createScene();
	void menuCloseCallback(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Logo);

	Sprite* LOGO;
	Sprite* LOGO_2;
	Sprite* TITLE; 
	void Go_main(float f);
	void Go_Main_2(float f);
	int count;
};
