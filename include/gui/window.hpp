#pragma once
#include <wx/wx.h>
#include "core/Traversal.hpp"
#include "core/TraversalAdapter.hpp"
#include "core/Adapter.hpp"

enum MenuIDs {
   ID_Type_Int = 101,
   ID_Type_Double,
   ID_Type_String,
   ID_InOrderTraversal,
   ID_PreOrderTraversal,
   ID_PostOrderTraversal
};


enum ButtonIDs {
   ID_Add = 201,
   ID_Remove,
   ID_Set_Traversal,
   ID_Contains,
   ID_Extract_Subtree
};

enum DataType {INT, DOUBLE, STRING};
enum TraversalType {IN, PRE, POST};

class MyFrame : public wxFrame {
private:

   wxPanel* panel;

   DataType current_type = INT;
   TraversalType current_traversal = IN;
   Adapter* seq = nullptr;
   Adapter* sub_seq = nullptr;

   wxString sub_str;

   wxTextCtrl* inputField;
   wxTextCtrl* displayBox;

   wxStaticText* traversalInfo;
   wxStaticText* typeInfo;


   void OnExit(wxCommandEvent& event);

   void OnSelectInOrderTraversal(wxCommandEvent& event);
   void OnSelectPreOrderTraversal(wxCommandEvent& event);
   void OnSelectPostOrderTraversal(wxCommandEvent& event);

   void OnSelectTypeInt(wxCommandEvent& event);
   void OnSelectTypeDouble(wxCommandEvent& event);
   void OnSelectTypeString(wxCommandEvent& event);

   void OnAdd(wxCommandEvent& event);
   void OnRemove(wxCommandEvent& event);
   void OnContains(wxCommandEvent& event);


   void UpdateDisplay();
   void UpdateLayout();
   void RecreateAdapter();

public:

   MyFrame();

};