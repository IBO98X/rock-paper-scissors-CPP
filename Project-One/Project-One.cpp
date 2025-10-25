#include <iostream>
#include <cstdlib>

using namespace std;

// First Project Requirements
/*
	Done ! [1] Ask for how many rounds the game will be.
	Done ! [2] Input user choies.
	Done ! [3] Computer choies will be random.
	Done ! [4] Proccess who won the round.
	Done ! [5] If computer won, show red screen with sound.
	Done ! [6] If Draw show yellow screen.
	Done ! [7] If user won show green.
	Done ! [8] Each round show choices and round number and who won.
	Done ! [9] At the end show who won and statistics.
	Done ! [10] At the end ask the user do you want to play again.
*/

enum enChoise {Rock = 1, Paper = 2, Scissors = 3};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message; 
        cin >> Number;   

    } while (Number <= 0 && Number <= 100);  

    return Number;
}

int RoundsNumber()
{
	return ReadPositiveNumber("How Many Rounds Do You Want To Play? ");
}

int InputUserChoise()
{
	int Choise;

	cout << "\nPlese Enter Your Choise [1] = Rock, [2] = Paper, [3] = Scissors : ";
	Choise = ReadPositiveNumber("");

	return Choise;
}

int ComputerChoise()
{
	int Choise;

	Choise = RandomNumber(1, 3);

	return Choise;
}

enChoise ReturnChoieses(int Number)
{
	enChoise Choise;
	switch(Number)
	{
	case 1:
	{
		return enChoise::Rock;
		break;
	}
	case 2:
	{
		return enChoise::Paper;
		break;
	}	
	case 3:
	{
		return enChoise::Scissors;
		break;
	}
	}
}

void ShowStatistics(int UserWins, int ComputerWins, int Draws, int GameRounds)
{
	cout << "\n\t\t_______________________________________________________________" << endl;

	if (UserWins > ComputerWins)
		cout << "\t\t\t\t    +++ W o n G a m e ! +++" << endl;
	else if (UserWins < ComputerWins)
		cout << "\t\t\t\t    +++ G a m e O v e r +++" << endl;
	else 
		cout << "\t\t\t\t    +++ F a i r G a m e +++" << endl;

	cout << "\t\t_______________________________________________________________" << endl;
	cout << "\t\t_______________________ [Game Results] ________________________" << endl;
	cout << "\t\tGame Rounds		 :" << GameRounds << endl;
	cout << "\t\tPlayer1 won Times	 :" << UserWins << endl;
	cout << "\t\tComputer won Times	 :" << ComputerWins << endl;
	cout << "\t\tDraw Times		 :" << Draws << endl;

	if (UserWins > ComputerWins)
		cout << "\t\tFinal Winner     	 : Player1" << endl;
	else if (UserWins < ComputerWins)
		cout << "\t\tFinal Winner     	 : Computer" << endl;
	else 
		cout << "\t\tFinal Winner     	 : [No Winners]" << endl;
	cout << "\t\t_______________________________________________________________" << endl << endl;
}

void CheckWinner(enChoise User, enChoise Computer, int GameRounds, int& UserWins, int& ComputerWins, int& Draws)
{
	

	if (User == enChoise::Rock && Computer == enChoise::Rock)
	{
		cout << "\nPlayer1 Choise: Rock" << endl;
		cout << "Computer Choise: Rock" << endl;
		cout << "Round Winner: [No Winner]\n" << endl;
		system("color 67");
		Draws++;
	}
	else if (User == enChoise::Paper && Computer == enChoise::Paper)
	{
		cout << "\nPlayer1 Choise: Paper" << endl;
		cout << "Computer Choise: Paper" << endl;
		cout << "Round Winner: [No Winner]\n" << endl;
		system("color 67");
		Draws++;
	}
	else if (User == enChoise::Scissors && Computer == enChoise::Scissors)
	{
		cout << "\nPlayer1 Choise: Scissors" << endl;
		cout << "Computer Choise: Scissors" << endl;
		cout << "Round Winner: [No Winner]\n" << endl;
		system("color 67");
		Draws++;
	}
	else if (User == enChoise::Rock && Computer == enChoise::Paper)
	{
		cout << "\a";
		cout << "\nPlayer1 Choise: Rock" << endl;
		cout << "Computer Choise: Paper" << endl;
		cout << "Round Winner: [Computer]\n" << endl;
		system("color 47");
		ComputerWins++;
	}
	else if (User == enChoise::Rock && Computer == enChoise::Scissors)
	{
		cout << "\nPlayer1 Choise: Rock" << endl;
		cout << "Computer Choise: Scissors" << endl;
		cout << "Round Winner: [Player1]\n" << endl;
		system("color 27");
		UserWins++;
	}
	else if (User == enChoise::Paper && Computer == enChoise::Rock)
	{
		cout << "\nPlayer1 Choise: Paper" << endl;
		cout << "Computer Choise: Rock" << endl;
		cout << "Round Winner: [Player1]\n" << endl;
		system("color 27");
		UserWins++;
	}
	else if (User == enChoise::Paper && Computer == enChoise::Scissors)
	{
		cout << "\a";
		cout << "\nPlayer1 Choise: Paper" << endl;
		cout << "Computer Choise: Scissors" << endl;
		cout << "Round Winner: [Computer]\n" << endl;
		system("color 47");
		ComputerWins++;
	}
	else if (User == enChoise::Scissors && Computer == enChoise::Rock)
	{
		cout << "\a";
		cout << "\nPlayer1 Choise: Scissors" << endl;
		cout << "Computer Choise: Rock" << endl;
		cout << "Round Winner: [Computer]\n" << endl;
		system("color 47");
		ComputerWins++;
	}
	else if (User == enChoise::Scissors && Computer == enChoise::Paper)
	{
		cout << "\nPlayer1 Choise: Scissors" << endl;
		cout << "Computer Choise: Paper" << endl;
		cout << "Round Winner: [Player1]\n" << endl;
		system("color 27");
		UserWins++;
	}

}

void ProccessTheChoises(int GameRounds)
{
	int Counter = 1;
	int UserWins = 0, ComputerWins = 0, Draws = 0;

	do
	{
		cout << "\nRound [" << Counter << "] Begins: " << endl;
		enChoise Player1 = ReturnChoieses(InputUserChoise());
		enChoise Computer = ReturnChoieses(ComputerChoise());

		cout << "\n_______________________Round [" << Counter << "] _______________________" << endl;
		CheckWinner(Player1, Computer, GameRounds, UserWins, ComputerWins, Draws);
		cout << "________________________________________________________" << endl;


		Counter++;
	} while (Counter <= GameRounds);

	ShowStatistics(UserWins, ComputerWins, Draws, GameRounds);
}

char DoYouWantToPlayAgain()
{
	char UserInput;

	cout << "\nDo You Want To Play Again Y/N ? ";
	cin >> UserInput;

	return UserInput;
}

void PrintHeader()
{
	cout << "_______________________________________________________________\n" << endl;
	cout << "________ +++ Welcome To Rock, Paper, Scissors Game ! +++ ______" << endl << endl;
	cout << "_______________________ [Game Starts] ________________________\n" << endl;
}

void ResetScreen()
{
	char Again = DoYouWantToPlayAgain();

	while (Again == 'y' || Again == 'Y')
	{
		system("cls");
		system("color 07");
		PrintHeader();
		ProccessTheChoises(RoundsNumber());
		Again = DoYouWantToPlayAgain();
	}

	cout << "\nSee You Next Time, Stay Safe :)" << endl;
}

void StartGame()
{
	int Times;
	PrintHeader();
	do
	{
		Times = RoundsNumber();
	} while (Times < 0 && Times > 10);


	ProccessTheChoises(Times);

	ResetScreen();
}

int main()
{
	// Seed the random number generator with the current time.
	srand((unsigned)time(NULL));

	StartGame();
	
	return 0;
}

