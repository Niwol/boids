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
  auto c = new Ra::Engine::Scene::TriangleMeshComponent(
      "mesh comp", e, std::move(mesh), nullptr);

  auto compMes = Ra::Engine::Scene::ComponentMessenger::getInstance();

  auto geometrySystem = m_engine->getSystem("GeometrySystem");
  geometrySystem->addComponent(e, c);

  m_mainWindow->prepareDisplay();
}
