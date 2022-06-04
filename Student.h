//
// Created by TAHER on 5/30/22.
//

#ifndef HOMEWORK5AP_STUDENT_H
#define HOMEWORK5AP_STUDENT_H

#include "Student.h"
#include "Course.h"


class Student : public Person {
public:
    Student();

    Student(const Student &arr);

    ~Student();

private:
    int numOfCourses;
    Course *courses;
    std::string FieldOfStudy;

#endif //HOMEWORK5AP_STUDENT_H
