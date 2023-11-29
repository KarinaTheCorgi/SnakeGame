/*  Resources:
	https://learn.microsoft.com/en-us/cpp/dotnet/file-handling-and-i-o-cpp-cli?view=msvc-170#read_text - reading a file
	https://learn.microsoft.com/en-us/cpp/dotnet/file-handling-and-i-o-cpp-cli?view=msvc-170#write_text - writing a file
	https://www.functionx.com/cppcli/fundamentals/Lesson08e.htm - Line 39 : (int::Parse(...))
	https://www.tutorialspoint.com/cplusplus/cpp_conditional_operator.htm - conditional?:operator
	*/
#pragma once
#include <cliext/vector>
#using<system.dll>

namespace SnakeGame {
	using namespace System;
	using namespace System::IO;

	public ref class Player {
		private:
			String^ initials;
			int score;
		public:
			Player() {
				initials = "---";
				score = -1;
			}
			Player(String^ str) {
				try {
					if (str != nullptr && str->Length >= 5) {
						this->initials = str->Substring(0, 3);
						this->score = int::Parse(str->Substring(4));
					}
					else {
						String^ errorMessage = "Incorrect String Length or Null String";
						throw errorMessage;
					}
				}
				catch (String^ ex) {
					Console::WriteLine(ex);
				}
			}
			Player(Player^ p) {
				try {
					if (p != nullptr) {
						initials = p->initials;
						score = p->score;
					}
					else {
						String^ errorMessage = "Null Player object";
						throw gcnew ArgumentNullException(errorMessage);
					}
				}
				catch (ArgumentNullException^ ex) {
					Console::WriteLine(ex->Message);
				}
			}


			/* Getter and Setters */
			int getScore() { return score; }
			String^ getInits() { return initials; }

			void setInits(String^ inits) { initials = inits; }
			void setScore(int sc) { score = sc; }

			/* writes a player into a file(given the output Stream) */
			static StreamWriter^ operator<<(StreamWriter^ fos, const Player^ p) {
				if (p->score >= 0)
					fos->WriteLine("{0} {1}", p->initials, p->score);
				else
					fos->WriteLine("--- {0}", p->score);
				return fos;
			}

			/* reads into a player given a file input stream */
			static StreamReader^ operator>>(StreamReader^ fis, Player^ p) {
				try {
					String^ line = fis->ReadLine();
					if (line != nullptr && p != nullptr) {
						array<String^>^ parts = line->Split(' ');
						if (parts->Length == 2) {
							p->setInits(parts[0]);
							p->setScore(int::Parse(parts[1]));
						}
						else {
							String^ errorMessage = "Incorrect line format";
							throw gcnew IOException(errorMessage);
						}
					}
				}
				catch (IOException^ ex) {
					Console::WriteLine(ex->Message);
				}

				return fis;
			}


			/* <, >, == operator overloads (used in sorting the scores) */
			static bool operator<(Player^ p1, Player^ p2) {
				if (p1->score < p2->score)
					return true;
				return false;
			};
			
			static bool operator>(Player^ p1, Player^ p2) {
				if (p1->score > p2->score)
					return true;
				return false;
			};
			
			static bool operator==(Player^ p1, Player^ p2) {
				if (p1->score == p2->score)
					return true;
				return false;
			};
	};

	public ref class RankedPlayer : public Player {
		private:
			String^ rank;
		public:
			RankedPlayer() : Player() {
				rank = "---";
			}
			RankedPlayer(Player^ p, int i) :Player(p) {
				this->rank = getRank(i);
			}

			void setRank(int r) {
				rank = getRank(r);
			}

			String^ getRank(int r) {
				switch(r){
					case 0:
						return "1st ";
					case 1:
						return "2nd";
					case 2:
						return "3rd";
					case 3:
						return "4th";
					case 4:
						return "5th";
					case 5:
						return "6th";
				}
				return "---";
			};
			String^ getRank() {
				return rank;
			}
	};

	public ref class LeaderBoard {
		private: 
			cliext::vector<RankedPlayer^> lb;
		public:
			// creates a leaderboard 
			LeaderBoard(String^ fileName) {
				StreamReader^ fis = File::OpenText(fileName);
				// this makes sure the file starts reading from the top
				fis->Close(); 
				fis = File::OpenText(fileName);
				
				int count = 0;

				// Read up to 6 players from the file
				while (!fis->EndOfStream) {
					Player^ p = gcnew Player();
					fis >> p; // Make sure the operator>> is reading the file correctly
					lb.push_back(gcnew RankedPlayer(p, count));
					count++;
				}

				fis->Close();

				// If there are less than 5 players in the file, fill the rest with default players
				while (count < 6) {
					Player^ p = gcnew Player();
					lb.push_back(gcnew RankedPlayer(p, count));
					count++;
				}

				// Sort the vector after populating it
				quickSort(0, lb.size() - 1);
			}

			int getSize() { return lb.size(); }

			RankedPlayer^ getFirst() {
				return lb.size() >= 1 ? lb[0] : gcnew RankedPlayer(gcnew Player(), 0);
			}
			RankedPlayer^ getSecond() {
				return lb.size() >= 2 ? lb[1] : gcnew RankedPlayer(gcnew Player(), 1);
			}
			RankedPlayer^ getThird() {
				return lb.size() >= 3 ? lb[2] : gcnew RankedPlayer(gcnew Player(), 2);
			}
			RankedPlayer^ getFourth() {
				return lb.size() >= 4 ? lb[3] : gcnew RankedPlayer(gcnew Player(), 3);
			}
			RankedPlayer^ getFifth() {
				return lb.size() >= 5 ? lb[4] : gcnew RankedPlayer(gcnew Player(), 4);
			}
			RankedPlayer^ getSixth() {
				return lb.size() >= 6 ? lb[5] : gcnew RankedPlayer(gcnew Player(), 5);
			}

			void swapRP(RankedPlayer^ p1, RankedPlayer^ p2) {
				RankedPlayer^ temp = gcnew RankedPlayer(); // Create a temporary RankedPlayer object

				// Copy the values from p1 to temp
				temp->setInits(p1->getInits());
				temp->setScore(p1->getScore());

				// Copy the values from p2 to p1
				p1->setInits(p2->getInits());
				p1->setScore(p2->getScore());

				// Copy the values from temp to p2
				p2->setInits(temp->getInits());
				p2->setScore(temp->getScore());
			}


			int partition(int low, int high) {
				RankedPlayer^ pivot = lb[high];
				int i = low - 1;
				for (int j = low; j < high; j++) {
					if (lb[j] > pivot || lb[j] == pivot) {
						i++;
						swapRP(lb[i], lb[j]);
					}
				}
				swapRP(lb[i + 1], lb[high]);
				return i + 1;
			}
			void quickSort(int low, int high) {
				if (low < high) {
					int pivotInd = partition(low, high);
					quickSort(low, pivotInd - 1);
					quickSort(pivotInd + 1, high);
				}
			}

	};
}