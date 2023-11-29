#pragma once
#include "Player.h"

namespace SnakeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/* NamePrompt Class */
	public ref class NamePrompt : public System::Windows::Forms::Form {
		public:
			/* NamePrompt Constructors */
			NamePrompt(Form^ prev, int sco) : previousForm(prev), score(sco){
				changeFont();
				InitializeComponent();
				this->textBox->Font = gcnew System::Drawing::Font(customFonts->Families[0], 26);
			}

		protected:
			/* NamePrompt Deconstructor */
			~NamePrompt() {
				if (components) {
					delete components;
				}
			}
		private: 
			/* Pointer to the previous form, so you can click the back button and return to the game screen */
			Form^ previousForm;
			
			/* Custom Font Collection (just using one) */
			System::Drawing::Text::PrivateFontCollection^ customFonts = gcnew System::Drawing::Text::PrivateFontCollection();

			/* Components of the window/form */
			System::Windows::Forms::TableLayoutPanel^ tablePanel;
			System::Windows::Forms::Label^ promptLabel;
			System::Windows::Forms::TextBox^ textBox;
			System::Windows::Forms::Button^ submitButton;
			System::ComponentModel::Container^ components;

			/* Player attributes */
			Player^ player;
			int score;

			/* function used to change the font of the form */
			void changeFont(void) {
				customFonts->AddFontFile("customfont.ttf");
				System::Drawing::Font^ customFont = gcnew System::Drawing::Font(customFonts->Families[0], 14);
				this->Font = customFont;
			}

			/* Adds the Player to the scores.txt file */
			void submitClick(System::Object^ sender, System::EventArgs^ e) {
				if (this->textBox->Text->Length == 3) {
					player = gcnew Player();
					String^ inits = gcnew String(this->textBox->Text);
					player->setInits(inits);
					player->setScore(score);

					String^ fileName = "scores.txt";
					// true = appends to the file
					StreamWriter^ sw = gcnew StreamWriter(fileName, true);
					sw << player;
					sw->Close();

					this->Hide();
					previousForm->Show();
				}
				else {
					this->promptLabel->Text = L"Please enter 3 characters for your initials.";
				}
			}

			/* Code Made By Windows Designer */
			#pragma region Windows Form Designer generated code
				/* Unmodified method made for designer support */
				void InitializeComponent(void) {
					System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NamePrompt::typeid));
					this->tablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
					this->submitButton = (gcnew System::Windows::Forms::Button());
					this->promptLabel = (gcnew System::Windows::Forms::Label());
					this->textBox = (gcnew System::Windows::Forms::TextBox());
					this->tablePanel->SuspendLayout();
					this->SuspendLayout();
					// 
					// tablePanel
					// 
					this->tablePanel->ColumnCount = 2;
					this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
					this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
					this->tablePanel->Controls->Add(this->submitButton, 1, 1);
					this->tablePanel->Controls->Add(this->promptLabel, 0, 0);
					this->tablePanel->Controls->Add(this->textBox, 1, 0);
					this->tablePanel->Location = System::Drawing::Point(12, 12);
					this->tablePanel->Name = L"tablePanel";
					this->tablePanel->RowCount = 2;
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
					this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
					this->tablePanel->Size = System::Drawing::Size(370, 207);
					this->tablePanel->TabIndex = 0;
					// 
					// submitButton
					// 
					this->submitButton->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->submitButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->submitButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->submitButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->submitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->submitButton->ForeColor = System::Drawing::Color::White;
					this->submitButton->Location = System::Drawing::Point(240, 137);
					this->submitButton->Name = L"submitButton";
					this->submitButton->Size = System::Drawing::Size(75, 35);
					this->submitButton->TabIndex = 3;
					this->submitButton->Text = L"submit";
					this->submitButton->UseVisualStyleBackColor = true;
					this->submitButton->Click += gcnew System::EventHandler(this, &NamePrompt::submitClick);
					// 
					// promptLabel
					// 
					this->promptLabel->ForeColor = System::Drawing::Color::Lime;
					this->promptLabel->Location = System::Drawing::Point(3, 0);
					this->promptLabel->Name = L"promptLabel";
					this->tablePanel->SetRowSpan(this->promptLabel, 2);
					this->promptLabel->Size = System::Drawing::Size(179, 207);
					this->promptLabel->TabIndex = 0;
					this->promptLabel->Text = L"You just set a NEW high score! Enter your initials for the scoreboard!";
					this->promptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					// 
					// textBox
					// 
					this->textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->textBox->BackColor = System::Drawing::Color::Black;
					this->textBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					this->textBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
					this->textBox->ForeColor = System::Drawing::Color::White;
					this->textBox->Location = System::Drawing::Point(227, 29);
					this->textBox->MaxLength = 3;
					this->textBox->Name = L"textBox";
					this->textBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
					this->textBox->Size = System::Drawing::Size(100, 44);
					this->textBox->TabIndex = 2;
					this->textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
					this->textBox->WordWrap = false;
					// 
					// NamePrompt
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->BackColor = System::Drawing::Color::Black;
					this->ClientSize = System::Drawing::Size(394, 231);
					this->Controls->Add(this->tablePanel);
					this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
					this->MaximizeBox = false;
					this->MaximumSize = System::Drawing::Size(410, 270);
					this->MinimumSize = System::Drawing::Size(410, 270);
					this->Name = L"NamePrompt";
					this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
					this->Text = L"Snake";
					this->tablePanel->ResumeLayout(false);
					this->tablePanel->PerformLayout();
					this->ResumeLayout(false);
				}
			#pragma endregion
	

	};
}
