#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

namespace bismuth {
    class DecompPlayLayer {
    public:
        // Adjust PlayLayer offsets and method signatures for 2.208
        static void setupObjectManager(PlayLayer* self);
        static void updateVisibility(PlayLayer* self);
    };
}

class $modify(BismuthPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects);
    void update(float dt);
    void postUpdate(float dt);
};