//
// Created by cilan on 1/22/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_NULLRESOURCES_H
#define I_AM_SYNTHETIC_C_SFML_NULLRESOURCES_H

#include <iostream>
#include "IResources.h"

class NullResources : public IResources {
public:
    virtual sf::Texture loadTexture(std::string state, std::string id, sf::IntRect* rect = 0) override;
    virtual std::unique_ptr<sf::Music> loadMusic(std::string state, std::string id) override;
    virtual std::unique_ptr<YAML::Node> loadYAML(std::string state) override;
};
#endif