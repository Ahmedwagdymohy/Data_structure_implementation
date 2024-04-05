/**
 * @file      Queue.cpp
 * @author    Ahmed Wagdy
 * @brief     implementing the queue using cpp
 * @version   0.1
 * @date      2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/********<includes*/
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

/********< headers*/
#define QueueSize 20
template<typename T>
struct queue{
    vector<T> queueData;
    T *firstPointer = nullptr;
    T *secondPointer = nullptr ;

};


template <typename T> 
struct queue <T> createQueue(){
    struct queue<T> Queue;
    
    Queue.firstPointer  = &(Queue.queueData.front());
    Queue.secondPointer = &(Queue.queueData.back());
    return Queue;
}


template <typename T> 
void queueElement(struct queue<T> &Queue, T data){
    
}







int main(){

    return 0 ;
}