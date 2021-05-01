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
    : Ra::Gui::BaseApplication(argc, argv, applicationName, organizationName) {}

void MainApplication::setup() {

  auto mesh =
      Ra::Core::Geometry::makeCone({0.2f, 0.5f, 0.f}, {-0.3f, 0.5f, 0.f}, 0.1f,
                                   32, Ra::Core::Utils::Color::Green());

  auto e = m_engine->getEntityManager()->createEntity("boid");
  auto cTriMesh = new Ra::Engine::Scene::TriangleMeshComponent(
      "mesh comp", e, std::move(mesh), nullptr);
  auto cKeyFrame = new KeyFrameComponent("key Frame", e);

  auto geometrySystem = m_engine->getSystem("GeometrySystem");
  geometrySystem->addComponent(e, cTriMesh);

  m_engine->registerSystem("BoidSystem", new BoidSystem);
  auto boidSys = m_engine->getSystem("BoidSystem");
  boidSys->addComponent(e, cKeyFrame);

  auto cm = Ra::Engine::Scene::ComponentMessenger::getInstance();

  if (cm->canGet<Ra::Core::Geometry::TriangleMesh>(e, "mesh comp"))
    printf("plop main\n");

  m_mainWindow->prepareDisplay();
}
