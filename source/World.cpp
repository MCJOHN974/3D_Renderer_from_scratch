#include "../headers/World.hpp"
#include "../headers/Sphere.hpp"
#include "../headers/Box.hpp"
#include "../headers/Triangle.hpp"
#include <memory>


void World::LoadToShader(sf::Shader& shader) const {
    shader.setUniform("u_pla_norm", pla_norm);
    shader.setUniform("u_pla_col", pla_col);
    shader.setUniform("u_sph_num", int(sph_col.size()));
    shader.setUniformArray("u_sph_cord", sph_cord.data(), sph_cord.size());
    shader.setUniformArray("u_sph_col", sph_col.data(), sph_col.size());
    shader.setUniform("u_box_num", int(box_col.size()));
    shader.setUniformArray("u_box_cord", box_cord.data(), box_cord.size());
    shader.setUniformArray("u_box_col", box_col.data(), box_col.size());
    shader.setUniform("u_triangle_num", int(triangle_col.size()));
    shader.setUniformArray("u_triangle_cord", triangle_cord.data(), triangle_cord.size());
    shader.setUniformArray("u_triangle_col", triangle_col.data(), triangle_col.size());
}

std::vector<std::unique_ptr<Figure>> World::Figures() {
    std::vector<std::unique_ptr<Figure>> ans;
    for (auto& v : sph_cord) {
        ans.push_back(std::make_unique<Sphere>(&v));
    }
    for (size_t i = 0; i < box_cord.size(); i+=2) {
        ans.push_back(std::make_unique<Box>(&box_cord[i]));
    }
    for (auto& v : triangle_cord) {
        ans.push_back(std::make_unique<Triangle>(&v));
    }
    return ans;
}
