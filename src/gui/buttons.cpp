#include "gui/window.hpp"
#include "core/exceptions.hpp"

void MyFrame::OnAdd(wxCommandEvent& event)
{   
    try 
    {

        std::string value = std::string(inputField->GetValue());
        if (value == "")  {
            wxMessageBox("Value required", "Data Error", wxOK | wxICON_ERROR);
            inputField->SetFocus();
            return;
        }
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

void MyFrame::OnWhere(wxCommandEvent& event)
{
    try 
    {
        wxTextEntryDialog dlg(this, "Enter filter value", "");
        if (dlg.ShowModal() != wxID_OK) {
            return;
        }

        wxString filter_str = dlg.GetValue();
        if (filter_str.IsEmpty()) {
            wxMessageBox("Error: filter value is required", "Error", wxICON_ERROR);
            return;
        }

        if (current_type == INT || current_type == DOUBLE) {
            std::string value = std::string(filter_str.mb_str());
            seq->where(value);
        } else if (current_type == STRING) {
            std::string value = std::string(filter_str.mb_str());
            seq->where(value);
        }

        inputField->SetFocus();
        UpdateDisplay();

    } catch(const data_is_null& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }
}

void MyFrame::OnGetSub(wxCommandEvent& event)
{
    try 
    {

        if (sub_seq != nullptr) {
            delete sub_seq;
        }
        
        std::string value = std::string(inputField->GetValue());

        if (value == "")  {
            wxMessageBox("Value required", "Data Error", wxOK | wxICON_ERROR);
            inputField->SetFocus();
            return;
        }

        sub_seq = seq->extract_subtree(value);
        
        sub_str = wxString::Format("Subtree from %s:\n%s",
            value,
            sub_seq->to_string()
        );
        
        wxMessageBox(sub_str, "Sub", wxOK | wxICON_NONE, this);
                                                             
    
    }  catch(const wrong_type& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }   catch(const data_is_null e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }
}

void MyFrame::OnShowSub(wxCommandEvent& event) 
{
    if (sub_str.IsEmpty()) {
        wxMessageBox("No subsequence generated yet.", "Info", 
            wxOK | wxICON_INFORMATION,
            this
        );
        return;
    }

    wxMessageBox(sub_str, "Sub", wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnMap(wxCommandEvent& event)
{
    try 
    {
        if (current_type != STRING){
                wxTextEntryDialog dlg(this, "Enter multiplier", "");
            if (dlg.ShowModal() != wxID_OK) {
                return;
            }

            wxString multiplier_str = dlg.GetValue();
            if (multiplier_str.IsEmpty()) {
                wxMessageBox("Error: multiplier is required", "Error", wxICON_ERROR);
                return;
            }
            
            double multiplier;
            if (!multiplier_str.ToDouble(&multiplier)) {
                wxMessageBox("Error: incorrect input", "Error", wxICON_ERROR);
                return;
            }

            seq->map(multiplier);
        
        } else {

            seq->map(0);
            
        }
        
        inputField->SetFocus();
        UpdateDisplay();

    } catch(const data_is_null& e){
        wxMessageBox(e.what(), "Data Error", wxOK | wxICON_ERROR);
    }
}

void MyFrame::UpdateDisplay()
{
    displayBox->Clear();
    // if (seq->get_size() == "0") return;
    std::string output = seq->to_string();
    displayBox->SetValue(output);
}