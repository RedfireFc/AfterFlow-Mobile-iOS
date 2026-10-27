#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

$execute {
    log::info("Bismuth initialized");
}

// This is the only place where Geode classes should be modified.
class $modify(BismuthGJBaseGameLayer, GJBaseGameLayer) {
public:
    bool init() {
        if (!GJBaseGameLayer::init())
            return false;

        return true;
    }
};

class $modify(BismuthPlayLayer, PlayLayer) {
public:
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        return true;
    }
};
