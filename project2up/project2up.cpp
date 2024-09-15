#include<iostream>
#include<cstdlib>
using namespace std;
enum enDifficulty { Easy = 1, Medium=2 , Hard=3, Mix=4};
enum enOPertaion{Add=1,Subtract=2,Multiply=3,Divide=4,MixOp=5};
string OPtypeName(enOPertaion optype) {
	string optypearr[] = { "Add","Sub","Mul","Div","Mix" };
	return optypearr[optype - 1];

}
string DifficultyName(enDifficulty hardness) {
	string Hardnessarr[] = { "Easy","Med","HArd","Mix" };
	return Hardnessarr[hardness - 1];
}
struct stGame {
	int NumberOfRounds = 0;
	int CorrectAnswers = 0;
	enDifficulty Difficulty;
	enOPertaion  OperationType;
};
void CorrectAnsCounter()
{
	int counter;

}
int GetRandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}
int ReadNumberOfRounds() {
	int Number = 0;
	cout << "How Many Questions you want to answer?  ";
	cin >> Number;
	return Number;

}
enOPertaion ReadOperationType()
{
	int c;
	cout << "Enter Operation Type [1]Add, [2]subtract, [3]Multiply, [4]Divide , [5]MixOp? ";
	cin >> c;
	return (enOPertaion)c;
}
enDifficulty ReadDifficulty() {
	int c = 0;
	do {
		cout << "Enter Question Level [1]:Easy , [2]:Med , [3]:Hard , [4]:Mix??  ";
		cin >> c;
		if (c < 1 || c>4)
			cout << "invalid number.";
	} while (c < 1 || c>4);
	return (enDifficulty)c;
}
void GetNumberForQuestion(int& num1, int& num2, enDifficulty difficulty)
{
	switch (difficulty)
	{
	case enDifficulty::Easy:
	    {
		num1 = GetRandomNumber(1, 10);
		num2 = GetRandomNumber(1, 10);
		break;
 
	    }
	case enDifficulty::Medium:
	{
		num1 = GetRandomNumber(0, 50);
		num2 = GetRandomNumber(0, 50);
		break;
	}
	case enDifficulty::Hard: {
		num1 = GetRandomNumber(0, 100);
		num2 = GetRandomNumber(0, 100);
		break;
	}
	}
}
bool GetQuestion(enOPertaion operation, enDifficulty difficulty)
{
	int number1 = 0, number2 = 0, ans=0,Userans=0;
	
	GetNumberForQuestion(number1, number2, difficulty);

	switch (operation)
	{
	  
	  case enOPertaion::Add:
	  {
		  cout << number1 << endl;
		  cout << number2 << "+" << endl;
		  cout << "______________" << endl;
		  cin >> Userans;
		  ans = number1 + number2;
		  if (Userans == ans) {
			  system("color 2f");
			  cout << "Right answer :-)\n";
			  return true;
		  }
		  else
		  {
			  system("color 4f");
			  cout << "Wrong answer :-(\n";
			  cout << "The write answer is :" << ans;
			  return 0;
		  }
		  break;
	  }
	  case enOPertaion::Subtract: {
		  cout << number1 << endl;
		  cout << number2 << "-" << endl;
		  cout << "______________" << endl;
		  cin >> Userans;
		  ans = number1 - number2;
		  if (Userans == ans) {
			  system("color 2f");
			  cout << "Right answer :-)\n";
			  return true;
		  }
		  else
		  {
			  system("color 4f");
			  cout << "Wrong answer :-(\n";
			  cout << "The write answer is :" << ans;
			  return 0;
		  }
		  break;
	  }
	  case enOPertaion::Multiply: {
		  cout << number1 << endl;
		  cout << number2 << "*" << endl;
		  cout << "______________" << endl;
		  cin >> Userans;
		  ans = number1 * number2;
		  if (Userans == ans) {
			  system("color 2f");
			  cout << "Right answer :-)\n";
			  return true;
		  }
		  else
		  {
			  system("color 4f");
			  cout << "Wrong answer :-(\n";
			  cout << "The write answer is :" << ans;
			  return 0;
		  }
		  break;
	  }
	  case enOPertaion::Divide: {
		  cout << number1 << endl;
		  cout << number2 << "/" << endl;
		  cout << "______________" << endl;
		  cin >> Userans;
		  ans = number1 / number2;
		  if (Userans == ans) {
			  system("color 2f");
			  cout << "Right answer :-)\n";
			  return true;
		  }
		  else
		  {
			  system("color 4f");
			  cout << "Wrong answer :-(\n";
			  cout << "The write answer is :" << ans;
			  return 0;
		  }
		  break;
	  }
	}
}
void PassOrFail(int correctans,int totalquestions) {
	int min = ceil(totalquestions / 2);
	if (correctans > min)
	{
		system("color 2f");
		cout << "PASS\n";
	}
	else {
		system("color 4f");
		cout << "FAIL\n";
	}
}
void PrintFinalResults(stGame Gameinfo) {
	cout << "\n______________________________________\n";
	cout << "   Final Results is ";
	PassOrFail(Gameinfo.CorrectAnswers, Gameinfo.NumberOfRounds);
	cout << "\n______________________________________\n";
	cout << "Number of Questions      : " << Gameinfo.NumberOfRounds<< endl;
	cout << "OPTyoe                   :" << OPtypeName(Gameinfo.OperationType) << endl;
	cout << "Questions Level          :" <<DifficultyName (Gameinfo.Difficulty) << endl;
	cout << "Number of Right Answers  :" << Gameinfo.CorrectAnswers << endl;
	cout << "Number of Worng Answers    :" << (Gameinfo.NumberOfRounds - Gameinfo.CorrectAnswers);
	cout << "\n______________________________________\n";



}
void Game()
{
	stGame Gameinfo;
	Gameinfo.NumberOfRounds = ReadNumberOfRounds();
	Gameinfo.OperationType = ReadOperationType();
	Gameinfo.Difficulty = ReadDifficulty();
	
	
	
	for (int Round = 1; Round <= Gameinfo.NumberOfRounds; Round++)
	{
		cout << "Question [" << Round << "/" << Gameinfo.NumberOfRounds << "]" << endl;
		enDifficulty Dificulty = Gameinfo.Difficulty;
		enOPertaion  OperationType = Gameinfo.OperationType;
		int number1 = 0, number2 = 0;
		if (Dificulty == enDifficulty::Mix)
		{
			Dificulty = (enDifficulty)GetRandomNumber(1, 3);

		}
		if (OperationType == enOPertaion::MixOp)
		{
			OperationType = (enOPertaion)GetRandomNumber(1, 4);
		}
		if (GetQuestion(OperationType, Dificulty))
			Gameinfo.CorrectAnswers++;
	}
	PrintFinalResults(Gameinfo);


}
void ClearScreen() {
	system("cls");
	system("color 0f");
}
int main() {
	char again = 'y';
	do {
		ClearScreen();
		Game();
		cout << "do you want to play again? Y/y?" << endl;
		cin >> again;

	} while (again == 'y' || again == 'Y');
}