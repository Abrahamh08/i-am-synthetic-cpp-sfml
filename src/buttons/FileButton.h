//
// Created by cilan on 3/29/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_FILEBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_FILEBUTTON_H

#include <crispsynth/buttons/Button.h>
#include "../Data.h"

class FileButton : public Button {
public:
    FileButton(std::vector<std::shared_ptr<FileButton>>& fileArray, std::string name);
    ~FileButton() {}
    bool selected = false;
    Data data = Data();
private:
    void sClickHandler();
    void sHoverHandler(bool first);
    void sHoverExit();
    std::vector<std::shared_ptr<FileButton>> &fileButtons;
};

#endif
