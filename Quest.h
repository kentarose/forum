#ifndef __QUEST_H__
#define __QUEST_H__
#include "cocos2d.h"

USING_NS_CC;

class Quest : public cocos2d::LayerColor
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	bool onTouchBegan(Touch* touch, Event* unsued_event);

	void menuCloseCallback(Ref* pSender);
	int quest_shit;
	// implement the "static create()" method manually
	CREATE_FUNC(Quest);
};
#endif // __QUEST_H__
