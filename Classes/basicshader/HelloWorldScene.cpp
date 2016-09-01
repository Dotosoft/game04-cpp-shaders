#include "basicshader/HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace basicshader;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	// 1 - create and initialize a Label
	auto label = Label::createWithTTF("Hello World", RESOURCES_FONTS_MARKER, 50);
	// 2 - ask director the the window size
	auto size = Director::getInstance()->getWinSize();
	// 3 - position the label on the center of the screen
	label->setPosition(Vec2(size.width / 2, size.height / 2));
	// 4 - add the label as a child to this Layer
	this->addChild(label);
	// 5 - Default font size will be 28 points.
	MenuItemFont::setFontSize(24);
	// 6 - color ramp Menu Item using blocks
	auto itemColorRamp = MenuItemFont::create("Color Ramp", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEColorRamp::createScene());
	});
	// 7 - Emboss menu item
	auto emboss = MenuItemFont::create("Emboss", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEEmboss::createScene());
	});
	// 7.1 - Grass menu item
	auto grass = MenuItemFont::create("Grass", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEGrass::createScene());
	});
	// 7.2 - Grass menu item
	auto medium = MenuItemFont::create("Medium", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEMedium::createScene());
	});
	// 7.3 - Grass menu item
	auto blink = MenuItemFont::create("Blink", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEBlink::createScene());
	});
	// 7.4 - Grass menu item
	auto gray = MenuItemFont::create("Gray", [&](Ref * sender) {
		Director::getInstance()->pushScene(CSEGray::createScene());
	});
	// 7.x - Create menu
	auto menuA = Menu::create(itemColorRamp, emboss, grass, NULL);
	auto menuB = Menu::create(medium, blink, gray, NULL);
	// 8 - Configure menu
	menuA->alignItemsHorizontallyWithPadding(20);
	menuB->alignItemsHorizontallyWithPadding(20);
	menuA->setPosition(ccp(size.width / 2, size.height / 2 - 50));
	menuB->setPosition(ccp(size.width / 2, size.height / 2 - 100));
	// 9 - Add the menu to the layer
	this->addChild(menuA);
	this->addChild(menuB);

    return true;
}
