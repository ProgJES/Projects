#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
#include <string>
using namespace std;

namespace Record
{
    const int defaultSalary = 1000;
    class Employee
    {
    protected:
        string empFirstName;
        string empLastName;
        int empID;
        int salary;
        bool hired;

    public:
        Employee();
        //~Employee();

        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);
        void hire();
        void fire();
        void display() const;

        // Setters and Getters
        void setFirstName(const string firstName);
        string getFirstName() const;
        void setLastName(const string lastName);
        string getLastName() const;

        void setEmpID(const int id);
        int getEmpID() const;

        void setSalary(const int salary);
        int getSalary() const;

        bool getIsHired() const;
    };
}

#else
#endif