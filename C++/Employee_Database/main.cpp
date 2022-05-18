#include "Database.h"
#include <windows.h>
#include <exception>
using namespace Record;
int displayMenu();
void doHire(Database &DB);
void doFire(Database &DB);
void doPromote(Database &DB);
void doDemote(Database &DB);

int main()
{
    bool done = false;
    Database EmployeeDB;
    do
    {
        system("cls");
        int selection = displayMenu();

        switch (selection)
        {
        case 1:
            system("cls");
            doHire(EmployeeDB);
            break;
        case 2:
            system("cls");
            doFire(EmployeeDB);
            break;
        case 3:
            system("cls");
            doPromote(EmployeeDB);
            break;
        case 4:
            system("cls");
            doDemote(EmployeeDB);
            break;
        case 5:
            system("cls");
            EmployeeDB.displayAll();
            cin.ignore();
            cin.get();
            break;
        case 6:
            system("cls");
            EmployeeDB.displayCurrent();
            cin.ignore();
            cin.get();
            break;
        case 7:
            system("cls");
            EmployeeDB.displayFormer();
            cin.ignore();
            cin.get();
            break;
        case 0:
            done = true;
            break;
        default:
            system("cls");
            cerr << "Unknown command" << endl;
            cin.ignore();
            cin.get();
        }
    } while (!done);

    return 0;
}

int displayMenu()
{
    int selection = 0;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------------" << endl;
    cout << "1) Hire a new Employee" << endl;
    cout << "2) Fire an Employee" << endl;
    cout << "3) Promote Employee" << endl;
    cout << "4) Demote Employee" << endl;
    cout << "5) List all employees" << endl;
    cout << "6) List all current employees" << endl;
    cout << "7) List all previous employees" << endl;
    cout << "0) Exit" << endl;
    cout << "- - - > ";
    cin >> selection;
    return selection;
}

void doHire(Database &DB)
{
    string firstName, lastName;
    cout << "Enter Employee First Name: ";
    cin >> firstName;
    cout << "Enter Employee last Name: ";
    cin >> lastName;

    try
    {
        DB.addEmployee(firstName, lastName);
        cout << endl;
        cout << "Successfully Registered! Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    catch (const exception &e)
    {
        cerr << "Unable to add new employee!" << endl;
        cin.ignore();
        cin.get();
    }
}
void doFire(Database &DB)
{
    int empID = 0;
    cout << "Enter Employee ID: ";
    cin >> empID;

    try
    {
        Employee &tempEmp = DB.getEmployee(empID);
        tempEmp.fire();
        cout << "Successfully terminated employee! Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }
    catch (const exception &e)
    {
        cerr << "Unable to terminate employee" << endl;
        cin.ignore();
        cin.get();
    }
}
void doPromote(Database &DB)
{
    int empID = 0;

    cout << "PROMOTE EMPLOYEE" << endl;
    cout << "Enter Employee ID: ";
    cin >> empID;

    try
    {
        Employee &tempEmp = DB.getEmployee(empID);
        int raiseAmount = 0;

        cout << "Enter Raise Amount: ";
        cin >> raiseAmount;
        tempEmp.promote(raiseAmount);
        cout << "Successfully promoted an employee! Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }
    catch (const exception &e)
    {
        cerr << "Unable to promote employee! Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }
}
void doDemote(Database &DB)
{
    int empID = 0;

    cout << "DEMOTE EMPLOYEE" << endl;
    cout << "Enter Employee ID: ";
    cin >> empID;

    try
    {
        Employee &tempEmp = DB.getEmployee(empID);
        int demeritAmount = 0;

        cout << "Enter demerit Amount: ";
        cin >> demeritAmount;
        tempEmp.demote(demeritAmount);
        cout << "Successfully demoted an employee! Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }
    catch (const exception &e)
    {
        cerr << "Unable to promote employee!" << endl;
        cin.ignore();
        cin.get();
    }
}