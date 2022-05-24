#include "../headers/Window.hpp"


Window::Window(const Settings &settings, const World &world, const std::string &shader_name) :
        _window(settings.CreateVideoMode(),
                "Ray tracing",
                sf::Style::Titlebar | sf::Style::Close),
        _shader(), _emptyTexture() {
    _window.setFramerateLimit(40);
    _window.setMouseCursorVisible(false);
    settings.CreateTexture(_emptyTexture);
    _emptySprite = sf::Sprite(_emptyTexture.getTexture());
    _shader.loadFromFile(shader_name, sf::Shader::Fragment);
    settings.PrepareShader2(_shader);
    _shader.setUniform("u_pla_norm", world.pla_norm);
    _shader.setUniform("u_pla_col", world.pla_col);
    _shader.setUniform("u_sph_num", int(world.sph_col.size()));
    _shader.setUniformArray("u_sph_cord", world.sph_cord.data(), world.sph_cord.size());
    _shader.setUniformArray("u_sph_col", world.sph_col.data(), world.sph_col.size());
    _shader.setUniform("u_box_num", int(world.box_col.size()));
    _shader.setUniformArray("u_box_cord", world.box_cord.data(), world.box_cord.size());
    _shader.setUniformArray("u_box_col", world.box_col.data(), world.box_col.size());
    _shader.setUniform("u_tri_num", int(world.tri_col.size()));
    _shader.setUniformArray("u_tri_cord", world.tri_cord.data(), world.tri_cord.size());
    _shader.setUniformArray("u_tri_col", world.tri_col.data(), world.tri_col.size());
    std::random_device RandomGenerator;
    _e2 = std::mt19937(RandomGenerator());
    _dist = std::uniform_real_distribution<>(0.0f, 1.0f);
    _change = true;
}
