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
    /**we can replace the using of the pointers by using the functions of the vector*/
    Queue.firstPointer  = &(Queue.queueData.front());
    Queue.secondPointer = &(Queue.queueData.back());
    return Queue;
}


template <typename T> 
void queueElement(struct queue<T> &Queue, T data){
    /**adding element in the back of the queue*/
    Queue.queueData.push_back(data);
    
}

template <typename T> 
void dequeueElement(struct queue<T> &Queue){
    /**removing the first elemet of the queue*/ 
    Queue.queueData.erase(Queue.queueData.begin());

}



template<typename T>
void printElements(struct queue<T> &Queue){
    int iteration_number = 0;
    for(int i: Queue.queueData){

        cout<<"the "<<iteration_number+1<<" element of the array is "<<i<<endl;
        iteration_number++;
    }
}


int main(){
    struct queue<int> queue1 = createQueue<int>();
    queueElement<int>(queue1 , 1);
    queueElement<int>(queue1 , 2);
    queueElement<int>(queue1 , 3);
    printElements(queue1);
    dequeueElement(queue1);
    printElements(queue1);
    

    return 0 ;
}