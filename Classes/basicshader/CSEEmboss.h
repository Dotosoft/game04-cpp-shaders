#ifndef  _BASICSHADER_CSE_EMBOSS_H_
#define  _BASICSHADER_CSE_EMBOSS_H_

#include "cocos2d.h"
#include "GameResources.h"

USING_NS_CC;

namespace basicshader {

	class CSEEmboss : public cocos2d::Layer
	{
		Sprite *sprite;  //1
		int timeUniformLocation;
		float totalTime;

		public:
			// there's no 'id' in cpp, so we recommend returning the class instance pointer
			static cocos2d::Scene* createScene();

			// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
			virtual bool init();

			// implement the "static create()" method manually
			CREATE_FUNC(CSEEmboss);

			void update(float dt);
	};

}

#endif  // _BASICSHADER_CSE_EMBOSS_H_