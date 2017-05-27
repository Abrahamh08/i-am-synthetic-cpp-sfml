//
// Created by cilan on 4/3/2017.
//

#include "TextInput.h"

TextInput::TextInput(std::string promptString, std::string defaultText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn, uint16_t len) : promptText(promptString, MainMenuTextures::defaultFont) {
    this->cancelBtn = cancelBtn;
    this->okBtn = okBtn;
    this->maxLen = len;
    this->cancelBtn->setRelativeScale();
    this->okBtn->setRelativeScale();
    const uint8_t gap = 20;
    const float btnWidth = this->cancelBtn->getTexture()->getSize().x * this->cancelBtn->getScale().x;
    const float btnHeight = this->cancelBtn->getTexture()->getSize().y * this->cancelBtn->getScale().y;
    this->cancelBtn->setPosition(gap, height - gap - btnHeight);
    this->okBtn->setPosition(width - gap - btnWidth, height - gap - btnHeight);
    sf::IntRect windowBounds = sf::IntRect(0, 0, width, height);
    TextureLoader::put("text-input/background", Locator::getResource()->loadTexture("standard", "standard-repeated.jpg"));
    sf::Texture& background = TextureLoader::get("text-input/background");
    background.setRepeated(true);
    std::shared_ptr<SpriteObject> backgroundObject = std::make_shared<SpriteObject>(background);
    backgroundObject->getSprite().setTextureRect(windowBounds);

    promptText.setCharacterSize(30);

    this->gameObjects = {backgroundObject};
    this->buttons = {this->cancelBtn, this->okBtn};
}

void TextInput::sDraw(sf::RenderWindow& window) {
    window.draw(promptText);
}

void TextInput::handleEvent(sf::Event event) {

}