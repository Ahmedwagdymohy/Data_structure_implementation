/**
 * @file stack.cpp
 * @author Ahmed Wagdy
 * @brief   implementing the stack dataStructrue
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */


////////////Includes
#include <iostream>
#include <vector>
#include <string>
using namespace std;


/////////////defines
#define stacksize  20



template<typename T>
struct stack{
    vector<T> stackData;
    T *topPointer = nullptr;

};
 

/**
 * @brief Create a Stack object
 * 
 * @return struct stack<int>* , we use refrence pointer because we return a pointer points to the new object of the struct
 *          so we can deal with it in the main function with a pointer points to it
 */
template<typename T>
struct stack<T> CreateStack(){     
    struct stack<T> stack;
    /**making the top pointer points to the empty space we should put into*/
    /**making the ==> & operator before the vector elements to get the address cuz the vector indexing returns values*/
    stack.topPointer = &(stack.stackData[0]); 
    return stack;

}


template <typename T>
/*taking the stack by reference */
void pushElements( struct stack <T>& stack, T data){
    stack.stackData.push_back(data);
    stack.topPointer = &stack.stackData.back();
}


template <typename T>
void printElements(struct stack <T>&stack){
    for(int i = 0 ; i<stack.stackData.size();i++){
        cout<<"the "<< i+1 << "element in the vector is " << stack.stackData[i]<<endl;
    }
}






int main(){
    struct stack<int> stack1 = CreateStack<int>();
    pushElements<int>(stack1, 1 );
    pushElements<int>(stack1, 2 );
    pushElements<int>(stack1, 3 );
    printElements<int>(stack1);

    return 0 ;
}