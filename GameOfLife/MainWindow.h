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

	void OnSizeChange(wxSizeEvent& event);
	void InitializeGrid();

	wxDECLARE_EVENT_TABLE();
	

};




#endif // MAINWINDOW_H


