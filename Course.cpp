
#include "Course.h"

Course::Course() {
    name = "";
    unit = 0;
    mark = new double;
    *mark = 0;
}

Course::Course(const Course &arr) {
    this->name = arr.name;
    this->unit = arr.unit;
    this->mark = new double;
    *(this->mark) = *(arr.mark);
}

    Course Course:: operator =(const Course &arr) {
        this->name = arr.name;
        this->unit = arr.unit;
        this->mark = new double;
        *(this->mark) = *(arr.mark);
    }
Course::~Course() {
    delete this->mark;
}

void Course::set_name(const std::string &arr) {
    this->name = arr;
}

void Course::set_unit(int arr) {
    this->unit = arr;
}

void Course::set_mark(double arr) {
    *(this->mark) = arr;
}

std::string Course::get_name() {
    return name;
}

int Course::get_unit() const {
    return unit;
}

double Course::get_mark() {
    return *mark;
}

std::ostream &operator<<(std::ostream &output, const Course &D) {
    output << "name : " << D.name << "\tunit : " << D.unit << "\tmark : " << *(D.mark) << "\n";
    return output;
}

std::istream &operator>>(std::istream &in, Course &D) {
    std::cout << "Enter name of course\n";
    std::cin>> D.name;
    std::cout << "Enter mark \n ";
    in >> *(D.mark);
    std::cout << "Enter unit\n ";
    in >> D.unit;
    return in;
}
