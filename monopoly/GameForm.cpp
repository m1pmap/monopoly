#include "GameForm.h"
#include "GameMenu.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <chrono>
#include <fstream>
#include <locale.h>

Player::Player() //����������� ������ Player, ������� ������������� ��������� �������� ��� ������� ������ 
{
	userName = "UserName";
	cash = 3000;
	streetMoney = 85;
}

Player* users = new Player[Player::playersNum]; //�������� ������� � ��������������

Cell board[40]; //������ ����� ����

Chance chance[16]; //������ �������� ����

using namespace monopoly;


//������ ������ PLAYER
void Player::PlayersMoving(System::Windows::Forms::PictureBox^ player, //�����, ������� ��������� ���������� �����
	int dice, Cell board[], System::Windows::Forms::PictureBox^ player1, //������ �� ����������� ����� �� ������� ����
	System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3)  
{
	int pos = this->GetCurrentPos(); //����� ������� ������� ����� ������������
	if (pos >= 40) //���� ����� �������(������ ����) ������ ��� ���-�� �����, �� ��������� ��
		pos -= 40;
	if (dice < 0)
	{
		pos = this->GetCurrentPos() - 1;
		this->SetCurrentPos(dice); //������������� ������� ������� ������� � �����, ������ ������� ������� + ����� �� �������
		if (this->GetCurrentPos() >= pos) //���� �������, � ������� ���������� ����������� ������ ������ ��� �������, �� ����������� ����� �� 40� ������, � ����� ������� ����������
		{
			for (int i = pos; i >= 0; i--)
			{
				player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ����� �� 1 ������ �����
				player->Refresh(); //���������� ��������, ����� ����������� ���� �������
				System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
			}
			pos = 39; //��������� �������
		}
		for (int i = pos; i >= this->GetCurrentPos() - 1; i--) //����������� �� 1 ������ �����, ���� �� ����������� ����������� ������� ������
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ���� �� 1 ������ �����
			player->Refresh();//���������� ��������, ����� ����������� ���� �������
			System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
		}
		return;
	}
	this->SetCurrentPos(dice); //������������� ������� ������� ������� � �����, ������ ������� ������� + ����� �� �������
	if (this->GetCurrentPos() <= pos) //���� �������, � ������� ���������� ����������� ������ ������ ��� �������, �� ����������� ����� �� 40� ������, � ����� ������� ����������
	{
		for (int i = pos; i < 40; i++)
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ����� �� 1 ������ �����
			player->Refresh(); //���������� ��������, ����� ����������� ���� �������
			System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
		}
		pos = 0; //��������� �������
	}
	for (int i = pos; i < this->GetCurrentPos(); i++) //����������� �� 1 ������ �����, ���� �� ����������� ����������� ������� ������
	{
		player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ���� �� 1 ������ �����
		player->Refresh();//���������� ��������, ����� ����������� ���� �������
		System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
	}
	for (int i = 0; i < 40; i++) //�������� ���� �� �����, ������� ��������� �� ����� ������ � ���������� �� �����
	{ 
		board[i].MoveOnCell(player1, player2, player3);
	}
}

int Player::GetCurrentPos() //���������� ������� ������� ������������
{
	return this->currentPos;
}

void Player::SetCurrentPos(int dice) //������������� ������� �������, ������ ������� ������� + ������
{
	if (dice >= 0)
	{
		if (this->currentPos + dice > 40)
			this->currentPos = this->currentPos + dice - 40;
		else
			this->currentPos += dice;
	}
	else
	{
		if (this->currentPos + dice < 0)
			this->currentPos = this->currentPos + dice + 40;
		else
			this->currentPos += dice;
	}
	
}

int Player::GetCash()
{
	return this->cash;
}

void Player::SetCash(int cash)
{
	this->cash = this->cash + cash;
}


//������ ������ CELL
int Cell::OnCell(Player users[]) //���������� ���-�� ������� �� ����������� ������
{
	int count = 0;
	for (int i = 0; i < Player::playersNum; i++)
	{
		if (users[i].GetCurrentPos() == this->cellPos)
			count++;
	}
	return count;
}

void Cell::MoveOnCell(System::Windows::Forms::PictureBox^ player1, System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3) //���������� ����� �� ����� ������
{
	array<PictureBox^>^ usersPictures = gcnew array<PictureBox^>(3) {player1, player2, player3}; //�������� ������� �������� �����
	if(this->OnCell(users) == 2) //�������� �� ���-�� ����� (2) � ������
	{
		std::vector<int> a;
		for (int i = 0; i < 2; i++) //��������� � ��������� ������� ��� ��������, ��� ��������� �� ���� ������
			if (users[i].GetCurrentPos() == this->cellPos)
				a.push_back(i);
		if((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40)) //����������� ����� � ������, ���� ��� ��������� �� ������� �������� ���� 
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		else //����������� ����� � ������, ���� ��� ��������� �� ������� � ������ �������� ����
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
	}
	if (this->OnCell(users) == 3) //�������� �� ���-�� ����� (3) � ������
	{
		if ((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40)) //����������� ����� � ������, ���� ��� ��������� �� ������� �������� ����
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x - 45, board[this->cellPos - 1].y);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		}
		else //����������� ����� � ������, ���� ��� ��������� �� ������� � ������ �������� ����
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y + 45);
		}
	}
}

//������ ������ CHANCE


//������ ����������� � ������� ���� � � ��������
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

//�������, ������� ����������� ��� ��������� �� ������� ���������� ���������� � ���
System::Void GameForm::InformationAboutStreets(System::Object^ sender, System::EventArgs^ e)
{
	array<PictureBox^>^ pictureBoxes = gcnew array<PictureBox^>(40) { //�������� ������� ��������, ������� ���������� ������
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};
	array<String^>^ a = gcnew array<String^>{ // �������� ������� ����� � ���������, ������� ����� ���������� ��� ���������
		"streetCell_1.png", "treasury.png", "streetCell_3.png", "tax.png", "railway.png", "streetCell_6.png", "chance.png", "streetCell_8.png", "streetCell_9.png",
			"prison.png", "streetCell_11.png", "electricity.png", "streetCell_13.png", "streetCell_14.png", "railway.png", "streetCell_16.png", "treasury.png", "streetCell_18.png",
			"streetCell_19.png", "freeParking.png", "streetCell_21.png", "chance.png", "streetCell_23.png", "streetCell_24.png", "railway.png", "streetCell_26.png", "streetCell_27.png",
			"waterSupply.png", "streetCell_29.png", "goToPrison.png", "streetCell_31.png", "streetCell_32.png", "treasury.png", "streetCell_34.png", "railway.png", "chance.png", "streetCell_37.png",
			"superTax.png", "streetCell_39.png", "start.png"};
	int index = Array::IndexOf(pictureBoxes, sender); //����� ������, ��� ������� ��������� pictureBox, �� ������� ��������� ������������, � ������� ��������, ������� ���������� ������
	pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + a[index]); //��������� ��������, ��� ��������
}

void change_picture(System::Windows::Forms::PictureBox^ pictureBox, System::String^ file_path) { //������� ��������� ��������
	pictureBox->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + file_path);
}

int randomChance;

System::Void GameForm::rollDice_Click(System::Object^ sender, System::EventArgs^ e)
{
	array<String^>^ personsPicture = gcnew array<String^>{ "person1.png", "person2.png", "person3.png", "person4.png", "person5.png", "person6.png"}; //�������� ������� ����� � ���������
	int randomPerson = rand() % 6 + 1;
	change_picture(this->persons, personsPicture[randomPerson - 1]);

	Chance buff;
	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onRoll.png"); //�������� �������, ������� ����� ������������ �� ������, ���� ��� ������ �������
	rollDice->Refresh(); //���������� ��������

	array<String^>^ images = gcnew array<String^>{ "dices\\dice_1.png", "dices\\dice_2.png", "dices\\dice_3.png", "dices\\dice_4.png", "dices\\dice_5.png", "dices\\dice_6.png"}; //�������� ������� ����� � ���������
	int sleepTime = 10; //�����, �� ������� ����� ��������������� ���������
	int dice = 0; //��������� ������
	for (int i = 0; i < 30; i++) {
		sleepTime += 5; //���������� �������, �� ������� ����� ������������� ���������
		int dice1_roll = rand() % 6 + 1; //��������� ����� 1�� ������
		int dice2_roll = rand() % 6 + 1; //��������� ����� 2�� ������
		//��������� �������� �� �������� �����
		change_picture(this->dice_1, images[dice1_roll - 1]);
		change_picture(this->dice_2, images[dice2_roll - 1]);
		//���������� ��������
		dice_1->Refresh();
		dice_2->Refresh();
		System::Threading::Thread::Sleep(sleepTime); //��������� ���������
		dice = dice1_roll + dice2_roll; //��������� ����������� ������
	}
	users[0].PlayersMoving(Player1, dice, board, Player1, Player2, Player3); //����������� ����� ������
	//users[1].PlayersMoving(Player2, 1, board, Player1, Player2, Player3);
	//users[2].PlayersMoving(Player3, 12, board);
	showNameCurCell->Text = "�� ����� �� ������" + "\r\n" + msclr::interop::marshal_as<System::String^>(board[users[0].GetCurrentPos() - 1].name);

	std::srand(std::time(nullptr));
	if (board[users[0].GetCurrentPos() - 1].definition == "street")
	{
		std::ifstream file(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/streets.txt");
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(file, line))
			lines.push_back(line);
		int randomStreet = std::rand() % lines.size();
		std::string randomLine = lines[randomStreet];
		textBox1->Text = gcnew String(randomLine.c_str());
		file.close();
	}

	if (board[users[0].GetCurrentPos() - 1].definition == "chance")
	{
		randomChance = rand() % 16;
		std::string randomLine = chance[randomChance].action;
		textBox1->Text = gcnew String(randomLine.c_str());

		toPerform->Visible = true;
	}
}

System::Void GameForm::toPerform_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (chance[randomChance].cellToMove != 0)
	{
		int moveOn = chance[randomChance].cellToMove - users[0].GetCurrentPos();
		if (chance[randomChance].cellToMove < 0)
			moveOn = chance[randomChance].cellToMove;
		users[0].PlayersMoving(Player1, moveOn, board, Player1, Player2, Player3);
	}
	if (chance[randomChance].addedCash != 0)
		users[0].SetCash(chance[randomChance].addedCash);

	std::string buffString = std::to_string(users[0].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[0].GetCash() + users[0].streetMoney) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());
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

System::Void GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e) //�������, ������������� ��� �������� �����
{
	setlocale(LC_ALL, "Russian");

	UserName->Text = gcnew System::String(users[0].userName.c_str()); //��������� ����� ������������ �� ������� ������

	//��������� ������ ���-�� ����� ������������ �� ������� ������
	std::string buffString = std::to_string(users[0].GetCash() + users[0].streetMoney) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());

	//��������� �������� ����� ������������ �� ������� ������
	buffString = std::to_string(users[0].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());

	//��������� ����� ������������ �� ������� ������
	buffString = std::to_string(users[0].streetMoney) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

	srand(time(NULL));
	array<PictureBox^>^ cells = gcnew array<PictureBox^>(40) { //�������� ������� ����� ����
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};

	std::ifstream file(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/data.txt");
	for (int i = 0; i < 40; i++) //��������� ��������� �������� ������ ������ ����
	{
		board[i].x = cells[i]->Location.X + cells[i]->Width / 2 - Player1->Width / 2;
		board[i].y = cells[i]->Location.Y + cells[i]->Height / 2 - Player1->Height / 2;
		board[i].cellPos = i + 1;
		std::getline(file, board[i].name);
		std::getline(file, board[i].definition);
	}
	file.close();

	std::ifstream file1(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/chance.txt");
	if (file1.is_open())
	{
		for (int i = 0; i < 16; i++) //��������� ��������� �������� ������ ������ ����
		{
			int cellToMove;
			int addedCash;

			std::getline(file1, chance[i].action);
			file1 >> cellToMove;
			file1.ignore(); // ������� ������� ����� ������
			file1 >> addedCash;
			file1.ignore();

			chance[i].cellToMove = cellToMove;
			chance[i].addedCash = addedCash;
		}
	}
	file1.close();
}

System::Void GameForm::UnFocus(System::Object^ sender, System::EventArgs^ e)
{
	backToMenu->Focus();
}

bool fullBalanceBool = false;

System::Void GameForm::showFullBalance_Click(System::Object^ sender, System::EventArgs^ e) //��������� � ���������� ���������� � ����� ������� ������
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

System::Void GameForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e) //�������� ��������� � ���������� ���������� � ����� ������� ������
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

