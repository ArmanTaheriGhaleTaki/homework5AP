
#ifndef HOMEWORK5AP_PERSON_H
#define HOMEWORK5AP_PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string id;
    double *workHours;

public:
    Person();

    Person(const Person &arr);

    ~Person();

    const std::string &getFirstName() const;

    friend std::ostream &operator<<(std::ostream &output,const Person &D);

    friend std::istream & operator >>( std::istream  &in, Person &D );

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getId() const;

    void setId(const std::string &id);

    double getWorkHours() const;

    void setWorkHours(double *workHours);

    Person &operator=(const Person &arr);

    virtual bool validate( std::string _id);

    double calculateSalary();

    int ageOfJoin();
};


#endif

