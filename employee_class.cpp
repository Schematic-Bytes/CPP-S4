#include <iostream>


class Employee_17{
    public:
    int employee_id17;
    int employee_age17;
    std::string employee_name17;
    Employee_17(){  // default constructor 
        employee_id17 = 0;
        employee_age17 = 20;
        employee_name17 = '\0';
    };
    Employee_17(int id17, int age17, std::string name17){  // parameterised constructor
        employee_id17 = id17;
        employee_age17 = age17;
        employee_name17 = name17;
    };
    void displayData17(){
        std::cout<<"\tEmployee Detail Chart\n";
        std::cout<<"Name: "<<employee_name17<<std::endl;
        std::cout<<"ID : "<<employee_id17<<std::endl;
        std::cout<<"Age: "<<employee_age17<<std::endl;
    };
    void getData17(){
        std::cout<<"Enter the employee name: ";
        std::cin>>employee_name17;
        std::cout<<"Enter the employee ID: ";
        std::cin>>employee_id17;
        std::cout<<"Enter the age of employee: ";
        std::cin>>employee_age17;
    }
};

int main(){
    Employee_17 arrays_17[7];
    for(int x = 0; x<=6 ; x++){
        Employee_17 temp;
        temp.getData17();
        arrays_17[x] = temp;
    }
    for(int x = 0; x<=6 ; x++){
        arrays_17[x].displayData17();
    }
}