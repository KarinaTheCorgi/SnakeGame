 #pragma once
#include "NamePrompt.h"
#include "Player.h"
#include <cstdlib>

/* enum to represent the directions the snake can be facing */
public enum class Direction {
	Up,
	Down,
	Left,
	Right
};

namespace SnakeGame {

	/* Forms uses the following namespaces (to make buttons, paint, listen to key events, etc */
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/* Snake Game Reference Class */
	public ref class SnakeGame : public System::Windows::Forms::Form {
		public:
			/* SnakeGame Constructor */
			SnakeGame(Form^ prev) : previousForm(prev){
				changeFont();
				initializeComponent();

				snakeBrush = gcnew SolidBrush(Color::LimeGreen);
				foodBrush = gcnew SolidBrush(Color::Red);

				// Add the initial segments without any direction (here so that it can show where the snake is before the game starts)
				snake.Add(Point(5, 3));
				snake.Add(Point(4, 3));
				snake.Add(Point(3, 3));
				cellSize = 20;
				score = 0;
				placeFood();
			}

		protected:
			/* SnakeGame Deconstructor */
			~SnakeGame() {
				if (components)
					delete components;
			}

		private:
			/* Pointer to the previous form, so you can click the back button and return to the menu */
			Form^ previousForm;
			
			/* Custom Font Collection (just using one) */
			System::Drawing::Text::PrivateFontCollection^ customFonts = gcnew System::Drawing::Text::PrivateFontCollection();

			/* Components of the window/form */
			System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
			System::Windows::Forms::Label^ scoreLabel;
			System::Windows::Forms::Button^ startButton;
			System::Windows::Forms::Button^ backButton;
			System::Windows::Forms::Label^ scoreNumLabel;
			System::Windows::Forms::PictureBox^ gameArea;
			System::Windows::Forms::Timer^ gameTimer;
			System::ComponentModel::IContainer^ components;

			/* Game Variables */
			Direction snakeDirection;
			SolidBrush^ snakeBrush;
			SolidBrush^ foodBrush;
			int cellSize;
			List<Point> snake;
			Point food;
			int score;

			/* changes the font of the window (to custom font) */
			void changeFont(void) {
				customFonts->AddFontFile("customfont.ttf");
				System::Drawing::Font^ customFont = gcnew System::Drawing::Font(customFonts->Families[0], 14);
				this->Font = customFont;
			}

			/* resets the game, so the player can hit start and play again */
			void resetGame() {
				// Clear the snake and reset its initial position and direction
				snake.Clear();
				snake.Add(Point(5, 3));
				snake.Add(Point(4, 3));
				snake.Add(Point(3, 3));
			
				snakeDirection = Direction::Right; // Set the initial direction to Right

				// Reset the score
				score = 0;

				// Redraw the game area
				this->gameArea->Image = nullptr;
				gameArea->Invalidate();
			}

			/* changes the gameArea image to one that displays Game Over, stops time, 
			   and checks leaderboard for high scores (promping player accordingly) */
			void gameOver() {
				this->gameArea->Image = nullptr;

				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SnakeGame::typeid));
				this->gameArea->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->gameArea->BackColor = System::Drawing::Color::DarkSlateGray;
				this->gameArea->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gameArea.Image")));
				this->gameArea->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;

				this->gameTimer->Enabled = false;

				if (isNewHighScore()) {
					NamePrompt^ np = gcnew NamePrompt(this, score);
					np->ShowDialog();
				}
			}

			/* randomly places food somewhere within the gameArea */
			void placeFood() {
				// Generate random positions for the food within the bounds
				int maxX = gameArea->Width / cellSize - 1;
				int maxY = gameArea->Height / cellSize - 1;

				food = Point(rand() % (maxX + 1), rand() % (maxY + 1));
			}

			/* moves the snake by adding a segment(head) at the beginning, and removing the last segment */
			void moveSnake() {
				// Move the snake based on the current direction
				Point newHead = snake[0];
				switch (snakeDirection) {
					case Direction::Left:
						newHead.X -= 1;
						break;
					case Direction::Right:
						newHead.X += 1;
						break;
					case Direction::Up:
						newHead.Y -= 1;
						break;
					case Direction::Down:
						newHead.Y += 1;
						break;
				}

				// Insert the new head at the beginning of the snake
				snake.Insert(0, newHead);
				// Remove the last segment to keep the snake the same size
				snake.RemoveAt(snake.Count - 1);
			}

			/* tests whether or not the snake has either collided with the walls or itself */
			bool hasCollided() {
				// Check for collisions with walls and itself
				Point head = snake[0];
				if (head.X < 0 || head.X >= gameArea->Width / cellSize ||
					head.Y < 0 || head.Y >= 1 + gameArea->Height / cellSize) {
					return true; // Collision with the wall
				}

				for (int i = 1; i < snake.Count; i++) {
					if (head == snake[i]) {
						return true; // Collision with itself
					}
				}

				return false;
			}

			/* checks if the player beat the lowest player on the score board and prompts them to enter their initials */
			bool isNewHighScore() {
				LeaderBoard^ lb = gcnew LeaderBoard("scores.txt");
				if (score > lb->getSixth()->getScore()) {
					return true;
				}
				return false;
			}

			/* shows previous form and hides this one */
			void backClick(System::Object^ sender, System::EventArgs^ e) {
				this->Hide();
				previousForm->Show();
			}

			/* starts the game (timer/reset) and allows for key events (how the player controls the snake) */
			void startClick(System::Object^ sender, System::EventArgs^ e) {
				gameTimer->Start();
				KeyPreview = true;
				resetGame();
			}

			/* every interval of the gameTimer, the score is updated, snake is moved and checked for collisions, and repaints the gameArea */
			void onTick(Object^ sender, EventArgs^ e) {
				this->scoreNumLabel->Text = score.ToString();
				moveSnake();

				if (hasCollided()) {
					gameOver();
				}

				if (snake[0] == food) {
					score ++;

					snake.Add(snake[snake.Count - 1]);

					placeFood();
				}

				// redraws the game
				gameArea->Invalidate();
			}

			/* when the gameArea is invalidated, this paints every segment of the snake on the gameArea, along with the food */
			void paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
				Graphics^ g = e->Graphics;

				// Draw the snake
				for each (Point segment in snake) {
					g->FillRectangle(snakeBrush, segment.X * cellSize, segment.Y * cellSize, cellSize, cellSize);
					// while looping through the segments of the snake, this checks if the food was randomized to be on the snake, and randomizes
					// it again.
					while (segment == food) {
						placeFood();
					}
				}

				// Draw the food
				g->FillEllipse(foodBrush, food.X * cellSize, food.Y * cellSize, cellSize, cellSize);

				Form::OnPaint(e);
			}

			/* when WASD is pressed, this changes the direction of the snake accordingly */
			void keyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
				// snake cannot move right if it's going left..etc
				switch (e->KeyCode) {
					case Keys::A:
						if (snakeDirection != Direction::Right)
							snakeDirection = Direction::Left;
						break;
					case Keys::D:
						if (snakeDirection != Direction::Left)
							snakeDirection = Direction::Right;
						break;
					case Keys::W:
						if (snakeDirection != Direction::Down)
							snakeDirection = Direction::Up;
						break;
					case Keys::S:
						if (snakeDirection != Direction::Up) 
							snakeDirection = Direction::Down;
						break;
					}
			}

			/* Code Made By Windows Designer */
			#pragma region Windows Form Designer generated code
				/* Unmodified method made for designer support */
				void initializeComponent(void) {
					this->components = (gcnew System::ComponentModel::Container());
					System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SnakeGame::typeid));
					this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
					this->scoreLabel = (gcnew System::Windows::Forms::Label());
					this->backButton = (gcnew System::Windows::Forms::Button());
					this->startButton = (gcnew System::Windows::Forms::Button());
					this->scoreNumLabel = (gcnew System::Windows::Forms::Label());
					this->gameArea = (gcnew System::Windows::Forms::PictureBox());
					this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
					this->tableLayoutPanel1->SuspendLayout();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameArea))->BeginInit();
					this->SuspendLayout();
					// 
					// tableLayoutPanel1
					// 
					this->tableLayoutPanel1->ColumnCount = 4;
					this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
						85)));
					this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
						85)));
					this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
						50)));
					this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
						50)));
					this->tableLayoutPanel1->Controls->Add(this->scoreLabel, 2, 0);
					this->tableLayoutPanel1->Controls->Add(this->backButton, 0, 0);
					this->tableLayoutPanel1->Controls->Add(this->startButton, 1, 0);
					this->tableLayoutPanel1->Controls->Add(this->scoreNumLabel, 3, 0);
					this->tableLayoutPanel1->Controls->Add(this->gameArea, 0, 1);
					this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
					this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
					this->tableLayoutPanel1->RowCount = 2;
					this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
					this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
					this->tableLayoutPanel1->Size = System::Drawing::Size(320, 417);
					this->tableLayoutPanel1->TabIndex = 0;
					// 
					// scoreLabel
					// 
					this->scoreLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->scoreLabel->ForeColor = System::Drawing::Color::White;
					this->scoreLabel->Location = System::Drawing::Point(173, 0);
					this->scoreLabel->Name = L"scoreLabel";
					this->scoreLabel->Size = System::Drawing::Size(69, 50);
					this->scoreLabel->TabIndex = 0;
					this->scoreLabel->Text = L"score:";
					this->scoreLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					// 
					// backButton
					// 
					this->backButton->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->backButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->backButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->backButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->backButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->backButton->ForeColor = System::Drawing::Color::White;
					this->backButton->Location = System::Drawing::Point(5, 7);
					this->backButton->Name = L"backButton";
					this->backButton->Size = System::Drawing::Size(75, 35);
					this->backButton->TabIndex = 3;
					this->backButton->Text = L"back";
					this->backButton->UseVisualStyleBackColor = true;
					this->backButton->Click += gcnew System::EventHandler(this, &SnakeGame::backClick);
					// 
					// startButton
					// 
					this->startButton->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->startButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
					this->startButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DimGray;
					this->startButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
					this->startButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					this->startButton->ForeColor = System::Drawing::Color::White;
					this->startButton->Location = System::Drawing::Point(90, 7);
					this->startButton->Name = L"startButton";
					this->startButton->Size = System::Drawing::Size(75, 35);
					this->startButton->TabIndex = 2;
					this->startButton->Text = L"start";
					this->startButton->UseVisualStyleBackColor = true;
					this->startButton->Click += gcnew System::EventHandler(this, &SnakeGame::startClick);
					// 
					// scoreNumLabel
					// 
					this->scoreNumLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->scoreNumLabel->ForeColor = System::Drawing::Color::Gold;
					this->scoreNumLabel->Location = System::Drawing::Point(249, 0);
					this->scoreNumLabel->Name = L"scoreNumLabel";
					this->scoreNumLabel->Size = System::Drawing::Size(67, 50);
					this->scoreNumLabel->TabIndex = 4;
					this->scoreNumLabel->Text = L"0";
					this->scoreNumLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					// 
					// gameArea
					// 
					this->gameArea->Anchor = System::Windows::Forms::AnchorStyles::None;
					this->gameArea->BackColor = System::Drawing::Color::DarkSlateGray;
					this->tableLayoutPanel1->SetColumnSpan(this->gameArea, 4);
					this->gameArea->Location = System::Drawing::Point(10, 53);
					this->gameArea->Name = L"gameArea";
					this->gameArea->Size = System::Drawing::Size(320, 360);
					this->gameArea->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
					this->gameArea->TabIndex = 5;
					this->gameArea->TabStop = false;
					this->gameArea->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SnakeGame::paint);
					// 
					// gameTimer
					// 
					this->gameTimer->Interval = 100;
					this->gameTimer->Tick += gcnew System::EventHandler(this, &SnakeGame::onTick);
					// 
					// SnakeGame
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->BackColor = System::Drawing::Color::Black;
					this->ClientSize = System::Drawing::Size(344, 441);
					this->Controls->Add(this->tableLayoutPanel1);
					this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
					this->MaximizeBox = false;
					this->MaximumSize = System::Drawing::Size(360, 480);
					this->MinimumSize = System::Drawing::Size(360, 480);
					this->Name = L"SnakeGame";
					this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
					this->Text = L"Snake";
					this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SnakeGame::keyDown);
					this->tableLayoutPanel1->ResumeLayout(false);
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameArea))->EndInit();
					this->ResumeLayout(false);

				}
			#pragma endregion

	};
}