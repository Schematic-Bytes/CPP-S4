#include <iostream>

template <typename T1, typename T2>
class Operations{
    T1 first;
    T2 second;
    public:
    template <typename Y1, typename Y2>
    void swap(Y1& x_17, Y2& y_17);
    template <typename Y1, typename Y2> 
    void max(Y1& x_17, Y2& y_17);
};

template <typename T1, typename T2>
template <typename Y1, typename Y2> 
void Operations<T1, T2>::max(Y1& x_17, Y2& y_17){  // pointer to Y1 and Y2 
    std::cout << (x_17 > y_17 ? x_17 : y_17) << std::endl; // prints largest after comparing
}

template <typename T1, typename T2>
template <typename Y1, typename Y2> 
void Operations<T1, T2>::swap(Y1& x_17, Y2& y_17){  // pointer to T1 to x and T2 to y
        Y1 temp_17 = x_17;
        x_17 = y_17;
        y_17 = temp_17;
    }


int main(){
    // creation on objects
    Operations<int, int>integer;
    Operations<float, int>floatinteger;
    Operations<char, char>charachter;
    // declaring variables
    float float1_17 = 11.5;
    int int1_17 = 10, int2_17 = 2;
    char char1_17 = 'a', char2_17 = 'z';
    // calling methods

    floatinteger.max(int1_17, float1_17);

    charachter.swap(char1_17, char2_17);
    std::cout << char1_17 << std::endl;
    charachter.max(char1_17, char2_17);
    
    integer.swap(char1_17, char2_17);
    std::cout << int1_17 << std::endl;
    integer.max(int1_17, int2_17);
    std::cout<<'a' + 'b'<<std::endl;
}
