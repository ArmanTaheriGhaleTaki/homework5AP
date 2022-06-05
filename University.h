//
// Created by TAHER on 6/6/22.
//
#include "Professor.h"
#include "Student.h"
#ifndef HOMEWORK5AP_UNIVERSITY_H
#define HOMEWORK5AP_UNIVERSITY_H


class University {
public:
    University();
    University(const University &arr) ;


        private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor * professors[100];
    Student* students[100];

};


#endif //HOMEWORK5AP_UNIVERSITY_H
