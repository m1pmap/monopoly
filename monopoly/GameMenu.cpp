#include "GameMenu.h"
#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace monopoly;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	monopoly::GameMenu form1;
	Application::Run(% form1);
}

System::Void GameMenu::StartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	GameForm^ f = gcnew GameForm(this);
	f->Show();
	this->Hide();
}

System::Void GameMenu::closeGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
