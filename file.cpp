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





void Display(PERSON *a,int N)
{
	cout << setw(20)<<left << "Name" << "Balance" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(20) <<left<< a[i].Name << a[i].Balance << endl;
	}
}
void FindRichest(PERSON *a, int N)
{
	int richest = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[richest].Balance < a[i].Balance)
			richest = i;
	}
	cout << "The customer with maximun balance is " << a[richest].Name << endl;
}

void Deposit(char CustName[], PERSON *a,int N)
{
	int name = -1;
	for (int i = 0; i < N; i++)
	{
		if (strcmp(CustName, a[i].Name)==0)
		{
			name = i;
			break;
		}
	}
	if (name == -1)
	{
		cout << "Sorry, can not get the name.";
	}
	else
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
	ofstream newfile;

	for (int i = 0; i < N; i++) {
		newfile << a[i].Name << " " << a[i].Balance << endl;
	}

	newfile.close();
}

int main()
{
	int N=0;
	int i = 0;
	string line;
	string fname, lname;
	PERSON *a=new PERSON[N];
	char CustName[20];

	ifstream file;
	file.open("data.txt");
	if (file.fail())
	{
		cout << "Can't open the file";
	}

	while (file.eof())
	{
		getline(file, line);
		N++;
	}
	file.clear();
	file.seekg(0, ios::beg);
	while (file >> fname >> lname >> a[i].Balance)
	{
		strcpy_s(a[i].Name, (fname + " " + lname).c_str());
		i++;
	}

	Display(a, N);
	FindRichest(a, N);
	cout << "Enter your full name to deposit money:";
	cin.getline(CustName, 20);
	Deposit(CustName, a, N);
	newone("data.txt", a, N);



	system("PAUSE");
}
