//
// Created by Abraham Hamidi on 3/9/17.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CREDITSBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CREDITSBUTTON_H

#include "../Synthy.h"
#include "MainMenuButton.h"

class CreditsButton : public MainMenuButton {
    using MainMenuButton::MainMenuButton;
public:
    ~CreditsButton(){}
protected:
    virtual void clickHandler(Game &game) override;
    virtual void clickHandler(Synthy &game);
};

#endif
