#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <boost/filesystem.hpp>
#include "resources/LocalResources.h"
#include "scenes/MainMenuScene.h"

void handleTransition(sf::RenderWindow& splash) {
    sf::Clock clock;
    Locator::provideMusic(Locator::getResource()->loadMusic("main-menu", "intro.wav"));
    std::unique_ptr<sf::Music>& introMusic = Locator::getMusic();
    introMusic->setVolume(20); // TODO: think about this
    introMusic->setLoop(true);
    introMusic->play();

    std::string configPath = Locator::getResource()->loadPath("config.yaml");
    YAML::Node &config = Locator::currentConfig;

    for (auto it = Locator::defaultConfig.begin(); it != Locator::defaultConfig.end(); ++it) {
        std::string key = it->first.as<std::string>();
        if (!config[key]) {
            config[key] = Locator::defaultConfig[key];
        }
    }

    std::ofstream fout(configPath);
    fout << config;

    sf::RenderWindow mainMenu;
    MainMenuScene mainMenuScene = MainMenuScene();

    while (splash.isOpen()) {
        const float timePassed = clock.getElapsedTime().asSeconds();
        if (timePassed >= 3) {
            splash.close();
        } else {
            sf::Event event;
            while (splash.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    splash.close();
                    exit(0);
                }
            }
        }
    }

    mainMenuScene.loop(mainMenu);
}

int main(int argc, char** argv) {
    const float scale = .6;

    const uint16_t width = (uint16_t) (sf::VideoMode::getDesktopMode().width * scale);
    const uint16_t height = (uint16_t) (sf::VideoMode::getDesktopMode().height * scale);
    const uint16_t windowDim = (uint16_t) (std::min(width, height) * scale);

    Locator::provideArgs(argv[0]);

    Locator::provideResourcesService(std::make_unique<LocalResources>());
    MainMenuTextures::init();

    std::string defaultConfigPath = Locator::getResource()->loadPath("default-config.yaml");
    std::string configPath = Locator::getResource()->loadPath("config.yaml");
    Locator::provideConfig(defaultConfigPath, Configs::DEFAULT);
    Locator::provideConfig(configPath, Configs::CURRENT);

    sf::Texture splash = Locator::getResource()->loadTexture("main-menu", "splash.png");
    sf::Sprite splashSprite;
    splashSprite.setScale((float) windowDim / splash.getSize().x, (float) windowDim / splash.getSize().y);
    splashSprite.setTexture(splash);

    sf::RenderWindow window(sf::VideoMode(windowDim, windowDim), "(Loading) I Am Synthetic", sf::Style::None);
    window.clear();
    window.draw(splashSprite);
    window.display();

    handleTransition(window);
    return 0;
}
