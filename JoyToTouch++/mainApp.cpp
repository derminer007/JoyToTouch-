#include "mainApp.h"
//#define WinMain main

wxIMPLEMENT_APP_NO_MAIN(mainApp);	// benötigt in main wxEntry

int main(int argc, char** argv) {		// Subsystem Console in Linker/System aktiviert
	//std::cout << "Test" << std::endl;

	return wxEntry(argc, argv);
}

bool mainApp::OnInit() {

	mainF = new fenster();
	mainF->Show();

	return true;
}