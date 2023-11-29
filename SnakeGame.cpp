#include "StartMenu.h"
#include "ScoreBoard.h"
#include "SnakeGame.h"
#include "NamePrompt.h"

using namespace System;
using namespace System::Windows::Forms;

int main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SnakeGame::StartMenu form;
	Application::Run(% form);
	return 0;
}