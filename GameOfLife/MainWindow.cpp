#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::OnSizeChange)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(400, 400)) {
    drawingPanel = new DrawingPanel(this);
    boxSizer = new wxBoxSizer(wxVERTICAL); 

    boxSizer->Add(drawingPanel, 1, wxEXPAND | wxALL);

    // Set the sizer for the window
    this->SetSizer(boxSizer);
}


MainWindow::~MainWindow() {
    delete drawingPanel;
    delete boxSizer;
}

void MainWindow::OnSizeChange(wxSizeEvent& event) {
    wxSize size = this->GetClientSize(); // Get the new size of the window
    drawingPanel->SetSize(size); // Set the size of the drawing panel
    event.Skip();
}


