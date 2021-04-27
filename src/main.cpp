#include <Gui/BaseApplication.hpp>

#include "mainApplication.hpp"
#include "mainWindow.hpp"

#include <iostream>

class MainWindowFactory : public Ra::Gui::BaseApplication::WindowFactory {
public:
  using Ra::Gui::BaseApplication::WindowFactory::WindowFactory;
  Ra::Gui::MainWindowInterface *createMainWindow() const override {
    return new MainWindow();
  }
};

int main(int argc, char *argv[]) {

  MainApplication app(argc, argv);
  app.initialize(MainWindowFactory{});

  app.setup();

  return app.exec();
}
