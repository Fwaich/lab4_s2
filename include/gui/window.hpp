#pragma once
#include <wx/wx.h>

enum MenuIDs {
   ID_Type_Int = 101,
   ID_Type_Double,
   ID_Type_String
};


enum ButtonIDs {
   ID_Append = 201,
   ID_Prepend,
   ID_Set,
   ID_Get,
   ID_GetFirst,
   ID_GetLast,
   ID_GetSize,
   ID_GetSub,
   ID_ShowSub,
   ID_Map
};

enum DataType {INT, DOUBLE, STRING};

class MyFrame : public wxFrame {
private:

   wxPanel* panel;

   DataType current_type = INT;

   wxString sub_str;

   wxTextCtrl* inputField;
   wxTextCtrl* displayBox;

   wxStaticText* structInfo;
   wxStaticText* typeInfo;


   void OnExit(wxCommandEvent& event);

   void OnSelectStructArray(wxCommandEvent& event);
   void OnSelectStructList(wxCommandEvent& event);
   void OnSelectTypeInt(wxCommandEvent& event);
   void OnSelectTypeDouble(wxCommandEvent& event);
   void OnSelectTypeString(wxCommandEvent& event);

   void UpdateDisplay();
   void UpdateLayout();
   void RecreateAdapter();

public:

   MyFrame();

};