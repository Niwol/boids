#include "boidSystem.hpp"

void BoidSystem::generateTasks(Ra::Core::TaskQueue *taskQueue,
                               const Ra::Engine::FrameInfo &frameInfo) {

  auto cm = Ra::Engine::Scene::ComponentMessenger::getInstance();

  for (auto &pair : m_components) {

    if (cm->canRw<Ra::Core::Geometry::TriangleMesh>(pair.first, "mesh comp")) {

      auto comp = static_cast<TransformComponent *>(pair.second);

      auto f1 = cm->rwCallback<Ra::Core::Geometry::TriangleMesh>(pair.first,
                                                                 "mesh comp");

      auto mesh = f1();

      auto physics = comp->getPhysics();

      Ra::Core::Transform t;
      t = Ra::Core::AngleAxis(frameInfo.m_dt, physics.prevRotationAxis);

      // Updating verts
      auto &verts = mesh->verticesWithLock();

      for (auto &v : verts) {
        v -= physics.position;
        v = t * v;
        v += physics.position;
      }

      mesh->verticesUnlock();

      // t = Ra::Core::AngleAxis(2.f * frameInfo.m_dt, preDir);
      // dir = t * dir;

      // t = Ra::Core::AngleAxis(5.f * frameInfo.m_dt,
      //                         Ra::Core::Vector3::Random());
      // preDir = t * preDir;

      std::cout << "axis = " << physics.rotationAxis.transpose()
                << "  ;  prevAxis = " << physics.prevRotationAxis.transpose()
                << std::endl;

      physics.rotationAxis.transpose();
      physics.prevRotationAxis.transpose();

      // trans.rotate(Ra::Core::AngleAxis(Ra::Core::Math::PiDiv3,
      //                                  Ra::Core::Vector3::UnitY()));
    }
  }
}