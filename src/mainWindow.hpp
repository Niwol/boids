#pragma once

#include <iostream>

#include <Gui/MainWindowInterface.hpp>
#include <Gui/TreeModel/EntityTreeModel.hpp>

class MainWindow : public Ra::Gui::MainWindowInterface {
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

public:
  Ra::Gui::Viewer *getViewer() override;
  Ra::Gui::SelectionManager *getSelectionManager() override;
  Ra::Gui::Timeline *getTimeline() override;

  void updateUi(Ra::Plugins::RadiumPluginInterface *plugin) override;
  void onFrameComplete() override;
  void addRenderer(const std::string &name,
                   std::shared_ptr<Ra::Engine::Rendering::Renderer> e) override;

public slots:

  void prepareDisplay() override;
  void cleanup() override;

signals:
  void frameUpdate();

private:
  void createConnections();

  std::unique_ptr<Ra::Gui::Viewer> m_viewer;
  std::unique_ptr<Ra::Gui::SelectionManager> m_selectionManager;
  std::unique_ptr<Ra::Gui::ItemModel> m_sceneModel;
};