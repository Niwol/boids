#include <Gui/SelectionManager/SelectionManager.hpp>
#include <Gui/Viewer/Viewer.hpp>

#include "mainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : Ra::Gui::MainWindowInterface(parent) {

  resize(800, 600);

  m_viewer = std::make_unique<Ra::Gui::Viewer>();
  m_viewer->setObjectName(QStringLiteral("m_viewer"));

  m_sceneModel = std::make_unique<Ra::Gui::ItemModel>(
      Ra::Engine::RadiumEngine::getInstance(), this);
  m_selectionManager =
      std::make_unique<Ra::Gui::SelectionManager>(m_sceneModel.get(), this);

  auto viewerWidget = QWidget::createWindowContainer(m_viewer.get());
  viewerWidget->setAutoFillBackground(false);
  setCentralWidget(viewerWidget);
  setWindowTitle(QString("Test"));
  createConnections();
}

MainWindow::~MainWindow() = default;

Ra::Gui::Viewer *MainWindow::getViewer() { return m_viewer.get(); }
Ra::Gui::SelectionManager *MainWindow::getSelectionManager() {
  return m_selectionManager.get();
}
Ra::Gui::Timeline *MainWindow::getTimeline() { return nullptr; }

void MainWindow::updateUi(Ra::Plugins::RadiumPluginInterface *plugin) {}
void MainWindow::onFrameComplete() {}
void MainWindow::addRenderer(
    const std::string &name,
    std::shared_ptr<Ra::Engine::Rendering::Renderer> e) {
  m_viewer->addRenderer(e);
}

void MainWindow::prepareDisplay() {
  m_selectionManager->clear();
  if (m_viewer->prepareDisplay()) {
    emit frameUpdate();
  }
}
void MainWindow::cleanup() { m_viewer.reset(nullptr); }

void MainWindow::frameUpdate() {}

void MainWindow::createConnections() {}
