#include "gui/window.hpp"
#include "core/Adapter.hpp"
#include "core/TreeSequence.hpp"
#include "core/IntAdapter.hpp"
#include "core/DoubleAdapter.hpp"
#include "core/StringAdapter.hpp"


MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "WX") {

    wxSize screenSize = wxGetDisplaySize();
    int frameWidth = screenSize.GetWidth() / 2;
    int frameHeight = screenSize.GetHeight() / 2;
    wxPoint framePosition(screenSize.GetWidth() / 2, 0);
    SetSize(framePosition.x, framePosition.y, frameWidth, frameHeight);

    wxMenu* menuTraversal = new wxMenu;
    menuTraversal->Append(ID_InOrderTraversal, "InOrder");
    menuTraversal->Append(ID_PreOrderTraversal, "PreOrder");
    menuTraversal->Append(ID_PostOrderTraversal, "PostOrder");

    wxMenu* menuType = new wxMenu;
    menuType->Append(ID_Type_Int, "Int");
    menuType->Append(ID_Type_Double, "Double");
    menuType->Append(ID_Type_String, "String");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuTraversal, "&Traversal");
    menuBar->Append(menuType, "&Type");
    SetMenuBar(menuBar);

    current_traversal = IN;
    current_type = INT;
    seq = new IntAdapter(new TreeSequence<int>());
    
    panel = new wxPanel(this);

    traversalInfo = new wxStaticText(panel, wxID_ANY, "Current traversal: InOrder");
    typeInfo = new wxStaticText(panel, wxID_ANY, "Current type: Int");

    wxBoxSizer* infoBox = new wxBoxSizer(wxHORIZONTAL);
    infoBox->Add(traversalInfo, 0, wxLEFT, 5);
    infoBox->Add(typeInfo, 0, wxLEFT, 10);

    inputField = new wxTextCtrl(panel, wxID_ANY, "");
    displayBox = new wxTextCtrl(
        panel, wxID_ANY, "",
        wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH | wxTE_WORDWRAP
    );

    wxPanel* buttonPanel = new wxPanel(panel);
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer* baseBox = new wxBoxSizer(wxVERTICAL);
    baseBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Basic"), 0, wxALL, 5);
    baseBox->Add(new wxButton(buttonPanel, ID_Add, "Add"), 0, wxALL, 5);
    baseBox->Add(new wxButton(buttonPanel, ID_Remove, "Remove"), 0, wxALL, 5);
    baseBox->Add(new wxButton(buttonPanel, ID_Contains, "Contains"), 0, wxALL, 5);

    wxBoxSizer* advancedBox = new wxBoxSizer(wxVERTICAL);
    advancedBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Advanced"), 0, wxALL, 5);
    advancedBox->Add(new wxButton(buttonPanel, ID_Map, "Map"), 0, wxALL, 5);
    advancedBox->Add(new wxButton(buttonPanel, ID_Where, "Where"), 0, wxALL, 5);

    wxBoxSizer* subsBox = new wxBoxSizer(wxVERTICAL);
    subsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Subs"), 0, wxALL, 5);
    subsBox->Add(new wxButton(buttonPanel, ID_Extract_Subtree, "Get Subtree"), 0, wxALL, 5);
    subsBox->Add(new wxButton(buttonPanel, ID_Show_Subtree, "Show Subtree"), 0, wxALL, 5);

    // wxBoxSizer* funcsBox = new wxBoxSizer(wxVERTICAL);
    // funcsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Funcs"), 0, wxALL, 5);

    hbox->Add(baseBox, 1, wxEXPAND | wxALL, 10);
    hbox->Add(advancedBox, 1, wxEXPAND | wxALL, 10);
    hbox->Add(subsBox, 1, wxEXPAND | wxALL, 10);
    // hbox->Add(funcsBox, 1, wxEXPAND | wxALL, 10);

    buttonPanel->SetSizer(hbox);

    //expand - перпердекулярно, proportion - вдоль оси сайзера
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(infoBox, 0, wxALL, 10);
    mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Target Value:"), 0, wxTOP | wxLEFT, 10);
    mainSizer->Add(inputField, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(displayBox, 1, wxEXPAND | wxALL, 10); 
    mainSizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    Bind(wxEVT_BUTTON, &MyFrame::OnAdd, this, ID_Add);
    Bind(wxEVT_BUTTON, &MyFrame::OnRemove, this, ID_Remove);
    Bind(wxEVT_BUTTON, &MyFrame::OnContains, this, ID_Contains);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetSub, this, ID_Extract_Subtree);
    Bind(wxEVT_BUTTON, &MyFrame::OnMap, this, ID_Map);
    Bind(wxEVT_BUTTON, &MyFrame::OnWhere, this, ID_Where);
    Bind(wxEVT_BUTTON, &MyFrame::OnShowSub, this, ID_Show_Subtree);

    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeInt, this, ID_Type_Int);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeDouble, this, ID_Type_Double);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeString, this, ID_Type_String);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTraversalIn, this, ID_InOrderTraversal);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTraversalPre, this, ID_PreOrderTraversal);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTraversalPost, this, ID_PostOrderTraversal);
}
