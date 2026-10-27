#include "Renderer.hpp"

using namespace geode::prelude;

static Renderer* g_renderer = nullptr;

Ref<Renderer> Renderer::create(PlayLayer* layer) {
    auto ren = new Renderer();
    ren->layer = layer;
    ren->autorelease();
    g_renderer = ren;
    return ren;
}

Ref<Renderer> Renderer::get() {
    return g_renderer;
}

void Renderer::update(float dt) {
    (void)dt;
}

bool Renderer::isEnabled() const {
    return enabled;
}

void Renderer::setEnabled(bool enabled) {
    this->enabled = enabled;
}
