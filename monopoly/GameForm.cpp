#include "GameForm.h"
#include "GameMenu.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <chrono>
#include <fstream>
#include <locale.h>

Player::Player() //����������� ������ Player, ������� ������������� ��������� �������� ��� ������� ������ 
{
	userName = "User";
	this->currentPos = 40;
	cash = 1500;
	streetMoney = 0;
	arrested = false;
	prisonCard = false;
}

Player* users = new Player[Player::playersNum]; //�������� ������� � ��������������

Cell board[40]; //������ ����� ����
Cell streetBoard[22];

Chance chance[16]; //������ �������� ����

Treasury treasury[16];

Street streets[22];

SubStreet subStreets[2];

using namespace monopoly;


//������ ������ PLAYER
bool Player::PlayersMoving(System::Windows::Forms::PictureBox^ player, //�����, ������� ��������� ���������� �����
	int dice, Cell board[], System::Windows::Forms::PictureBox^ player1, //������ �� ����������� ����� �� ������� ����
	System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3)  
{
	bool checkStart = false;
	int pos = this->GetCurrentPos(); //����� ������� ������� ����� ������������
	if (pos >= 40) //���� ����� �������(������ ����) ������ ��� ���-�� �����, �� ��������� ��
		pos -= 40;
	if (dice < 0)
	{
		pos = this->GetCurrentPos() - 1;
		this->SetCurrentPos(dice); //������������� ������� ������� ������� � �����, ������ ������� ������� + ����� �� �������
		if (this->GetCurrentPos() > pos) //���� �������, � ������� ���������� ����������� ������ ������ ��� �������, �� ����������� ����� �� 40� ������, � ����� ������� ����������
		{
			for (int i = pos; i >= 0; i--)
			{
				player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ����� �� 1 ������ �����
				player->Refresh(); //���������� ��������, ����� ����������� ���� �������
				System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
				if (i == 39)
					checkStart = true;
			}
			pos = 39; //��������� �������
		}
		for (int i = pos; i >= this->GetCurrentPos() - 1; i--) //����������� �� 1 ������ �����, ���� �� ����������� ����������� ������� ������
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ���� �� 1 ������ �����
			player->Refresh();//���������� ��������, ����� ����������� ���� �������
			System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
			if (i == 39)
				checkStart = true;
		}
		return  checkStart;
	}
	this->SetCurrentPos(dice); //������������� ������� ������� ������� � �����, ������ ������� ������� + ����� �� �������
	if (this->GetCurrentPos() <= pos) //���� �������, � ������� ���������� ����������� ������ ������ ��� �������, �� ����������� ����� �� 40� ������, � ����� ������� ����������
	{
		for (int i = pos; i < 40; i++)
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ����� �� 1 ������ �����
			player->Refresh(); //���������� ��������, ����� ����������� ���� �������
			System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
			if (i == 39)
				checkStart = true;
		}
		pos = 0; //��������� �������
	}
	for (int i = pos; i < this->GetCurrentPos(); i++) //����������� �� 1 ������ �����, ���� �� ����������� ����������� ������� ������
	{
		player->Location = System::Drawing::Point(board[i].x, board[i].y); //��������� ��������� ���� �� 1 ������ �����
		player->Refresh();//���������� ��������, ����� ����������� ���� �������
		System::Threading::Thread::Sleep(100);//��������� ���������, ��� ���������� ��������
		if (i == 39)
			checkStart = true;
	}
	for (int i = 0; i < 40; i++) //�������� ���� �� �����, ������� ��������� �� ����� ������ � ���������� �� �����
	{ 
		board[i].MoveOnCell(player1, player2, player3);
	}

	return checkStart;
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
	this->cash += cash;
}

bool Player::GetArrested()
{
	return this->arrested;
}

void Player::SetArrested(bool arrested)
{
	this->arrested = arrested;
}

void Player::SetOwnStreet(Street street)
{
	this->ownStreet.push_back(street);
}

void Player::SetOwnSubStreet(SubStreet subStreet)
{
	this->ownSubStreet.push_back(subStreet);
}

int Player::GetStreetMoney()
{
	return this->streetMoney;
}
void Player::SetStreetMoney(int streetMoney)
{
	this->streetMoney += streetMoney;
}
void Player::PlayersInfo(Player users[], System::Windows::Forms::TextBox^ textBox)
{
	textBox->Text = "";
	std::vector<Player> onlinePlayers;
	for (int i = 0; i < Player::playersNum; i++)
		if (users[i].userName != this->userName)
			onlinePlayers.push_back(users[i]);
	if (Player::playersNum > 1)
	{
		for (int i = 0; i < onlinePlayers.size(); i++)
		{
			std::string buffString = std::to_string(onlinePlayers[i].GetCash()) + "$";
			textBox->Text += msclr::interop::marshal_as<System::String^>(onlinePlayers[i].userName) + ":" + msclr::interop::marshal_as<System::String^>(buffString) + "\r\n";
		}
	}
}
bool Player::GetPrisonCard()
{
	return this->prisonCard;
}
void Player::SetPrisonCard(bool arrested)
{
	this->prisonCard = arrested;
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
std::string Chance::GetAction()
{
	return this->action;
}
void Chance::SetAction(std::string action)
{
	this->action = action;
}
int Chance::GetCellToMove()
{
	return this->cellToMove;
}
void Chance::SetCellToMove(int cellToMove)
{
	this->cellToMove = cellToMove;
}
int Chance::GetAddedCash()
{
	return this->addedCash;
}
void Chance::SetAddedCash(int addedCash)
{
	this->addedCash = addedCash;
}

//������ ������ STREET
Street::Street()
{
	owner = "monopoly";
	housesCount = 0;
}

std::string Street::CheckOwner(Player users[], Street street) 
{
	for (int i = 0; i < Player::playersNum; i++) {
		for (int j = 0; j < users[i].ownStreet.size(); j++) {
			if (users[i].ownStreet[j].streetName == street.streetName) {
				return users[i].userName;
			}
		}
	}
	return "";
}

//������ ������ TREASURY
std::string Treasury::GetAction()
{
	return this->action;
}
void Treasury::SetAction(std::string action)
{
	this->action = action;
}
int Treasury::GetCellToMove()
{
	return this->cellToMove;
}
void Treasury::SetCellToMove(int cellToMove)
{
	this->cellToMove = cellToMove;
}
int Treasury::GetAddedCash()
{
	return this->addedCash;
}
void Treasury::SetAddedCash(int addedCash)
{
	this->addedCash = addedCash;
}


//������ ������ SubStreet

SubStreet::SubStreet()
{
	this->rent[0] = 25;
	this->rent[1] = 75;
	this->owner = "monopoly";
	this->cost = 100;
}

std::string SubStreet::CheckOwner(Player users[], SubStreet subStreet)
{
	for (int i = 0; i < Player::playersNum; i++) {
		for (int j = 0; j < users[i].ownSubStreet.size(); j++) {
			if (users[i].ownSubStreet[j].subStreetName == subStreet.subStreetName) {
				return users[i].userName;
			}
		}
	}
	return "";
}


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
int streetIndex;
int randomTreasury;

System::Void GameForm::rollDice_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (users[0].GetArrested() == true)
	{
		textBox1->Text = "\r\n" + "����� ������ �� ���������� � ������ � �� ������ �����������. ���� ������ ����������� - �������� ��������� ����� ��� ��������� �������� ���������� ������������ �� ������";
		roll->Visible = true;
		useCard->Visible = true;
		moveOn->Visible = true;
		moveOn->Enabled = true;
		rollDice->Enabled = false;
	}
	else
	{
		buy->Visible = false;
		buy->Enabled = true;
		moveOn->Visible = false;
		moveOn->Enabled = true;

		toPerform->Visible = false;
		toPerform->Enabled = true;

		array<String^>^ personsPicture = gcnew array<String^>{ "person1.png", "person2.png", "person3.png", "person4.png", "person5.png", "person6.png"}; //�������� ������� ����� � ���������
		int randomPerson = rand() % 6 + 1;
		change_picture(this->persons, personsPicture[randomPerson - 1]);

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

		users[1].SetOwnStreet(streets[0]);
		streets[0].owner = users[1].userName;

		users[2].SetOwnStreet(streets[17]);
		streets[17].owner = users[2].userName;


		bool checkStart = users[0].PlayersMoving(Player1, dice, board, Player1, Player2, Player3);
		//users[1].PlayersMoving(Player2, 2, board, Player1, Player2, Player3);
		//users[2].PlayersMoving(Player3, 2, board, Player1, Player2, Player3);//����������� ����� ������
		if (checkStart)
		{
			users[0].SetCash(200);
			std::string buffString = std::to_string(users[0].GetCash()) + "$";
			cash->Text = gcnew System::String(buffString.c_str());
			buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
			AllMoney->Text = gcnew System::String(buffString.c_str());
		}
		showNameCurCell->Text = "�� ����� �� ������" + "\r\n" + msclr::interop::marshal_as<System::String^>(board[users[0].GetCurrentPos() - 1].name);

		std::srand(std::time(nullptr));

		if (board[users[0].GetCurrentPos() - 1].definition == "street")
		{
			std::ifstream file(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/streets.txt");
			std::vector<std::string> lines;
			std::string line;
			while (std::getline(file, line))
				lines.push_back(line);
			file.close();
			int randomStreet = std::rand() % lines.size();
			std::string randomLine = lines[randomStreet];
			textBox1->Text = gcnew String(randomLine.c_str());
			for (int i = 0; i < 22; i++)
				if (board[users[0].GetCurrentPos() - 1].name == streets[i].streetName)
					streetIndex = i;
			if (streets[streetIndex].owner == "monopoly")
			{
				std::string buffString = std::to_string(streets[streetIndex].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "���������: ������ � �������";
				textBox1->Text += "\r\n" + "��������� ������� " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = streets[streetIndex].CheckOwner(users, streets[streetIndex]);
				if (users[0].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "��� ���� �������������" + "\r\n" + "���� ������ �� ���� �������";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "��������: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(streets[streetIndex].rent[streets[streetIndex].housesCount]) + "$";
					textBox1->Text += "\r\n" + "��� ������� ���������: " + msclr::interop::marshal_as<System::String^>(buffString);
					toPerform->Visible = true;
					moveOn->Visible = true;
				}

			}
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "chance")
		{
			randomChance = rand() % 16;
			std::string randomLine = chance[randomChance].GetAction();
			textBox1->Text = gcnew String(randomLine.c_str());

			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;

			if (randomChance == 7)
				users[0].SetArrested(true);
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "treasury")
		{
			randomTreasury = rand() % 16;
			std::string randomLine = treasury[randomTreasury].GetAction();
			textBox1->Text = gcnew String(randomLine.c_str());

			toPerform->Visible = true;
			moveOn->Enabled = false;
			moveOn->Visible = true;
		}






		if (board[users[0].GetCurrentPos() - 1].definition == "tax")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "������ �� �������� ��������� 100$";
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "superTax")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "������ �� �������� ��������� 200$";
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "freeParking")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "������� ��������, � ������� ������. ��� �� �� ��� ��������... ���� ���, � ������, ��� ����������, � ��� �������� � ������� ������";
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "railway")
		{
			std::ifstream file4(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/railway.txt");
			std::vector<std::string> lines;
			std::string line;
			while (std::getline(file4, line))
				lines.push_back(line);
			file4.close();
			int randomRailway = std::rand() % lines.size();
			std::string randomLine = lines[randomRailway];
			textBox1->Text = gcnew String(randomLine.c_str());

			moveOn->Visible = true;
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "prison")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "� ��� ������. ��� �� ������, ��� �� �� ��� ������. � ��� ���� �� ������� ������, �� ����� �������� ������� ����";
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "goToPrison")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "����-�� ����� ������ ���������. ������� ����������� � ������. ���� �������� ���������, �� ������� ���� ��������� ����� ���� ������������ �������� ������������ �� ������";
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "electricity")
		{
			textBox1->Text = "\r\n" + "������������� ��������, ������ �����. ������ ������������ ������� ��� ������ ����������";
			if (subStreets[0].owner == "monopoly")
			{
				std::string buffString = std::to_string(subStreets[0].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "���������: ������ � �������";
				textBox1->Text += "\r\n" + "��������� ������� " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = subStreets[0].CheckOwner(users, subStreets[0]);
				if (users[0].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "��� ���� �������������" + "\r\n" + "���� ������ �� ���� �������";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "��������: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(subStreets[0].rent[0]) + "$";
					if (subStreets[0].owner == subStreets[1].owner)
						buffString = std::to_string(subStreets[0].rent[1]) + "$";
					textBox1->Text += "\r\n" + "��� ������� ���������: " + msclr::interop::marshal_as<System::String^>(buffString);
					moveOn->Visible = true;
				}
			}
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "waterSupply")
		{
			textBox1->Text = "\r\n" + "���������� ��� ������ ����������";
			if (subStreets[1].owner == "monopoly")
			{
				std::string buffString = std::to_string(subStreets[1].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "���������: ������ � �������";
				textBox1->Text += "\r\n" + "��������� ������� " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = subStreets[1].CheckOwner(users, subStreets[1]);
				if (users[0].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "��� ���� �������������" + "\r\n" + "���� ������ �� ���� �������";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "��������: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(subStreets[1].rent[0]) + "$";
					if (subStreets[0].owner == subStreets[1].owner)
						buffString = std::to_string(subStreets[0].rent[1]) + "$";
					textBox1->Text += "\r\n" + "��� ������� ���������: " + msclr::interop::marshal_as<System::String^>(buffString);
					moveOn->Visible = true;
				}
			}
		}





		if (board[users[0].GetCurrentPos() - 1].definition == "start")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "� ��� � �����. ������� 200$ �� �� ��� ��� ���������� � ����";
		}





		users[0].PlayersInfo(users, playersInfo);

		rollDice->Enabled = false;
	}
}

System::Void GameForm::toPerform_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (board[users[0].GetCurrentPos() - 1].definition == "street")
	{
		users[0].SetCash(-streets[streetIndex].rent[streets[streetIndex].housesCount]);
		std::string buffString = std::to_string(users[0].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}

	toPerform->Visible = false;
	moveOn->Enabled = true;

	if (board[users[0].GetCurrentPos() - 1].definition == "chance")
	{
		if (chance[randomChance].GetCellToMove() != 0)
		{
			int moveOn = chance[randomChance].GetCellToMove() - users[0].GetCurrentPos();
			if (chance[randomChance].GetCellToMove() < 0)
				moveOn = chance[randomChance].GetCellToMove();
			users[0].PlayersMoving(Player1, moveOn, board, Player1, Player2, Player3);
		}
		if (chance[randomChance].GetAddedCash() != 0)
			users[0].SetCash(chance[randomChance].GetAddedCash());
		if (randomChance == 2)
			users[0].SetPrisonCard(true);
		if (randomChance == 7)
			users[0].SetArrested(true);

		std::string buffString = std::to_string(users[0].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[0].GetCurrentPos() - 1].definition == "treasury")
	{
		if (treasury[randomTreasury].GetCellToMove() != 0)
		{
			int moveOn = treasury[randomTreasury].GetCellToMove() - users[0].GetCurrentPos();
			users[0].PlayersMoving(Player1, moveOn, board, Player1, Player2, Player3);
		}
		if (treasury[randomTreasury].GetAddedCash() != 0)
		{
			int buffCash = treasury[randomTreasury].GetAddedCash();
			if (randomTreasury == 13)
				buffCash = 10 * Player::playersNum;
			users[0].SetCash(buffCash);
		}
		if (randomTreasury == 2)
			users[0].SetPrisonCard(true);
		if(randomTreasury == 6)
			users[0].SetArrested(true);

		std::string buffString = std::to_string(users[0].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[0].GetCurrentPos() - 1].definition == "tax")
	{
		users[0].SetCash(-100);

		std::string buffString = std::to_string(users[0].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[0].GetCurrentPos() - 1].definition == "superTax")
	{
		users[0].SetCash(-200);

		std::string buffString = std::to_string(users[0].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[0].GetCurrentPos() - 1].definition == "goToPrison")
	{
		users[0].SetArrested(true);
		users[0].PlayersMoving(Player1, 20, board, Player1, Player2, Player3);
	}


	toPerform->Enabled = false;
}

System::Void GameForm::toPerform_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	toPerform->Image = Image::FromFile(Application::StartupPath + "\\assets\\toPerform_onMouseDown.png");
}
System::Void GameForm::toPerform_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	toPerform->Image = Image::FromFile(Application::StartupPath + "\\assets\\toPerform_onMouseUp.png");
}
System::Void GameForm::toPerform_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	toPerform->Image = Image::FromFile(Application::StartupPath + "\\assets\\toPerform_onMouseEnter.png");
}
System::Void GameForm::toPerform_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	toPerform->Image = Image::FromFile(Application::StartupPath + "\\assets\\toPerform_onMouseUp.png");
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
	if(Player::playersNum > 1)
		users[1].userName = "User1";
	if(Player::playersNum > 2)
		users[2].userName = "User2";

	setlocale(LC_ALL, "Russian");

	UserName->Text = gcnew System::String(users[0].userName.c_str()); //��������� ����� ������������ �� ������� ������

	//��������� ������ ���-�� ����� ������������ �� ������� ������
	std::string buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());

	//��������� �������� ����� ������������ �� ������� ������
	buffString = std::to_string(users[0].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());

	//��������� ����� ������������ �� ������� ������
	buffString = std::to_string(users[0].GetStreetMoney()) + "$";
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

	int j = 0;

	for (int i = 0; i < 40; i++) //��������� ��������� �������� ������ ������ ����
	{
		if (board[i].definition == "street")
		{
			if (j > 10)
			{
				streetBoard[j].x = cells[i]->Location.X + 3;
				streetBoard[j].y = cells[i]->Location.Y + cells[i]->Height - 18;
			}
			else
			{
				streetBoard[j].x = cells[i]->Location.X + cells[i]->Width - 20;
				streetBoard[j].y = cells[i]->Location.Y + 3;
			}
			j++;
		}
	}

	j = 0;

	for (int i = 0; i < 40; i++)
		if (board[i].definition == "street")
		{
			streetBoard[j].name = board[i].name;
			j++;
		}


	std::ifstream file1(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/chance.txt");
	if (file1.is_open())
	{
		for (int i = 0; i < 16; i++) //��������� ��������� �������� ������ ������ ����
		{
			int cellToMove;
			int addedCash;
			std::string a;

			std::getline(file1, a);
			file1 >> cellToMove;
			file1.ignore(); // ������� ������� ����� ������
			file1 >> addedCash;
			file1.ignore();

			chance[i].SetAction(a);
			chance[i].SetCellToMove(cellToMove);
			chance[i].SetAddedCash(addedCash);
		}
	}
	file1.close();

	std::ifstream file2(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/streetsInfo.txt");

	if (file2.is_open())
	{
		for (int i = 0; i < 22; i++)
		{
			std::getline(file2, streets[i].streetName);
			for (int j = 0; j < 6; j++)
			{
				file2 >> streets[i].rent[j];
			}
			file2.ignore();
			file2 >> streets[i].buildCost;
			file2.ignore();
			file2 >> streets[i].cost;
			file2.ignore();
		}
		file2.close();
	}

	std::ifstream file3(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/treasury.txt");
	if (file3.is_open())
	{
		for (int i = 0; i < 16; i++) //��������� ��������� �������� ������ ������ ����
		{
			int cellToMove;
			int addedCash;
			std::string a;

			std::getline(file3, a);
			file3 >> cellToMove;
			file3.ignore(); // ������� ������� ����� ������
			file3 >> addedCash;
			file3.ignore();

			treasury[i].SetAction(a);
			treasury[i].SetCellToMove(cellToMove);
			treasury[i].SetAddedCash(addedCash);
		}
	}
	file3.close();

	subStreets[0].subStreetName = "electricity";
	subStreets[1].subStreetName = "waterSupply";
}

System::Void GameForm::UnFocus(System::Object^ sender, System::EventArgs^ e)
{
	backToMenu->Focus();
}

System::Void GameForm::UnFocusOnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
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

System::Void GameForm::buy_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (board[users[0].GetCurrentPos() - 1].definition == "street")
	{
		streets[streetIndex].owner = users[0].userName;
		users[0].SetOwnStreet(streets[streetIndex]);
		users[0].SetStreetMoney(streets[streetIndex].cost / 2);
		users[0].SetCash(-streets[streetIndex].cost);
		buy->Visible = false;
		buy->Enabled = false;
	}

	if (board[users[0].GetCurrentPos() - 1].definition == "electricity")
	{
		subStreets[0].owner = users[0].userName;
		users[0].SetOwnSubStreet(subStreets[0]);
		users[0].SetCash(-subStreets[0].cost);
		buy->Visible = false;
		buy->Enabled = false;
	}

	if (board[users[0].GetCurrentPos() - 1].definition == "waterSupply")
	{
		subStreets[1].owner = users[0].userName;
		users[0].SetOwnSubStreet(subStreets[1]);
		users[0].SetCash(-subStreets[1].cost);
		buy->Visible = false;
		buy->Enabled = false;
	}

	std::string buffString = std::to_string(users[0].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[0].GetCash() + users[0].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[0].GetStreetMoney()) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < Player::playersNum; j++)
		{
			for (int k = 0; k < users[j].ownStreet.size(); k++)
			{
				if (streetBoard[i].name == users[j].ownStreet[k].streetName)
				{
					PictureBox^ pictureBox = gcnew PictureBox();
					pictureBox->Location = System::Drawing::Point(streetBoard[i].x, streetBoard[i].y);
					pictureBox->Size = System::Drawing::Size(17, 16);
					System::String^ buffString;
					if (users[j].userName == users[0].userName)
						buffString = "\\assets\\blueOwner.png";
					else
						if (users[j].userName == users[1].userName)
							buffString = "\\assets\\redOwner.png";
						else
							buffString = "\\assets\\orangeOwner.png";
					pictureBox->Image = Image::FromFile(Application::StartupPath + buffString);
					pictureBox->BackColor = Color::Transparent;
					this->Controls->Add(pictureBox);
					pictureBox->BringToFront();
				}
			}
		}
	}
}

System::Void GameForm::buy_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	buy->Image = Image::FromFile(Application::StartupPath + "\\assets\\buy_onMouseDown.png");
}
System::Void GameForm::buy_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	buy->Image = Image::FromFile(Application::StartupPath + "\\assets\\buy_onMouseUp.png");
}
System::Void GameForm::buy_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	buy->Image = Image::FromFile(Application::StartupPath + "\\assets\\buy_onMouseEnter.png");
}
System::Void GameForm::buy_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	buy->Image = Image::FromFile(Application::StartupPath + "\\assets\\buy_onMouseUp.png");
}



System::Void GameForm::moveOn_Click(System::Object^ sender, System::EventArgs^ e)
{
	moveOn->Visible = false;
	moveOn->Enabled = false;
	buy->Enabled = false;
	rollDice->Enabled = true;
	roll->Visible = false;
	useCard->Visible = false;
}

System::Void GameForm::moveOn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	moveOn->Image = Image::FromFile(Application::StartupPath + "\\assets\\moveOn_onMouseDown.png");
}
System::Void GameForm::moveOn_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	moveOn->Image = Image::FromFile(Application::StartupPath + "\\assets\\moveOn_onMouseUp.png");
}
System::Void GameForm::moveOn_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	moveOn->Image = Image::FromFile(Application::StartupPath + "\\assets\\moveOn_onMouseEnter.png");
}
System::Void GameForm::moveOn_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	moveOn->Image = Image::FromFile(Application::StartupPath + "\\assets\\moveOn_onMouseUp.png");
}

System::Void GameForm::GameForm_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	pictureBox2->Image = nullptr;
}

System::Void GameForm::roll_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "\r\n" + "����� ������ �� ���������� � ������ � �� ������ �����������. ���� ������ ����������� - �������� ��������� ����� ��� ��������� �������� ���������� ������������ �� ������";

	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onRoll.png"); //�������� �������, ������� ����� ������������ �� ������, ���� ��� ������ �������
	rollDice->Refresh(); //���������� ��������

	int dice1_roll;
	int dice2_roll;

	array<String^>^ images = gcnew array<String^>{ "dices\\dice_1.png", "dices\\dice_2.png", "dices\\dice_3.png", "dices\\dice_4.png", "dices\\dice_5.png", "dices\\dice_6.png"}; //�������� ������� ����� � ���������
	int sleepTime = 10; //�����, �� ������� ����� ��������������� ���������
	int dice = 0; //��������� ������
	for (int i = 0; i < 30; i++) {
		sleepTime += 5; //���������� �������, �� ������� ����� ������������� ���������
		dice1_roll = rand() % 6 + 1; //��������� ����� 1�� ������
		dice2_roll = rand() % 6 + 1; //��������� ����� 2�� ������
		//��������� �������� �� �������� �����
		change_picture(this->dice_1, images[dice1_roll - 1]);
		change_picture(this->dice_2, images[dice2_roll - 1]);
		//���������� ��������
		dice_1->Refresh();
		dice_2->Refresh();
		System::Threading::Thread::Sleep(sleepTime); //��������� ���������
	}

	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseUp.png"); //�������� �������, ������� ����� ������������ �� ������, ���� ��� ������ �������

	if (dice1_roll == dice2_roll)
	{
		textBox1->Text = "\r\n" + "����������, �� ���� ��������� ����� � ������� �� ����� �������� �����. �������, ��� �� ������ ����� ���������� ����� � �������";
		users[0].SetArrested(false);
		useCard->Visible = false;
	}
	else
	{
		textBox1->Text += "\r\n" + "\r\n" + "�� �� ���� ��������� �����. ������� ������ ������";
	}

	roll->Visible = false;
}


System::Void GameForm::useCard_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "\r\n" + "����� ������ �� ���������� � ������ � �� ������ �����������. ���� ������ ����������� - �������� ��������� ����� ��� ��������� �������� ���������� ������������ �� ������";

	useCard->Visible = false;
	if (users[0].GetPrisonCard())
	{
		textBox1->Text = "\r\n" + "����������, ���� �������� ������ ���� �����, ������ ��� � ���� ������ �� ����� ���, ��� �� ������ ������";
		users[0].SetArrested(false);
		roll->Visible = false;
	}
	else
	{
		textBox1->Text += "\r\n" + "\r\n" + "� ���� ��� �������� ���������� ������������";
	}

}




System::Void GameForm::saleButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer2->Start();
}

System::Void GameForm::notSale_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer3->Start();
	streetNameForSale->Visible = false;
	notSale->Visible = false;
	sale->Visible = false;
}

System::Void GameForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e)
{
		if (saleButton->Left > -400)
			saleButton->Left -= 52;
		else {
			if (saleStreets->Left < 68)
				saleStreets->Left += 52;
			else {
				timer2->Stop();
				streetNameForSale->Visible = true;
				notSale->Visible = true;
				sale->Visible = true;
			}
		}
}

System::Void GameForm::timer3_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (saleStreets->Left > -400)
		saleStreets->Left -= 52;
	else {
		if (saleButton->Left < 68)
			saleButton->Left += 52;
		else {
			timer3->Stop();
		}
	}
}