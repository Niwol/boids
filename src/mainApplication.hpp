#pragma once

#include <memory>

#include <Core/Geometry/MeshPrimitives.hpp>
#include <Engine/RadiumEngine.hpp>
#include <Engine/Scene/Component.hpp>
#include <Gui/BaseApplication.hpp>

#include "boidSystem.hpp"

class MainApplication : public Ra::Gui::BaseApplication {
public:
  MainApplication(int &argc, char **argv,
                  QString applicationName = "RadiumEngine",
                  QString organizationName = "STORM-IRIT");

  void setup();

private:
};