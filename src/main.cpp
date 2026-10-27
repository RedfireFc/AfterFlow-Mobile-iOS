#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include "profiler.hpp"
#include "decomp/PlayLayer.hpp"
#include "decomp/GJBaseGameLayer.hpp"

using namespace geode::prelude;

$execute {
    log::info("Bismuth renderer initialized for Geometry Dash 2.208");
}

class $modify(BismuthGJBaseGameLayer, GJBaseGameLayer) {
    void processMoveActions() {
        // Calls Bismuth's decompiled custom move actions implementation
        reinterpret_cast<decomp_GJBaseGameLayer*>(this)->processMoveActions();
    }
};

class $modify(BismuthPlayLayer, PlayLayer) {
    void updateVisibility(float dt) {
        // Delegate visibility pipeline to Bismuth's custom batch renderer
        reinterpret_cast<decomp_PlayLayer*>(this)->virtual_updateVisibility(dt);
    }
};