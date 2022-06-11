
#include "Professor.h"

Professor::Professor() {

    this->title = "";
}

bool Professor::validate(std::string _id) {
    if (Person::validate(_id) ==1&& _id[2] == '#' && _id.size() == 8) {
        return true;
    } else {
        std::cout << "invalid id" << std::endl;
        exit(1);
    }
}

double Professor::calculateSalary() {
    double salary = (50000 + ranks[this->title] * 10000 +
                     2000 * (101 - ((this->getId()[0] - 48) * 10 + (this->getId()[1] - 48))) * this->getWorkHours());

    return salary;
}

std::ostream &operator<<(std::ostream &output, const Professor &D) {
    output << static_cast<const Person &>(D);
    output << "title : " << D.title;
    return output;
}

std::istream &operator>>(std::istream &in, Professor &D) {
    int num;
    num = 0;
    std::cout << "Enter the rank\n";
    for (auto pair: D.ranks) {
        std::cout << pair.second << " - " << pair.first << std::endl;
    }
    bool flag = true;
    while (flag) {
        std::cin>> num;
        switch (num) {
            case 1:
                std::cout << "Instructor is selected\n";
                D.title = "Instructor";
                flag = false;
                break;
            case 2:
                std::cout << "Professor Assistant is selected\n";
                D.title = "Professor Assistant";
                flag = false;
                break;
            case 3:
                std::cout << "Associate Professor is selected\n";
                D.title = "Associate Professor";
                flag = false;
                break;
            case 4:
                std::cout << "Professor is selected\n";
                D.title = "Professor";
                flag = false;
                break;
            default:
                std::cout << "you have to enter a number between 1 &4" << std::endl;
        }
    }
    std::cin >> static_cast< Person &>(D);

    return in;
}
