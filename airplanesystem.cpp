#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
//------------Function Prototypes-----------//
void header();
void clearScreen();
int menu();
void store(string file_name);
void load(string file_name);
void array();
char parseRecord(int field);
void display();
void category();
void reserve();
bool check();
void updated_array();
void plane();
//---------------Variable Declaration---------//
char seats[13][6] = {{'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}};
string line;
string file_name = "seat.txt";
int op;
char column;
int row;
int col;

//------------------Color Change----------------//
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//--------------------Main Body------------------//
main()
{
    // store(file_name);
    // load(file_name);
    system("cls");
    header();
    int option = menu();
    clearScreen();
    while (option < 3)
    {
        if (option == 1)
        {
            //header();
            display();
            clearScreen();
            //header();
            category();
            reserve();
            clearScreen();
            //header();
            updated_array();
            clearScreen();
            store(file_name);
            // load(file_name);
        }
        if (option == 2)
        {
            // seats[13][6] = {{'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}, {'*', '*', '*', '*', '*', '*'}};
            for (int i = 0; i < 13; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    seats[i][j] = '*';
                }
            }
            header();
            plane();
            clearScreen();
        }
        header();
        option = menu();
        clearScreen();
        SetConsoleTextAttribute(hConsole, 15);
    }
}
//----------------Functions Definition--------------------//
void clearScreen()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  Press any key to continue_";
    SetConsoleTextAttribute(hConsole, 15);
    getch();
    system("cls");
}
void header()
{
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t\t\t\t**********************************************************" << endl;
    cout << "\t\t\t\t*                                                        *" << endl;
    cout << "\t\t\t\t*           Airplane Seat Reservation System             *" << endl;
    cout << "\t\t\t\t*                                                        *" << endl;
    cout << "\t\t\t\t**********************************************************" << endl;
    cout << endl;
}
int menu()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t\t\t\t---------------------" << endl;
    cout << "\t\t\t\t\t\t|     Main Menu     |" << endl;
    cout << "\t\t\t\t\t\t---------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "  -------------------------------" << endl;
    cout << "  | Select one option from menu |" << endl;
    cout << "  -------------------------------" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t1. Seat Reservation" << endl;
    cout << "\t2. New Plane" << endl;
    cout << "\t3. Exit" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << " Your option_";
    int option;
    cin >> option;
    return option;
    SetConsoleTextAttribute(hConsole, 15);
}
void store(string file_name)
{
    fstream file;
    file.open(file_name, ios ::out);
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            file << seats[i][j] << ",";
        }
        file << endl;
    }
    file.close();
}
void load(string file_name)
{
    fstream file;
    file.open(file_name, ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        array();
    }
}
void array()
{
    char a;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            a = parseRecord(i);
            seats[i][j] = a;
        }
    }
}
char parseRecord(int field)
{
    int comma = 1;
    char item;
    for (int x = 0; line[x] != '\0'; x++)
    {
        if (line[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = line[x];
        }
    }
    return item;
}
void display()
{
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t   -------------------------------" << endl;
    cout << "\t\t\t\t\t   |  Airplane Classes and Seats |" << endl;
    cout << "\t\t\t\t\t   -------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t"
         << "\tA\tB\tC\tD\tE\tF" << endl;
    cout << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << "\t\t\t\t"
             << "Row " << i + 1;
        for (int j = 0; j < 6; j++)
        {
            cout << "\t" << seats[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;
}
void category()
{
    cout << " -----------------------------" << endl;
    cout << " | Select category of Ticket |" << endl;
    cout << " -----------------------------" << endl;
    cout << endl;
    cout << "\t1. First Class" << endl;
    cout << "\t2. Bussiness Class" << endl;
    cout << "\t3. Economy Class" << endl;
    cout << endl;
    cout << "Your option_";
    int option;
    cin >> option;
    if (option == 1)
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t"
             << "\tA\tB\tC\tD\tE\tF" << endl;
        cout << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "\t\t\t"
                 << "Row " << i + 1;
            for (int j = 0; j < 6; j++)
            {
                cout << "\t" << seats[i][j] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
    if (option == 2)
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t"
             << "\tA\tB\tC\tD\tE\tF" << endl;
        cout << endl;
        for (int i = 2; i < 7; i++)
        {
            cout << "\t\t\t"
                 << "Row " << i + 1;
            for (int j = 0; j < 6; j++)
            {
                cout << "\t" << seats[i][j] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
    if (option == 3)
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t"
             << "\tA\tB\tC\tD\tE\tF" << endl;
        cout << endl;
        for (int i = 7; i < 13; i++)
        {
            cout << "\t\t\t"
                 << "Row " << i + 1;
            for (int j = 0; j < 6; j++)
            {
                cout << "\t" << seats[i][j] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    cout << "Select Row: ";
    cin >> row;
    cout << "Select Column: ";
    cin >> column;
}
void reserve()
{
    if (column == 'A' || column == 'a')
    {
        col = 0;
    }
    if (column == 'B' || column == 'b')
    {
        col = 1;
    }
    if (column == 'C' || column == 'c')
    {
        col = 2;
    }
    if (column == 'D' || column == 'd')
    {
        col = 3;
    }
    if (column == 'E' || column == 'e')
    {
        col = 4;
    }
    if (column == 'F' || column == 'f')
    {
        col = 5;
    }
    if (check() == false)
    {
        cout << "Seat Reserved !!! Please select another seat." << endl;
    }
    else if (check() == true)
    {
        seats[row - 1][col] = 'X';
    }
}
bool check()
{
    // for (int i = 0; i < 13; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    if (seats[row - 1][col] == 'X')
    {
        return false;
    }
    // }
    //}
    return true;
}
void updated_array()
{
    display();
    cout << "Your Seat Reserved." << endl;
}
void plane()
{
    cout << "Enter name of Airplane: ";
    cin.ignore();
    getline(cin, file_name);
    file_name = file_name + ".txt";
}