#include "Student.h"


Student::Student() {
    this->courses = new Course;
    this->FieldOfStudy = "";
    this->numOfCourses = 0;
    if (validate(const_cast<std::string &>(this->getId())) == 0) {
        std::cout << "invalid id";
    }
}

Student::Student(const Student &arr) {
    this->courses = arr.courses;
    this->FieldOfStudy = arr.FieldOfStudy;
    this->numOfCourses = arr.numOfCourses;
}

Student::~Student() {
    delete this->courses;
}

std::istream &operator>>(std::istream &in, Student &D) {
    std::cin >> *(D.courses);
    std::cout << "Enter firstName\n";
//    Person *temp = static_cast<Person>(D);//how to cast Student to Person
//    std::cin>>;
//    in >> D.firstName;
//    std::cout<< "Enter FieldOfStudy \n ";
//    in >> D.lastName ;
//    in>>id;
//    isvalid(id);
    std::cout << "Enter numOfCourses \n ";
    in >> D.numOfCourses;
    return in;
}

std::ostream &operator<<(std::ostream &output, const Student &D) {
//    std::cout<<D;
    output << "courses : " << D.courses << "\tFieldOfStudy : " << D.FieldOfStudy << "\tnumOfCourses : "
           << D.numOfCourses << "\n";
    return output;
}

bool Student::validate(std::string &_id) {
    if (Person::validate(_id) == 1 && _id[2] == '*')
        return true;
    {
        std::cout << "invalid id \n";
        exit(1);
    }
}

double Student::gpa() {return 0;}//its not completed

double Student::calculateSalary() {
    double salary = 20000 * this->getWorkHours();
    if (this->gpa() > 17.00) {
        return (salary * 11 / 10);
    } else {
        return salary;
    }
};