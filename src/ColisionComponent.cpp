#include "ColisionComponent.hpp"

ColisionComponent::ColisionComponent(const std::string &name,
                                       Ra::Engine::Scene::Entity *entity, Ra::Core::Vector3f position, float radius)
        : Component(name, entity) {

    this->position = position;
    this->radius = radius;
}

void ColisionComponent::initialize() {}

Ra::Core::Vector3f &ColisionComponent::getPosition() {return position;};