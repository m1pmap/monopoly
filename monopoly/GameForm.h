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
	/// —водка дл€ GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(GameMenu^ parent)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			parentForm = parent;
		}

	protected:
		/// <summary> 
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
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
	private:

	private:


		   GameMenu^ parentForm;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->UserName->Font = (gcnew System::Drawing::Font(L"Impact", 58, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UserName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->UserName->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->UserName->Location = System::Drawing::Point(140, 7);
			this->UserName->MaxLength = 7;
			this->UserName->Name = L"UserName";
			this->UserName->ReadOnly = true;
			this->UserName->ShortcutsEnabled = false;
			this->UserName->Size = System::Drawing::Size(369, 95);
			this->UserName->TabIndex = 85;
			this->UserName->TabStop = false;
			this->UserName->Text = L"YourName";
			this->UserName->WordWrap = false;
			this->UserName->MouseLeave += gcnew System::EventHandler(this, &GameForm::UnFocus);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
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
};
}

class Player {
public:
	static std::string userName;
};


