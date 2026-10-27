#include "PlayLayer.hpp"
#include "../renderer/Renderer.hpp"

bool BismuthPlayLayer::init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
    if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
        return false;
    }
    
    // Initialize custom batch renderer state for GD 2.208
    bismuth::Renderer::get()->resetState();
    return true;
}

void BismuthPlayLayer::update(float dt) {
    PlayLayer::update(dt);
    
    // Custom renderer step during PlayLayer update cycle
    bismuth::Renderer::get()->onUpdate(dt);
}

void BismuthPlayLayer::postUpdate(float dt) {
    PlayLayer::postUpdate(dt);
    
    // Ensure object sorter updates after physical positions are resolved
    bismuth::Renderer::get()->sortBatchNodes();
}