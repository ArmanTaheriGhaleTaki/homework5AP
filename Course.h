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

    friend std::ostream &operator<<(std::ostream &output,const Course &D);

    friend std::istream & operator >>( std::istream  &in, Course &D );

//    friend std::ostream &operator<<(std::ostream &os, const Complex &dt);
    void set_name(const std::string &arr);

    void set_unit(int arr);

    void set_mark(double arr);

    std::string get_name();

    int get_unit() const;

    double get_mark();


};


#endif