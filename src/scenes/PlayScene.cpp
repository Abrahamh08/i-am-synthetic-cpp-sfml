//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

PlayScene::PlayScene() {
    /*uint16_t i = 0;
    while (boost::filesystem::exists(boost::filesystem::path(Locator::getResource()->loadPath("saves/save" + patch::to_string(++i))))) {
        std::cout << "test" << std::endl;
        fileButtons.push_back(std::make_shared<FileButton>(fileButtons));
    }*/

    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(&fileButtons, width, height);
    fileButtons.push_back(newFileButton);
    newFileButton->position();
}

bool PlayScene::updateButtons(sf::Event event, sf::RenderWindow &window) {
    bool stay = true;
    for (std::shared_ptr<Button> button : buttons) {
        if (!button->update(event, window)) stay = false;
    }

    for (std::shared_ptr<Button> fileButton : fileButtons) {
        if (!fileButton->update(event, window)) stay = false;
    }
    return stay;
}

void PlayScene::draw(sf::RenderWindow& window)  {
    window.clear();
    for (GameObject &obj : gameObjects) {
        window.draw(*obj.getSprite());
    }
    for (std::shared_ptr<Button> button : buttons) {
        window.draw(*button);
    }
    for (std::shared_ptr<Button> fileButton : fileButtons) {
        window.draw(*fileButton);
    }
    window.display();
}
