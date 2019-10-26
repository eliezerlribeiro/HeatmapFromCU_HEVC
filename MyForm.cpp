#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

[STAThreadAttribute]

int main(array<String^>^ args) {
	FreeConsole();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HeatMapForm::MyForm form;

	Application::Run(% form);

	return 0;
}