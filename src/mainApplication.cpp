#include "mainApplication.hpp"
#include "mainWindow.hpp"

#include <Core/Geometry/MeshPrimitives.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/EntityManager.hpp>
#include <Engine/Scene/GeometryComponent.hpp>
#include <Engine/Scene/GeometrySystem.hpp>
#include "ColisionComponent.hpp"

MainApplication::MainApplication(int &argc, char **argv,
                                 QString applicationName,
                                 QString organizationName)
        : Ra::Gui::BaseApplication(argc, argv, applicationName, organizationName),
          m_nbBoids(50) {
    if (argc == 2)
        m_nbBoids = std::atoi(argv[1]);
}

void MainApplication::setup() {

    m_engine->registerSystem("BoidSystem", new BoidSystem);

    for (int i = 0; i < m_nbBoids; i++) {

        std::string entName = "boid";
        entName += std::to_string(i);

        auto e = m_engine->getEntityManager()->createEntity(entName);

        auto transformComp = new TransformComponent("key Frame", e);
        auto &physics = transformComp->getPhysics();
        Ra::Core::Geometry::TriangleMesh mesh;
        Ra::Core::Vector3f randomVector = Ra::Core::Vector3f::Random();
        if (i == 0) {
            mesh =
                Ra::Core::Geometry::makeCone((Ra::Core::Vector3f(0.2f, 0.5f, 0.f) + physics.position + randomVector),
                                             (Ra::Core::Vector3f(-0.3f, 0.5f, 0.f) + physics.position + randomVector),
                                             0.1f, 32, Ra::Core::Utils::Color::Red());
        }
        else {
            mesh =
                Ra::Core::Geometry::makeCone((Ra::Core::Vector3f(0.2f, 0.5f, 0.f) + physics.position + randomVector),
                                             (Ra::Core::Vector3f(-0.3f, 0.5f, 0.f) + physics.position + randomVector),
                                             0.1f, 32, Ra::Core::Utils::Color::Green());
        }

        auto meshComp = new Ra::Engine::Scene::TriangleMeshComponent(
                "mesh comp", e, std::move(mesh), nullptr);

        auto geometrySystem = m_engine->getSystem("GeometrySystem");
        geometrySystem->addComponent(e, meshComp);

        auto boidSys = m_engine->getSystem("BoidSystem");
        boidSys->addComponent(e, transformComp);
    }
    /* Cyan sphere */
    auto sphereToAvoid = Ra::Core::Geometry::makeParametricSphere(1.5_ra, Ra::Core::Utils::Color::Cyan());

    auto sphereEntity = m_engine->getEntityManager()->createEntity("Cyan sphere");
    auto sphereComponent = new Ra::Engine::Scene::TriangleMeshComponent("Sphere Mesh", sphereEntity,
                                                                        std::move(sphereToAvoid), nullptr);
    auto colComponent = new ColisionComponent("colcomp", sphereEntity, Ra::Core::Vector3f(0.f, 0.f, 0.f), 1.5f);
    BoidSystem * boidSys = static_cast<BoidSystem *>(m_engine->getSystem("BoidSystem"));
    boidSys->addToObstacles(*colComponent);
    /*auto &verts = sphereToAvoid.verticesWithLock();
    for (auto &v : verts) {
        // v -= transformComp->getPhysics().position;
        v += Ra::Core::Vector3f(3.f, 5.f, 0.f);
    }
    sphereToAvoid.verticesUnlock();*/

    auto geometrySystem = m_engine->getSystem("GeometrySystem");
    geometrySystem->addComponent(sphereEntity, sphereComponent);


    /* Cyan sphere n2 */
    //auto sphereToAvoid2 = Ra::Core::Geometry::makeGeodesicSphere(3.0_ra, 24, Ra::Core::Utils::Color::Cyan());

    //auto sphereEntity2 = m_engine->getEntityManager()->createEntity("Red sphere");
    //auto sphereComponent2 = new Ra::Engine::Scene::TriangleMeshComponent("Sphere Mesh 2", sphereEntity2,
    //                                                                    std::move(sphereToAvoid2), nullptr);
    //auto colComponent2 = new ColisionComponent("colcomp2", sphereEntity2, Ra::Core::Vector3f(2.f, 0.f, -1.f), 3.f);
    //boidSys->addToObstacles(*colComponent2);
    /*auto &verts = sphereToAvoid2.verticesWithLock();
    for (auto &v : verts) {
        // v -= transformComp->getPhysics().position;
        v += Ra::Core::Vector3f(2.f, 0.f, -1.f);
    }
    sphereToAvoid2.verticesUnlock();
    geometrySystem->addComponent(sphereEntity2, sphereComponent2);

    colisionSys->addComponent(sphereEntity2, colComponent2);*/

    m_mainWindow->prepareDisplay();
}
