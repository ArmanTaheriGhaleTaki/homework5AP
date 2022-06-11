#include "Student.h"


Student::Student() {
    this->courses = new Course;
    this->FieldOfStudy = "";
    this->numOfCourses = 0;
}

Student::Student(const Student &arr) {
    this->courses = new Course[arr.numOfCourses];
    this->courses = new Course;
    this->courses = arr.courses;
    this->FieldOfStudy = arr.FieldOfStudy;
    this->numOfCourses = arr.numOfCourses;
}

Student::~Student() {
    delete this->courses;
}

std::istream &operator>>(std::istream &in, Student &D) {
    std::cin >> static_cast<Person &>(D);
    std::cout << "Enter FieldOfStudy\n";
    std::getline(std::cin, D.FieldOfStudy);
    std::cin.ignore();
    std::cout << "Enter numOfCourses \n";
    in >> D.numOfCourses;
    Course *temp = new Course[D.numOfCourses];
    for (int i = 0; i < D.numOfCourses; i++) {
        in >> temp[i];
    }
    D.courses = temp;
    return in;
}

std::ostream &operator<<(std::ostream &output, const Student &D) {
    std::cout << static_cast<const Person &>(D);
    output << "field of study : \t" << D.FieldOfStudy << "\n";
    for (int i = 0; i < D.numOfCourses; i++) {
        std::cout << static_cast<const Course &>(D.courses[i]);
    }
    return output;
}

bool Student::validate(std::string _id) {
    if (Person::validate(_id) == 1 && _id[2] == '*')
        return true;
    {
        std::cout << "invalid id \n";
        exit(1);
    }
}

double Student::gpa() {
    double GPA = 0;
    int totalUnit = 0;
    for (int i = 0; i < this->numOfCourses; i++) {
        GPA += this->courses[i].get_mark() * (this->courses[i].get_unit());
        totalUnit += this->courses[i].get_unit();
    }

    return GPA / totalUnit;
}

double Student::calculateSalary() {
    double salary = 20000 * this->getWorkHours();
    if (this->gpa() > 17.00) {
        return (salary * 11 / 10);
    } else {
        return salary;
    }
};