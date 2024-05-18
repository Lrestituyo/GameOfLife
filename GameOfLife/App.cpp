#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainWindow* mainWindow = new MainWindow ("Game Of Life");
	mainWindow->Show(true);


	return true;
}