
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
struct PERSON {
    char Name[20];
    float Balance;
};

PERSON *readData(int &N);
void Display(PERSON *arr, int N);
void FindRichest(PERSON *arr, int N);
void Deposit(char CustName[], PERSON *arr, int N,float amount);
void NewCopy(string fname, PERSON *arr, int N);

PERSON *readData(int &N)
{
    PERSON *personptr=nullptr;
    string fname,lname,line;
    float balance;
    ifstream file;
    file.open("data.txt");
 if(file.fail())
 {
     cout<<"can't open the file."<<endl;
     exit(1);
 }
 else{
     while(getline(file,line))
     {
         N++;
     }
    file.clear();
    file.seekg(0, ios::beg); // seek to 0 characters from the beginning of the file
    personptr= new PERSON[N];
   for(int i = 0; i < N;i++)
    {
        file>>fname>>lname>>balance;
        personptr[i].Balance=balance;
  
        strcpy(personptr[i].Name,(fname + " "+lname).c_str());
        
    }
      file.close();
 }
    return personptr;
}


void Display(PERSON *arr, int N)
{
    cout << setprecision(2) << fixed;
    cout << setw(20) << left << "Name" << "Balance" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << setw(20) << left << arr[i].Name << arr[i].Balance << endl;
    }
}

void FindRichest(PERSON *arr, int N)
{
    int richest = 0;
    
    //use loop to run all number than find out the richest
    for (int i = 0; i < N; i++)
    {
        if (arr[richest].Balance < arr[i].Balance) //find out the richest
            richest = i;
    }
    cout << "The customer with maximun balance is: " << arr[richest].Name << endl;
}

void Deposit(char CustName[], PERSON arr[], int N,float amount)
{
    
    int name = -1; //set the number help to print the wrong when the name can not find
    cout << "Enter your full name to deposit money:"<<endl;
   
    cin.ignore();
    cin.getline(CustName, 20);
    for (int i = 0; i < N; i++)
    {
       
        if (strcmp(CustName, arr[i].Name) == 0) //use strcmp to comparison name if the name is same
        {
            name=i;
            break;
        }
    }
    if (name == -1) //strcmp if name is not same output -1
    {
        cout << "Record not found."<<endl;
        exit(2);
    }
    else{
            cout << CustName << ", how much would you like to deposit? ";
            cin >> amount;
            arr[name].Balance += amount;
            cout << "Now your new balance is " << arr[name].Balance << endl;
            name++;
        }
}
void NewCopy(string fname, PERSON *arr, int N)
{
    ofstream outfile;
    outfile<< setprecision(2) << fixed;
    outfile.open(fname.c_str());//opening file
    for (int i = 0; i < N; i++)
    {
        outfile << arr[i].Name << " " << arr[i].Balance<<endl;
        
    }
    outfile.close();
    cout << "File Updated...\n";

}
void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
    int choice=0;
    int N=0;
    float amount=0.0;
    char CustName[20];
    PERSON *personPtr=nullptr;
    personPtr =readData(N);
    do
    {
        
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Act on display
                Display(personPtr, N);
                break;
                
            case 2:
                // Act on deposit
                Deposit(CustName,personPtr,N,amount);
                break;
                
            case 3:
                // Act highest balance
                FindRichest(personPtr, N);
                break;
                
            case 4:
                // Act on update records
                NewCopy("data.txt", personPtr, N);
                break;
                
            case 5:
                // Must call update records here before exiting the program
                break;
                
            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
    } while(choice != 5);
    return 0;
}
