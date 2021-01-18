#include <iostream>


class Student17{
    public:
    int roll_no17;
    int class_no17;
    int mark17;
    std::string student_first_name17;
    std::string student_last_name17;
    Student17(){
        student_first_name17 = '\0';
        student_last_name17 = student_first_name17;
        roll_no17 = 0;
        class_no17 = 0;
        mark17 = 0;
    };
    Student17(std::string first17, std::string last17, int roll17, int class17, int _mark17){
        student_first_name17 = first17;
        student_last_name17 = last17;
        roll_no17 = roll17;
        class_no17 = class17;
        mark17 = _mark17;
    };
    void displayData17(){
        std::cout<<"\tStudent Detail Chart\n";
        std::cout<<"Name: "<<student_first_name17<<" "<<student_last_name17<<std::endl;
        std::cout<<"Roll no: "<<roll_no17<<std::endl;
        std::cout<<"Class: "<<class_no17<<std::endl;
        std::cout<<"Mark: "<<mark17<<std::endl;
    };
    void getData17(){
        std::cout<<"Enter the first name: ";
        std::getline(std::cin, student_first_name17);
        std::cout<<"Enter the last name: ";
        std::getline(std::cin, student_last_name17);
        std::cout<<"Enter the roll no: ";
        std::cin>>roll_no17;
        std::cout<<"Enter the class no: ";
        std::cin>>class_no17;
        std::cout<<"Enter the mark: ";
        std::cin>>mark17;
    };
};

int main(){
    Student17 a17;
    Student17 b17("Eobawd", "Thawne", 2, 3, 100);
    a17.getData17();
    a17.displayData17();
    b17.displayData17();
}