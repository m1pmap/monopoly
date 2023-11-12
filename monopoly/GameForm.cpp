#include "GameForm.h"
#include "GameMenu.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <chrono>

Player::Player() {
	userName = "UserName";
	cash = 3000;
	streetMoney = 85;
}

Player* users = new Player[Player::playersNum];

Cell board[40];

using namespace monopoly;


//Ã≈“Œƒ€  À¿——¿ PLAYER
void Player::PlayersMoving(System::Windows::Forms::PictureBox^ player, int dice, Cell board[])
{
	this->currentPos = this->currentPos + dice;
	if (this->currentPos > 40)
		this->currentPos -= 40;
	player->Location = System::Drawing::Point(board[this->currentPos - 1].x, board[this->currentPos - 1].y);
}

int Player::GetCurrentPos() //‚ÓÁ‚‡˘‡ÂÚ ÚÂÍÛ˘Û˛ ÔÓÁËˆË˛ ÔÓÎ¸ÁÓ‚‡ÚÂÎˇ
{
	return this->currentPos;
}

void Player::SetCurrentPos(int dice)
{
	if (this->currentPos + dice > 40)
	{
		this->currentPos = this->currentPos + dice - 40;
	}
	else
	{
		this->currentPos += dice;
	}
}

//Ã≈“Œƒ€  À¿——¿ CELL
int Cell::OnCell(Player users[])
{
	int count = 0;
	for (int i = 0; i < Player::playersNum; i++)
	{
		if (users[i].GetCurrentPos() == this->cellPos)
			count++;
	}
	return count;
}

void Cell::MoveOnCell(System::Windows::Forms::PictureBox^ player1, System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3, Player users[])
{
	array<PictureBox^>^ usersPictures = gcnew array<PictureBox^>(3) {player1, player2, player3};
	if(this->OnCell(users) == 2)
	{
		std::vector<int> a;
		for (int i = 0; i < 2; i++)
			if (users[i].GetCurrentPos() == this->cellPos)
				a.push_back(i);
		if((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40))
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		else
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
	}
	if (this->OnCell(users) == 3)
	{
		if ((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40))
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x - 45, board[this->cellPos - 1].y);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		}
		else
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y + 45);
		}
	}
}



System::Void GameForm::backToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	parentForm->Show();
	this->Hide();
}
System::Void GameForm::backToMenu_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	backToMenu->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonBackToMenu_onMouseDown.png");
}
System::Void GameForm::backToMenu_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	std::string a = "\\assets\\buttonBackToMenu_onMouseUp.png";
	System::String^ mySystemString = msclr::interop::marshal_as<System::String^>(a);
	backToMenu->Image = Image::FromFile(Application::StartupPath + mySystemString);
}
System::Void GameForm::backToMenu_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	backToMenu->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonBackToMenu_onMouseEnter.png");
}
System::Void GameForm::backToMenu_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	backToMenu->Image = Image::FromFile(Application::StartupPath + "\\assets\\buttonBackToMenu_onMouseUp.png");
}

System::Void GameForm::InformationAboutStreets(System::Object^ sender, System::EventArgs^ e)
{
	array<PictureBox^>^ pictureBoxes = gcnew array<PictureBox^>(40) {
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};
	array<String^>^ a = gcnew array<String^>{
		"streetCell_1.png", "treasury.png", "streetCell_3.png", "tax.png", "railway.png", "streetCell_6.png", "chance.png", "streetCell_8.png", "streetCell_9.png",
			"prison.png", "streetCell_11.png", "electricity.png", "streetCell_13.png", "streetCell_14.png", "railway.png", "streetCell_16.png", "treasury.png", "streetCell_18.png",
			"streetCell_19.png", "freeParking.png", "streetCell_21.png", "chance.png", "streetCell_23.png", "streetCell_24.png", "railway.png", "streetCell_26.png", "streetCell_27.png",
			"waterSupply.png", "streetCell_29.png", "goToPrison.png", "streetCell_31.png", "streetCell_32.png", "treasury.png", "streetCell_34.png", "railway.png", "chance.png", "streetCell_37.png",
			"superTax.png", "streetCell_39.png", "start.png"};
	PictureBox^ street = safe_cast<PictureBox^>(sender);
	int index = Array::IndexOf(pictureBoxes, sender);
	pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + a[index]);
}

bool isMove = false;
void change_picture(System::Windows::Forms::PictureBox^ pictureBox, System::String^ file_path) {
	pictureBox->Image = Image::FromFile(Application::StartupPath + "\\assets\\dices\\" + file_path);
}

System::Void GameForm::rollDice_Click(System::Object^ sender, System::EventArgs^ e)
{
	int pos = users[0].GetCurrentPos();
	if (pos >= 40)
		pos -= 40;
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onRoll.png");
	rollDice->Refresh();

	srand(time(NULL));

	array<String^>^ images = gcnew array<String^>{ "dice_1.png", "dice_2.png", "dice_3.png", "dice_4.png", "dice_5.png", "dice_6.png"};
	int sleepTime = 10;
	int dice = 0;
	for (int i = 0; i < 30; i++) {
		sleepTime += 5;
		int dice1_roll = rand() % 6 + 1;
		int dice2_roll = rand() % 6 + 1;
		change_picture(this->dice_1, images[dice1_roll - 1]);
		change_picture(this->dice_2, images[dice2_roll - 1]);
		dice_1->Refresh();
		dice_2->Refresh();
		System::Threading::Thread::Sleep(sleepTime);
		dice = dice1_roll + dice2_roll;
	}
	users[0].SetCurrentPos(dice);
	if (users[0].GetCurrentPos() <= pos)
	{
		for (int i = pos; i <= 40; i++)
		{
			Player1->Location = System::Drawing::Point(board[i - 1].x, board[i - 1].y);
			Player1->Refresh();
			System::Threading::Thread::Sleep(100);
		}
		pos = 0;
	}
	//users[0].PlayersMoving(Player1, dice, board);
	//users[1].PlayersMoving(Player2, 9, board);
	//users[2].PlayersMoving(Player3, 12, board);
	for (int i = pos; i <= users[0].GetCurrentPos(); i++)
	{
		Player1->Location = System::Drawing::Point(board[i - 1].x, board[i - 1].y);
		Player1->Refresh();
		System::Threading::Thread::Sleep(100);
	}
	std::string buffString = std::to_string(users[0].GetCurrentPos()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	for (int i = 0; i < 40; i++)
	{
			board[i].MoveOnCell(Player1, Player2, Player3, users);
	}
}

System::Void GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	UserName->Text = gcnew System::String(users[0].userName.c_str());

	std::string buffString = std::to_string(users[0].cash + users[0].streetMoney) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());

	buffString = std::to_string(users[0].cash) + "$";
	cash->Text = gcnew System::String(buffString.c_str());

	buffString = std::to_string(users[0].streetMoney) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

	srand(time(NULL));
	array<PictureBox^>^ cells = gcnew array<PictureBox^>(40) {
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};
	for (int i = 0; i < 40; i++)
	{
		board[i].x = cells[i]->Location.X + cells[i]->Width / 2 - Player1->Width / 2;
		board[i].y = cells[i]->Location.Y + cells[i]->Height / 2 - Player1->Height / 2;
		board[i].cellPos = i + 1;
	}
}

System::Void GameForm::rollDice_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseDown.png");
}
System::Void GameForm::rollDice_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseUp.png");
}
System::Void GameForm::rollDice_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseEnter.png");
}
System::Void GameForm::rollDice_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseUp.png");
}

System::Void GameForm::UnFocus(System::Object^ sender, System::EventArgs^ e)
{
	backToMenu->Focus();
}

bool fullBalanceBool = false;

System::Void GameForm::showFullBalance_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (fullBalanceBool)
	{
		timer1->Start();
		fullBalanceBool = false;
		cash->Visible = false;
		streetMoney->Visible = false;
	}
	else
	{
		timer1->Start();
		fullBalanceBool = true;
	}
}

System::Void GameForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (!fullBalanceBool)
	{
		if (fullBalance->Left > -400)
			fullBalance->Left -= 52;
		else {
			timer1->Stop();
			showFullBalance->Image = Image::FromFile(Application::StartupPath + "\\assets\\showFullBalance.png");
		}
	}
	else {
		if (fullBalance->Left < 68)
			fullBalance->Left += 52;
		else {
			timer1->Stop();
			showFullBalance->Image = Image::FromFile(Application::StartupPath + "\\assets\\hideFullBalance.png");
			cash->Visible = true;
			streetMoney->Visible = true;
		}
	}
}

