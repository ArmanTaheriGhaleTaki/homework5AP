
#include "Professor.h"

Professor::Professor() {

    this->title = "";
}

bool Professor::validate(std::string _id) {
if(Person::validate(_id)&&_id[2]=='#'&&_id.size()==8){
    return true;
}
else
{
    std::cout<<"invalid id"<<std::endl;
    exit(1);
}
}
double Professor::calculateSalary() {
    double salary = (50000+ranks[this->title]*10000+101-((this->getId()[0]-48)*10+(this->getId()[1]-48)) +this->getWorkHours());

        return salary;
    }