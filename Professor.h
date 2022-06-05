
#ifndef HOMEWORK5AP_PROFESSOR_H
#define HOMEWORK5AP_PROFESSOR_H
#include"Person.h"
//std::string rank[4]={"Instructor","Professor Assistant","Associate Professor","Professor"};
class Professor :public Person{
private:
    std::string title;
public:
    Professor() ;
    virtual bool validate(std::string _id);
    double calculateSalary();
};



#endif
