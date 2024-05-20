#include "MainWindow.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"


wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::OnSizeChange)
EVT_SIZE(MainWindow::OnSizeChange)
EVT_MENU(10001, MainWindow::OnPlay)
EVT_MENU(10002, MainWindow::OnPause)
EVT_MENU(10003, MainWindow::OnNext)
EVT_MENU(10004, MainWindow::OnClear)
wxEND_EVENT_TABLE()

MainWindow::MainWindow(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(400, 400)), gridSize(15), gameBoard(gridSize, std::vector<bool>(gridSize, false)),
generations(0), livingCells(0) { 
    
    // Initialize grid size
    drawingPanel = new DrawingPanel(this, gameBoard);
    boxSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer->Add(drawingPanel, 1, wxEXPAND | wxALL, 0);
    this->SetSizer(boxSizer);

    InitializeGrid(); // Initialize the game board grid

    // initialize Status Bar
    statusBar = this->CreateStatusBar();
    UpdateStatusBar();

    //Create toolbar
    wxToolBar* toolbar = this->CreateToolBar();
    wxBitmap playIcon(play_xpm);
    wxBitmap pauseIcon(pause_xpm);
    wxBitmap nextIcon(next_xpm);
    wxBitmap trashIcon(trash_xpm);


    toolbar->AddTool(10001, "Play", playIcon);
    toolbar->AddTool(10002, "Pause", pauseIcon);
    toolbar->AddTool(10003, "Next", nextIcon);
    toolbar ->AddTool(10004, "Trash", trashIcon);
    toolbar->Realize();
}

MainWindow::~MainWindow() {
   
}

int MainWindow::GetLivingNeighborcount(int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < gridSize && newCol >= 0 && newCol < gridSize) {
                if (gameBoard[newRow][newCol]) {
                    ++count;
                }
            }
        }
    }
    return count;
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

void MainWindow::UpdateStatusBar()
{
}

void MainWindow::OnPlay(wxCommandEvent& event)
{
}

void MainWindow::OnPause(wxCommandEvent& event)
{
}

void MainWindow::OnNext(wxCommandEvent& event)
{
}

void MainWindow::OnClear(wxCommandEvent& event)
{
}

