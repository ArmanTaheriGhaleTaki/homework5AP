
#include "Person.h"

Person::Person() {
    this->firstName = "";
    this->lastName = "";
    this->id = "";
    this->workHours = new double;
    if (validate(id) == 0) {//WTF namoosan
        std::cout << "id invalid";
    }
}

Person::Person(const Person &arr) {
    this->firstName = arr.firstName;
    this->lastName = arr.lastName;
    this->id = arr.id;
    this->workHours = arr.workHours;
}

Person::~Person() {
    delete this->workHours;
}

const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

const std::string &Person::getId() const {
    return id;
}

double Person::getWorkHours() const {
    return *workHours;
}

void Person::Person::setWorkHours(double *workHours) {
    Person::workHours = workHours;
}

void Person::Person::setId(const std::string &id) {
    Person::id = id;
}

void Person::Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

void Person::Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

Person &Person::operator=(const Person &arr) {
    this->firstName = arr.firstName;
    this->lastName = arr.lastName;
    this->id = arr.id;
    *this->workHours = *workHours;
    return *this;
}

bool Person::validate(std::string _id) {
    if (_id.size() >= 8 && _id.size() <= 10) {
        int yearOfSignIn = ((_id[0] - 48) * 10 + (_id[1] - 48));//the different between (char)'1' and (int)1 is 48
        int indexOfNotNum = 2;
        if (yearOfSignIn >= 0 && yearOfSignIn <= 84) {
            for (; indexOfNotNum < _id.size() -
                                   5; indexOfNotNum++)//checks that if the string size is 8 there is one char that is not a number or if its size is 10 there are 3 none chars in the string
            {
                if ((_id[indexOfNotNum] < 48 || _id[indexOfNotNum] > 57) == 0) {
                    return false;
                }
            }
            for (int i = 0; i < 5; i++, indexOfNotNum++) {
                if ((_id[indexOfNotNum] < 4 || _id[indexOfNotNum] > 6) == 0) {
                    return 0;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

double Person::calculateSalary() {
    double salary = 10000 * (*workHours);
    return salary;
};