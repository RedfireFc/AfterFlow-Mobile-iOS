#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include "../renderer/Renderer.hpp"

class $modify(BismuthBaseGameLayer, GJBaseGameLayer) {
    void processCommands(float dt) {
        GJBaseGameLayer::processCommands(dt);
    }

    void updateColor(cocos2d::_ccColor3B const& color, float duration, int colorID, bool blending, float opacity, cocos2d::_ccColor3B const& color2, bool p7, int p8) {
        GJBaseGameLayer::updateColor(color, duration, colorID, blending, opacity, color2, p7, p8);
        
        // Notify custom shaders when color triggers update
        bismuth::Renderer::get()->updateColorState(colorID, color);
    }
};