#include "boidSystem.hpp"

void BoidSystem::generateTasks(Ra::Core::TaskQueue *taskQueue,
                               const Ra::Engine::FrameInfo &frameInfo) {

  auto c = static_cast<KeyFrameComponent *>(m_components[0].second);

  auto t = c->getTransform();
}