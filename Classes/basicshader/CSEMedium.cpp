#include "basicshader\CSEMedium.h"

using namespace basicshader;

Scene* CSEMedium::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CSEMedium::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CSEMedium::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Sprite * ball1 = Sprite::create("basicshader/Default.png");
	this->addChild(ball1);
	auto size = Director::getInstance()->getWinSize();
	ball1->setPosition(size.width / 2, size.height / 2);

	auto shaderProgram = GLProgram::createWithFilenames("basicshader/medium.vsh", "basicshader/medium.fsh");
	shaderProgram->link();
	shaderProgram->updateUniforms();
	shaderProgram->retain();
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	ball1->setGLProgram(shaderProgram);

	return true;
}