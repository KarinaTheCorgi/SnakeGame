#pragma once
#include "Player.h"

namespace SnakeGame {
	/* namespaces used */
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/* Reference Class for the ScoreBoard Form */
	public ref class ScoreBoard : public System::Windows::Forms::Form {
		public:
			/* ScoreBoard Constructors */
			ScoreBoard(Form^ previous) {
				previousForm = previous;
				changeFont();
				initializeComponents();
				updateBoard();
			}
		protected:
			/* ScoreBoard Deconstructor */
			~ScoreBoard() {
				if (components)
					delete components;
			}
		
		private: 
			Form^ previousForm;
			/* Custom Font Collection (just using one) */
			System::Drawing::Text::PrivateFontCollection^ customFonts = gcnew System::Drawing::Text::PrivateFontCollection();
			
			/* Holds the Components in a table arrangement */
			System::Windows::Forms::TableLayoutPanel^ tablePanel;
			
			/* Button to go back to the StartMenu */
			System::Windows::Forms::Button^ backButton;

			/* Hold Text for Placement and Column Titles (these dont change) */
			System::Windows::Forms::Label^ rank;
			System::Windows::Forms::Label^ score;
			System::Windows::Forms::Label^ initials;
			System::Windows::Forms::Label^ firstRank;
			System::Windows::Forms::Label^ secondRank;
			System::Windows::Forms::Label^ thirdRank;
			System::Windows::Forms::Label^ fourthRank;
			System::Windows::Forms::Label^ fifthRank;
			System::Windows::Forms::Label^ sixthRank;

			System::Windows::Forms::Label^ firstScore;
			System::Windows::Forms::Label^ secondScore;
			System::Windows::Forms::Label^ thirdScore;
			System::Windows::Forms::Label^ fourthScore;
			System::Windows::Forms::Label^ fifthScore;
			System::Windows::Forms::Label^ sixthScore;

			System::Windows::Forms::Label^ firstInits;
			System::Windows::Forms::Label^ secondInits;
			System::Windows::Forms::Label^ thirdInits;
			System::Windows::Forms::Label^ fourthInits;
			System::Windows::Forms::Label^ fifthInits;
			System::Windows::Forms::Label^ sixthInits;
			System::ComponentModel::Container ^components;

			/* LeaderBoard */
			LeaderBoard^ highScores;

			/* function used to change the font of the form */
			void changeFont(void) {
				customFonts->AddFontFile("customfont.ttf");
				System::Drawing::Font^ customFont = gcnew System::Drawing::Font(customFonts->Families[0], 14);
				this->Font = customFont;
			}

			/* function called when back button clicked */
			void backClick(Object^ sender, EventArgs^ e) {
				this->Hide();
				previousForm->Show();
			}

			/* populates the scoreboard with their values */
			void updateBoard() {
				highScores = gcnew LeaderBoard("scores.txt");

				this->firstRank->Text = (highScores->getFirst()->getRank());
				int firstSC = highScores->getFirst()->getScore();
				this->firstScore->Text = (firstSC >= 0) ? firstSC.ToString() : "---";
				this->firstInits->Text = (highScores->getFirst()->getInits());

				this->secondRank->Text = (highScores->getSecond()->getRank());
				int secSC = highScores->getSecond()->getScore();
				this->secondScore->Text = (secSC >= 0) ? secSC.ToString() : "---";
				this->secondInits->Text = (highScores->getSecond()->getInits());

				this->thirdRank->Text = (highScores->getThird()->getRank());
				int thirSC = highScores->getThird()->getScore();
				this->thirdScore->Text = (thirSC >= 0) ? thirSC.ToString() : "---";
				this->thirdInits->Text = (highScores->getThird()->getInits());

				this->fourthRank->Text = (highScores->getFourth()->getRank());
				int fourSC = highScores->getFourth()->getScore();
				this->fourthScore->Text = (fourSC >= 0) ? fourSC.ToString() : "---";
				this->fourthInits->Text = (highScores->getFourth()->getInits());

				this->fifthRank->Text = (highScores->getFifth()->getRank());
				int fifSC = highScores->getFifth()->getScore();
				this->fifthScore->Text = (fifSC >= 0) ? fifSC.ToString() : "---";
				this->fifthInits->Text = (highScores->getFifth()->getInits());

				this->sixthRank->Text = (highScores->getSixth()->getRank());
				int sixSC = highScores->getSixth()->getScore();
				this->sixthScore->Text = (sixSC >= 0) ? (highScores->getSixth()->getScore()).ToString() : "---";
				this->sixthInits->Text = (highScores->getSixth()->getInits());
			}


			/* Code Made By Windows Designer */
			#pragma region Windows Form Designer generated code
					/* Unmodified method made for designer support */
					void initializeComponents(void) {
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ScoreBoard::typeid));
						this->tablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
						this->rank = (gcnew System::Windows::Forms::Label());
						this->score = (gcnew System::Windows::Forms::Label());
						this->initials = (gcnew System::Windows::Forms::Label());
						this->backButton = (gcnew System::Windows::Forms::Button());
						this->firstRank = (gcnew System::Windows::Forms::Label());
						this->secondRank = (gcnew System::Windows::Forms::Label());
						this->thirdRank = (gcnew System::Windows::Forms::Label());
						this->fourthRank = (gcnew System::Windows::Forms::Label());
						this->fifthRank = (gcnew System::Windows::Forms::Label());
						this->sixthRank = (gcnew System::Windows::Forms::Label());

						this->firstScore = (gcnew System::Windows::Forms::Label());
						this->secondScore = (gcnew System::Windows::Forms::Label());
						this->thirdScore = (gcnew System::Windows::Forms::Label());
						this->fourthScore = (gcnew System::Windows::Forms::Label());
						this->fifthScore = (gcnew System::Windows::Forms::Label());
						this->sixthScore = (gcnew System::Windows::Forms::Label());

						this->firstInits = (gcnew System::Windows::Forms::Label());
						this->secondInits = (gcnew System::Windows::Forms::Label());
						this->thirdInits = (gcnew System::Windows::Forms::Label());
						this->fourthInits = (gcnew System::Windows::Forms::Label());
						this->fifthInits = (gcnew System::Windows::Forms::Label());
						this->sixthInits = (gcnew System::Windows::Forms::Label());
						this->tablePanel->SuspendLayout();
						this->SuspendLayout();
						// 
						// TablePanel
						// 
						this->tablePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->tablePanel->BackColor = System::Drawing::Color::Black;
						this->tablePanel->ColumnCount = 3;
						this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
						this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
						this->tablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
						this->tablePanel->Controls->Add(this->rank, 0, 1);
						this->tablePanel->Controls->Add(this->score, 1, 1);
						this->tablePanel->Controls->Add(this->initials, 2, 1);
						this->tablePanel->Controls->Add(this->backButton, 0, 0);
						this->tablePanel->Controls->Add(this->firstRank, 0, 2);
						this->tablePanel->Controls->Add(this->secondRank, 0, 3);
						this->tablePanel->Controls->Add(this->thirdRank, 0, 4);
						this->tablePanel->Controls->Add(this->fourthRank, 0, 5);
						this->tablePanel->Controls->Add(this->fifthRank, 0, 6);
						this->tablePanel->Controls->Add(this->sixthRank, 0, 7);

						this->tablePanel->Controls->Add(this->firstScore, 1, 2);
						this->tablePanel->Controls->Add(this->secondScore, 1, 3);
						this->tablePanel->Controls->Add(this->thirdScore, 1, 4);
						this->tablePanel->Controls->Add(this->fourthScore, 1, 5);
						this->tablePanel->Controls->Add(this->fifthScore, 1, 6);
						this->tablePanel->Controls->Add(this->sixthScore, 1, 7);

						this->tablePanel->Controls->Add(this->firstInits, 2, 2);
						this->tablePanel->Controls->Add(this->secondInits, 2, 3);
						this->tablePanel->Controls->Add(this->thirdInits, 2, 4);
						this->tablePanel->Controls->Add(this->fourthInits, 2, 5);
						this->tablePanel->Controls->Add(this->fifthInits, 2, 6);
						this->tablePanel->Controls->Add(this->sixthInits, 2, 7);

						this->tablePanel->Location = System::Drawing::Point(12, 12);
						this->tablePanel->Name = L"TablePanel";
						this->tablePanel->RowCount = 8;
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
						this->tablePanel->Size = System::Drawing::Size(320, 393);
						this->tablePanel->TabIndex = 0;
						//
						// Rank
						// 
						this->rank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->rank->ForeColor = System::Drawing::Color::Lime;
						this->rank->Location = System::Drawing::Point(3, 49);
						this->rank->Name = L"Rank";
						this->rank->Size = System::Drawing::Size(100, 49);
						this->rank->TabIndex = 0;
						this->rank->Text = L"Rank";
						this->rank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// Score
						// 
						this->score->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->score->AutoSize = true;
						this->score->ForeColor = System::Drawing::Color::Lime;
						this->score->Location = System::Drawing::Point(109, 49);
						this->score->Name = L"Score";
						this->score->Size = System::Drawing::Size(100, 49);
						this->score->TabIndex = 1;
						this->score->Text = L"Score";
						this->score->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// Initials
						// 
						this->initials->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->initials->AutoSize = true;
						this->initials->ForeColor = System::Drawing::Color::Lime;
						this->initials->Location = System::Drawing::Point(215, 49);
						this->initials->Name = L"Initials";
						this->initials->Size = System::Drawing::Size(102, 49);
						this->initials->TabIndex = 2;
						this->initials->Text = L"Initials";
						this->initials->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						//
						// Back
						// 
						this->backButton->AccessibleDescription = L"click to return to the main menu";
						this->backButton->AccessibleName = L"back button";
						this->backButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->backButton->BackColor = System::Drawing::Color::Black;
						this->backButton->Cursor = System::Windows::Forms::Cursors::Hand;
						this->backButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
						this->backButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
						this->backButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
						this->backButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
						this->backButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
						this->backButton->ForeColor = System::Drawing::Color::White;
						this->backButton->Location = System::Drawing::Point(3, 3);
						this->backButton->Name = L"Back";
						this->backButton->Size = System::Drawing::Size(100, 43);
						this->backButton->TabIndex = 3;
						this->backButton->Text = L"Back";
						this->backButton->UseVisualStyleBackColor = false;
						this->backButton->Click += gcnew System::EventHandler(this, &ScoreBoard::backClick);
						// 
						// FirstRank
						// 
						this->firstRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->firstRank->AutoSize = true;
						this->firstRank->ForeColor = System::Drawing::Color::Gold;
						this->firstRank->Location = System::Drawing::Point(3, 98);
						this->firstRank->Name = L"First";
						this->firstRank->Size = System::Drawing::Size(100, 49);
						this->firstRank->TabIndex = 4;
						this->firstRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FirstScore
						// 
						this->firstScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->firstScore->AutoSize = true;
						this->firstScore->ForeColor = System::Drawing::Color::Gold;
						this->firstScore->Location = System::Drawing::Point(109, 98);
						this->firstScore->Name = L"FirstScore";
						this->firstScore->Size = System::Drawing::Size(100, 49);
						this->firstScore->TabIndex = 4;
						this->firstScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FirstInits
						// 
						this->firstInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->firstInits->AutoSize = true;
						this->firstInits->ForeColor = System::Drawing::Color::Gold;
						this->firstInits->Location = System::Drawing::Point(215, 98);
						this->firstInits->Name = L"FirstInits";
						this->firstInits->Size = System::Drawing::Size(100, 49);
						this->firstInits->TabIndex = 4;
						this->firstInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SecondRank
						// 
						this->secondRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->secondRank->AutoSize = true;
						this->secondRank->ForeColor = System::Drawing::Color::Pink;
						this->secondRank->Location = System::Drawing::Point(3, 147);
						this->secondRank->Name = L"SecondRank";
						this->secondRank->Size = System::Drawing::Size(100, 49);
						this->secondRank->TabIndex = 5;
						this->secondRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SecondScore
						// 
						this->secondScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->secondScore->AutoSize = true;
						this->secondScore->ForeColor = System::Drawing::Color::Pink;
						this->secondScore->Location = System::Drawing::Point(109, 147);
						this->secondScore->Name = L"SecondScore";
						this->secondScore->Size = System::Drawing::Size(100, 49);
						this->secondScore->TabIndex = 5;
						this->secondScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SecondInits
						// 
						this->secondInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->secondInits->AutoSize = true;
						this->secondInits->ForeColor = System::Drawing::Color::Pink;
						this->secondInits->Location = System::Drawing::Point(215, 147);
						this->secondInits->Name = L"SecondInits";
						this->secondInits->Size = System::Drawing::Size(100, 49);
						this->secondInits->TabIndex = 5;
						this->secondInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// ThirdRank
						// 
						this->thirdRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->thirdRank->AutoSize = true;
						this->thirdRank->ForeColor = System::Drawing::Color::Orange;
						this->thirdRank->Location = System::Drawing::Point(3, 196);
						this->thirdRank->Name = L"ThirdRank";
						this->thirdRank->Size = System::Drawing::Size(100, 49);
						this->thirdRank->TabIndex = 6;
						this->thirdRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// ThirdScore
						// 
						this->thirdScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->thirdScore->AutoSize = true;
						this->thirdScore->ForeColor = System::Drawing::Color::Orange;
						this->thirdScore->Location = System::Drawing::Point(109, 196);
						this->thirdScore->Name = L"ThirdScore";
						this->thirdScore->Size = System::Drawing::Size(100, 49);
						this->thirdScore->TabIndex = 6;
						this->thirdScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// ThirdInits
						// 
						this->thirdInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->thirdInits->AutoSize = true;
						this->thirdInits->ForeColor = System::Drawing::Color::Orange;
						this->thirdInits->Location = System::Drawing::Point(215, 196);
						this->thirdInits->Name = L"Third";
						this->thirdInits->Size = System::Drawing::Size(100, 49);
						this->thirdInits->TabIndex = 6;
						this->thirdInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FourthRank
						// 
						this->fourthRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fourthRank->AutoSize = true;
						this->fourthRank->ForeColor = System::Drawing::Color::LightGreen;
						this->fourthRank->Location = System::Drawing::Point(3, 245);
						this->fourthRank->Name = L"FourthRank";
						this->fourthRank->Size = System::Drawing::Size(100, 49);
						this->fourthRank->TabIndex = 7;
						this->fourthRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FourthScore
						// 
						this->fourthScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fourthScore->AutoSize = true;
						this->fourthScore->ForeColor = System::Drawing::Color::LightGreen;
						this->fourthScore->Location = System::Drawing::Point(109, 245);
						this->fourthScore->Name = L"FourthScore";
						this->fourthScore->Size = System::Drawing::Size(100, 49);
						this->fourthScore->TabIndex = 7;
						this->fourthScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FourthInits
						// 
						this->fourthInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fourthInits->AutoSize = true;
						this->fourthInits->ForeColor = System::Drawing::Color::LightGreen;
						this->fourthInits->Location = System::Drawing::Point(215, 245);
						this->fourthInits->Name = L"FourthInits";
						this->fourthInits->Size = System::Drawing::Size(100, 49);
						this->fourthInits->TabIndex = 7;
						this->fourthInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FifthRank
						// 
						this->fifthRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fifthRank->AutoSize = true;
						this->fifthRank->ForeColor = System::Drawing::Color::LightBlue;
						this->fifthRank->Location = System::Drawing::Point(3, 294);
						this->fifthRank->Name = L"FifthRank";
						this->fifthRank->Size = System::Drawing::Size(100, 49);
						this->fifthRank->TabIndex = 8;
						this->fifthRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FifthScore
						// 
						this->fifthScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fifthScore->AutoSize = true;
						this->fifthScore->ForeColor = System::Drawing::Color::LightBlue;
						this->fifthScore->Location = System::Drawing::Point(109, 294);
						this->fifthScore->Name = L"FifthScore";
						this->fifthScore->Size = System::Drawing::Size(100, 49);
						this->fifthScore->TabIndex = 8;
						this->fifthScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// FifthInits
						// 
						this->fifthInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->fifthInits->AutoSize = true;
						this->fifthInits->ForeColor = System::Drawing::Color::LightBlue;
						this->fifthInits->Location = System::Drawing::Point(215, 294);
						this->fifthInits->Name = L"FifthInits";
						this->fifthInits->Size = System::Drawing::Size(100, 49);
						this->fifthInits->TabIndex = 8;
						this->fifthInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SixthRank
						// 
						this->sixthRank->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->sixthRank->AutoSize = true;
						this->sixthRank->ForeColor = System::Drawing::Color::Turquoise;
						this->sixthRank->Location = System::Drawing::Point(3, 343);
						this->sixthRank->Name = L"SixthRank";
						this->sixthRank->Size = System::Drawing::Size(100, 50);
						this->sixthRank->TabIndex = 9;
						this->sixthRank->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SixthScore
						// 
						this->sixthScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->sixthScore->AutoSize = true;
						this->sixthScore->ForeColor = System::Drawing::Color::Turquoise;
						this->sixthScore->Location = System::Drawing::Point(109, 343);
						this->sixthScore->Name = L"SixthScore";
						this->sixthScore->Size = System::Drawing::Size(100, 50);
						this->sixthScore->TabIndex = 9;
						this->sixthScore->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// SixthInits
						// 
						this->sixthInits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
							| System::Windows::Forms::AnchorStyles::Left)
							| System::Windows::Forms::AnchorStyles::Right));
						this->sixthInits->AutoSize = true;
						this->sixthInits->ForeColor = System::Drawing::Color::Turquoise;
						this->sixthInits->Location = System::Drawing::Point(215, 343);
						this->sixthInits->Name = L"SixthInits";
						this->sixthInits->Size = System::Drawing::Size(100, 50);
						this->sixthInits->TabIndex = 9;
						this->sixthInits->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
						// 
						// ScoreBoard
						// 
						this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
						this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
						this->BackColor = System::Drawing::Color::Black;
						this->CancelButton = this->backButton;
						this->ClientSize = System::Drawing::Size(344, 441);
						this->Controls->Add(this->tablePanel);
						this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
						this->MaximizeBox = false;
						this->MaximumSize = System::Drawing::Size(360, 480);
						this->MinimumSize = System::Drawing::Size(360, 480);
						this->Name = L"ScoreBoard";
						this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
						this->Text = L"Snake";
						this->tablePanel->ResumeLayout(false);
						this->tablePanel->PerformLayout();
						this->ResumeLayout(false);

					}
			#pragma endregion

	};
}
