
#ifndef HOMEWORK5AP_PROFESSOR_H
#define HOMEWORK5AP_PROFESSOR_H

#include "Person.h"
#include <map>

class Professor : public Person {
private:
    std::string title;
public:
    std::map<std::string, int> ranks = {
            {"Instructor",          1},
            {"Professor Assistant", 2},
            {"Associate Professor", 3},
            {"Professor",           4}
    };

    Professor();

    virtual bool validate(std::string _id);

    double calculateSalary();
};


#endif
