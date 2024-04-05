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
    T *topPointer = NULL;

};
 

/**
 * @brief Create a Stack object
 * 
 * @return struct stack<int>* , we use refrence pointer because we return a pointer points to the new object of the struct
 *          so we can deal with it in the main function with a pointer points to it
 */

struct stack<int>* CreateStack(){
    struct stack<int> stack;
    /**making the top pointer points to the empty space we should put into*/
    /**making the ==> & operator before the vector elements to get the address cuz the vector indexing returns values*/
    stack.topPointer = &(stack.stackData[0]); 
    return stack;

}







int main(){
    return 0 ;
}