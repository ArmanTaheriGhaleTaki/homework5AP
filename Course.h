#ifndef HOMEWORK5AP_COURSE_H
#define HOMEWORK5AP_COURSE_H

#include <iostream>

class Course {
private:
    std::string name;
    int unit;
    double *mark;
public:
    Course();

    Course(const Course &arr);

    ~Course();

    void set_name(std::string arr);

    void set_unit(int arr);

    void set_mark(double arr);

    std::string get_name();

    int get_unit();

    double get_mark();


};


#endif