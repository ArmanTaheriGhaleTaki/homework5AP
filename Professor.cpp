
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
    double salary = 50000 * this->getWorkHours();
    //use map here
        return salary;
    }