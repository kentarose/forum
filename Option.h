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

	void Go_Option(Ref *sender);
};

#endif // __HELLOWORLD_SCENE_H__
