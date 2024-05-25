#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wx.h>
#include <vector>

class MainWindow : public wxFrame {
public:
	MainWindow(const wxString& title);
	~MainWindow();

private:
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

	wxDECLARE_EVENT_TABLE();
	

};

#endif // MAINWINDOW_H


