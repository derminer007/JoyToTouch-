#pragma once
#include <iostream>
#include <wx/wx.h>
#include <SDL.h>
#include "fenster.h"
class mainApp : public wxApp
{
private:
	fenster* mainF;
public:
	virtual bool OnInit();
};

