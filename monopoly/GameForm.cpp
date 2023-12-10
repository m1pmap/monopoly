#include "GameForm.h"
#include "GameMenu.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <chrono>
#include <fstream>
#include <locale.h>

Player::Player() //конструктор класса Player, который устанавливает начальные значения для каждого игрока 
{
	userName = "User";
	this->currentPos = 40;
	cash = 1500;
	streetMoney = 0;
	arrested = false;
	prisonCard = false;
}

Player user1;
Player user2;
Player user3;

int curPlayerIndex = 0;

//Player* users = new Player[globalPlayersNum]; //создание массива с пользователями

std::vector<Player> users;

Cell board[40]; //массив ячеек поля
Cell streetBoard[22];

Chance chance[16]; //массив карточек Шанс

Treasury treasury[16];

Street streets[22];

SubStreet subStreets[2];

using namespace monopoly;


//МЕТОДЫ КЛАССА PLAYER
bool Player::PlayersMoving(System::Windows::Forms::PictureBox^ player, //метод, который позволяет перемещать фишку
	int dice, Cell board[], System::Windows::Forms::PictureBox^ player1, //игрока на определённое место на игровом поле
	System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3)  
{
	bool checkStart = false;
	int pos = this->GetCurrentPos(); //узнаём текущую позицую фишки пользователя
	if (pos >= 40) //если номер позиции(ячейки поля) больше чем кол-во ячеек, то уменьшаем их
		pos -= 40;
	if (dice < 0)
	{
		pos = this->GetCurrentPos() - 1;
		this->SetCurrentPos(dice); //устанавливаем значени текущей позиции в место, равное текущей позиции + число на кубиках
		if (this->GetCurrentPos() > pos) //если позиция, в которую необходимо переместить кубики меньше чем текущая, то перемещение пойдёт до 40й ячейки, а потом позиция обнулиться
		{
			for (int i = pos; i >= 0; i--)
			{
				player->Location = System::Drawing::Point(board[i].x, board[i].y); //установка координат фишки на 1 ячейку вперёд
				player->Refresh(); //обновление картинки, чтобы перемещение было заметно
				System::Threading::Thread::Sleep(100);//остановка программы, для замедления анимации
				if (i == 39)
					checkStart = true;
			}
			pos = 39; //обнуление позиции
		}
		for (int i = pos; i >= this->GetCurrentPos() - 1; i--) //перемещение на 1 ячейку вперёд, пока не достигнется необходимая позиция ячейки
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //установка координат фики на 1 ячейку вперёд
			player->Refresh();//обновление картинки, чтобы перемещение было заметно
			System::Threading::Thread::Sleep(100);//остановка программы, для замедления анимации
			if (i == 39)
				checkStart = true;
		}
		for (int i = 0; i < 40; i++) //проверка поля на фишки, которые находятся на одной ячейке и размещение их рядом
		{
			board[i].MoveOnCell(player1, player2, player3);
		}
		return  checkStart;
	}
	this->SetCurrentPos(dice); //устанавливаем значени текущей позиции в место, равное текущей позиции + число на кубиках
	if (this->GetCurrentPos() <= pos) //если позиция, в которую необходимо переместить кубики меньше чем текущая, то перемещение пойдёт до 40й ячейки, а потом позиция обнулиться
	{
		for (int i = pos; i < 40; i++)
		{
			player->Location = System::Drawing::Point(board[i].x, board[i].y); //установка координат фишки на 1 ячейку вперёд
			player->Refresh(); //обновление картинки, чтобы перемещение было заметно
			System::Threading::Thread::Sleep(100);//остановка программы, для замедления анимации
			if (i == 39)
				checkStart = true;
		}
		pos = 0; //обнуление позиции
	}
	for (int i = pos; i < this->GetCurrentPos(); i++) //перемещение на 1 ячейку вперёд, пока не достигнется необходимая позиция ячейки
	{
		player->Location = System::Drawing::Point(board[i].x, board[i].y); //установка координат фики на 1 ячейку вперёд
		player->Refresh();//обновление картинки, чтобы перемещение было заметно
		System::Threading::Thread::Sleep(100);//остановка программы, для замедления анимации
		if (i == 39)
			checkStart = true;
	}
	for (int i = 0; i < 40; i++) //проверка поля на фишки, которые находятся на одной ячейке и размещение их рядом
	{ 
		board[i].MoveOnCell(player1, player2, player3);
	}

	return checkStart;
}

int Player::GetCurrentPos() //возвращает текущую позицию пользователя
{
	return this->currentPos;
}

void Player::SetCurrentPos(int dice) //устанавливает текущую позицию, равную текущей позиции + кубики
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
void Player::PlayersInfo(std::vector<Player> users, System::Windows::Forms::TextBox^ textBox)
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

//МЕТОДЫ КЛАССА CELL
int Cell::OnCell(std::vector<Player> users) //возвращает кол-во игроков на определённой ячейке
{
	int count = 0;
	for (int i = 0; i < Player::playersNum; i++)
	{
		if (users[i].GetCurrentPos() == this->cellPos)
			count++;
	}
	return count;
}

void Cell::MoveOnCell(System::Windows::Forms::PictureBox^ player1, System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3) //размещение фишек на одной ячейке
{
	array<PictureBox^>^ usersPictures = gcnew array<PictureBox^>(3) {player1, player2, player3}; //создание массива картинок фишек
	if(this->OnCell(users) == 2) //проверка на кол-во фишек (2) в ячейке
	{
		std::vector<int> a;
		for (int i = 0; i < 2; i++) //занесение в контейнер позиции тех картинок, что находятся на этой ячейке
			if (users[i].GetCurrentPos() == this->cellPos)
				a.push_back(i);
		if((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40)) //перемещение фишки в случае, если она находится на боковых участках поля 
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		else //перемещение фишки в случае, если она находится на верхних и нижних участках поля
			usersPictures[a[0]]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
	}
	if (this->OnCell(users) == 3) //проверка на кол-во фишек (3) в ячейке
	{
		if ((this->cellPos > 10 && this->cellPos < 20) || (this->cellPos > 30 && this->cellPos < 40)) //перемещение фишек в случае, если они находится на боковых участках поля
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x - 45, board[this->cellPos - 1].y);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x + 45, board[this->cellPos - 1].y);
		}
		else //перемещение фишек в случае, если они находится на верхних и нижних участках поля
		{
			usersPictures[0]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y - 45);
			usersPictures[1]->Location = System::Drawing::Point(board[this->cellPos - 1].x, board[this->cellPos - 1].y + 45);
		}
	}
}

//МЕТОДЫ КЛАССА CHANCE
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

//МЕТОДЫ КЛАССА STREET
Street::Street()
{
	owner = "monopoly";
	housesCount = 0;
}

std::string Street::CheckOwner(std::vector<Player> users, Street street)
{
	for (int i = 0; i < Player::playersNum; i++) {
		for (int j = 0; j < users[i].ownStreet.size(); j++) {
			if (users[i].ownStreet[j].streetName == street.streetName) {
				return users[i].userName;
			}
		}
	}
	return "monopoly";
}

//МЕТОДЫ КЛАССА TREASURY


//МЕТОДЫ КЛАССА SubStreet

SubStreet::SubStreet()
{
	this->rent[0] = 25;
	this->rent[1] = 75;
	this->owner = "monopoly";
	this->cost = 100;
}

std::string SubStreet::CheckOwner(std::vector<Player> users, SubStreet subStreet)
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


//кнопка возвращения в главное меню и её свойства
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

//функция, которая срабатывает при наведении на ячейкии показывает информацию о них
System::Void GameForm::InformationAboutStreets(System::Object^ sender, System::EventArgs^ e)
{
	array<PictureBox^>^ pictureBoxes = gcnew array<PictureBox^>(40) { //создание массива картинок, которые отображают ячейки
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};
	array<String^>^ a = gcnew array<String^>{ // создание массива путей к картинкам, которые будут появляться при наведении
		"streetCell_1.png", "treasury.png", "streetCell_3.png", "tax.png", "railway.png", "streetCell_6.png", "chance.png", "streetCell_8.png", "streetCell_9.png",
			"prison.png", "streetCell_11.png", "electricity.png", "streetCell_13.png", "streetCell_14.png", "railway.png", "streetCell_16.png", "treasury.png", "streetCell_18.png",
			"streetCell_19.png", "freeParking.png", "streetCell_21.png", "chance.png", "streetCell_23.png", "streetCell_24.png", "railway.png", "streetCell_26.png", "streetCell_27.png",
			"waterSupply.png", "streetCell_29.png", "goToPrison.png", "streetCell_31.png", "streetCell_32.png", "treasury.png", "streetCell_34.png", "railway.png", "chance.png", "streetCell_37.png",
			"superTax.png", "streetCell_39.png", "start.png"};
	int index = Array::IndexOf(pictureBoxes, sender); //узнаём индекс, под которым находится pictureBox, на который наводится пользователь, в массиве картинок, которые отображают ячейки
	pictureBox2->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + a[index]); //установка картинки, под индексом
}

void change_picture(System::Windows::Forms::PictureBox^ pictureBox, System::String^ file_path) { //функция изменения картинки
	pictureBox->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + file_path);
}

int randomChance;
int streetIndex;
int randomTreasury;

System::Void GameForm::rollDice_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->ForeColor = System::Drawing::Color::FromArgb(97, 97, 96);

	if (users[curPlayerIndex].GetArrested() == true)
	{
		showNameCurCell->Text = "Ты в Тюрьме";
		textBox1->Text = "Прямо сейчас ты находишься в тюрьме и не можешь действовать. Если хочешь освободится - попробуй выбросить дубль или используй карточку досрочного освобождения из тюрьмы";
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

		array<String^>^ personsPicture = gcnew array<String^>{ "person1.png", "person2.png", "person3.png", "person4.png", "person5.png", "person6.png"}; //создание массива путей к картинкам
		int randomPerson = rand() % 6 + 1;
		change_picture(this->persons, personsPicture[randomPerson - 1]);

		rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onRoll.png"); //установк каринки, которая будет отображаться на кнопке, пока идёт бросок кубиков
		rollDice->Refresh(); //обновления картинки

		array<String^>^ images = gcnew array<String^>{ "dices\\dice_1.png", "dices\\dice_2.png", "dices\\dice_3.png", "dices\\dice_4.png", "dices\\dice_5.png", "dices\\dice_6.png"}; //создание массива путей к картинкам
		int sleepTime = 10; //время, на которое будет останавливаться программа
		int dice = 0; //результат броска
		for (int i = 0; i < 30; i++) {
			sleepTime += 5; //увелечение времени, на которое будет оставливаться программа
			int dice1_roll = rand() % 6 + 1; //рандомное число 1го кубика
			int dice2_roll = rand() % 6 + 1; //рандомное число 2го кубика
			//измениние картинки на выпавшее число
			change_picture(this->dice_1, images[dice1_roll - 1]);
			change_picture(this->dice_2, images[dice2_roll - 1]);
			//обновление картинок
			dice_1->Refresh();
			dice_2->Refresh();
			System::Threading::Thread::Sleep(sleepTime); //остановка программы
			dice = dice1_roll + dice2_roll; //установка результатов броска
		}

		bool checkStart;

		if(curPlayerIndex == 0)
			checkStart = users[curPlayerIndex].PlayersMoving(Player1, dice, board, Player1, Player2, Player3);
		if(curPlayerIndex == 1)
			checkStart = users[curPlayerIndex].PlayersMoving(Player2, dice, board, Player1, Player2, Player3);
		if (curPlayerIndex == 2)
			checkStart = users[curPlayerIndex].PlayersMoving(Player3, dice, board, Player1, Player2, Player3);

		if (checkStart)
		{
			users[curPlayerIndex].SetCash(200);
			std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
			cash->Text = gcnew System::String(buffString.c_str());
			buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
			AllMoney->Text = gcnew System::String(buffString.c_str());
		}
		showNameCurCell->Text = "Ты попал на ячейку" + "\r\n" + msclr::interop::marshal_as<System::String^>(board[users[curPlayerIndex].GetCurrentPos() - 1].name);

		std::srand(std::time(nullptr));

		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "street")
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
				if (board[users[curPlayerIndex].GetCurrentPos() - 1].name == streets[i].streetName)
					streetIndex = i;
			if (streets[streetIndex].owner == "monopoly")
			{
				std::string buffString = std::to_string(streets[streetIndex].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "Состояние: Готова к продаже";
				textBox1->Text += "\r\n" + "Стоимость покупки " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = streets[streetIndex].CheckOwner(users, streets[streetIndex]);
				if (users[curPlayerIndex].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "Это твоя собственность" + "\r\n" + "Тебе ничего не надо платить";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "Владелец: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(streets[streetIndex].rent[streets[streetIndex].housesCount]) + "$";
					textBox1->Text += "\r\n" + "Вам придётся заплатить: " + msclr::interop::marshal_as<System::String^>(buffString);
					toPerform->Visible = true;
					moveOn->Visible = true;
				}

			}
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "chance")
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





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "treasury")
		{
			randomTreasury = rand() % 16;
			std::string randomLine = treasury[randomTreasury].GetAction();
			textBox1->Text = gcnew String(randomLine.c_str());

			toPerform->Visible = true;
			moveOn->Enabled = false;
			moveOn->Visible = true;
		}






		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "tax")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "Теперь ты вынужден заплатить 100$";
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "superTax")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "Теперь ты вынужден заплатить 200$";
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "freeParking")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "Обычная парковка, в обычном городе. Тут не на что смотреть... Хотя нет, я ошибся, она бесплатная, а это редкость в обычном городе";
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "railway")
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





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "prison")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "А это тюрьма. Как же хорошо, что мы не там сейчас. А вот если не платить налоги, то можно запросто угодить туда";
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "goToPrison")
		{
			toPerform->Visible = true;
			moveOn->Visible = true;
			moveOn->Enabled = false;
			textBox1->Text = "\r\n" + "Кому-то очень сильно неповезло. Придётся отправиться в тюрьму. Если захочешь выбраться, то придётся либо выбросить дублю либо использовать карточку освобождения из тюрьмы";
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "electricity")
		{
			textBox1->Text = "\r\n" + "Электрическая компания, ничего более. Просто вырабатывает энергию для нашего Монополиса";
			if (subStreets[0].owner == "monopoly")
			{
				std::string buffString = std::to_string(subStreets[0].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "Состояние: Готова к продаже";
				textBox1->Text += "\r\n" + "Стоимость покупки " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = subStreets[0].CheckOwner(users, subStreets[0]);
				if (users[curPlayerIndex].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "Это твоя собственность" + "\r\n" + "Тебе ничего не надо платить";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "Владелец: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(subStreets[0].rent[0]) + "$";
					if (subStreets[0].owner == subStreets[1].owner)
						buffString = std::to_string(subStreets[0].rent[1]) + "$";
					textBox1->Text += "\r\n" + "Вам придётся заплатить: " + msclr::interop::marshal_as<System::String^>(buffString);
					moveOn->Visible = true;
				}
			}
		}





		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "waterSupply")
		{
			textBox1->Text = "\r\n" + "Водопровод для нашего Монополиса";
			if (subStreets[1].owner == "monopoly")
			{
				std::string buffString = std::to_string(subStreets[1].cost) + "$";
				textBox1->Text += "\r\n" + "\r\n" + "Состояние: Готова к продаже";
				textBox1->Text += "\r\n" + "Стоимость покупки " + msclr::interop::marshal_as<System::String^>(buffString);
				buy->Visible = true;
				moveOn->Visible = true;
			}
			else
			{
				std::string buffString = subStreets[1].CheckOwner(users, subStreets[1]);
				if (users[curPlayerIndex].userName == buffString)
				{
					textBox1->Text += "\r\n" + "\r\n" + "Это твоя собственность" + "\r\n" + "Тебе ничего не надо платить";
					moveOn->Visible = true;
				}
				else
				{
					textBox1->Text += "\r\n" + "\r\n" + "Владелец: " + msclr::interop::marshal_as<System::String^>(buffString);
					buffString = std::to_string(subStreets[1].rent[0]) + "$";
					if (subStreets[1].owner == subStreets[0].owner)
						buffString = std::to_string(subStreets[1].rent[1]) + "$";
					textBox1->Text += "\r\n" + "Вам придётся заплатить: " + msclr::interop::marshal_as<System::String^>(buffString);
					moveOn->Visible = true;
				}
			}
		}

		if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "start")
		{
			moveOn->Visible = true;
			textBox1->Text = "\r\n" + "А вот и старт. Получай 200$ за то что ещё находишься в игре";
		}

		rollDice->Enabled = false;
	}
}

System::Void GameForm::toPerform_Click(System::Object^ sender, System::EventArgs^ e)
{
	toPerform->Visible = false;
	moveOn->Enabled = true;

	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "street")
	{
		if (users[curPlayerIndex].GetCash() >= streets[streetIndex].rent[streets[streetIndex].housesCount])
		{
			users[curPlayerIndex].SetCash(-streets[streetIndex].rent[streets[streetIndex].housesCount]);
			std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
			cash->Text = gcnew System::String(buffString.c_str());
			buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
			AllMoney->Text = gcnew System::String(buffString.c_str());
			for (int i = 0; i < users.size(); i++)
				if (users[i].userName == streets[streetIndex].CheckOwner(users, streets[streetIndex]))
					users[i].SetCash(streets[streetIndex].rent[streets[streetIndex].housesCount]);
			textBox1->Text = "\r\n" + "Рента оплачена успешно";
		}
		else
		{
			if (users[curPlayerIndex].GetStreetMoney() > 0)
			{
				textBox1->Text = "\r\n" + "У тебя недостаточно средств, но в твоей собственности всё ещё находятся некоторые улицы. Можешь продать их, чтобы расплатить с долгами или же признать банкротство, закончив ход";
				toPerform->Visible = true;
			}
			else
				textBox1->Text = "\r\n" + "У тебя недостаточно средств, а так же в собственности нет ни одной улицы. Мне жаль сообщать такую новость, но ты БАНКРОТ";
				
		}
	}

	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "chance")
	{
		if (chance[randomChance].GetCellToMove() != 0)
		{
			int moveOn = chance[randomChance].GetCellToMove() - users[curPlayerIndex].GetCurrentPos();
			if (chance[randomChance].GetCellToMove() < 0)
				moveOn = chance[randomChance].GetCellToMove();
			if (curPlayerIndex == 0)
				users[curPlayerIndex].PlayersMoving(Player1, moveOn, board, Player1, Player2, Player3);

			else if(curPlayerIndex == 1)
					users[curPlayerIndex].PlayersMoving(Player2, moveOn, board, Player1, Player2, Player3);

				else
					users[curPlayerIndex].PlayersMoving(Player3, moveOn, board, Player1, Player2, Player3);
		}
		if (chance[randomChance].GetAddedCash() < 0)
		{
			if (users[curPlayerIndex].GetCash() >= -chance[randomChance].GetAddedCash())
			{
				users[curPlayerIndex].SetCash(chance[randomChance].GetAddedCash());
				textBox1->Text = "\r\n" + "Деньги поступили в банк";
			}
			else
			{
				if (users[curPlayerIndex].GetStreetMoney() > 0)
				{
					textBox1->Text += "\r\n" + "\r\n" + "У тебя недостаточно средств для оплаты. Ты можете продать улицы или признать, что ты БАНКРОТ";
					toPerform->Visible = true;
				}
				else
				{
					textBox1->Text = "У тебя совсем не осталось денег, чтобы расплатиться с долгами. К сожалению, ты БАНКРОТ";
				}
			}
		}
		if (chance[randomChance].GetAddedCash() > 0)
		{
			users[curPlayerIndex].SetCash(chance[randomChance].GetAddedCash());
		}

		if (randomChance == 2)
			users[curPlayerIndex].SetPrisonCard(true);
		if (randomChance == 7)
			users[curPlayerIndex].SetArrested(true);

		std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "treasury")
	{
		if (treasury[randomTreasury].GetCellToMove() != 0)
		{
			int moveOn = treasury[randomTreasury].GetCellToMove() - users[curPlayerIndex].GetCurrentPos();
			if (curPlayerIndex == 0)
				users[curPlayerIndex].PlayersMoving(Player1, moveOn, board, Player1, Player2, Player3);

			else if (curPlayerIndex == 1)
				users[curPlayerIndex].PlayersMoving(Player2, moveOn, board, Player1, Player2, Player3);

			else
				users[curPlayerIndex].PlayersMoving(Player3, moveOn, board, Player1, Player2, Player3);
		}
		if (treasury[randomTreasury].GetAddedCash() < 0)
		{
			if (users[curPlayerIndex].GetCash() >= -treasury[randomTreasury].GetAddedCash())
			{
				users[curPlayerIndex].SetCash(treasury[randomTreasury].GetAddedCash());
				textBox1->Text = "\r\n" + "Передача выполнена успешно";
			}
			else
			{
				if (users[curPlayerIndex].GetStreetMoney() > 0)
				{
					textBox1->Text = "\r\n" + "У тебя недостаточно средств для оплаты. Необходимо " + -treasury[randomTreasury].GetAddedCash() + "$. Ты можете продать улицы или признать, что ты БАНКРОТ.";
					toPerform->Visible = true;
				}
				else
				{
					textBox1->Text = "У тебя совсем не осталось денег, чтобы расплатиться с долгами. К сожалению, ты БАНКРОТ";
				}
			}
		}
		if (treasury[randomTreasury].GetAddedCash() > 0)
		{
			if (randomTreasury == 13)
			{
				users[curPlayerIndex].SetCash(10 * Player::playersNum);
				for (int i = 0; i < users.size(); i++)
					if (i != curPlayerIndex)
						users[i].SetCash(-10);
			}
			else
				users[curPlayerIndex].SetCash(treasury[randomTreasury].GetAddedCash());
			
		}
		if (randomTreasury == 2)
			users[curPlayerIndex].SetPrisonCard(true);
		if(randomTreasury == 6)
			users[curPlayerIndex].SetArrested(true);

		std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "tax")
	{
		if (users[curPlayerIndex].GetCash() >= 100)
		{
			users[curPlayerIndex].SetCash(-100);
			textBox1->Text = "\r\n" + "Налоги оплачены";
		}
		else
		{
			if (users[curPlayerIndex].GetStreetMoney() > 0)
			{
				textBox1->Text = "\r\n" + "Необходимо 100$, а у тебя всего лишь " + users[curPlayerIndex].GetCash() + "$. Ты можете продать пару улиц и тогда есть возможность, что БАКРОТСТВО пройдёт мимо";
				toPerform->Visible = true;
			}
			else
			{
				textBox1->Text = "Вот ты и попался! Налоги платить обязан каждый, поэтому твоя история подходит к концу";
			}
		}
		

		std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "superTax")
	{
		if (users[curPlayerIndex].GetCash() >= 200)
		{
			users[curPlayerIndex].SetCash(-200);
			textBox1->Text = "\r\n" + "Налоги оплачены";
		}
		else
		{
			if (users[curPlayerIndex].GetStreetMoney() > 0)
			{
				textBox1->Text = "\r\n" + "Для оплаты надо 200$, а у тебя всего лишь " + users[curPlayerIndex].GetCash() + "$. Ты конечно можешь продать всю свою недвижимость, но не факт что это тебе поможет";
				toPerform->Visible = true;
			}
			else
			{
				textBox1->Text = "\r\n" + "А вот и бедность подобралась незаметно. У тебя совсем не осталось денег - ты БАНКРОТ. Теперь только на завод";
			}
		}

		std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
		cash->Text = gcnew System::String(buffString.c_str());
		buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
		AllMoney->Text = gcnew System::String(buffString.c_str());
	}





	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "goToPrison")
	{
		users[curPlayerIndex].SetArrested(true);
		if (curPlayerIndex == 0)
			users[curPlayerIndex].PlayersMoving(Player1, 20, board, Player1, Player2, Player3);

		else if(curPlayerIndex == 1)
			users[curPlayerIndex].PlayersMoving(Player2, 20, board, Player1, Player2, Player3);

		else
			users[curPlayerIndex].PlayersMoving(Player3, 20, board, Player1, Player2, Player3);
	}

	users[curPlayerIndex].PlayersInfo(users, playersInfo);
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

System::Void GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e) //функция, срабатывающуя при загрузке формы
{
	if (Player::playersNum > 0)
		users.push_back(user1);
	if (Player::playersNum > 1)
		users.push_back(user2);
	if (Player::playersNum > 2)
		users.push_back(user3);

	setlocale(LC_ALL, "Russian");

	UserName->Text = gcnew System::String(users[curPlayerIndex].userName.c_str()); //установка имени пользователя из класса

	//установка общего кол-ва денег пользователя из объекта класса
	std::string buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());

	//установка наличных денег пользователя из объекта класса
	buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());

	//установка имени пользователя из объекта класса
	buffString = std::to_string(users[curPlayerIndex].GetStreetMoney()) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

	srand(time(NULL));
	array<PictureBox^>^ cells = gcnew array<PictureBox^>(40) { //создание массива ячеек поля
		cell_1, cell_2, cell_3, cell_4, cell_5, cell_6, cell_7, cell_8, cell_9, cell_10, cell_11, cell_12, cell_13, cell_14, cell_15, cell_16, cell_17, cell_18, cell_19, cell_20,
			cell_21, cell_22, cell_23, cell_24, cell_25, cell_26, cell_27, cell_28, cell_29, cell_30, cell_31, cell_32, cell_33, cell_34, cell_35, cell_36, cell_37, cell_38, cell_39, cell_40
	};

	std::ifstream file(msclr::interop::marshal_as<std::string>(Application::StartupPath) + "/data.txt");
	for (int i = 0; i < 40; i++) //установка начальных значений каждой ячейки поля
	{
		board[i].x = cells[i]->Location.X + cells[i]->Width / 2 - Player1->Width / 2;
		board[i].y = cells[i]->Location.Y + cells[i]->Height / 2 - Player1->Height / 2;
		board[i].cellPos = i + 1;
		std::getline(file, board[i].name);
		std::getline(file, board[i].definition);
	}
	file.close();

	int j = 0;

	for (int i = 0; i < 40; i++) //установка начальных значений каждой ячейки поля
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
		for (int i = 0; i < 16; i++) //установка начальных значений каждой ячейки поля
		{
			int cellToMove;
			int addedCash;
			std::string a;

			std::getline(file1, a);
			file1 >> cellToMove;
			file1.ignore(); // пропуск символа новой строки
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
		for (int i = 0; i < 16; i++) //установка начальных значений каждой ячейки поля
		{
			int cellToMove;
			int addedCash;
			std::string a;

			std::getline(file3, a);
			file3 >> cellToMove;
			file3.ignore(); // пропуск символа новой строки
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

	users[curPlayerIndex].PlayersInfo(users, playersInfo);
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

System::Void GameForm::showFullBalance_Click(System::Object^ sender, System::EventArgs^ e) //появление и пропадание информации о общем балансе игрока
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

System::Void GameForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e) //анимация появления и пропадания информации о общем балансе игрока
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
	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "street")
	{
		streets[streetIndex].owner = users[curPlayerIndex].userName;
		if (users[curPlayerIndex].GetCash() >= streets[streetIndex].cost)
		{
			users[curPlayerIndex].SetCash(-streets[streetIndex].cost);
			users[curPlayerIndex].SetOwnStreet(streets[streetIndex]);
			users[curPlayerIndex].SetStreetMoney(streets[streetIndex].cost / 2);
		}
		else
		{
			textBox1->ForeColor = System::Drawing::Color::FromArgb(214, 84, 89);
			textBox1->Text = "\r\n" + "У вас недостаточно средств";
		}
		buy->Visible = false;
		buy->Enabled = false;
	}

	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "electricity")
	{
		subStreets[0].owner = users[curPlayerIndex].userName;
		if (users[curPlayerIndex].GetCash() >= subStreets[0].cost)
		{
			users[curPlayerIndex].SetOwnSubStreet(subStreets[0]);
			users[curPlayerIndex].SetCash(-subStreets[0].cost);
		}
		else
		{
			textBox1->ForeColor = System::Drawing::Color::FromArgb(214, 84, 89);
			textBox1->Text = "\r\n" + "У вас недостаточно средств";
		}
		buy->Visible = false;
		buy->Enabled = false;
	}

	if (board[users[curPlayerIndex].GetCurrentPos() - 1].definition == "waterSupply")
	{
		subStreets[1].owner = users[0].userName;
		if (users[curPlayerIndex].GetCash() >= subStreets[1].cost)
		{
			users[curPlayerIndex].SetOwnSubStreet(subStreets[1]);
			users[curPlayerIndex].SetCash(-subStreets[1].cost);
		}
		else
		{
			textBox1->ForeColor = System::Drawing::Color::FromArgb(214, 84, 89);
			textBox1->Text = "\r\n" + "У вас недостаточно средств";
		}
		buy->Visible = false;
		buy->Enabled = false;
	}

	std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetStreetMoney()) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

	for (int i = this->Controls->Count - 1; i >= 0; i--) {
		PictureBox^ pb = dynamic_cast<PictureBox^>(this->Controls[i]);
		if (pb != nullptr && pb->Width == 17 && pb->Height == 16) {
			this->Controls->Remove(pb);
			delete pb;
		}
	}

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
	curPlayerIndex++;
	if (curPlayerIndex > Player::playersNum - 1)
		curPlayerIndex = 0;
	showNameCurCell->Text = "Очередь хода" + "\r\n" + msclr::interop::marshal_as<System::String^>(users[curPlayerIndex].userName);
	textBox1->Text = "Ход передан игроку с никнеймом " + msclr::interop::marshal_as<System::String^>(users[curPlayerIndex].userName);
	moveOn->Visible = false;
	moveOn->Enabled = false;
	buy->Enabled = false;
	buy->Visible = false;
	roll->Visible = false;
	useCard->Visible = false;
	ok->Visible = true;
	saleButton->Enabled = false;
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
	textBox1->Text = "Прямо сейчас ты находишься в тюрьме и не можешь действовать. Если хочешь освободится - попробуй выбросить дубль или используй карточку досрочного освобождения из тюрьмы";

	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onRoll.png"); //установк каринки, которая будет отображаться на кнопке, пока идёт бросок кубиков
	rollDice->Refresh(); //обновления картинки

	int dice1_roll;
	int dice2_roll;

	array<String^>^ images = gcnew array<String^>{ "dices\\dice_1.png", "dices\\dice_2.png", "dices\\dice_3.png", "dices\\dice_4.png", "dices\\dice_5.png", "dices\\dice_6.png"}; //создание массива путей к картинкам
	int sleepTime = 10; //время, на которое будет останавливаться программа
	int dice = 0; //результат броска
	for (int i = 0; i < 30; i++) {
		sleepTime += 5; //увелечение времени, на которое будет оставливаться программа
		dice1_roll = rand() % 6 + 1; //рандомное число 1го кубика
		dice2_roll = rand() % 6 + 1; //рандомное число 2го кубика
		//измениние картинки на выпавшее число
		change_picture(this->dice_1, images[dice1_roll - 1]);
		change_picture(this->dice_2, images[dice2_roll - 1]);
		//обновление картинок
		dice_1->Refresh();
		dice_2->Refresh();
		System::Threading::Thread::Sleep(sleepTime); //остановка программы
	}

	rollDice->Image = Image::FromFile(Application::StartupPath + "\\assets\\rollTheDice_onMouseUp.png"); //установк каринки, которая будет отображаться на кнопке, пока идёт бросок кубиков

	if (dice1_roll == dice2_roll)
	{
		textBox1->Text = "Поздравляю, ты смог выбросить дубль и сбежать из этого ужасного места. Надеюсь, это не станет твоим постоянным домом в будущем";
		users[curPlayerIndex].SetArrested(false);
		useCard->Visible = false;
	}
	else
	{
		textBox1->Text += "\r\n" + "\r\n" + "Ты не смог выбросить дубль. Придётся сидеть дальше";
	}

	roll->Visible = false;
}
System::Void GameForm::roll_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	roll->Image = Image::FromFile(Application::StartupPath + "\\assets\\roll_onMouseDown.png");
}
System::Void GameForm::roll_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	roll->Image = Image::FromFile(Application::StartupPath + "\\assets\\roll_onMouseUp.png");
}
System::Void GameForm::roll_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	roll->Image = Image::FromFile(Application::StartupPath + "\\assets\\roll_onMouseEnter.png");
}
System::Void GameForm::roll_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	roll->Image = Image::FromFile(Application::StartupPath + "\\assets\\roll_onMouseUp.png");
}


System::Void GameForm::useCard_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "Прямо сейчас ты находишься в тюрьме и не можешь действовать. Если хочешь освободится - попробуй выбросить дубль или используй карточку досрочного освобождения из тюрьмы";

	useCard->Visible = false;
	if (users[curPlayerIndex].GetPrisonCard())
	{
		textBox1->Text = "Поздравляю, твоя карточка спасла тебе жизнь, потому что в этой тюрьме не любят тех, кто не платит налоги";
		users[curPlayerIndex].SetArrested(false);
		roll->Visible = false;
	}
	else
	{
		textBox1->Text += "\r\n" + "\r\n" + "У тебя нет карточки досрочного освобождения";
	}

}
System::Void GameForm::useCard_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	useCard->Image = Image::FromFile(Application::StartupPath + "\\assets\\useCard_onMouseDown.png");
}
System::Void GameForm::useCard_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	useCard->Image = Image::FromFile(Application::StartupPath + "\\assets\\useCard_onMouseUp.png");
}
System::Void GameForm::useCard_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	useCard->Image = Image::FromFile(Application::StartupPath + "\\assets\\useCard_onMouseEnter.png");
}
System::Void GameForm::useCard_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	useCard->Image = Image::FromFile(Application::StartupPath + "\\assets\\useCard_onMouseUp.png");
}




System::Void GameForm::saleButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer2->Start();
}
System::Void GameForm::saleButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	saleButton->Image = Image::FromFile(Application::StartupPath + "\\assets\\saleButton_onMouseDown.png");
}
System::Void GameForm::saleButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	saleButton->Image = Image::FromFile(Application::StartupPath + "\\assets\\saleButton_onMouseUp.png");
}
System::Void GameForm::saleButton_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	saleButton->Image = Image::FromFile(Application::StartupPath + "\\assets\\saleButton_onMouseEnter.png");
}
System::Void GameForm::saleButton_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	saleButton->Image = Image::FromFile(Application::StartupPath + "\\assets\\saleButton_onMouseUp.png");
}

System::Void GameForm::notSale_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer3->Start();
	streetNameForSale->Visible = false;
	notSale->Visible = false;
	sale->Visible = false;
	streetNameForSale->ForeColor = System::Drawing::Color::FromArgb(49, 20, 53);
	streetNameForSale->Text = "Название вашей улицы для продажи";
}
System::Void GameForm::notSale_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	notSale->Image = Image::FromFile(Application::StartupPath + "\\assets\\notSale_onMouseDown.png");
}
System::Void GameForm::notSale_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	notSale->Image = Image::FromFile(Application::StartupPath + "\\assets\\notSale_onMouseUp.png");
}
System::Void GameForm::notSale_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	notSale->Image = Image::FromFile(Application::StartupPath + "\\assets\\notSale_onMouseEnter.png");
}
System::Void GameForm::notSale_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	notSale->Image = Image::FromFile(Application::StartupPath + "\\assets\\notSale_onMouseUp.png");
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


System::Void GameForm::sale_Click(System::Object^ sender, System::EventArgs^ e)
{
	int streetNum = 0;
	for (int i = 0; i < 22; i++)
	{
		if (streets[i].streetName == msclr::interop::marshal_as<std::string>(streetNameForSale->Text))
		{
			streetNum = i;
		}
	}
	bool buffBool = users[curPlayerIndex].SellStreet(msclr::interop::marshal_as<std::string>(streetNameForSale->Text));
	if (buffBool)
	{
		streets[streetNum].owner = "monopoly";
		streetNameForSale->ForeColor = System::Drawing::Color::FromArgb(48, 154, 74);
		streetNameForSale->Text = "Ваша улица успешно продана";
		users[curPlayerIndex].SetCash(streets[streetNum].cost / 2);
		users[curPlayerIndex].SetStreetMoney(-streets[streetNum].cost / 2);
	}
	else
	{
		streetNameForSale->ForeColor = System::Drawing::Color::FromArgb(214, 84, 89);
		streetNameForSale->Text = "Эта улица вам не принадлежит";
	}

	for (int i = this->Controls->Count - 1; i >= 0; i--) {
		PictureBox^ pb = dynamic_cast<PictureBox^>(this->Controls[i]);
		if (pb != nullptr && pb->Width == 17 && pb->Height == 16) {
			this->Controls->Remove(pb);
			delete pb;
		}
	}

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

	std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetStreetMoney()) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());

}
System::Void GameForm::sale_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	sale->Image = Image::FromFile(Application::StartupPath + "\\assets\\sale_onMouseDown.png");
}
System::Void GameForm::sale_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	sale->Image = Image::FromFile(Application::StartupPath + "\\assets\\sale_onMouseUp.png");
}
System::Void GameForm::sale_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	sale->Image = Image::FromFile(Application::StartupPath + "\\assets\\sale_onMouseEnter.png");
}
System::Void GameForm::sale_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	sale->Image = Image::FromFile(Application::StartupPath + "\\assets\\sale_onMouseUp.png");
}


System::Void GameForm::streetNameForSale_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	streetNameForSale->ForeColor = System::Drawing::Color::FromArgb(49, 20, 53);
	streetNameForSale->Text = "";
}


System::Void GameForm::ok_Click(System::Object^ sender, System::EventArgs^ e)
{
	ok->Visible = false;
	array<String^>^ usersIcon = gcnew array<String^>{"user1Icon.png", "user2Icon.png", "user3Icon.png"};
	userIcon->Image = Image::FromFile(Application::StartupPath + "\\assets\\" + usersIcon[curPlayerIndex]);
	std::string buffString = std::to_string(users[curPlayerIndex].GetCash()) + "$";
	cash->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetCash() + users[curPlayerIndex].GetStreetMoney()) + "$";
	AllMoney->Text = gcnew System::String(buffString.c_str());
	buffString = std::to_string(users[curPlayerIndex].GetStreetMoney()) + "$";
	streetMoney->Text = gcnew System::String(buffString.c_str());
	UserName->Text = msclr::interop::marshal_as<System::String^>(users[curPlayerIndex].userName);
	users[curPlayerIndex].PlayersInfo(users, playersInfo);
	rollDice->Enabled = true;
	saleButton->Enabled = true;
}

System::Void GameForm::ok_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	ok->Image = Image::FromFile(Application::StartupPath + "\\assets\\ok_onMouseDown.png");
}
System::Void GameForm::ok_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	ok->Image = Image::FromFile(Application::StartupPath + "\\assets\\ok_onMouseUp.png");
}
System::Void GameForm::ok_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	ok->Image = Image::FromFile(Application::StartupPath + "\\assets\\ok_onMouseEnter.png");
}
System::Void GameForm::ok_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	ok->Image = Image::FromFile(Application::StartupPath + "\\assets\\ok_onMouseUp.png");
}
