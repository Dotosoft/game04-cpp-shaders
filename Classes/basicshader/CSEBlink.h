#ifndef  _BASICSHADER_CSE_BLINK_H_
#define  _BASICSHADER_CSE_BLINK_H_

#include "cocos2d.h"
#include "GameResources.h"

USING_NS_CC;

namespace basicshader {

	class CSEBlink : public cocos2d::Layer
	{
		public:
			// there's no 'id' in cpp, so we recommend returning the class instance pointer
			static cocos2d::Scene* createScene();

			// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
			virtual bool init();

			// implement the "static create()" method manually
			CREATE_FUNC(CSEBlink);

			void update(float dt);

			float m_angleWaveUniform;
	};

}

#endif  // _BASICSHADER_CSE_BLINK_H_