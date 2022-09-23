#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.hpp"
#include <vector>
#include <memory>


struct WorldImage {
    sf::Glsl::Vec3 pla_norm;
    sf::Glsl::Vec4 pla_col;
    std::vector<sf::Glsl::Vec4> sph_cord;
    std::vector<sf::Glsl::Vec4> sph_col;
    std::vector<sf::Glsl::Vec3> box_cord;
    std::vector<sf::Glsl::Vec4> box_col;
    std::vector<sf::Glsl::Mat3> triangle_cord;
    std::vector<sf::Glsl::Vec4> triangle_col;
};

class World {
    sf::Glsl::Vec3 pla_norm;
    sf::Glsl::Vec4 pla_col;
    std::vector<sf::Glsl::Vec4> sph_cord;
    std::vector<sf::Glsl::Vec4> sph_col;
    std::vector<sf::Glsl::Vec3> box_cord;
    std::vector<sf::Glsl::Vec4> box_col;
    std::vector<sf::Glsl::Mat3> triangle_cord;
    std::vector<sf::Glsl::Vec4> triangle_col;

public:
    explicit World(const WorldImage& image) :
        pla_norm(image.pla_norm),
        pla_col(image.pla_col),
        sph_cord(image.sph_cord),
        sph_col(image.sph_col),
        box_cord(image.box_cord),
        box_col(image.box_col),
        triangle_cord(image.triangle_cord),
        triangle_col(image.triangle_col) {};

    void LoadToShader(sf::Shader& shader) const;
    std::vector<std::unique_ptr<Figure>> Figures();
};
