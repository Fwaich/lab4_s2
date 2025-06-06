#include "gui/window.hpp"
#include "core/Adapter.hpp"
#include "core/IntAdapter.hpp"
#include "core/DoubleAdapter.hpp"
#include "core/StringAdapter.hpp"
#include "core/Sequence.hpp"
#include "core/TreeSequence.hpp"
#include "core/TraversalAdapter.hpp"

void MyFrame::ChangeType()
{
    if (seq != nullptr) delete seq;

    if (current_type == INT) {
        seq = new IntAdapter(new TreeSequence<int>);
    }
    else if (current_type == DOUBLE) {
        seq = new DoubleAdapter(new TreeSequence<double>);
    }
    else if (current_type == STRING) {
        seq = new StringAdapter(new TreeSequence<std::string>);
    }

    UpdateDisplay();
}

void MyFrame::ChangeTraversal()
{
    ITraversal* traversal = nullptr;

    if (current_type == INT) {
        if (current_traversal == IN) {
            traversal = new TreeTraversalAdapter(new InOrderTraversal<int>());
        } else if (current_traversal == PRE) {
            traversal = new TreeTraversalAdapter(new PreOrderTraversal<int>());
        } else if (current_traversal == POST) {
            traversal = new TreeTraversalAdapter(new PostOrderTraversal<int>());
        }
    } 
    else if (current_type == DOUBLE) {
        if (current_traversal == IN) {
            traversal = new TreeTraversalAdapter(new InOrderTraversal<double>());
        } else if (current_traversal == PRE) {
            traversal = new TreeTraversalAdapter(new PreOrderTraversal<double>());
        } else if (current_traversal == POST) {
            traversal = new TreeTraversalAdapter(new PostOrderTraversal<double>());
        }
    } 
    else if (current_type == STRING) {
        if (current_traversal == IN) {
            traversal = new TreeTraversalAdapter(new InOrderTraversal<std::string>());
        } else if (current_traversal == PRE) {
            traversal = new TreeTraversalAdapter(new PreOrderTraversal<std::string>());
        } else if (current_traversal == POST) {
            traversal = new TreeTraversalAdapter(new PostOrderTraversal<std::string>());
        }
    }

    if (seq) {
        seq->set_traversal(traversal);
    }

    UpdateDisplay();
}


void MyFrame::OnSelectTraversalIn(wxCommandEvent& event)
{
    current_traversal = IN;
    ChangeTraversal();
    traversalInfo->SetLabel("Current traversal: InOrder");
    UpdateLayout();
}

void MyFrame::OnSelectTraversalPre(wxCommandEvent& event)
{
    current_traversal = PRE;
    ChangeTraversal();
    traversalInfo->SetLabel("Current traversal: PreOrder");
    UpdateLayout();
}

void MyFrame::OnSelectTraversalPost(wxCommandEvent& event)
{
    current_traversal = POST;
    ChangeTraversal();
    traversalInfo->SetLabel("Current traversal: PostOrder");
    UpdateLayout();
}

void MyFrame::OnSelectTypeInt(wxCommandEvent& event)
{
    current_type = INT;
    ChangeType();
    typeInfo->SetLabel("Current type: Int");
    UpdateLayout();
}

void MyFrame::OnSelectTypeDouble(wxCommandEvent& event)
{
    current_type = DOUBLE;
    ChangeType();
    typeInfo->SetLabel("Current type: Double");
    UpdateLayout();
}

void MyFrame::OnSelectTypeString(wxCommandEvent& event)
{
    current_type = STRING;
    ChangeType();
    typeInfo->SetLabel("Current type: String");
    UpdateLayout();
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    delete seq;
    Close(true);
}

void MyFrame::UpdateLayout() 
{
    panel->Layout();
    panel->Refresh(); 
}

