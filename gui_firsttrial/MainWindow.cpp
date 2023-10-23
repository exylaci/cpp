#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	guifirsttrial::MainWindow form;
	Application::Run(% form);
}