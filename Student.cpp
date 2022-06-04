//
// Created by TAHER on 5/30/22.
//

#include "Student.h"

Student::Student() {
    this->courses = new Course;
    this->FieldOfStudy = "";
    this->numOfCourses = 0;
}

Student::Student(const Student &arr) {
    this->courses = arr.courses;
    this->FieldOfStudy = arr.FieldOfStudy;
    this->numOfCourses = arr.numOfCourses;
}

Student::~Student() {
    delete this->courses;
}
