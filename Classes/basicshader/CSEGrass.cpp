#include "basicshader\CSEGrass.h"

using namespace basicshader;

Scene* CSEGrass::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CSEGrass::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CSEGrass::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	// 1
	sprite = Sprite::create("basicshader/grass.png");
	auto size = Director::getInstance()->getWinSize();
	sprite->setPosition(size.width / 2, size.height / 2);
	this->addChild(sprite);

	// 2
	GLchar * fragmentSource = (GLchar*)String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename("basicshader/CSEGrass.fsh").c_str())->getCString();
	sprite->getShaderProgram()->initWithByteArrays(ccPositionTextureColor_noMVP_vert, fragmentSource);

	sprite->getShaderProgram()->addAttribute(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	sprite->getShaderProgram()->addAttribute(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	sprite->getShaderProgram()->link();
	sprite->getShaderProgram()->updateUniforms();

	// 3
	timeUniformLocation = glGetUniformLocation(sprite->getShaderProgram()->getProgram(), "u_time");

	// 4
	this->scheduleUpdate();

	// 5
	sprite->getShaderProgram()->use();

	return true;
}

void CSEGrass::update(float dt)
{
	totalTime += dt;
	sprite->getShaderProgram()->use();
	glUniform1f(timeUniformLocation, totalTime);
}