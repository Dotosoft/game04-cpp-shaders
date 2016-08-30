#include "basicshader\CSEColorRamp.h"

using namespace basicshader;

Scene* CSEColorRamp::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CSEColorRamp::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CSEColorRamp::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	// 1
	sprite = Sprite::create("basicshader/Default.png");
	sprite->setAnchorPoint(Point::ZERO);
	sprite->setRotation(90);
	sprite->setPosition( Vec2(0, 320) );
	
	
	CCGLProgram *glProgram = new CCGLProgram();
	glProgram->initWithVertexShaderFilename("basicshader/CSEColorRamp.vsh", "basicshader/CSEColorRamp.fsh");

	sprite->setShaderProgram(glProgram);
	// sprite->getShaderProgram()->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	// sprite->getShaderProgram()->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);

	sprite->getShaderProgram()->link();
	sprite->getShaderProgram()->updateUniforms();
	int colorRampUniformLocation = glGetUniformLocation(sprite->getShaderProgram()->getProgram(), "u_colorRampTexture");
	glUniform1i(colorRampUniformLocation, 1);

	CCTexture2D *colorRampTexture = CCTextureCache::sharedTextureCache()->addImage("basicshader/colorRamp.png");
	colorRampTexture->setAliasTexParameters();
	sprite->getShaderProgram()->use();
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, colorRampTexture->getName());
	glActiveTexture(GL_TEXTURE0);

	// Add the sprite to HelloWorld layer as a child layer.
	this->addChild(sprite, 0);

	return true;
}
