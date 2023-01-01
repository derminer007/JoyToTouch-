#include "mainApp.h"
//#define WinMain main

wxIMPLEMENT_APP_NO_MAIN(mainApp);	// benötigt in main 

//SDL_WarpMouseGlobal(100, 100);	// verschiebt MouseZeiger
//SDL_GetGlobalMouseState(&x, &y);	// Nimmt Mousezeiger Position

int main(int argc, char** argv) {		// Subsystem Console in Linker/System aktiviert
	//std::cout << "Test" << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)	// Init SDL für Controller
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	printf("%i joysticks were found.\n\n", SDL_NumJoysticks());

	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		//SDL_Joystick* controller = SDL_JoystickNameForIndex

		if (SDL_JoystickNameForIndex(i) == NULL) {
			printf("Fehler beim Öffnen von Controller %d\n", i);
		}
		else {
			//printf("    Index: %d - Name: %s\n", i, SDL_JoystickName(SDL_JoystickOpen(i)));	// Bekomme Controller Instanz und erhalte den Namen daraus
			printf("    Index: %d - Name: %s\n", i, SDL_JoystickNameForIndex(i));	// Besser als zu Öffnen
		}
	}

	//SDL_Window* gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 320, SDL_WINDOW_SHOWN); /* I don't want this window! */

	// ControllerInput soll auch im Hintergrund möglich sein
	SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

	// Nutze EventHandler und öffne Controller
	SDL_JoystickEventState(SDL_ENABLE);
	//SDL_Joystick* controller = SDL_JoystickOpen(0);	// wähle Controller 0
	SDL_GameController* controller = SDL_GameControllerOpen(0);	// wähle Controller 0

	if (controller == NULL) {
		printf("Controller Opening Fail\n");
	}
	else {
		SDL_Event event;

		while (1) {
			while (SDL_PollEvent(&event)) {

				printf("%d\n", event.type);
				printf("Axis: %d\n", event.caxis.axis);

				switch (event.type) {
				case SDL_KEYDOWN:
					printf("Reached\n");
					break;
				case SDL_JOYAXISMOTION:
					if ((event.caxis.value < -3200) || (event.caxis.value > 3200)) {
						if (event.caxis.axis == 0) {	// Linker Analogstick: links-rechts
							printf("0: %d\n", event.caxis.value);
						}
						if (event.caxis.axis == 1) {	// Linker Analogstick: oben-unten
							printf("1: %d\n", event.caxis.value);
						}

						if (event.caxis.axis == 2) {	// Rechter Analogstick: links-rechts
							printf("2: %d\n", event.caxis.value);
						}
						if (event.caxis.axis == 3) {	// Rechter Analogstick: oben-unten
							printf("3: %d\n", event.caxis.value);
						}

						if (event.caxis.axis == 4) {	// L-Trigger
							printf("4: %d\n", event.caxis.value);
						}
						if (event.caxis.axis == 5) {	// R-Trigger
							printf("5: %d\n", event.caxis.value);
						}
					}
					break;
				case SDL_CONTROLLERBUTTONDOWN:
					printf("BDown\n");
					break;
				}
			}
		}
	}

	//return wxEntry(argc, argv);
	return 0;
}

bool mainApp::OnInit() {

	mainF = new fenster();
	mainF->Show();

	return true;
}