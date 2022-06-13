#ifndef HOMEWORK5AP_STUDENT_H
#define HOMEWORK5AP_STUDENT_H

#include "Person.h"
#include "Course.h"

class Student : public Person {
public:
    Student();

    Student(const Student &arr);

    ~Student();

    friend std::ostream &operator<<(std::ostream &output, const Student &D);

    friend std::istream &operator>>(std::istream &in, Student &D);

    virtual bool validate(std::string _id);

    double gpa();//it's not completed
    double calculateSalary();

    std::string getFieldOfStudy();

    int getNumOfCourses();

    Course* getPointerToCourse();


private:
    int numOfCourses;
    Course *courses;
    std::string FieldOfStudy;
};

#endif
