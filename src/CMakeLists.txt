set(CMAKE_BUILD_TYPE Release)


set(EXECUTABLE_OUTPUT_PATH ../)

set(Radium_DIR ${radium_config_dir})
find_package(Radium REQUIRED Core Engine Gui IO PluginBase)

set(Qt5_LIBRARIES Qt5::Core Qt5::Widgets)

# Source files
file(GLOB_RECURSE
source_files
./*)

add_executable(boids
${source_files})

# Linking
target_link_libraries(boids PUBLIC Radium::Core Radium::Engine Radium::Gui Radium::IO
        ${Qt5_LIBRARIES})

configure_radium_app(
    NAME ${PROJECT_NAME}
    USE_PLUGINS
)
