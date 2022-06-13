#include "Professor.h"
#include "Student.h"

#ifndef HOMEWORK5AP_UNIVERSITY_H
#define HOMEWORK5AP_UNIVERSITY_H


class University {
public:
    University();

    University(const University &arr);

    ~University();

    friend std::ostream &operator<<(std::ostream &output, const University &D);

    friend std::istream &operator>>(std::istream &in, University &D);

    double averageGpa();
    double averageGpaOfField(std::string major);
    double averageMarkOfCourse(std::string subject);
    void printCourses();
    bool isEnoughBudget();
    void saveToFile();
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor *professors;
    Student *students;

};


#endif //HOMEWORK5AP_UNIVERSITY_H
