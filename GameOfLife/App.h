#pragma once

#include "wx/wx.h"
#include "MainWindow.h"


class App : public wxApp
{
private: 
	MainWindow* mainWindow;

public:
	virtual bool OnInit();
};

