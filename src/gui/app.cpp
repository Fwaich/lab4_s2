#include "gui/app.hpp"
#include "gui/window.hpp"

bool myApp::OnInit(){
    MyFrame* frame = new MyFrame(); 
    frame->Show(true);
    return true;
}
 