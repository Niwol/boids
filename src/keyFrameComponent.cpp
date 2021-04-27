#include "keyFrameComponent.hpp"

KeyFrameComponent::KeyFrameComponent(const std::string &name,
                                     Ra::Engine::Scene::Entity *entity)
    : Component(name, entity),
      m_transform(Ra::Core::Transform::Identity(), 0_ra) {}

void KeyFrameComponent::initialize() {}

Ra::Core::Animation::KeyFramedValue<Ra::Core::Transform>
KeyFrameComponent::getTransform() {
  return m_transform;
}
