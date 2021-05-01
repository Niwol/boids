#include "keyFrameComponent.hpp"

KeyFrameComponent::KeyFrameComponent(const std::string &name,
                                     Ra::Engine::Scene::Entity *entity)
    : Component(name, entity), m_transform() {}

void KeyFrameComponent::initialize() {}

Ra::Core::Transform KeyFrameComponent::getTransform() { return m_transform; }
