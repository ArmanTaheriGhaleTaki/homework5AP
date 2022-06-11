
#ifndef HOMEWORK5AP_PROFESSOR_H
#define HOMEWORK5AP_PROFESSOR_H

#include "Person.h"
#include <unordered_map>

class Professor : public Person {
private:
    std::string title;
public:
    std::unordered_map<std::string, int> ranks = {
            {"Instructor",          1},
            {"Professor Assistant", 2},
            {"Associate Professor", 3},
            {"Professor",           4}
    };

    Professor();

    virtual bool validate(std::string _id);

    virtual double calculateSalary();

    friend std::ostream &operator<<(std::ostream &output, const Professor &D);

    friend std::istream &operator>>(std::istream &in, Professor &D);
};


#endif
