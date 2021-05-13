#include "mainApplication.hpp"
#include "mainWindow.hpp"

#include <Core/Geometry/MeshPrimitives.hpp>
#include <Engine/Scene/ComponentMessenger.hpp>
#include <Engine/Scene/EntityManager.hpp>
#include <Engine/Scene/GeometryComponent.hpp>
#include <Engine/Scene/GeometrySystem.hpp>

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

    auto mesh =
        Ra::Core::Geometry::makeCone({0.2f, 0.5f, 0.f}, {-0.3f, 0.5f, 0.f},
                                     0.1f, 32, Ra::Core::Utils::Color::Green());

    auto e = m_engine->getEntityManager()->createEntity(entName);
    auto meshComp = new Ra::Engine::Scene::TriangleMeshComponent(
        "mesh comp", e, std::move(mesh), nullptr);
    auto transformComp = new TransformComponent("key Frame", e);

    auto geometrySystem = m_engine->getSystem("GeometrySystem");
    geometrySystem->addComponent(e, meshComp);

    auto boidSys = m_engine->getSystem("BoidSystem");
    boidSys->addComponent(e, transformComp);
  }

  m_mainWindow->prepareDisplay();
}
