#include "GameMenu.h"
#include "GameForm.h"
#include <msclr/marshal_cppstd.h>
#include <string>

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

bool arrowBool = true;
int currentImageIndex = 0;

System::Void GameMenu::StartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	GameForm^ f = gcnew GameForm(this);
	f->Show();
	this->Hide();
}
System::Void GameMenu::startGame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	startGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonStartGame_onMouseDown.png");
}
System::Void GameMenu::startGame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	startGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonStartGame_onMouseUp.png");
}
System::Void GameMenu::startGame_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	startGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonStartGame_onMouseEnter.png");
}
System::Void GameMenu::startGame_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	startGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonStartGame_onMouseUp.png");
}

System::Void GameMenu::closeGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
System::Void GameMenu::closeGame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	closeGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonCloseGame_onMouseDown.png");
}
System::Void GameMenu::closeGame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	closeGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonCloseGame_onMouseUp.png");
}
System::Void GameMenu::closeGame_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	closeGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonCloseGame_onMouseEnter.png");
}
System::Void GameMenu::closeGame_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	closeGame->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonCloseGame_onMouseUp.png");
}

System::Void GameMenu::arrowRight_Click(System::Object^ sender, System::EventArgs^ e)
{
	arrowRight->Visible = false;		//скрытие всех компонентов 1-го меню
	startGame->Visible = false;
	timer1->Start();	//запуск таймера и анимации
	arrowBool = false;
}

System::Void GameMenu::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (!arrowBool) //проверка булевой переменной(true - анимация влево, false - анимация вправо) 
	{
		if (card->Left > -1900)	//таймер и анимация действует и перемещается вправо до момента пока координаты не достигнут установленного предела
			card->Left -= 100;
		else {	//если достигнут предел
			timer1->Stop();	//остановка таймера
			arrowLeft->Visible = true; //показ кнопки, возвращения на 1-ое меню
			this->BackgroundImage = Image::FromFile(Application::StartupPath + "\\assets\\bcg.png"); //смена свойства BackgroundImage у формы
			//показ всех элементов 2-го меню
			characters->Visible = true;
			arrowNext->Visible = true;
			arrowPrev->Visible = true;
			UserName->Visible = true;
			changeName->Visible = true;
		}
	}
	else {
		if (card->Left < 0)	//таймер и анимация действует и перемещается влево до момента пока координаты не достигнут установленного предела
			card->Left += 100;
		else {	//если достигнут предел
			timer1->Stop();	//остановка таймера
			arrowRight->Visible = true;	//показ кнопки, возвращения на 2-ое меню
			this->BackgroundImage = Image::FromFile(Application::StartupPath + "\\assets\\menuBackground.png"); //смена свойства BackgroundImage у формы
			//показ всех элементов 1-го меню
			startGame->Visible = true;
		}
	}
}

System::Void GameMenu::arrowLeft_Click(System::Object^ sender, System::EventArgs^ e)
{
	arrowNext->Visible = false;  //скрытие всех компонентов 2-го меню
	arrowPrev->Visible = false;
	characters->Visible = false;
	arrowLeft->Visible = false;
	UserName->Visible = false;
	changeName->Visible = false;
	timer1->Start();	//запуск таймера и анимации
	arrowBool = true;
}

System::Void GameMenu::arrowNext_Click(System::Object^ sender, System::EventArgs^ e)
{
	array<String^>^ images = gcnew array<String^>{ "character1.png", "character2.png", "character3.png", "character4.png"}; // массив картинок
	currentImageIndex++;		//установка номера картинки(следующей)
	if (currentImageIndex >= 4)	//всего в массиве 4 картинки, поэтому если ноиер равен 4, то значит стоит начать отсчёт сначала
	{
		currentImageIndex = 0;
	}
	characters->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + images[currentImageIndex]); //установка картинки соответсвующего номера
}

System::Void GameMenu::arrowPrev_Click(System::Object^ sender, System::EventArgs^ e)
{
	array<String^>^ images = gcnew array<String^>{ "character1.png", "character2.png", "character3.png", "character4.png"}; // массив картинок
	currentImageIndex--; //установка номера картинки(предыдущей)
	if (currentImageIndex < 0) //всего в массиве 4 картинки, поэтому если ноиер равен меньше 0, то значит стоит начать отсчёт с конца
	{
		currentImageIndex = 3;
	}
	characters->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + images[currentImageIndex]); //установка картинки соответсвующего номера
}

System::Void GameMenu::Unfocus(System::Object^ sender, System::EventArgs^ e)
{
	arrowPrev->Focus();
}

//кнопка изменения никкнейма игрока и её свойства:
bool changeNameBool = true;

System::Void GameMenu::changeName_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (changeNameBool) // проверка булевой переменной(true - можно изменять имя игрока, false - сохранить изменения и запрет именять имя игрока)
	{
		UserName->ReadOnly = false; //разрешение изменять имя игрока
		changeName->Image = Image::FromFile(Application::StartupPath + "\\assets\\save_onMouseUp.png"); //смена картинки на "сохранить"
		changeNameBool = false; //изменение на противоположное значение
	}
	else
	{
		UserName->ReadOnly = true;	//запрет изменять имя игрока
		changeName->Image = Image::FromFile(Application::StartupPath + "\\assets\\changeName_onMouseUp.png");	//смена картинки на "изменить"
		users[0].userName = msclr::interop::marshal_as<std::string>(UserName->Text);
		changeNameBool = true;	//изменение на противоположное значение
	}
}



