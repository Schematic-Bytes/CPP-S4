#include <iostream>


template <typename T>
class Stack{
    private:
        int top_17 = 0;
        int max_17 = 100;
    public:
        T arr_17[100]; // 100 is the max size
    Stack(int size_17){
        if(size_17 > 100){
           std::cout<<"Maximum size exceeded, using 100"<<std::endl;
           size_17 = 100;
        }
        top_17 = -1;
        max_17 = size_17 - 1;
        
    }
    bool push_17(T item_17);
    T pop_17();
    T checkTop_17();
    bool isEmpty_17();
};


template <typename T>
bool Stack<T>::push_17(T item_17){
    if (top_17 >= max_17){
        std::cout<<"Stack is full"<<std::endl;
        return false;
    }
    else {
        arr_17[++top_17] = item_17;
        std::cout<<item_17<< " pushed"<<std::endl;
        return true;
    }
}

template <typename T>
T Stack<T>::pop_17(){
    if (top_17 < 0){
        std::cout<<"Stack is Empty"<<std::endl;
        T temp_17;
        return temp_17;  // returning empty object
    }
    else {
        T temp_17 = arr_17[top_17--];
        return temp_17;
    }
}

template <typename T>
T Stack<T>::checkTop_17(){
    if (top_17 < 0){
    std::cout<<"Stack is Empty"<<std::endl;
    T temp_17; 
    return temp_17;  // returning empty object
    }
    else {
        T temp_17 = arr_17[top_17--];
        return temp_17;
    }
}

template <typename T>
bool Stack<T>::isEmpty_17(){
    return (top_17 < 0);
}


int main(){
    Stack<std::string>stack(3);
    stack.push_17("a");
    stack.push_17("b");
    stack.push_17("c");
    std::cout<<stack.pop_17()<<std::endl;
    std::cout<<stack.pop_17()<<std::endl;
    std::cout<<stack.pop_17()<<std::endl;
    std::cout<<stack.pop_17()<<std::endl;
    std::cout<<stack.isEmpty_17()<<std::endl;
    stack.push_17("Hello World !");
    std::cout<<stack.checkTop_17()<<std::endl;
}