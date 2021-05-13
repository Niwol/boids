#include "boidSystem.hpp"

void BoidSystem::generateTasks(Ra::Core::TaskQueue *taskQueue,
                               const Ra::Engine::FrameInfo &frameInfo) {

  auto cm = Ra::Engine::Scene::ComponentMessenger::getInstance();

  for (auto &pair : m_components) {

    if (cm->canRw<Ra::Core::Geometry::TriangleMesh>(pair.first, "mesh comp")) {

      auto comp = static_cast<TransformComponent *>(pair.second);

      auto triMeshGetter = cm->rwCallback<Ra::Core::Geometry::TriangleMesh>(
          pair.first, "mesh comp");

      auto mesh = triMeshGetter();

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
      mesh->verticesUnlock();

      physics.position += physics.direction * physics.speed;

      physics.direction = t * physics.direction;

      physics.rotationAxis.transpose();

      physics.rotationSpeed += (float(rand()) / RAND_MAX - 0.5);
      physics.rotationAxis += Ra::Core::Vector3::Random() * 0.5;
      physics.rotationAxis.normalize();

      // Boid interaction
      for (auto &otherPair : m_components) {
        auto otherComp = static_cast<TransformComponent *>(otherPair.second);

        PhysicInfo otherPhysics = otherComp->getPhysics();

        if (otherPhysics.position != physics.position) {

          auto diffVector = otherPhysics.position - physics.position;
          float dist = diffVector.norm();

          if (dist < 0.5f) {
            physics.rotationAxis += diffVector.cross(physics.direction);
            physics.rotationAxis.normalize();

            physics.rotationSpeed += 0.01;

          } else if (dist < 2.f) {
            physics.rotationAxis += diffVector.cross(physics.direction);
            physics.rotationAxis.normalize();

            physics.rotationSpeed -= 0.01;
          }
        }
      }

      // Rotation speed check
      const float rotationSpeedLimit = 1.5f;

      if (physics.rotationSpeed > rotationSpeedLimit)
        physics.rotationSpeed = rotationSpeedLimit;

      if (physics.rotationSpeed < -rotationSpeedLimit)
        physics.rotationSpeed = -rotationSpeedLimit;
    }
  }
}