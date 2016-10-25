#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	bool onTouchBegan(Touch* touch, Event* unsued_event);

	void onTouchMoved(Touch* touch, Event* unsued_event);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	Sprite *backsound_on;
	Sprite *backsound_off;
	Sprite *effectsound_on;
	Sprite *effectsound_off;


	bool isbgmoff;
	bool isegmoff;
	float TouchPosx;
	float TouchPosy;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
