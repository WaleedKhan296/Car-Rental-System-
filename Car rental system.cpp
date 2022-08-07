#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <iomanip>

using namespace std;
void login();
class customer
{
private:
public:
    string customername;
    string carmodel;
    string carnumber;
    char data;
    virtual void display() = 0;
};
class rent : public customer
{
public:
    int days = 0, rentalfee = 0;
    void data()
    {
        
        login();
        cout << "\tPlease Enter your Name: ";
        cin >> customername;
        cout << endl;
        do
        {
            cout << "\tPlease Select a Car" << endl;
            cout << "\tEnter 'A' for Tesla 20011." << endl;
            cout << "\ttEnter 'B' for Hyundai 2015." << endl;
            cout << "\tEnter 'C' for Ford 2017." << endl;
            cout << endl;
            cout << "\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            if (carmodel == "A" || carmodel == "a")
            {
                system("CLS");

                cout << "You have choosed Tesla model 2011" << endl;
                ifstream inA("A.txt");
                char str[200];
                while (inA) {
                    inA.getline(str, 200);
                    if (inA) cout << str << endl;
                }
                Sleep(2);
            }
            if (carmodel == "B" || carmodel=="b")
            {
                system("CLS");

                cout << "You have choosed Hyundai model 2015" << endl;
                ifstream inB("B.txt");
                char str[200];
                while (inB) {
                    inB.getline(str, 200);
                    if (inB) cout << str << endl;

                }
                Sleep(2);
            }
            if (carmodel == "C" || carmodel=="c")
            {
                system("CLS");
                cout << "You have choosed Ford model 2017" << endl;
                ifstream inC("C.txt");
                char str[200];
                while (inC) {
                    inC.getline(str, 200);
                    if (inC) cout << str << endl;
                }
                Sleep(2);
            }
            if (carmodel != "A" && carmodel != "B" && carmodel != "C")

                cout << "Invaild Car Model. Please try again!" << endl;
        } while (carmodel != "A" && carmodel != "B" && carmodel != "C");
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide following information: " << endl;

        cout << "Please select a Car No. : ";
        cin >> carnumber;
        cout << "Number of days you wish to rent the car : ";
        cin >> days;
        cout << endl;
    }
    void calculate()
    {
        Sleep(1);
        system("CLS");
        cout << "Calculating rent. Please wait......" << endl;
        Sleep(2);
        if (carmodel == "A" || carmodel == "a")
            rentalfee = days * 56;
        if (carmodel == "B" || carmodel == "b")
            rentalfee = days * 60;
        if (carmodel == "C" || carmodel == "c")
            rentalfee = days * 75;
    }
    void display()
    {
        cout << "\n                       Car Rental - Customer Invoice                  " << endl;
        cout << "	///////////////////////////////////////////////////////////" << endl;
        cout << "	| Invoice No. :" << "------------------|" << setw(10) << "#Cnb81353" << " |" << endl;
        cout << "	| Customer Name:" << "-----------------|" << setw(10) << customername << " |" << endl;
        cout << "	| Car Model :" << "--------------------|" << setw(10) << carmodel << " |" << endl;
        cout << "	| Car No. :" << "----------------------|" << setw(10) << carnumber << " |" << endl;
        cout << "	| Number of days :" << "---------------|" << setw(10) << days << " |" << endl;
        cout << "	| Your Rental Amount is :" << "--------|" << setw(10) << rentalfee << " |" << endl;
        cout << "	| Caution Money :" << "----------------|" << setw(10) << "0" << " |" << endl;
        cout << "	| Advanced :" << "---------------------|" << setw(10) << "0" << " |" << endl;
        cout << "	 ________" << endl;
        cout << "\n";
        cout << "	| Total Rental Amount is :" << "-------|" << setw(10) << rentalfee << " |" << endl;
        cout << "	 ________" << endl;
        cout << "	 # This is a computer generated invoce and it does not" << endl;
        cout << "	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "	///////////////////////////////////////////////////////////" << endl;
        cout << "	You are advised to pay up the amount before due date." << endl;
        cout << "	Otherwise penelty fee will be applied" << endl;
        cout << "	///////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");

        system("CLS");

        ifstream inf("thanks.txt");


        char str[300];

        while (inf) {
            inf.getline(str, 300);
            if (inf) cout << str << endl;
        }
        inf.close();
    }
};
class welcome {
    
public:
    void welcum()
    {
        ifstream in("welcome.txt");

        if (!in) {
            cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in) {
            in.getline(str, 1000);
            if (in) cout << str << endl;
        }
        in.close();
        Sleep(1);
        cout << "\nStarting the program please wait....." << endl;
        Sleep(1);
        cout << "\nloading up files....." << endl;
        Sleep(1);
        system("CLS");
    }

};
int main()
{
    rent obj2;
    welcome obj1;
    obj1.welcum();    

    obj2.data();
    obj2.calculate();

    obj2.display();
    

    return 0; //end of the program
}

void login() {
    string pass;
    char ch;
    cout << "\n\n\n\n\n\n\n\n\tCAR RENTAL SYSTEM \n\n";
    cout << "\t------------------------------";
    cout << "\n\tLOGIN \n";
    cout << "\t------------------------------\n\n";
    cout << "\tEnter Password: ";
    cin>>pass;
    if (pass == "pass") {
        cout << "\n\n\n\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
    }
    else {
        cout << "\n\n\tAccess Aborted...\n\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}
