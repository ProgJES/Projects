#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>
#include "Employee.h"

namespace Record
{
    const int firstEmployeeNumber = 1000;
    class Database
    {
    protected:
        vector<Employee> employees;
        int nextEmployeeID;

    public:
        Database();
        ~Database();
        Employee &addEmployee(const string firstName, const string lastName);
        Employee &getEmployee(const int empID);
        Employee &getEmployee(const string firstName, const string lastName);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
    };
}
#else
#endif