#include "MainWindow.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	gui0Xgame::MainWindow form;
	Application::Run(% form);
}
