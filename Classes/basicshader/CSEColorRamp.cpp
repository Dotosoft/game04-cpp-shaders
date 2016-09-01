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
	sprite->setPosition(Vec2(0, 320));
	this->addChild(sprite);

	// 2
	GLchar * fragmentSource = (GLchar*)String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename("basicshader/CSEColorRamp.fsh").c_str())->getCString();
	sprite->getShaderProgram()->initWithByteArrays(ccPositionTextureColor_noMVP_vert, fragmentSource);
	
	sprite->getShaderProgram()->addAttribute(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	sprite->getShaderProgram()->addAttribute(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);

	sprite->getShaderProgram()->link();
	sprite->getShaderProgram()->updateUniforms();

	// 3
	colorRampUniformLocation = glGetUniformLocation(sprite->getShaderProgram()->getProgram(), "u_colorRampTexture");
	glUniform1i(colorRampUniformLocation, 1);

	// 4
	colorRampTexture = Director::getInstance()->getTextureCache()->addImage("basicshader/colorRamp.png");
	colorRampTexture->setAliasTexParameters();

	// 5
	sprite->getShaderProgram()->use();
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, colorRampTexture->getName());
	glActiveTexture(GL_TEXTURE0);

	return true;
}
