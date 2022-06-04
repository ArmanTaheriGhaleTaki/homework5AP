
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
    *(this->mark) = *(arr.mark);
}

Course::~Course() {
    delete this->mark;
}

void Course::set_name(std::string arr) {
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

int Course::get_unit() {
    return unit;
}

double Course::get_mark() {
    return *mark;
}
