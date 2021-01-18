#include <iostream>

template <typename T1, typename T2>
T1 Add_17(T1 x_17, T2 y_17){
    return (x_17 + y_17);
}

template <typename T1, typename T2>
T1 Substract_17(T1 x_17, T2 y_17){
    return (x_17 - y_17);
}

template <typename T1, typename T2>
T1 Multiply_17(T1 x_17, T2 y_17){
    return (x_17 * y_17);
}

template <typename T1, typename T2>
T1 Division_17(T1 x_17, T2 y_17){
    return (x_17 / y_17);
}

int main(){
        // Addition
    std::cout<<"<-- Addition -->"<<std::endl;
    // integers
    std::cout<<Add_17<int>(5, 5)<<std::endl;
    // floats
    std::cout<<Add_17<float>(2.5, 2.5)<<std::endl;
    // longs
    std::cout<<Add_17<long>(1000, 2000)<<std::endl;
    // float and int
    std::cout<<Add_17<float, int>(1.5, 1)<<std::endl;
        // Substraction
    std::cout<<"<-- Substraction -->"<<std::endl;
    // integers
    std::cout<<Substract_17<int>(10, 5)<<std::endl;
    // floats
    std::cout<<Substract_17<float>(8.5, 0.5)<<std::endl;
    // longs
    std::cout<<Substract_17<long>(10000, 500)<<std::endl;
    // float and int
    std::cout<<Substract_17<float, int>(11.1, 1)<<std::endl;
        // Multiplication
    std::cout<<"<-- Multiplication -->"<<std::endl;
    // integers
    std::cout<<Multiply_17<int>(10, 5)<<std::endl;
    // floats
    std::cout<<Multiply_17<float>(8.5, 0.5)<<std::endl;
    // longs
    std::cout<<Multiply_17<long>(10000, 500)<<std::endl;
    // float and int
    std::cout<<Multiply_17<float, int>(11.1, 2)<<std::endl;
        // Division
    std::cout<<"<-- Division -->"<<std::endl;
    // integers
    std::cout<<Division_17<int>(10, 5)<<std::endl;
    // floats
    std::cout<<Division_17<float>(8.5, 0.5)<<std::endl;
    // longs
    std::cout<<Division_17<long>(10000, 500)<<std::endl;
    // float and int
    std::cout<<Division_17<float, int>(11.1, 2)<<std::endl;
}