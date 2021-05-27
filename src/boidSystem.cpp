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
            newPhysicsPosition = verifyCubeBorders(newPhysicsPosition, MAP_BORDER);
            //newPhysicsPosition = verifyBorders(newPhysicsPosition, MAP_BORDER, 0.f, MAP_BORDER,0.f, MAP_BORDER, 0.f);

            // Updating verts
            auto &verts = mesh->verticesWithLock();
            for (auto &v : verts) {
                v -= physics.position;
                v = t * v;
                v += newPhysicsPosition;
                //v += newPhysics.position;
            }
            mesh->verticesUnlock();

            physics.position = newPhysicsPosition;
            physics.direction = t * physics.direction;

            // Deplacement plus aleatoire d'un boid sur 9
            int randomInt = rand() % 100;
            if (randomInt % 9 == 0) {
                physics.rotationSpeed += float(rand() % 500 / 1000);
                physics.rotationAxis += Ra::Core::Vector3::Random();
            }
            // fin de deplacement plus aleatoire d'un boid sur 9

            physics.rotationAxis.normalize();
            physics.rotationAxis.transpose();

            // Declaration de compteurs de voisins pris en compte pour les regles de cohesion et de separation
            int nbReallyCloseNeighbours = 0;
            int nbCloseNeighbours = 0;

            int nbNeighboursLeft = 0;
            int nbNeighbourgsRight = 0;

            // Declaration d'accumulateur des angles pris en compte pour le calcul de la rotation du boid :
            // TODO : il serait plus juste de calculer avec un accumulateur pour les valeurs negatives
            //        et un pour les valeurs positives et faire la moyenne pour chacune des valeurs avant de les sommer
            double angleAvg = 0.0;
            double angleAvgPos = 0.0;
            double angleAvgNeg = 0.0;

            // Boid interaction
            for (auto &otherPair : m_components) {
                auto otherComp = static_cast<TransformComponent *>(otherPair.second);

                PhysicInfo otherPhysics = otherComp->getPhysics();

                if (otherPhysics.position != physics.position) {

                    auto diffVector = otherPhysics.position - physics.position;
                    Ra::Core::Vector3f diffVectorNormalised = diffVector;
                    diffVectorNormalised.normalize();
                    float dist = diffVector.norm();

                    /* Separation : le boid s'eloigne de ses voisins tres proches */
                    if (dist < 1.f) {
                        physics.rotationAxis += diffVector.cross(physics.direction);
                        physics.rotationAxis.normalize();

                        // calcul de l'angle entre le boid et le boid voisin
                        // (prise en compte du signe du cos pour orienter a gauche ou a droite la rotation)
                        auto cos = physics.direction.dot(diffVectorNormalised) / (physics.direction.norm() * diffVectorNormalised.norm());
                        if (cos >= 0) {
                          angleAvgNeg -= 5.f * 2.f * M_PI / 360.f;
                          nbNeighbourgsRight ++;
                        }
                        else {
                          angleAvgPos -= -(5.f * 2.f * M_PI / 360.f);
                          nbNeighboursLeft ++;
                        }

                        // ralentissement du boid trop proche de son voisin
                        /*if (physics.speed > 0.05f) {
                            physics.speed -= 0.005f;
                        }*/

                        nbReallyCloseNeighbours ++;
                    }
                    /* Cohesion : le boid se rapproche de ses voisins */
                    else if (dist < 7.f) {
                        // regle alignement ?
                        //physics.rotationAxis += otherPhysics.rotationAxis;
                        //physics.rotationAxis.normalize();

                        physics.rotationAxis += diffVector.cross(physics.direction);
                        physics.rotationAxis.normalize();

                        // calcul de l'angle entre le boid et le boid voisin
                        // (prise en compte du signe du cos pour orienter a gauche ou a droite la rotation)
                        auto cos = physics.direction.dot(diffVectorNormalised) / (physics.direction.norm() * diffVectorNormalised.norm());
                        if (cos >= 0) {
                          angleAvgPos += acos(cos) * 2.f * M_PI / 360.f;
                          nbNeighbourgsRight ++;
                        }
                        else {
                          angleAvgNeg += -(acos(cos) * 2.f * M_PI / 360.f);
                          nbNeighboursLeft ++;
                        }

                        // acceleration du boid pour se rapprocher de ses voisins
                        /*if (physics.speed < 0.1f) {
                            physics.speed += 0.005f;
                        }*/
                        nbCloseNeighbours ++;
                    }
                }
            }

            if (nbCloseNeighbours > 0) {
              // ralentissement du boid trop proche de son voisin
              if (physics.speed > 0.10f) {
                  physics.speed -= 0.005f;
              }
            }

            if (nbReallyCloseNeighbours == 0) {
              // acceleration du boid pour se rapprocher de ses voisins
              if (physics.speed < 0.14f) {
                  physics.speed += 0.005f;
              }
            }

              // affichage des infos pour le boid rouge
              // if (pair.first->getName() == "boid0") {
              //    std::cout << angleAvg << std::endl;
              //}

              // calcul de la moyenne des angles entre la direction du boid et les vecteurs distance boid-voisin
              // angleAvg = angleAvg / (float) (nbCloseNeighbours + nbReallyCloseNeighbours);
              angleAvg = angleAvgNeg / ((float)nbNeighboursLeft) +
                         angleAvgPos / ((float)nbNeighbourgsRight);

              // rotation du boid prenant en compte la moyenne des angles pour orienter le boid vers ses voisins sans les percuter et sans depasser un certain angle
              if (physics.rotationSpeed + (float)angleAvg < 1.5f &&
                  physics.rotationSpeed + (float)angleAvg > -1.5f)
                physics.rotationSpeed += (float)angleAvg;
              else if (physics.rotationSpeed + (float)angleAvg >= 1.5f)
                physics.rotationSpeed = 1.5f;
              else
                physics.rotationSpeed = -1.5f;
            // affichage des infos pour le boid rouge
            //if (pair.first->getName() == "boid0") {
            //    std::cout << physics.rotationSpeed << std::endl;
            //}


            // Avoid obstacles
            /*auto collisionAvoidDirection = Ra::Core::Vector3f (0.f, 0.f, 0.f);
            for (auto obstacle : obstacles) {
                auto diffVector = obstacle.getPosition() - physics.position;
                float dist = diffVector.norm();

                if (dist < obstacle.radius + 0.5f) {
                    collisionAvoidDirection += diffVector;
                }*/
                /*else {
                    collisionAvoidDirection -= diffVector;
                }*/

                /*if (dist < obstacle.radius + 10.f) {
                    //physics.rotationAxis += diffVector.cross(physics.direction);
                    physics.rotationAxis += obstacle.getPosition() - physics.position;
                    physics.rotationAxis.normalize();
                    //physics.direction -= diffVector.cross(physics.direction);
                    //physics.direction += obstacle.getPosition() - physics.position;

                    physics.direction.normalize();

                    physics.rotationSpeed += 0.05;
                }*/
            /*}
            physics.rotationAxis += collisionAvoidDirection.cross(physics.direction) * 5;
            physics.rotationAxis.normalize();*/

            //physics.rotationSpeed += 1.f;


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
void BoidSystem::addToObstacles(ColisionComponent obstacle) {
    obstacles.push_back(obstacle);
}
