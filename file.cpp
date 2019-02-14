
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
struct PERSON {
	char Name[100];
	float Balance;
};
void Display(PERSON *a, int N);
void FindRichest(PERSON *a, int N);
void newone(string fname, PERSON *a, int N);



void Display(PERSON *a, int N)
{
	cout << setw(20) << left << "Name" << "Balance" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(20) << left << a[i].Name << a[i].Balance << endl;
	}
}
void FindRichest(PERSON *a, int N)
{
	int richest = 0; 

	//use loop to run all number than find out the richest
	for (int i = 0; i < N; i++)
	{
		if (a[richest].Balance < a[i].Balance) //find out the richest
			richest = i;
	}
	cout << "The customer with maximun balance is " << a[richest].Name << endl;
}

void Deposit(char CustName[], PERSON *a, int N)
{
	
	int name = -1; //set the number help to print the wrong when the name can not find
	cout << "Enter your full name to deposit money:";
	cin.getline(CustName, 20);
	for (int i = 0; i < N; i++)
	{
		if (strcmp(CustName, a[i].Name) == 0) //use strcmp to comparison name if the name is same
		{
			name = i;
			break;
		}
	}
	if (name == -1) //strcmp if name is not same output -1
	{
		cout << "Sorry, can not get the name.";
	}
	else //if there is a same name than continue
	{
		float deposit;
		cout << CustName << ", how much would you like to deposit? ";
		cin >> deposit;
		a[name].Balance += deposit;
		cout << "Now your new balance is " << a[name].Balance << endl;
	}
}
void newone(string fname, PERSON *a, int N)
{
	ofstream outfile;
	outfile<< setprecision(2) << fixed;
	outfile.open(fname.c_str());//opening file
	for (int i = 0; i < N; i++)
	{
		outfile << a[i].Name << " " << a[i].Balance << endl;
	}
	outfile.close();

}
int main()
{
	int N = 0;
	int i = 0;
	string line;
	string fname, lname;
	char CustName[20];

	ifstream file;
	file.open("data.txt");
	if (file.fail())
	{
		cout << "Can't open the file";
		return 0;
	}

	while (!file.eof()) //while it end of the file than jump out the while, use eof because we do not know how long is the file
	{
		getline(file, line);//count how many line in the file
		N++;
	}
	file.clear();
	file.seekg(0, ios::beg); // seek to 0 characters from the beginning of the file

	PERSON *a = new PERSON[N]; //initial person *a
	while (file >> fname >> lname >> a[i].Balance)//extracting name and balance from the file
	{
		strcpy_s(a[i].Name, (fname + " " + lname).c_str()); //copying the contents of the string to char array
		i++;
	}

	Display(a, N);
	FindRichest(a, N);
	Deposit(CustName, a, N);
	newone("data.txt", a, N);
	system("PAUSE");
}
/*

Name                Balance
---------------------------
Maria Brown         2100.9
Jeffrey Jackson     200.2
Bernard Smith       223.1
Matthew Davenport   1630.2
Kimberly Macias     19100.9
Amber Daniels       2400.4
The customer with maximun balance is Kimberly Macias
Enter your full name to deposit money:Maria Brown
Maria Brown, how much would you like to deposit? 100
Now your new balance is 2200.9

*/
