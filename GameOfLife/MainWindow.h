#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wx.h>
#include <vector>
#include "DrawingPanel.h"



class MainWindow : public wxFrame {

public:
	MainWindow(const wxString& title);
	~MainWindow();

private:
	DrawingPanel* drawingPanel;
	wxBoxSizer* boxSizer;
	std::vector<std::vector<bool>> gameBoard;
	int gridSize;
	int generations;
	int livingCells;
	int GetLivingNeighborcount(int row, int col);
	wxStatusBar* statusBar;

	void OnSizeChange(wxSizeEvent& event);
	void InitializeGrid();
	void UpdateStatusBar();
	void OnPlay(wxCommandEvent& event);
	void OnPause(wxCommandEvent& event);
	void OnNext(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	

	wxDECLARE_EVENT_TABLE();
	

};




#endif // MAINWINDOW_H


