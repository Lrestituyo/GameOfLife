#include "MainWindow.h"
#include "DrawingPanel.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"
#include <iostream>


wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::OnSizeChange)
EVT_MENU(10001, MainWindow::OnPlay)
EVT_MENU(10002, MainWindow::OnPause)
EVT_MENU(10003, MainWindow::OnNext)
EVT_MENU(10004, MainWindow::OnClear)
EVT_TIMER(10005, MainWindow::OnTimer)
wxEND_EVENT_TABLE()

MainWindow::MainWindow(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, "Game of Life",wxDefaultPosition, wxSize(600, 600)), gridSize(15),
generationCount(0), livingCells(0), timerInterval(50) { 
    
    // Initialize grid size
  
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


    drawingPanel = new DrawingPanel(this, gameBoard);
    boxSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer->Add(drawingPanel, 1, wxEXPAND | wxALL, 0);
    this->SetSizer(boxSizer);

    InitializeGrid(); // Initialize the game board grid

    timer = new wxTimer(this, 10005);
    std::cout << " MainWindow initialized successfully" << std::endl;

}

MainWindow::~MainWindow() {
    std::cout << "Destroying MainWindow" << std::endl;
    if (timer->IsRunning()) {
        timer->Stop();
    }
    delete timer;
}

int MainWindow::GetLivingNeighborCount(int row, int col)
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

void MainWindow::OnTimer(wxTimerEvent& event)
{
    CalculateNextGeneration();
}

void MainWindow::OnSizeChange(wxSizeEvent& event) {
    if (drawingPanel) {
        wxSize size = this->GetClientSize();
        drawingPanel->SetSize(size);
            drawingPanel->Refresh();
    }
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
    wxString statusText;
    statusText.Printf("Generations: %d Living Cells: %d", generationCount, livingCells);
    statusBar->SetStatusText(statusText);
}

void MainWindow::OnPlay(wxCommandEvent& event)
{
    std::cout << "Timer started with interval " << std::endl;
    if (!timer->IsRunning()) {
        timer->Start(timerInterval);
        std::cout << "Timer started with interval " << timerInterval << "ms" << std::endl;
    }
    else {
        std::cout << "Timer already running" << std::endl;
    }
}

void MainWindow::OnPause(wxCommandEvent& event)
{
    std::cout << "Pause button clicked " << std::endl;
    if (!timer->IsRunning()) {
        timer->Stop();
        std::cout << "Timer stopped " << std::endl;
    }
    else {
        std::cout << "Timer is not running" << std::endl;
    }
}

void MainWindow::OnNext(wxCommandEvent& event)
{
    std::cout << "Next button clicked" << std::endl;
    CalculateNextGeneration();
}

void MainWindow::OnClear(wxCommandEvent& event)
{
    std::cout << "clear button clicked" << std::endl;
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            gameBoard[row][col] = false;
        }
    }
    
    generationCount = 0;
    livingCells = 0;
    
    UpdateStatusBar();

    drawingPanel->Refresh();

    std::cout << "Grid cleared" << std::endl;
}

void MainWindow::CalculateNextGeneration()
{
    std::vector<std::vector<bool>> sandbox(gridSize, std::vector<bool>(gridSize, false));
    int newLivingCells = 0;

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            int livingNeighbors = GetLivingNeighborCount(row, col);
            if (gameBoard[row][col]) {
                if (livingNeighbors < 2 || livingNeighbors > 3) {
                    sandbox[row][col] = false;  // Cell dies
                }
                else {
                    sandbox[row][col] = true;   // Cell lives
                    ++newLivingCells;
                }
            }
            else {
                if (livingNeighbors == 3) {
                    sandbox[row][col] = true;   // Cell becomes alive
                    ++newLivingCells;
                }
            }
        }
    }

    gameBoard.swap(sandbox);
    livingCells = newLivingCells;
    ++generationCount;
    UpdateStatusBar();
    drawingPanel->Refresh();


    
}

