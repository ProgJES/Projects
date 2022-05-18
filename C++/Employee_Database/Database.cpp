#include "Database.h"

namespace Record
{
    Database::Database()
    {
        this->nextEmployeeID = firstEmployeeNumber;
    }
    Database::~Database()
    {
    }

    Employee &Database::addEmployee(const string firstName, const string lastName)
    {
        Employee emp;
        emp.setFirstName(firstName);
        emp.setLastName(lastName);
        emp.setEmpID(nextEmployeeID++);
        emp.hire();
        employees.push_back(emp);

        return employees[employees.size() - 1];
    }

    Employee &Database::getEmployee(const int empID)
    {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter)
        {
            if (iter->getEmpID() == empID)
                return *iter;
        }
    }
    Employee &Database::getEmployee(const string firstName, const string lastName)
    {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter)
        {
            if (iter->getLastName() == lastName && iter->getFirstName() == firstName)
                return *iter;
        }
    }

    void Database::displayAll() const
    {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter)
        {
            iter->display();
        }
    }
    void Database::displayCurrent() const
    {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter)
        {
            if (iter->getIsHired())
                iter->display();
        }
    }
    void Database::displayFormer() const
    {
        for (auto iter = employees.begin(); iter != employees.end(); ++iter)
        {
            if (!iter->getIsHired())
                iter->display();
        }
    }
}