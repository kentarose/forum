#ifndef __OPTION_H__
#define __OPTION_H__

#include "cocos2d.h"

USING_NS_CC;
class Option : public cocos2d::LayerColor
{

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	void menuCloseCallback(Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Option);

	bool onTouchBegan(Touch* touch, Event* unsued_event);
	void onTouchMoved(Touch* touch, Event* unsued_event);

	Layer *SLayer;//Sound layer
	Layer *ELayer;//Exit layer

	Sprite *backsound_on;
	Sprite *backsound_off;
	Sprite *effectsound_on;
	Sprite *effectsound_off;

	bool isbgmoff;
	bool isegmoff;
	float TouchPosx;
	float TouchPosy;

	void Go_Option(Ref *sender);
	void Option_on(Ref *sender);
	void Option_off(Ref* pSender);
	void Really_on(Ref* pSender);
	void Really_off(Ref* pSender);

	bool isoption;
	bool isreal;
};

#endif // __OPTION_H__

