#include "basicshader/HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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
		Director::getInstance()->pushScene(HelloWorld::createScene());
	});
	// 7 - Emboss menu item
	auto emboss = MenuItemFont::create("Emboss", [&](Ref * sender) {
		Director::getInstance()->pushScene(HelloWorld::createScene());
	});
	// 7.1 - Grass menu item
	auto grass = MenuItemFont::create("Grass", [&](Ref * sender) {
		Director::getInstance()->pushScene(HelloWorld::createScene());
	});
	// 7.2 - Create menu
	auto menu = Menu::create(itemColorRamp, emboss, grass, NULL);
	// 8 - Configure menu
	menu->alignItemsHorizontallyWithPadding(20);
	menu->setPosition(ccp(size.width / 2, size.height / 2 - 50));
	// 9 - Add the menu to the layer
	this->addChild(menu);

    return true;
}
