#include "boidSystem.hpp"

void BoidSystem::generateTasks(Ra::Core::TaskQueue *taskQueue,
                               const Ra::Engine::FrameInfo &frameInfo) {

  auto comp = static_cast<KeyFrameComponent *>(m_components[0].second);

  auto cm = Ra::Engine::Scene::ComponentMessenger::getInstance();

  for (auto &pair : m_components) {

    if (cm->canRw<Ra::Core::Geometry::TriangleMesh>(pair.first, "mesh comp")) {

      // auto mesh =
      //     cm->get<Ra::Core::Geometry::TriangleMesh>(pair.first, "mesh comp");

      auto f1 = cm->rwCallback<Ra::Core::Geometry::TriangleMesh>(pair.first,
                                                                 "mesh comp");

      auto mesh = f1();

      auto &verts = mesh->verticesWithLock();

      for (auto &v : verts) {
        v -= (0.02 * Ra::Core::Vector3::Identity());
      }

      mesh->verticesUnlock();

      printf("plop sys\n");

      // auto f = cm->setterCallback<Ra::Core::Geometry::TriangleMesh>(
      //     pair.first, "mesh comp");

      // f(&mesh);
    }
  }
}