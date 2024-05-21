#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wx.h>
#include <vector>






class MainWindow : public wxFrame {

public:
	MainWindow(const wxString& title);
	~MainWindow();

private:

	void OnTimer(wxTimerEvent& event);
	void OnSizeChange(wxSizeEvent& event);
	void InitializeGrid();
	void UpdateStatusBar();
	void OnPlay(wxCommandEvent& event);
	void OnPause(wxCommandEvent& event);
	void OnNext(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	void CalculateNextGeneration();


    DrawingPanel* drawingPanel;
	wxBoxSizer* boxSizer;
	std::vector<std::vector<bool>> gameBoard;
	int gridSize;
	int generationCount;
	int livingCells;
	int GetLivingNeighborCount(int row, int col);
	wxStatusBar* statusBar;

	

	wxTimer* timer;
	int timerInterval;
	

	wxDECLARE_EVENT_TABLE();
	

};




#endif // MAINWINDOW_H


