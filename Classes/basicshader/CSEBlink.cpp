#include "basicshader\CSEBlink.h"

using namespace basicshader;

Scene* CSEBlink::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CSEBlink::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CSEBlink::init()
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
	

	/*
	auto shaderProgram = GLProgram::createWithFilenames("vertex.vsh", "pixel.fsh");
	shaderProgram->link();
	shaderProgram->updateUniforms();
	shaderProgram->retain();
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	shaderProgram->addAttribute(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD); 
	*/

	auto m_myShader = GLProgram::createWithFilenames("basicshader/blink.vsh", "basicshader/blink.fsh");
	m_myShader->retain();

	m_myShader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	m_myShader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	m_myShader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
	m_myShader->link();
	CHECK_GL_ERROR_DEBUG();
	m_myShader->updateUniforms();
	CHECK_GL_ERROR_DEBUG();

	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(m_myShader);
	setGLProgramState(glProgramState);

	getGLProgramState()->setUniformFloat("waveData", 0.5f);

	// this->setShaderProgram(m_myShader);
	ball1->setGLProgram(m_myShader);

	m_myShader->use();

	this->schedule(schedule_selector(CSEBlink::update));

	return true;
}

void CSEBlink::update(float _dt) {
	m_angleWaveUniform += _dt;

	while (m_angleWaveUniform > 0.99f)
		m_angleWaveUniform -= 0.98f;

	getGLProgramState()->setUniformFloat("waveData", m_angleWaveUniform);
}