#pragma once
#include <string>


namespace monopoly {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ GameMenu
	/// </summary>
	public ref class GameMenu : public System::Windows::Forms::Form
	{
	public:
		GameMenu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GameMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ startGame;
	protected:

	private: System::Windows::Forms::PictureBox^ closeGame;
	private: System::Windows::Forms::PictureBox^ card;
	private: System::Windows::Forms::PictureBox^ arrowRight;
	private: System::Windows::Forms::PictureBox^ arrowLeft;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ characters;
	private: System::Windows::Forms::PictureBox^ arrowPrev;
	private: System::Windows::Forms::PictureBox^ arrowNext;
	private: System::Windows::Forms::PictureBox^ changeName;
	public: System::Windows::Forms::TextBox^ UserName;
	private:

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::IContainer^ components;
	public:
	protected:

	protected:



	public:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameMenu::typeid));
			this->startGame = (gcnew System::Windows::Forms::PictureBox());
			this->closeGame = (gcnew System::Windows::Forms::PictureBox());
			this->card = (gcnew System::Windows::Forms::PictureBox());
			this->arrowRight = (gcnew System::Windows::Forms::PictureBox());
			this->arrowLeft = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->characters = (gcnew System::Windows::Forms::PictureBox());
			this->arrowPrev = (gcnew System::Windows::Forms::PictureBox());
			this->arrowNext = (gcnew System::Windows::Forms::PictureBox());
			this->changeName = (gcnew System::Windows::Forms::PictureBox());
			this->UserName = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startGame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->closeGame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->card))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->characters))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowPrev))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowNext))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeName))->BeginInit();
			this->SuspendLayout();
			// 
			// startGame
			// 
			this->startGame->BackColor = System::Drawing::Color::Transparent;
			this->startGame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"startGame.Image")));
			this->startGame->Location = System::Drawing::Point(716, 469);
			this->startGame->Name = L"startGame";
			this->startGame->Size = System::Drawing::Size(515, 116);
			this->startGame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->startGame->TabIndex = 1;
			this->startGame->TabStop = false;
			this->startGame->Click += gcnew System::EventHandler(this, &GameMenu::StartGame_Click);
			this->startGame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::startGame_MouseDown);
			this->startGame->MouseEnter += gcnew System::EventHandler(this, &GameMenu::startGame_MouseEnter);
			this->startGame->MouseLeave += gcnew System::EventHandler(this, &GameMenu::startGame_MouseLeave);
			this->startGame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::startGame_MouseUp);
			// 
			// closeGame
			// 
			this->closeGame->BackColor = System::Drawing::Color::Transparent;
			this->closeGame->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->closeGame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeGame.Image")));
			this->closeGame->Location = System::Drawing::Point(1802, 22);
			this->closeGame->Name = L"closeGame";
			this->closeGame->Size = System::Drawing::Size(81, 87);
			this->closeGame->TabIndex = 2;
			this->closeGame->TabStop = false;
			this->closeGame->Click += gcnew System::EventHandler(this, &GameMenu::closeGame_Click);
			this->closeGame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::closeGame_MouseDown);
			this->closeGame->MouseEnter += gcnew System::EventHandler(this, &GameMenu::closeGame_MouseEnter);
			this->closeGame->MouseLeave += gcnew System::EventHandler(this, &GameMenu::closeGame_MouseLeave);
			this->closeGame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::closeGame_MouseUp);
			// 
			// card
			// 
			this->card->BackColor = System::Drawing::Color::Transparent;
			this->card->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"card.BackgroundImage")));
			this->card->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"card.Image")));
			this->card->Location = System::Drawing::Point(0, 0);
			this->card->Name = L"card";
			this->card->Size = System::Drawing::Size(3840, 1080);
			this->card->TabIndex = 3;
			this->card->TabStop = false;
			// 
			// arrowRight
			// 
			this->arrowRight->BackColor = System::Drawing::Color::Transparent;
			this->arrowRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrowRight.Image")));
			this->arrowRight->Location = System::Drawing::Point(1837, 646);
			this->arrowRight->Name = L"arrowRight";
			this->arrowRight->Size = System::Drawing::Size(55, 124);
			this->arrowRight->TabIndex = 4;
			this->arrowRight->TabStop = false;
			this->arrowRight->Click += gcnew System::EventHandler(this, &GameMenu::arrowRight_Click);
			this->arrowRight->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::arrowRight_MouseDown);
			this->arrowRight->MouseEnter += gcnew System::EventHandler(this, &GameMenu::arrowRight_MouseEnter);
			this->arrowRight->MouseLeave += gcnew System::EventHandler(this, &GameMenu::arrowRight_MouseLeave);
			this->arrowRight->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::arrowRight_MouseUp);
			// 
			// arrowLeft
			// 
			this->arrowLeft->BackColor = System::Drawing::Color::Transparent;
			this->arrowLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrowLeft.Image")));
			this->arrowLeft->Location = System::Drawing::Point(30, 646);
			this->arrowLeft->Name = L"arrowLeft";
			this->arrowLeft->Size = System::Drawing::Size(55, 124);
			this->arrowLeft->TabIndex = 5;
			this->arrowLeft->TabStop = false;
			this->arrowLeft->Visible = false;
			this->arrowLeft->Click += gcnew System::EventHandler(this, &GameMenu::arrowLeft_Click);
			this->arrowLeft->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::arrowLeft_MouseDown);
			this->arrowLeft->MouseEnter += gcnew System::EventHandler(this, &GameMenu::arrowLeft_MouseEnter);
			this->arrowLeft->MouseLeave += gcnew System::EventHandler(this, &GameMenu::arrowLeft_MouseLeave);
			this->arrowLeft->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::arrowLeft_MouseUp);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameMenu::timer1_Tick);
			// 
			// characters
			// 
			this->characters->BackColor = System::Drawing::Color::Transparent;
			this->characters->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->characters->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"characters.Image")));
			this->characters->Location = System::Drawing::Point(150, 152);
			this->characters->Name = L"characters";
			this->characters->Size = System::Drawing::Size(1696, 863);
			this->characters->TabIndex = 6;
			this->characters->TabStop = false;
			this->characters->Visible = false;
			// 
			// arrowPrev
			// 
			this->arrowPrev->BackColor = System::Drawing::Color::Transparent;
			this->arrowPrev->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrowPrev.Image")));
			this->arrowPrev->Location = System::Drawing::Point(1237, 469);
			this->arrowPrev->Name = L"arrowPrev";
			this->arrowPrev->Size = System::Drawing::Size(46, 68);
			this->arrowPrev->TabIndex = 9;
			this->arrowPrev->TabStop = false;
			this->arrowPrev->Visible = false;
			this->arrowPrev->Click += gcnew System::EventHandler(this, &GameMenu::arrowPrev_Click);
			// 
			// arrowNext
			// 
			this->arrowNext->BackColor = System::Drawing::Color::Transparent;
			this->arrowNext->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrowNext.Image")));
			this->arrowNext->Location = System::Drawing::Point(1737, 469);
			this->arrowNext->Name = L"arrowNext";
			this->arrowNext->Size = System::Drawing::Size(46, 68);
			this->arrowNext->TabIndex = 8;
			this->arrowNext->TabStop = false;
			this->arrowNext->Visible = false;
			this->arrowNext->Click += gcnew System::EventHandler(this, &GameMenu::arrowNext_Click);
			// 
			// changeName
			// 
			this->changeName->BackColor = System::Drawing::Color::Transparent;
			this->changeName->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"changeName.Image")));
			this->changeName->Location = System::Drawing::Point(384, 282);
			this->changeName->Name = L"changeName";
			this->changeName->Size = System::Drawing::Size(330, 71);
			this->changeName->TabIndex = 11;
			this->changeName->TabStop = false;
			this->changeName->Visible = false;
			this->changeName->Click += gcnew System::EventHandler(this, &GameMenu::changeName_Click);
			this->changeName->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::changeName_MouseDown);
			this->changeName->MouseEnter += gcnew System::EventHandler(this, &GameMenu::changeName_MouseEnter);
			this->changeName->MouseLeave += gcnew System::EventHandler(this, &GameMenu::changeName_MouseLeave);
			this->changeName->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameMenu::changeName_MouseUp);
			// 
			// UserName
			// 
			this->UserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(159)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->UserName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UserName->Font = (gcnew System::Drawing::Font(L"Impact", 68.54F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UserName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->UserName->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->UserName->Location = System::Drawing::Point(384, 164);
			this->UserName->MaxLength = 7;
			this->UserName->Name = L"UserName";
			this->UserName->ReadOnly = true;
			this->UserName->ShortcutsEnabled = false;
			this->UserName->Size = System::Drawing::Size(400, 112);
			this->UserName->TabIndex = 10;
			this->UserName->TabStop = false;
			this->UserName->Text = L"YourName";
			this->UserName->Visible = false;
			this->UserName->WordWrap = false;
			this->UserName->MouseEnter += gcnew System::EventHandler(this, &GameMenu::Unfocus);
			this->UserName->MouseLeave += gcnew System::EventHandler(this, &GameMenu::Unfocus);
			// 
			// GameMenu
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->ControlBox = false;
			this->Controls->Add(this->changeName);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->arrowPrev);
			this->Controls->Add(this->arrowNext);
			this->Controls->Add(this->arrowLeft);
			this->Controls->Add(this->arrowRight);
			this->Controls->Add(this->closeGame);
			this->Controls->Add(this->startGame);
			this->Controls->Add(this->characters);
			this->Controls->Add(this->card);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GameMenu";
			this->Text = L"GameMenu";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startGame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->closeGame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->card))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->characters))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowPrev))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrowNext))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeName))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void StartGame_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void startGame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void startGame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void startGame_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void startGame_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void closeGame_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void closeGame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void closeGame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void closeGame_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void closeGame_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void arrowRight_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void arrowLeft_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void arrowNext_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void arrowPrev_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Unfocus(System::Object^ sender, System::EventArgs^ e);

private: System::Void changeName_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void changeName_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void changeName_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void changeName_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void changeName_MouseLeave(System::Object^ sender, System::EventArgs^ e);

private: System::Void arrowRight_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void arrowRight_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void arrowRight_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void arrowRight_MouseLeave(System::Object^ sender, System::EventArgs^ e);

private: System::Void arrowLeft_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void arrowLeft_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void arrowLeft_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void arrowLeft_MouseLeave(System::Object^ sender, System::EventArgs^ e);
};
}