#pragma once
#include "GameMenu.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace monopoly {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(GameMenu^ parent, int playersNum)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			parentForm = parent;

			/*array<PictureBox^, 1>^ players = gcnew array<PictureBox^, 1>(3);
			for (int i = 0; i < players->Length; i++)
			{
				players[i] = gcnew PictureBox();
				players[i]->Location = System::Drawing::Point(1401 + i * 18, 882 + i * 48);
				players[i]->Size = System::Drawing::Size(43, 42);
				players[i]->BackColor = Color::Transparent;
				players[i]->Image = Image::FromFile(Application::StartupPath + String::Format("\\assets\\playerColor{0}.png", i + 1));
				this->Controls->Add(players[i]);
				players[i]->BringToFront();
			}
			
			array<PictureBox^>^ pictureBoxes = gcnew array<PictureBox^>(40) {
				Player1, Player2
			};*/
			Player1 = gcnew PictureBox();
			Player1->Location = System::Drawing::Point(1401, 910);
			Player1->Size = System::Drawing::Size(43, 42);
			Player1->BackColor = Color::Transparent;
			Player1->Image = Image::FromFile(Application::StartupPath + "\\assets\\playerColor1.png");
			this->Controls->Add(Player1);
			Player1->BringToFront();

			if (playersNum >= 2)
			{
				Player2 = gcnew PictureBox();
				Player2->Location = System::Drawing::Point(1430, 870);
				Player2->Size = System::Drawing::Size(43, 42);
				Player2->BackColor = Color::Transparent;
				Player2->Image = Image::FromFile(Application::StartupPath + "\\assets\\playerColor2.png");
				this->Controls->Add(Player2);
				Player2->BringToFront();
			}
			if (playersNum == 3)
			{

				Player3 = gcnew PictureBox();
				Player3->Location = System::Drawing::Point(1450, 930);
				Player3->Size = System::Drawing::Size(43, 42);
				Player3->BackColor = Color::Transparent;
				Player3->Image = Image::FromFile(Application::StartupPath + "\\assets\\playerColor3.png");
				this->Controls->Add(Player3);
				Player3->BringToFront();
			}
		}

	protected:
		/// <summary> 
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

	public: System::Windows::Forms::PictureBox^ Player1;
	public: System::Windows::Forms::PictureBox^ Player2;
	public: System::Windows::Forms::PictureBox^ Player3;
	private: System::Windows::Forms::PictureBox^ backToMenu;
	private: System::Windows::Forms::PictureBox^ cell_11;
	private: System::Windows::Forms::PictureBox^ cell_12;
	private: System::Windows::Forms::PictureBox^ cell_13;
	private: System::Windows::Forms::PictureBox^ cell_14;
	private: System::Windows::Forms::PictureBox^ cell_15;
	private: System::Windows::Forms::PictureBox^ cell_16;
	private: System::Windows::Forms::PictureBox^ cell_17;
	private: System::Windows::Forms::PictureBox^ cell_10;
	private: System::Windows::Forms::PictureBox^ cell_9;
	private: System::Windows::Forms::PictureBox^ cell_8;
	private: System::Windows::Forms::PictureBox^ cell_7;
	private: System::Windows::Forms::PictureBox^ cell_6;
	private: System::Windows::Forms::PictureBox^ cell_5;
	private: System::Windows::Forms::PictureBox^ cell_4;
	private: System::Windows::Forms::PictureBox^ cell_3;
	private: System::Windows::Forms::PictureBox^ cell_2;
	private: System::Windows::Forms::PictureBox^ cell_1;
	private: System::Windows::Forms::PictureBox^ cell_40;
	private: System::Windows::Forms::PictureBox^ cell_39;
	private: System::Windows::Forms::PictureBox^ cell_38;
	private: System::Windows::Forms::PictureBox^ cell_37;
	private: System::Windows::Forms::PictureBox^ cell_36;
	private: System::Windows::Forms::PictureBox^ cell_35;
	private: System::Windows::Forms::PictureBox^ cell_34;
	private: System::Windows::Forms::PictureBox^ cell_33;
	private: System::Windows::Forms::PictureBox^ cell_32;
	private: System::Windows::Forms::PictureBox^ cell_31;
	private: System::Windows::Forms::PictureBox^ cell_30;
	private: System::Windows::Forms::PictureBox^ cell_29;
	private: System::Windows::Forms::PictureBox^ cell_28;
	private: System::Windows::Forms::PictureBox^ cell_27;
	private: System::Windows::Forms::PictureBox^ cell_26;
	private: System::Windows::Forms::PictureBox^ cell_25;
	private: System::Windows::Forms::PictureBox^ cell_24;
	private: System::Windows::Forms::PictureBox^ cell_23;
	private: System::Windows::Forms::PictureBox^ cell_22;
	private: System::Windows::Forms::PictureBox^ cell_21;
	private: System::Windows::Forms::PictureBox^ cell_20;
	private: System::Windows::Forms::PictureBox^ cell_19;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ cell_18;
	private: System::Windows::Forms::PictureBox^ rollDice;
	private: System::Windows::Forms::PictureBox^ dice_1;

	private: System::Windows::Forms::PictureBox^ dice_2;
	public: System::Windows::Forms::TextBox^ UserName;
	public: System::Windows::Forms::TextBox^ AllMoney;
	private: System::Windows::Forms::PictureBox^ showFullBalance;
	public:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ fullBalance;
	public: System::Windows::Forms::TextBox^ cash;
	public: System::Windows::Forms::TextBox^ streetMoney;
public: System::Windows::Forms::TextBox^ showNameCurCell;

private: System::Windows::Forms::PictureBox^ persons;
private: System::Windows::Forms::PictureBox^ toPerform;
private: System::Windows::Forms::PictureBox^ buy;
private: System::Windows::Forms::PictureBox^ moveOn;
public: System::Windows::Forms::TextBox^ playersInfo;
public: System::Windows::Forms::TextBox^ textBox1;
private:

private:

private:

private:


public:

public:


	public:


	public:
	private:

	private:



	private:

	private:


		   GameMenu^ parentForm;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->backToMenu = (gcnew System::Windows::Forms::PictureBox());
			this->cell_11 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_12 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_13 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_14 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_15 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_16 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_17 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_10 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_9 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_8 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_7 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_6 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_5 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_4 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_3 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_2 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_1 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_40 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_39 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_38 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_37 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_36 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_35 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_34 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_33 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_32 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_31 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_30 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_29 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_28 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_27 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_26 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_25 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_24 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_23 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_22 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_21 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_20 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->cell_18 = (gcnew System::Windows::Forms::PictureBox());
			this->rollDice = (gcnew System::Windows::Forms::PictureBox());
			this->dice_1 = (gcnew System::Windows::Forms::PictureBox());
			this->dice_2 = (gcnew System::Windows::Forms::PictureBox());
			this->UserName = (gcnew System::Windows::Forms::TextBox());
			this->AllMoney = (gcnew System::Windows::Forms::TextBox());
			this->showFullBalance = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->fullBalance = (gcnew System::Windows::Forms::PictureBox());
			this->cash = (gcnew System::Windows::Forms::TextBox());
			this->streetMoney = (gcnew System::Windows::Forms::TextBox());
			this->showNameCurCell = (gcnew System::Windows::Forms::TextBox());
			this->persons = (gcnew System::Windows::Forms::PictureBox());
			this->toPerform = (gcnew System::Windows::Forms::PictureBox());
			this->buy = (gcnew System::Windows::Forms::PictureBox());
			this->moveOn = (gcnew System::Windows::Forms::PictureBox());
			this->playersInfo = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backToMenu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rollDice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->showFullBalance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fullBalance))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->persons))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toPerform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->buy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moveOn))->BeginInit();
			this->SuspendLayout();
			// 
			// backToMenu
			// 
			this->backToMenu->BackColor = System::Drawing::Color::Transparent;
			this->backToMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backToMenu.Image")));
			this->backToMenu->Location = System::Drawing::Point(68, 907);
			this->backToMenu->Name = L"backToMenu";
			this->backToMenu->Size = System::Drawing::Size(404, 90);
			this->backToMenu->TabIndex = 0;
			this->backToMenu->TabStop = false;
			this->backToMenu->Click += gcnew System::EventHandler(this, &GameForm::backToMenu_Click);
			this->backToMenu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::backToMenu_MouseDown);
			this->backToMenu->MouseEnter += gcnew System::EventHandler(this, &GameForm::backToMenu_MouseEnter);
			this->backToMenu->MouseLeave += gcnew System::EventHandler(this, &GameForm::backToMenu_MouseLeave);
			this->backToMenu->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::backToMenu_MouseUp);
			// 
			// cell_11
			// 
			this->cell_11->BackColor = System::Drawing::Color::Transparent;
			this->cell_11->Location = System::Drawing::Point(545, 790);
			this->cell_11->Name = L"cell_11";
			this->cell_11->Size = System::Drawing::Size(123, 76);
			this->cell_11->TabIndex = 81;
			this->cell_11->TabStop = false;
			this->cell_11->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_12
			// 
			this->cell_12->BackColor = System::Drawing::Color::Transparent;
			this->cell_12->Location = System::Drawing::Point(545, 711);
			this->cell_12->Name = L"cell_12";
			this->cell_12->Size = System::Drawing::Size(123, 76);
			this->cell_12->TabIndex = 80;
			this->cell_12->TabStop = false;
			this->cell_12->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_13
			// 
			this->cell_13->BackColor = System::Drawing::Color::Transparent;
			this->cell_13->Location = System::Drawing::Point(545, 630);
			this->cell_13->Name = L"cell_13";
			this->cell_13->Size = System::Drawing::Size(123, 76);
			this->cell_13->TabIndex = 79;
			this->cell_13->TabStop = false;
			this->cell_13->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_14
			// 
			this->cell_14->BackColor = System::Drawing::Color::Transparent;
			this->cell_14->Location = System::Drawing::Point(545, 551);
			this->cell_14->Name = L"cell_14";
			this->cell_14->Size = System::Drawing::Size(123, 76);
			this->cell_14->TabIndex = 78;
			this->cell_14->TabStop = false;
			this->cell_14->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_15
			// 
			this->cell_15->BackColor = System::Drawing::Color::Transparent;
			this->cell_15->Location = System::Drawing::Point(545, 471);
			this->cell_15->Name = L"cell_15";
			this->cell_15->Size = System::Drawing::Size(123, 76);
			this->cell_15->TabIndex = 77;
			this->cell_15->TabStop = false;
			this->cell_15->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_16
			// 
			this->cell_16->BackColor = System::Drawing::Color::Transparent;
			this->cell_16->Location = System::Drawing::Point(545, 392);
			this->cell_16->Name = L"cell_16";
			this->cell_16->Size = System::Drawing::Size(123, 76);
			this->cell_16->TabIndex = 76;
			this->cell_16->TabStop = false;
			this->cell_16->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_17
			// 
			this->cell_17->BackColor = System::Drawing::Color::Transparent;
			this->cell_17->Location = System::Drawing::Point(545, 312);
			this->cell_17->Name = L"cell_17";
			this->cell_17->Size = System::Drawing::Size(123, 76);
			this->cell_17->TabIndex = 75;
			this->cell_17->TabStop = false;
			this->cell_17->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_10
			// 
			this->cell_10->BackColor = System::Drawing::Color::Transparent;
			this->cell_10->Location = System::Drawing::Point(545, 870);
			this->cell_10->Name = L"cell_10";
			this->cell_10->Size = System::Drawing::Size(123, 121);
			this->cell_10->TabIndex = 74;
			this->cell_10->TabStop = false;
			this->cell_10->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_9
			// 
			this->cell_9->BackColor = System::Drawing::Color::Transparent;
			this->cell_9->Location = System::Drawing::Point(672, 870);
			this->cell_9->Name = L"cell_9";
			this->cell_9->Size = System::Drawing::Size(81, 121);
			this->cell_9->TabIndex = 73;
			this->cell_9->TabStop = false;
			this->cell_9->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_8
			// 
			this->cell_8->BackColor = System::Drawing::Color::Transparent;
			this->cell_8->Location = System::Drawing::Point(756, 870);
			this->cell_8->Name = L"cell_8";
			this->cell_8->Size = System::Drawing::Size(74, 121);
			this->cell_8->TabIndex = 72;
			this->cell_8->TabStop = false;
			this->cell_8->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_7
			// 
			this->cell_7->BackColor = System::Drawing::Color::Transparent;
			this->cell_7->Location = System::Drawing::Point(835, 870);
			this->cell_7->Name = L"cell_7";
			this->cell_7->Size = System::Drawing::Size(74, 121);
			this->cell_7->TabIndex = 71;
			this->cell_7->TabStop = false;
			this->cell_7->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_6
			// 
			this->cell_6->BackColor = System::Drawing::Color::Transparent;
			this->cell_6->Location = System::Drawing::Point(914, 870);
			this->cell_6->Name = L"cell_6";
			this->cell_6->Size = System::Drawing::Size(74, 121);
			this->cell_6->TabIndex = 70;
			this->cell_6->TabStop = false;
			this->cell_6->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_5
			// 
			this->cell_5->BackColor = System::Drawing::Color::Transparent;
			this->cell_5->Location = System::Drawing::Point(993, 870);
			this->cell_5->Name = L"cell_5";
			this->cell_5->Size = System::Drawing::Size(74, 121);
			this->cell_5->TabIndex = 69;
			this->cell_5->TabStop = false;
			this->cell_5->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_4
			// 
			this->cell_4->BackColor = System::Drawing::Color::Transparent;
			this->cell_4->Location = System::Drawing::Point(1072, 870);
			this->cell_4->Name = L"cell_4";
			this->cell_4->Size = System::Drawing::Size(74, 121);
			this->cell_4->TabIndex = 68;
			this->cell_4->TabStop = false;
			this->cell_4->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_3
			// 
			this->cell_3->BackColor = System::Drawing::Color::Transparent;
			this->cell_3->Location = System::Drawing::Point(1151, 870);
			this->cell_3->Name = L"cell_3";
			this->cell_3->Size = System::Drawing::Size(74, 121);
			this->cell_3->TabIndex = 67;
			this->cell_3->TabStop = false;
			this->cell_3->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_2
			// 
			this->cell_2->BackColor = System::Drawing::Color::Transparent;
			this->cell_2->Location = System::Drawing::Point(1230, 870);
			this->cell_2->Name = L"cell_2";
			this->cell_2->Size = System::Drawing::Size(74, 121);
			this->cell_2->TabIndex = 66;
			this->cell_2->TabStop = false;
			this->cell_2->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_1
			// 
			this->cell_1->BackColor = System::Drawing::Color::Transparent;
			this->cell_1->Location = System::Drawing::Point(1309, 870);
			this->cell_1->Name = L"cell_1";
			this->cell_1->Size = System::Drawing::Size(74, 121);
			this->cell_1->TabIndex = 65;
			this->cell_1->TabStop = false;
			this->cell_1->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_40
			// 
			this->cell_40->BackColor = System::Drawing::Color::Transparent;
			this->cell_40->Location = System::Drawing::Point(1388, 870);
			this->cell_40->Name = L"cell_40";
			this->cell_40->Size = System::Drawing::Size(122, 121);
			this->cell_40->TabIndex = 64;
			this->cell_40->TabStop = false;
			this->cell_40->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_39
			// 
			this->cell_39->BackColor = System::Drawing::Color::Transparent;
			this->cell_39->Location = System::Drawing::Point(1388, 790);
			this->cell_39->Name = L"cell_39";
			this->cell_39->Size = System::Drawing::Size(122, 75);
			this->cell_39->TabIndex = 63;
			this->cell_39->TabStop = false;
			this->cell_39->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_38
			// 
			this->cell_38->BackColor = System::Drawing::Color::Transparent;
			this->cell_38->Location = System::Drawing::Point(1388, 711);
			this->cell_38->Name = L"cell_38";
			this->cell_38->Size = System::Drawing::Size(122, 75);
			this->cell_38->TabIndex = 62;
			this->cell_38->TabStop = false;
			this->cell_38->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_37
			// 
			this->cell_37->BackColor = System::Drawing::Color::Transparent;
			this->cell_37->Location = System::Drawing::Point(1388, 631);
			this->cell_37->Name = L"cell_37";
			this->cell_37->Size = System::Drawing::Size(122, 75);
			this->cell_37->TabIndex = 61;
			this->cell_37->TabStop = false;
			this->cell_37->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_36
			// 
			this->cell_36->BackColor = System::Drawing::Color::Transparent;
			this->cell_36->Location = System::Drawing::Point(1388, 552);
			this->cell_36->Name = L"cell_36";
			this->cell_36->Size = System::Drawing::Size(122, 75);
			this->cell_36->TabIndex = 60;
			this->cell_36->TabStop = false;
			this->cell_36->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_35
			// 
			this->cell_35->BackColor = System::Drawing::Color::Transparent;
			this->cell_35->Location = System::Drawing::Point(1388, 472);
			this->cell_35->Name = L"cell_35";
			this->cell_35->Size = System::Drawing::Size(122, 75);
			this->cell_35->TabIndex = 59;
			this->cell_35->TabStop = false;
			this->cell_35->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_34
			// 
			this->cell_34->BackColor = System::Drawing::Color::Transparent;
			this->cell_34->Location = System::Drawing::Point(1388, 392);
			this->cell_34->Name = L"cell_34";
			this->cell_34->Size = System::Drawing::Size(122, 75);
			this->cell_34->TabIndex = 58;
			this->cell_34->TabStop = false;
			this->cell_34->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_33
			// 
			this->cell_33->BackColor = System::Drawing::Color::Transparent;
			this->cell_33->Location = System::Drawing::Point(1388, 313);
			this->cell_33->Margin = System::Windows::Forms::Padding(0);
			this->cell_33->Name = L"cell_33";
			this->cell_33->Size = System::Drawing::Size(122, 75);
			this->cell_33->TabIndex = 57;
			this->cell_33->TabStop = false;
			this->cell_33->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_32
			// 
			this->cell_32->BackColor = System::Drawing::Color::Transparent;
			this->cell_32->Location = System::Drawing::Point(1388, 233);
			this->cell_32->Name = L"cell_32";
			this->cell_32->Size = System::Drawing::Size(122, 76);
			this->cell_32->TabIndex = 56;
			this->cell_32->TabStop = false;
			this->cell_32->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_31
			// 
			this->cell_31->BackColor = System::Drawing::Color::Transparent;
			this->cell_31->Location = System::Drawing::Point(1388, 155);
			this->cell_31->Name = L"cell_31";
			this->cell_31->Size = System::Drawing::Size(122, 73);
			this->cell_31->TabIndex = 55;
			this->cell_31->TabStop = false;
			this->cell_31->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_30
			// 
			this->cell_30->BackColor = System::Drawing::Color::Transparent;
			this->cell_30->Location = System::Drawing::Point(1388, 27);
			this->cell_30->Name = L"cell_30";
			this->cell_30->Size = System::Drawing::Size(122, 122);
			this->cell_30->TabIndex = 54;
			this->cell_30->TabStop = false;
			this->cell_30->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_29
			// 
			this->cell_29->BackColor = System::Drawing::Color::Transparent;
			this->cell_29->Location = System::Drawing::Point(1309, 27);
			this->cell_29->Name = L"cell_29";
			this->cell_29->Size = System::Drawing::Size(74, 122);
			this->cell_29->TabIndex = 53;
			this->cell_29->TabStop = false;
			this->cell_29->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_28
			// 
			this->cell_28->BackColor = System::Drawing::Color::Transparent;
			this->cell_28->Location = System::Drawing::Point(1230, 27);
			this->cell_28->Name = L"cell_28";
			this->cell_28->Size = System::Drawing::Size(74, 122);
			this->cell_28->TabIndex = 52;
			this->cell_28->TabStop = false;
			this->cell_28->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_27
			// 
			this->cell_27->BackColor = System::Drawing::Color::Transparent;
			this->cell_27->Location = System::Drawing::Point(1151, 27);
			this->cell_27->Name = L"cell_27";
			this->cell_27->Size = System::Drawing::Size(74, 122);
			this->cell_27->TabIndex = 51;
			this->cell_27->TabStop = false;
			this->cell_27->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_26
			// 
			this->cell_26->BackColor = System::Drawing::Color::Transparent;
			this->cell_26->Location = System::Drawing::Point(1072, 27);
			this->cell_26->Name = L"cell_26";
			this->cell_26->Size = System::Drawing::Size(74, 122);
			this->cell_26->TabIndex = 50;
			this->cell_26->TabStop = false;
			this->cell_26->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_25
			// 
			this->cell_25->BackColor = System::Drawing::Color::Transparent;
			this->cell_25->Location = System::Drawing::Point(993, 27);
			this->cell_25->Name = L"cell_25";
			this->cell_25->Size = System::Drawing::Size(74, 122);
			this->cell_25->TabIndex = 49;
			this->cell_25->TabStop = false;
			this->cell_25->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_24
			// 
			this->cell_24->BackColor = System::Drawing::Color::Transparent;
			this->cell_24->Location = System::Drawing::Point(914, 27);
			this->cell_24->Name = L"cell_24";
			this->cell_24->Size = System::Drawing::Size(74, 122);
			this->cell_24->TabIndex = 48;
			this->cell_24->TabStop = false;
			this->cell_24->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_23
			// 
			this->cell_23->BackColor = System::Drawing::Color::Transparent;
			this->cell_23->Location = System::Drawing::Point(835, 27);
			this->cell_23->Name = L"cell_23";
			this->cell_23->Size = System::Drawing::Size(74, 122);
			this->cell_23->TabIndex = 47;
			this->cell_23->TabStop = false;
			this->cell_23->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_22
			// 
			this->cell_22->BackColor = System::Drawing::Color::Transparent;
			this->cell_22->Location = System::Drawing::Point(756, 27);
			this->cell_22->Name = L"cell_22";
			this->cell_22->Size = System::Drawing::Size(74, 122);
			this->cell_22->TabIndex = 46;
			this->cell_22->TabStop = false;
			this->cell_22->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_21
			// 
			this->cell_21->BackColor = System::Drawing::Color::Transparent;
			this->cell_21->Location = System::Drawing::Point(672, 27);
			this->cell_21->Name = L"cell_21";
			this->cell_21->Size = System::Drawing::Size(81, 122);
			this->cell_21->TabIndex = 45;
			this->cell_21->TabStop = false;
			this->cell_21->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_20
			// 
			this->cell_20->BackColor = System::Drawing::Color::Transparent;
			this->cell_20->Location = System::Drawing::Point(545, 27);
			this->cell_20->Name = L"cell_20";
			this->cell_20->Size = System::Drawing::Size(123, 122);
			this->cell_20->TabIndex = 44;
			this->cell_20->TabStop = false;
			this->cell_20->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// cell_19
			// 
			this->cell_19->BackColor = System::Drawing::Color::Transparent;
			this->cell_19->Location = System::Drawing::Point(545, 152);
			this->cell_19->Name = L"cell_19";
			this->cell_19->Size = System::Drawing::Size(123, 76);
			this->cell_19->TabIndex = 43;
			this->cell_19->TabStop = false;
			this->cell_19->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Location = System::Drawing::Point(861, 233);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(351, 575);
			this->pictureBox2->TabIndex = 42;
			this->pictureBox2->TabStop = false;
			// 
			// cell_18
			// 
			this->cell_18->BackColor = System::Drawing::Color::Transparent;
			this->cell_18->Location = System::Drawing::Point(545, 233);
			this->cell_18->Name = L"cell_18";
			this->cell_18->Size = System::Drawing::Size(123, 76);
			this->cell_18->TabIndex = 41;
			this->cell_18->TabStop = false;
			this->cell_18->MouseEnter += gcnew System::EventHandler(this, &GameForm::InformationAboutStreets);
			// 
			// rollDice
			// 
			this->rollDice->BackColor = System::Drawing::Color::Transparent;
			this->rollDice->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rollDice.Image")));
			this->rollDice->Location = System::Drawing::Point(1532, 774);
			this->rollDice->Name = L"rollDice";
			this->rollDice->Size = System::Drawing::Size(364, 217);
			this->rollDice->TabIndex = 82;
			this->rollDice->TabStop = false;
			this->rollDice->Click += gcnew System::EventHandler(this, &GameForm::rollDice_Click);
			this->rollDice->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::rollDice_MouseDown);
			this->rollDice->MouseEnter += gcnew System::EventHandler(this, &GameForm::rollDice_MouseEnter);
			this->rollDice->MouseLeave += gcnew System::EventHandler(this, &GameForm::rollDice_MouseLeave);
			this->rollDice->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::rollDice_MouseUp);
			// 
			// dice_1
			// 
			this->dice_1->BackColor = System::Drawing::Color::Transparent;
			this->dice_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dice_1.Image")));
			this->dice_1->Location = System::Drawing::Point(1537, 768);
			this->dice_1->Name = L"dice_1";
			this->dice_1->Size = System::Drawing::Size(100, 100);
			this->dice_1->TabIndex = 83;
			this->dice_1->TabStop = false;
			// 
			// dice_2
			// 
			this->dice_2->BackColor = System::Drawing::Color::Transparent;
			this->dice_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dice_2.Image")));
			this->dice_2->Location = System::Drawing::Point(1752, 898);
			this->dice_2->Name = L"dice_2";
			this->dice_2->Size = System::Drawing::Size(100, 100);
			this->dice_2->TabIndex = 84;
			this->dice_2->TabStop = false;
			// 
			// UserName
			// 
			this->UserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(159)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->UserName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UserName->Font = (gcnew System::Drawing::Font(L"Impact", 45, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UserName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->UserName->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->UserName->Location = System::Drawing::Point(145, 15);
			this->UserName->MaxLength = 7;
			this->UserName->Name = L"UserName";
			this->UserName->ReadOnly = true;
			this->UserName->ShortcutsEnabled = false;
			this->UserName->Size = System::Drawing::Size(369, 74);
			this->UserName->TabIndex = 85;
			this->UserName->TabStop = false;
			this->UserName->Text = L"YourName";
			this->UserName->WordWrap = false;
			this->UserName->MouseLeave += gcnew System::EventHandler(this, &GameForm::UnFocus);
			// 
			// AllMoney
			// 
			this->AllMoney->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->AllMoney->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->AllMoney->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 45, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AllMoney->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->AllMoney->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->AllMoney->Location = System::Drawing::Point(100, 186);
			this->AllMoney->MaxLength = 7;
			this->AllMoney->Name = L"AllMoney";
			this->AllMoney->ReadOnly = true;
			this->AllMoney->ShortcutsEnabled = false;
			this->AllMoney->Size = System::Drawing::Size(276, 84);
			this->AllMoney->TabIndex = 86;
			this->AllMoney->TabStop = false;
			this->AllMoney->Text = L"0.000$";
			this->AllMoney->WordWrap = false;
			// 
			// showFullBalance
			// 
			this->showFullBalance->BackColor = System::Drawing::Color::Transparent;
			this->showFullBalance->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"showFullBalance.Image")));
			this->showFullBalance->Location = System::Drawing::Point(409, 203);
			this->showFullBalance->Name = L"showFullBalance";
			this->showFullBalance->Size = System::Drawing::Size(37, 57);
			this->showFullBalance->TabIndex = 87;
			this->showFullBalance->TabStop = false;
			this->showFullBalance->Click += gcnew System::EventHandler(this, &GameForm::showFullBalance_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 9;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// fullBalance
			// 
			this->fullBalance->BackColor = System::Drawing::Color::Transparent;
			this->fullBalance->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fullBalance.Image")));
			this->fullBalance->Location = System::Drawing::Point(-400, 301);
			this->fullBalance->Name = L"fullBalance";
			this->fullBalance->Size = System::Drawing::Size(401, 134);
			this->fullBalance->TabIndex = 88;
			this->fullBalance->TabStop = false;
			// 
			// cash
			// 
			this->cash->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->cash->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cash->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cash->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->cash->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->cash->Location = System::Drawing::Point(316, 322);
			this->cash->MaxLength = 7;
			this->cash->Name = L"cash";
			this->cash->ReadOnly = true;
			this->cash->ShortcutsEnabled = false;
			this->cash->Size = System::Drawing::Size(133, 47);
			this->cash->TabIndex = 89;
			this->cash->TabStop = false;
			this->cash->Text = L"0.000$";
			this->cash->Visible = false;
			this->cash->WordWrap = false;
			this->cash->MouseEnter += gcnew System::EventHandler(this, &GameForm::UnFocus);
			this->cash->MouseLeave += gcnew System::EventHandler(this, &GameForm::UnFocus);
			// 
			// streetMoney
			// 
			this->streetMoney->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->streetMoney->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->streetMoney->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->streetMoney->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->streetMoney->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->streetMoney->Location = System::Drawing::Point(280, 367);
			this->streetMoney->MaxLength = 7;
			this->streetMoney->Name = L"streetMoney";
			this->streetMoney->ReadOnly = true;
			this->streetMoney->ShortcutsEnabled = false;
			this->streetMoney->Size = System::Drawing::Size(133, 47);
			this->streetMoney->TabIndex = 90;
			this->streetMoney->TabStop = false;
			this->streetMoney->Text = L"0.000$";
			this->streetMoney->Visible = false;
			this->streetMoney->WordWrap = false;
			this->streetMoney->MouseEnter += gcnew System::EventHandler(this, &GameForm::UnFocus);
			this->streetMoney->MouseLeave += gcnew System::EventHandler(this, &GameForm::UnFocus);
			// 
			// showNameCurCell
			// 
			this->showNameCurCell->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->showNameCurCell->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->showNameCurCell->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->showNameCurCell->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->showNameCurCell->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->showNameCurCell->Location = System::Drawing::Point(1565, 184);
			this->showNameCurCell->MaxLength = 7;
			this->showNameCurCell->Multiline = true;
			this->showNameCurCell->Name = L"showNameCurCell";
			this->showNameCurCell->ReadOnly = true;
			this->showNameCurCell->ShortcutsEnabled = false;
			this->showNameCurCell->Size = System::Drawing::Size(303, 60);
			this->showNameCurCell->TabIndex = 91;
			this->showNameCurCell->TabStop = false;
			this->showNameCurCell->Text = L"Добро пожаловать в\r\nМонополию";
			this->showNameCurCell->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->showNameCurCell->WordWrap = false;
			// 
			// persons
			// 
			this->persons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->persons->BackColor = System::Drawing::Color::Transparent;
			this->persons->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->persons->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"persons.Image")));
			this->persons->Location = System::Drawing::Point(1660, 80);
			this->persons->Margin = System::Windows::Forms::Padding(0);
			this->persons->Name = L"persons";
			this->persons->Size = System::Drawing::Size(91, 100);
			this->persons->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->persons->TabIndex = 93;
			this->persons->TabStop = false;
			// 
			// toPerform
			// 
			this->toPerform->BackColor = System::Drawing::Color::Transparent;
			this->toPerform->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toPerform.Image")));
			this->toPerform->Location = System::Drawing::Point(1573, 638);
			this->toPerform->Name = L"toPerform";
			this->toPerform->Size = System::Drawing::Size(287, 53);
			this->toPerform->TabIndex = 94;
			this->toPerform->TabStop = false;
			this->toPerform->Visible = false;
			this->toPerform->Click += gcnew System::EventHandler(this, &GameForm::toPerform_Click);
			this->toPerform->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::toPerform_MouseDown);
			this->toPerform->MouseEnter += gcnew System::EventHandler(this, &GameForm::toPerform_MouseEnter);
			this->toPerform->MouseLeave += gcnew System::EventHandler(this, &GameForm::toPerform_MouseLeave);
			this->toPerform->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::toPerform_MouseUp);
			// 
			// buy
			// 
			this->buy->BackColor = System::Drawing::Color::Transparent;
			this->buy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buy.Image")));
			this->buy->Location = System::Drawing::Point(1573, 638);
			this->buy->Name = L"buy";
			this->buy->Size = System::Drawing::Size(287, 53);
			this->buy->TabIndex = 95;
			this->buy->TabStop = false;
			this->buy->Visible = false;
			this->buy->Click += gcnew System::EventHandler(this, &GameForm::buy_Click);
			this->buy->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::buy_MouseDown);
			this->buy->MouseEnter += gcnew System::EventHandler(this, &GameForm::buy_MouseEnter);
			this->buy->MouseLeave += gcnew System::EventHandler(this, &GameForm::buy_MouseLeave);
			this->buy->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::buy_MouseUp);
			// 
			// moveOn
			// 
			this->moveOn->BackColor = System::Drawing::Color::Transparent;
			this->moveOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"moveOn.Image")));
			this->moveOn->Location = System::Drawing::Point(1573, 693);
			this->moveOn->Name = L"moveOn";
			this->moveOn->Size = System::Drawing::Size(287, 53);
			this->moveOn->TabIndex = 96;
			this->moveOn->TabStop = false;
			this->moveOn->Visible = false;
			this->moveOn->Click += gcnew System::EventHandler(this, &GameForm::moveOn_Click);
			this->moveOn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::moveOn_MouseDown);
			this->moveOn->MouseEnter += gcnew System::EventHandler(this, &GameForm::moveOn_MouseEnter);
			this->moveOn->MouseLeave += gcnew System::EventHandler(this, &GameForm::moveOn_MouseLeave);
			this->moveOn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::moveOn_MouseUp);
			// 
			// playersInfo
			// 
			this->playersInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->playersInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->playersInfo->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->playersInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->playersInfo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->playersInfo->Location = System::Drawing::Point(96, 711);
			this->playersInfo->MaxLength = 7;
			this->playersInfo->Multiline = true;
			this->playersInfo->Name = L"playersInfo";
			this->playersInfo->ReadOnly = true;
			this->playersInfo->ShortcutsEnabled = false;
			this->playersInfo->Size = System::Drawing::Size(350, 136);
			this->playersInfo->TabIndex = 97;
			this->playersInfo->TabStop = false;
			this->playersInfo->WordWrap = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(179)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox1->Location = System::Drawing::Point(1565, 249);
			this->textBox1->MaxLength = 7;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ShortcutsEnabled = false;
			this->textBox1->Size = System::Drawing::Size(295, 388);
			this->textBox1->TabIndex = 92;
			this->textBox1->TabStop = false;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->WordWrap = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(159)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->playersInfo);
			this->Controls->Add(this->moveOn);
			this->Controls->Add(this->buy);
			this->Controls->Add(this->toPerform);
			this->Controls->Add(this->showNameCurCell);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->persons);
			this->Controls->Add(this->streetMoney);
			this->Controls->Add(this->cash);
			this->Controls->Add(this->fullBalance);
			this->Controls->Add(this->showFullBalance);
			this->Controls->Add(this->AllMoney);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->dice_2);
			this->Controls->Add(this->dice_1);
			this->Controls->Add(this->rollDice);
			this->Controls->Add(this->cell_11);
			this->Controls->Add(this->cell_12);
			this->Controls->Add(this->cell_13);
			this->Controls->Add(this->cell_14);
			this->Controls->Add(this->cell_15);
			this->Controls->Add(this->cell_16);
			this->Controls->Add(this->cell_17);
			this->Controls->Add(this->cell_10);
			this->Controls->Add(this->cell_9);
			this->Controls->Add(this->cell_8);
			this->Controls->Add(this->cell_7);
			this->Controls->Add(this->cell_6);
			this->Controls->Add(this->cell_5);
			this->Controls->Add(this->cell_4);
			this->Controls->Add(this->cell_3);
			this->Controls->Add(this->cell_2);
			this->Controls->Add(this->cell_1);
			this->Controls->Add(this->cell_40);
			this->Controls->Add(this->cell_39);
			this->Controls->Add(this->cell_38);
			this->Controls->Add(this->cell_37);
			this->Controls->Add(this->cell_36);
			this->Controls->Add(this->cell_35);
			this->Controls->Add(this->cell_34);
			this->Controls->Add(this->cell_33);
			this->Controls->Add(this->cell_32);
			this->Controls->Add(this->cell_31);
			this->Controls->Add(this->cell_30);
			this->Controls->Add(this->cell_29);
			this->Controls->Add(this->cell_28);
			this->Controls->Add(this->cell_27);
			this->Controls->Add(this->cell_26);
			this->Controls->Add(this->cell_25);
			this->Controls->Add(this->cell_24);
			this->Controls->Add(this->cell_23);
			this->Controls->Add(this->cell_22);
			this->Controls->Add(this->cell_21);
			this->Controls->Add(this->cell_20);
			this->Controls->Add(this->cell_19);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->cell_18);
			this->Controls->Add(this->backToMenu);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backToMenu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cell_18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rollDice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dice_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->showFullBalance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fullBalance))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->persons))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toPerform))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->buy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moveOn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backToMenu_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backToMenu_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void backToMenu_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void backToMenu_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backToMenu_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void InformationAboutStreets(System::Object^ sender, System::EventArgs^ e);

	private: System::Void rollDice_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rollDice_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void rollDice_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void rollDice_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rollDice_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void UnFocus(System::Object^ sender, System::EventArgs^ e);

	private: System::Void showFullBalance_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void toPerform_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buy_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void moveOn_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void moveOn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void moveOn_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void moveOn_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void moveOn_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buy_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void buy_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void buy_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buy_MouseLeave(System::Object^ sender, System::EventArgs^ e);

private: System::Void toPerform_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void toPerform_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void toPerform_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void toPerform_MouseLeave(System::Object^ sender, System::EventArgs^ e);
};
}

class Player;
class Street;
class SubStreet;

class Cell
{
public:
	int x;
	int y;
	int cellPos;
	std::string name;
	std::string definition;
	std::string action;
	int OnCell(Player users[]);

	void MoveOnCell(System::Windows::Forms::PictureBox^ player1, System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3);
};

class Player {
private: 
	int currentPos;
	int cash;
	bool arrested;
	int streetMoney;
public:
	Player();
	std::vector<Street> ownStreet;
	void SetOwnStreet(Street street);
	std::vector<SubStreet> ownSubStreet;
	void SetOwnSubStreet(SubStreet subStreet);

	int GetStreetMoney();
	void SetStreetMoney(int streetMoney);

	std::string userName;
	static int playersNum;

	int GetCurrentPos();
	void SetCurrentPos(int curPos);

	int GetCash();
	void SetCash(int cash);

	bool GetArrested();
	void SetArrested(bool arrested);

	bool PlayersMoving(System::Windows::Forms::PictureBox^ player, int dice, Cell board[], System::Windows::Forms::PictureBox^ player1, System::Windows::Forms::PictureBox^ player2, System::Windows::Forms::PictureBox^ player3);
	void PlayersInfo(Player users[], System::Windows::Forms::TextBox^ textBox)
	{
		textBox->Text = "";
		std::vector<Player> onlinePlayers;
		for (int i = 0; i < Player::playersNum; i++)
			if(users[i].userName != this->userName)
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
};

class Street
{
public:
	Street();
	std::string streetName;
	int rent[6];
	std::string owner;
	int buildCost;
	int cost;
	int housesCount;
	std::string CheckOwner(Player users[], Street street);
};

class SubStreet
{
public:
	SubStreet();
	std::string subStreetName;
	int rent[2];
	std::string owner;
	int cost;
	std::string CheckOwner(Player users[], SubStreet street);
};

class Chance
{
	std::string action;
	int cellToMove;
	int addedCash;
public:	
	std::string GetAction();
	void SetAction(std::string action);

	int GetCellToMove();
	void SetCellToMove(int cellToMove);

	int GetAddedCash();
	void SetAddedCash(int addedCash);
};

class Treasury
{
	std::string action;
	int cellToMove;
	int addedCash;
public:
	std::string GetAction();
	void SetAction(std::string action);

	int GetCellToMove();
	void SetCellToMove(int cellToMove);

	int GetAddedCash();
	void SetAddedCash(int addedCash);
};

extern Player* users;