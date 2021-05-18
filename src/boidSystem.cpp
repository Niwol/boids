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

            Ra::Core::Vector3f newPhysicsPosition = physics.position + physics.direction * physics.speed;
            //newPhysicsPosition = verifyCubeBorders(newPhysicsPosition, MAP_BORDER);
            newPhysicsPosition = verifyBorders(newPhysicsPosition, MAP_BORDER, 0.f, MAP_BORDER,0.f, MAP_BORDER, 0.f);

            // Updating verts
            auto &verts = mesh->verticesWithLock();
            for (auto &v : verts) {
                v -= physics.position;
                v = t * v;
                v += newPhysicsPosition;
            }
            mesh->verticesUnlock();

            physics.position = newPhysicsPosition;

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

                    if (dist < 3.f) {
                        physics.rotationAxis += diffVector.cross(physics.direction);
                        physics.rotationAxis.normalize();

                        physics.rotationSpeed += 0.01;

                    } else if (dist < 6.f) {
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

Ra::Core::Vector3f BoidSystem::verifyCubeBorders(Ra::Core::Vector3f position, float halfSideLength) {
    if (position.x() < -halfSideLength)
        position = Ra::Core::Vector3f(halfSideLength, position.y(), position.z());
    else if (position.x() > halfSideLength)
        position = Ra::Core::Vector3f(-halfSideLength, position.y(), position.z());
    if (position.y() < -halfSideLength)
        position = Ra::Core::Vector3f(position.x(), halfSideLength, position.z());
    else if (position.y() > halfSideLength)
        position = Ra::Core::Vector3f(position.x(), -halfSideLength, position.z());
    if (position.z() < -halfSideLength)
        position = Ra::Core::Vector3f(position.x(), position.y(), halfSideLength);
    else if (position.z() > halfSideLength)
        position = Ra::Core::Vector3f(position.x(), position.y(), -halfSideLength);

    return position;
}

Ra::Core::Vector3f BoidSystem::verifyBorders(Ra::Core::Vector3f position,
                                             float toRightLength, float toLeftLength,
                                             float toBackLength, float toForwardLength,
                                             float toUpLength, float toBottomLength) {
    if (position.x() < toLeftLength)
        position = Ra::Core::Vector3f(toRightLength, position.y(), position.z());
    else if (position.x() > toRightLength)
        position = Ra::Core::Vector3f(toLeftLength, position.y(), position.z());
    if (position.y() < toForwardLength)
        position = Ra::Core::Vector3f(position.x(), toBackLength, position.z());
    else if (position.y() > toBackLength)
        position = Ra::Core::Vector3f(position.x(), toForwardLength, position.z());
    if (position.z() < toBottomLength)
        position = Ra::Core::Vector3f(position.x(), position.y(), toUpLength);
    else if (position.z() > toUpLength)
        position = Ra::Core::Vector3f(position.x(), position.y(), toBottomLength);

    return position;
}