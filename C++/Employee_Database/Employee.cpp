#include "Employee.h"

namespace Record
{
    Employee::Employee() : empFirstName("test"), empLastName(""), empID(-1), salary(defaultSalary), hired(true)
    {
    }

    // Promote and Demote
    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }
    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }
    // Setters
    void Employee::setFirstName(const string firstName)
    {
        this->empFirstName = firstName;
    }
    void Employee::setLastName(const string lastName)
    {
        this->empLastName = lastName;
    }
    void Employee::setEmpID(const int id)
    {
        this->empID = id;
    }
    void Employee::setSalary(const int salary)
    {
        this->salary = salary;
    }

    void Employee::hire()
    {
        this->hired = true;
    }
    void Employee::fire()
    {
        this->hired = false;
    }

    // Getters
    string Employee::getFirstName() const
    {
        return this->empFirstName;
    }
    string Employee::getLastName() const
    {
        return this->empLastName;
    }
    int Employee::getEmpID() const
    {
        return this->empID;
    }
    int Employee::getSalary() const
    {
        return this->salary;
    }
    bool Employee::getIsHired() const
    {
        return this->hired;
    }

    // Print method
    void Employee::display() const
    {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "---------------------------------------------------" << endl;
        cout << (hired ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmpID() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

}