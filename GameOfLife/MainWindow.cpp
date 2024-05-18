#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::OnSizeChange)
wxEND_EVENT_TABLE()

MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(400, 400)), gridSize(15) { // Initialize grid size
    drawingPanel = new DrawingPanel(this);
    boxSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer->Add(drawingPanel, 1, wxEXPAND | wxALL, 0);
    this->SetSizer(boxSizer);

    InitializeGrid(); // Initialize the game board grid
}

MainWindow::~MainWindow() {
    delete drawingPanel;
    delete boxSizer;
}

void MainWindow::OnSizeChange(wxSizeEvent& event) {
    wxSize size = this->GetClientSize();
    drawingPanel->SetSize(size);
    event.Skip();
}

void MainWindow::InitializeGrid() {
    gameBoard.resize(gridSize); // Resize the outer vector
    for (int i = 0; i < gridSize; ++i) {
        gameBoard[i].resize(gridSize, false); // Resize each inner vector and initialize cells to false (dead)
    }
    drawingPanel->SetGridSize(gridSize); // Set the grid size in the drawing panel
}

