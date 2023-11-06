#pragma once

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
	public: System::Windows::Forms::PictureBox^ StartGame;
	private: System::Windows::Forms::PictureBox^ closeGame;
	public:
	protected:

	protected:



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameMenu::typeid));
			this->StartGame = (gcnew System::Windows::Forms::PictureBox());
			this->closeGame = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartGame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->closeGame))->BeginInit();
			this->SuspendLayout();
			// 
			// StartGame
			// 
			this->StartGame->BackColor = System::Drawing::Color::Transparent;
			this->StartGame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartGame.Image")));
			this->StartGame->Location = System::Drawing::Point(715, 467);
			this->StartGame->Name = L"StartGame";
			this->StartGame->Size = System::Drawing::Size(515, 116);
			this->StartGame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->StartGame->TabIndex = 1;
			this->StartGame->TabStop = false;
			this->StartGame->Click += gcnew System::EventHandler(this, &GameMenu::StartGame_Click);
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
			this->Controls->Add(this->closeGame);
			this->Controls->Add(this->StartGame);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GameMenu";
			this->Text = L"GameMenu";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartGame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->closeGame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StartGame_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void closeGame_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
