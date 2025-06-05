#include "gui/window.hpp"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "WX") {

    wxSize screenSize = wxGetDisplaySize();
    int frameWidth = screenSize.GetWidth() / 2;
    int frameHeight = screenSize.GetHeight() / 2;
    wxPoint framePosition(screenSize.GetWidth() / 2, 0);
    SetSize(framePosition.x, framePosition.y, frameWidth, frameHeight);


}
