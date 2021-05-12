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

      auto pos = comp->getPosition();
      auto dir = comp->getDirection();
      auto preDir = comp->getPreDirection();

      Ra::Core::Transform t;
      t = Ra::Core::AngleAxis(frameInfo.m_dt, dir);

      // Updating verts
      auto &verts = mesh->verticesWithLock();

      for (auto &v : verts) {
        v -= pos;
        v = t * v;
        v += pos;
      }

      mesh->verticesUnlock();


      // t = Ra::Core::AngleAxis(2.f * frameInfo.m_dt, preDir);
      // dir = t * dir;

      // t = Ra::Core::AngleAxis(5.f * frameInfo.m_dt,
      //                         Ra::Core::Vector3::Random());
      // preDir = t * preDir;

      std::cout << "dir = " << dir.transpose()
                << "  ;  preDir = " << preDir.transpose() << std::endl;

      dir.transpose();
      preDir.transpose();

      // trans.rotate(Ra::Core::AngleAxis(Ra::Core::Math::PiDiv3,
      //                                  Ra::Core::Vector3::UnitY()));
    }
  }
}