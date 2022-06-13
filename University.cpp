#include "University.h"

University::University() {
    this->budget = 0;
    this->numOfProfessors = 0;
    this->numOfStudents = 0;
}

University::University(const University &arr) {
    this->budget = budget;
    this->numOfProfessors = numOfProfessors;
    this->numOfStudents = numOfStudents;
    this->professors = new Professor;
    this->professors = arr.professors;
    this->students = new Student;
    this->students = arr.students;
}

University::~University() {
    delete this->students;
    delete this->professors;
}

std::ostream &operator<<(std::ostream &output, const University &D) {
    for (int j = 0; j < D.numOfProfessors; j++) {
        Professor temp = D.professors[j];
        for (int k = 0; k < D.numOfProfessors; k++) {
            if (temp.ageOfJoin() > D.professors[k].ageOfJoin()) {
                temp = D.professors[k];
            } else {

                if (temp.ageOfJoin() == D.professors[k].ageOfJoin()) {
                    if (temp.getLastName() > D.professors[k].getLastName()) {
                        temp = D.professors[k];
                    } else(temp.getLastName() == D.professors[k].getLastName());
                    {
                        if (temp.getFirstName() > D.professors[k].getFirstName()) {
                            temp = D.professors[k];
                        }

                    }
                }
            }
        }
        std::cout << D.professors[j];
    }
    for (int j = 0; j < D.numOfStudents; j++) {
        Student temp = D.students[j];
        for (int k = 0; k < D.numOfStudents; k++) {
            if (temp.ageOfJoin() > D.students[k].ageOfJoin()) {
                temp = D.students[k];
            } else {

                if (temp.ageOfJoin() == D.students[k].ageOfJoin()) {
                    if (temp.getLastName() > D.students[k].getLastName()) {
                        temp = D.students[k];
                    } else(temp.getLastName() == D.students[k].getLastName());
                    {
                        if (temp.getFirstName() > D.students[k].getFirstName()) {
                            temp = D.students[k];
                        }

                    }
                }
            }
        }
        std::cout << D.students[j];
    }
    return output;
}

std::istream &operator>>(std::istream &in, University &D) {
    std::cout << "Enter the budget\n";
    in >> D.budget;
    std::cout << "Enter the number of Professors\n";
    in >> D.numOfProfessors;
    Professor *temp0 = new Professor[D.numOfProfessors];
    for (int i = 0; i < D.numOfProfessors; i++) {
        in >> temp0[i];
    }
    std::cout << "Enter the number of students";
    Student *temp1 = new Student[D.numOfProfessors];
    for (int j = 0; j < D.numOfStudents; j++) {
        in >> temp1[j];
    }
    D.professors = temp0;
    D.students = temp1;
    return in;
}

double University::averageGpa() {
    double gpa;
    for (int i = 0; i < this->numOfProfessors; i++) {
        gpa += this->students[i].gpa();
    }
    gpa /= this->numOfStudents;
    return gpa;
}

double University::averageGpaOfField(std::string major) {
    int numOfStudentsThatHasThisMajor = 0;
    double gpa;
    for (int i = 0; i < this->numOfStudents; i++) {
        if (this->students[i].getFieldOfStudy() == major) {
            numOfStudentsThatHasThisMajor++;
            gpa += this->students[i].gpa();
        }
    }
    gpa /= numOfStudentsThatHasThisMajor;
    return gpa;
}

double University::averageMarkOfCourse(std::string subject) {
    int numOfStudentsThatHasThisSubject = 0;
    double gpa;
    for (int i = 0; i < this->numOfStudents; i++) {
        for (int k = 0; k < this->students[i].getNumOfCourses(); k++) {
            if (this->students[i].getPointerToCourse()[k].get_name() == subject) {
                numOfStudentsThatHasThisSubject++;
                gpa += this->students[i].gpa();
            }
        }
    }
    gpa /= numOfStudentsThatHasThisSubject;
    return gpa;
}

bool University::isEnoughBudget() {
    double Payment = 0;
    for (int i = 0; i < this->numOfStudents; i++) {
        Payment += this->students[i].calculateSalary();
    }
    for (int j = 0; j < this->numOfProfessors; j++) {
        Payment += this->professors[j].calculateSalary();
    }
    if (budget < Payment) {
        return false;
    } else {
        return true;
    }
}

void University::printCourses() {
    std::string nameOfstudies[30];
    double gpaOfStudies[30];
    int numOfStudentsInACourse[30]{};
    for (int q = 0; q < 30; q++) {
        gpaOfStudies[q] = 0;
        numOfStudentsInACourse[q] = 0;
        nameOfstudies[q] = "";
    }

    int indexReserved = 0;
    for (int i = 0; i < this->numOfStudents; i++) {
        for (int j = 0; j < this->students[i].getNumOfCourses(); j++) {
            for (int k = 0; k < 30; k++) {
                if (this->students[i].getPointerToCourse()[j].get_name() == nameOfstudies[k]) {
                    gpaOfStudies[k] += this->students[i].getPointerToCourse()[j].get_mark();
                    numOfStudentsInACourse[k]++;
                    break;
                } else {
                    if (numOfStudentsInACourse[k] == 0) {
                        nameOfstudies[indexReserved] = this->students[i].getPointerToCourse()[j].get_name();
                        indexReserved++;
                        gpaOfStudies[k] += this->students[i].getPointerToCourse()[j].get_mark();
                        numOfStudentsInACourse[k]++;
                    } else {

                        nameOfstudies[indexReserved] = this->students[i].getPointerToCourse()[j].get_name();
                        indexReserved++;
                    }
                }
            }
        }
    }
    for (int g = 0; nameOfstudies[g] != ""; g++) {
        std::cout << nameOfstudies[g] << std::endl;
        std::cout << double(gpaOfStudies[g] / numOfStudentsInACourse[g]) << std::endl;
    }
}
