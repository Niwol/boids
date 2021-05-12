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

      auto &physics = comp->getPhysics();

      Ra::Core::Transform t;
      t = Ra::Core::AngleAxis(frameInfo.m_dt * physics.rotationSpeed,
                              physics.rotationAxis);

      // Updating verts
      auto &verts = mesh->verticesWithLock();

      for (auto &v : verts) {
        v -= physics.position;
        v = t * v;
        v += physics.position;

        v += physics.direction * physics.speed;
      }

      physics.position += physics.direction * physics.speed;

      physics.direction = t * physics.direction;

      mesh->verticesUnlock();

      // t = Ra::Core::AngleAxis(2.f * frameInfo.m_dt, preDir);
      // dir = t * dir;

      // t = Ra::Core::AngleAxis(5.f * frameInfo.m_dt,
      //                         Ra::Core::Vector3::Random());
      // preDir = t * preDir;

      std::cout << "axis = " << physics.rotationAxis.transpose()
                << "  ;  rotSpeed = " << physics.rotationSpeed << std::endl;

      physics.rotationAxis.transpose();

      physics.rotationSpeed += (float(rand()) / RAND_MAX - 0.5);
      physics.rotationAxis += Ra::Core::Vector3::Random() * 0.5;
      physics.rotationAxis.normalize();

      // trans.rotate(Ra::Core::AngleAxis(Ra::Core::Math::PiDiv3,
      //                                  Ra::Core::Vector3::UnitY()));
    }
  }
}