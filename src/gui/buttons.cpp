#include "gui/window.hpp"
#include "core/exceptions.hpp"

void MyFrame::OnAdd(wxCommandEvent& event)
{   
    try 
    {

        std::string value = std::string(inputField->GetValue());
        seq->add(value);
        inputField->Clear();
        inputField->SetFocus();
        UpdateDisplay();
    
    } catch(const wrong_type& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }
}

void MyFrame::OnRemove(wxCommandEvent& event)
{
    try 
    {

        std::string value = std::string(inputField->GetValue());
        seq->remove(value);
        inputField->Clear();
        inputField->SetFocus();
        UpdateDisplay();
    
    } catch(const wrong_type& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    } catch(const no_such_element& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    };
}  

void MyFrame::OnContains(wxCommandEvent& event)
{
    try 
    {
        std::string value = std::string(inputField->GetValue());

        if (seq->contains(value)) {
            std::string result = "The tree contains the element: " + value;
            wxMessageBox(result, "Contais", wxOK | wxICON_NONE);
        } else {
            std::string result = "The tree does not contain the element: " + value;
            wxMessageBox(result, "Contais", wxOK | wxICON_NONE);
        }
        inputField->Clear();
        inputField->SetFocus();
        UpdateDisplay();

    } catch(const wrong_type& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }
}

// void MyFrame::OnGet(wxCommandEvent& event)
// {
//     try 
//     {

//         wxTextEntryDialog dlg(this, "Enter index", "");
//         if (dlg.ShowModal() != wxID_OK) {
//             return;
//         }

//         wxString index_str = dlg.GetValue();
//         if (index_str.IsEmpty()) {
//             wxMessageBox("Error: index is required", "Error", wxICON_ERROR);
//             return;
//         }

//         long index;
//         if (!index_str.ToLong(&index)) {
//             wxMessageBox("Error: index must be a number", "Error", wxICON_ERROR);
//             return;
//         }
    
//         wxMessageBox(seq->get((int)index), "Selected member", wxOK | wxICON_NONE, this);
//         inputField->SetFocus();
//         UpdateDisplay();

//     } catch(const array_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } catch(const list_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } 
// }


// void MyFrame::OnGetFirst(wxCommandEvent& event)
// {
//     try 
//     {

//         std::string value = seq->get_first();
//         wxMessageBox(value, "First Member", wxOK | wxICON_NONE, this);
//         inputField->SetFocus();
    
//     } catch(const array_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } catch(const list_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } 
// }

// void MyFrame::OnGetLast(wxCommandEvent& event)
// {
//     try 
//     {

//         std::string value = seq->get_last();
//         wxMessageBox(value, "Last Member", wxOK | wxICON_NONE, this);
//         inputField->SetFocus();
    
//     } catch(const array_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } catch(const list_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } 
// }

// void MyFrame::OnGetSize(wxCommandEvent& event)
// {
//     std::string value = seq->get_size();
//     wxMessageBox(value, "Size Of Struct", wxOK | wxICON_NONE, this);
//     inputField->SetFocus();
// }

// void MyFrame::OnGetSub(wxCommandEvent& event)
// {
//     try 
//     {

//         SubInput dialog(this, "Get Sub");
//         if (dialog.ShowModal() == wxID_OK) {
    
//             if (sub_seq != nullptr){
//                 delete sub_seq;
//             }
    
//             long start_index, end_index;
//             if (!dialog.GetStartIndex().ToLong(&start_index) || !dialog.GetEndIndex().ToLong(&end_index)) {
//                 wxMessageBox("Invalid input. Please enter correct indexes.", "Error", wxOK | wxICON_ERROR);
//                 return;
//             }
    
//             sub_seq = seq->get_subsequence((int)start_index, (int)end_index);
//             sub_str = wxString::Format("Subsequence from %ld to %ld:\n%s",
//                 start_index, end_index,
//                 sub_seq->to_string()
//             );
    
//             wxMessageBox(sub_str, "Sub", wxOK | wxICON_NONE, this);                                             
            
//         }
    
//     } catch(const array_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     } catch(const list_out_of_range& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     }  catch(const data_is_null& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     }
// }

// void MyFrame::OnShowSub(wxCommandEvent& event) 
// {
//     if (sub_str.IsEmpty()) {
//         wxMessageBox("No subsequence generated yet.", "Info", 
//             wxOK | wxICON_INFORMATION,
//             this
//         );
//         return;
//     }

//     wxMessageBox(sub_str, "Sub", wxOK | wxICON_INFORMATION, this);
// }

// void MyFrame::OnMap(wxCommandEvent& event)
// {
//     try 
//     {
//         if (current_type != STRING){
//                 wxTextEntryDialog dlg(this, "Enter multiplier", "");
//             if (dlg.ShowModal() != wxID_OK) {
//                 return;
//             }

//             wxString multiplier_str = dlg.GetValue();
//             if (multiplier_str.IsEmpty()) {
//                 wxMessageBox("Error: multiplier is required", "Error", wxICON_ERROR);
//                 return;
//             }
            
//             double multiplier;
//             if (!multiplier_str.ToDouble(&multiplier)) {
//                 wxMessageBox("Error: incorrect input", "Error", wxICON_ERROR);
//                 return;
//             }

//             seq->map(multiplier);
        
//         } else {

//             seq->map(0);
            
//         }
        
//         // wxMessageBox(seq->get((int)index), "Selected member", wxOK | wxICON_NONE, this);
//         inputField->SetFocus();
//         UpdateDisplay();

//     } catch(const data_is_null& e){
//         wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
//     }
// }

void MyFrame::UpdateDisplay()
{
    displayBox->Clear();
    // if (seq->get_size() == "0") return;
    std::string output = seq->to_string();
    displayBox->SetValue(output);
}