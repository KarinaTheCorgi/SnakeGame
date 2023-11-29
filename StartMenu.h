#pragma once
#include "ScoreBoard.h"
#include "SnakeGame.h"

namespace SnakeGame {

	/* Forms uses the following namespaces (to make buttons, labels, etc */
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/* Reference Class for Start Menu Form */
	public ref class StartMenu : public System::Windows::Forms::Form {
		public:
			/* StartMenu Constructor */
			StartMenu(void) {
				changeFont();
				initializeComponent();
			}

		protected:
			/* StartMenu Deconstructor */
			~StartMenu() {
				if (components)
					delete components;
			}

		private: 
			/* Custom Font Collection (just using one) */
			System::Drawing::Text::PrivateFontCollection^ customFonts = gcnew System::Drawing::Text::PrivateFontCollection();
			
			/* Components of the window/form */
			System::Windows::Forms::TableLayoutPanel^ tablePanel;
			System::Windows::Forms::PictureBox^ gameImg;
			System::Windows::Forms::Button^ playButton;
			System::Windows::Forms::Button^ scoreBoard;
			System::Windows::Forms::Button^ exitGame;
			System::ComponentModel::Container ^components;

			/* changes the font of the window (to custom font) */
			void changeFont(void) {
				customFonts->AddFontFile("customfont.ttf");
				System::Drawing::Font^ customFont = gcnew System::Drawing::Font(customFonts->Families[0], 14);
				this->Font = customFont;
			}

			/* Creates instance/pointer to instange of SnakeGame form when the play button is clicked */
			void playClick(System::Object^ sender, System::EventArgs^ e) {
				this->Hide();
				SnakeGame^ playGame = gcnew SnakeGame(this);
				playGame->ShowDialog();
			}
			
			/* Displays the scoreboard when the scores button is clicked */
			void scoresClick(System::Object^ sender, System::EventArgs^ e) {
				this->Hide();
				ScoreBoard^ highScores = gcnew ScoreBoard(this);
				highScores->ShowDialog();
			}
			
			/* Closes the app when the exit button is clicked */
			void exitClick(System::Object^ sender, System::EventArgs^ e) {
				Application::Exit();
			}
			
			/* Code Made By Windows Designer */
			#pragma region Windows Form Designer generated code
				/* Unmodified method made for designer support */
				void initializeComponent(void) {
					System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartMenu::typeid));
					this->tablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
					this->playButton = (gcnew System::Windows::Forms::Button());
					this->exitGame = (gcnew System::Windows::Forms::Button());
					this->scoreBoard = (gcnew System::Windows::Forms::Button());
					this->gameImg = (gcnew System::Windows::Forms::PictureBox());
					this->tablePanel->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameImg))->BeginInit();
					this->SuspendLayout();
					// 
					// tablePanel
					// 
					this->tablePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
						| System::Windows::Forms::AnchorStyles::Left)
						| System::Windows::Forms::AnchorStyles::Right));
					this->tablePanel->ColumnCount = 1;
					this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
					this->tablePanel->Controls->Add(this->playButton, 0, 1);
					this->tablePanel->Controls->Add(this->exitGame, 0, 3);
					this->tablePanel->Controls->Add(this->scoreBoard, 0, 2);
					this->tablePanel->Controls->Add(this->gameImg, 0, 0);
					this->tablePanel->Location = System::Drawing::Point(12, 12);
					this->tablePanel->Name = L"tablePanel";
					this->tablePanel->RowCount = 5;
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45)));
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
					this->tablePanel->Size = System::Drawing::Size(320, 417);
					this->tablePanel->TabIndex = 0;
					// 
					// playButton
					// 
					this->playButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
					this->playButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->playButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->playButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->playButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->playButton->ForeColor = System::Drawing::Color::Lime;
					this->playButton->Location = System::Drawing::Point(122, 190);
					this->playButton->MaximumSize = System::Drawing::Size(75, 35);
					this->playButton->MinimumSize = System::Drawing::Size(75, 35);
					this->playButton->Name = L"playButton";
					this->playButton->Size = System::Drawing::Size(75, 35);
					this->playButton->TabIndex = 0;
					this->playButton->Text = L"play";
					this->playButton->UseVisualStyleBackColor = true;
					this->playButton->Click += gcnew System::EventHandler(this, &StartMenu::playClick);
					// 
					// exitGame
					// 
					this->exitGame->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
					this->exitGame->DialogResult = System::Windows::Forms::DialogResult::Cancel;
					this->exitGame->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->exitGame->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->exitGame->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->exitGame->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->exitGame->ForeColor = System::Drawing::Color::Red;
					this->exitGame->Location = System::Drawing::Point(122, 272);
					this->exitGame->MaximumSize = System::Drawing::Size(75, 35);
					this->exitGame->MinimumSize = System::Drawing::Size(75, 35);
					this->exitGame->Name = L"exitGame";
					this->exitGame->Size = System::Drawing::Size(75, 35);
					this->exitGame->TabIndex = 2;
					this->exitGame->Text = L"exit";
					this->exitGame->UseVisualStyleBackColor = true;
					this->exitGame->Click += gcnew System::EventHandler(this, &StartMenu::exitClick);
					// 
					// scoreBoard
					// 
					this->scoreBoard->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
					this->scoreBoard->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->scoreBoard->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->scoreBoard->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->scoreBoard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->scoreBoard->ForeColor = System::Drawing::Color::Lime;
					this->scoreBoard->Location = System::Drawing::Point(122, 231);
					this->scoreBoard->MaximumSize = System::Drawing::Size(75, 35);
					this->scoreBoard->MinimumSize = System::Drawing::Size(75, 35);
					this->scoreBoard->Name = L"scoreBoard";
					this->scoreBoard->Size = System::Drawing::Size(75, 35);
					this->scoreBoard->TabIndex = 1;
					this->scoreBoard->Text = L"highscores";
					this->scoreBoard->UseVisualStyleBackColor = true;
					this->scoreBoard->Click += gcnew System::EventHandler(this, &StartMenu::scoresClick);
					// 
					// gameImg
					// 
					this->gameImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gameImg.Image")));
					this->gameImg->Location = System::Drawing::Point(3, 3);
					this->gameImg->Name = L"gameImg";
					this->gameImg->Size = System::Drawing::Size(314, 181);
					this->gameImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
					this->gameImg->TabIndex = 3;
					this->gameImg->TabStop = false;
					// 
					// StartMenu
					// 
					this->AcceptButton = this->playButton;
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->BackColor = System::Drawing::Color::Black;
					this->CancelButton = this->exitGame;
					this->ClientSize = System::Drawing::Size(344, 441);
					this->Controls->Add(this->tablePanel);
					this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
					this->MaximizeBox = false;
					this->MaximumSize = System::Drawing::Size(360, 480);
					this->MinimumSize = System::Drawing::Size(360, 480);
					this->Name = L"StartMenu";
					this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
					this->Text = L"Snake";
					this->tablePanel->ResumeLayout(false);
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameImg))->EndInit();
					this->ResumeLayout(false);

				}
			#pragma endregion
	};
}
