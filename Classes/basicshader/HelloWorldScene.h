#ifndef _BASICSHADER_HELLOWORLD_SCENE_H_
#define _BASICSHADER_HELLOWORLD_SCENE_H_

#include "cocos2d.h"
#include "GameResources.h"
#include "basicshader\CSEColorRamp.h"
#include "basicshader\CSEEmboss.h"
#include "basicshader\CSEGrass.h"
#include "basicshader\CSEMedium.h"
#include "basicshader\CSEBlink.h"
#include "basicshader\CSEGray.h"

namespace basicshader {

	class CSEColorRamp;
	class CSEEmboss;
	class CSEGrass;

	class HelloWorld : public cocos2d::Layer
	{
		public:
			// there's no 'id' in cpp, so we recommend returning the class instance pointer
			static cocos2d::Scene* createScene();

			// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
			virtual bool init();

			// implement the "static create()" method manually
			CREATE_FUNC(HelloWorld);
	};

}

#endif // _BASICSHADER_HELLOWORLD_SCENE_H_
