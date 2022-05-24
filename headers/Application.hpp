#pragma once

#include <string>
#include "KeyboardHandler.hpp"
#include "Window.hpp"


class Application {
    friend class Window;

    Settings settings;
    World world;
    Window window;

public:
    explicit Application(const std::string &settings_file,
                         const std::string &objects_file,
                         const std::string &shader_file) :
            settings(FileReader::get_settings(settings_file)),
            world(FileReader::get_world(objects_file)),
            window(settings, world, shader_file) {};

    void run();
};
