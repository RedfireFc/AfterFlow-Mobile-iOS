#include "GJBaseGameLayer.hpp"
#include "../renderer/Renderer.hpp"

using namespace geode::prelude;

class $modify(BismuthBaseGameLayer, GJBaseGameLayer) {
    bool init() {
        if (!GJBaseGameLayer::init()) {
            return false;
        }
        // Reset Bismuth batch renderer state when a layer initializes
        bismuth::Renderer::get()->resetState();
        return true;
    }

    void addObject(GameObject* obj) {
        GJBaseGameLayer::addObject(obj);
        
        // Register newly instantiated objects in Bismuth's custom batch sorter
        if (obj) {
            bismuth::Renderer::get()->registerObject(obj);
        }
    }

    void removeObjectFromSection(GameObject* obj) {
        GJBaseGameLayer::removeObjectFromSection(obj);
        
        // Unregister objects when removed from level sections
        if (obj) {
            bismuth::Renderer::get()->unregisterObject(obj);
        }
    }

    void updateColor(cocos2d::ccColor3B const& color, float duration, int colorID, bool blending, float opacity, cocos2d::ccColor3B const& color2, bool p7, int p8) {
        GJBaseGameLayer::updateColor(color, duration, colorID, blending, opacity, color2, p7, p8);
        
        // Pass updated color channel uniforms to Bismuth shaders in GD 2.208
        bismuth::Renderer::get()->updateColorState(colorID, color);
    }

    void processCommands(float dt) {
        GJBaseGameLayer::processCommands(dt);
        
        // Update batching buffers following trigger processing
        bismuth::Renderer::get()->onProcessCommands(dt);
    }
};