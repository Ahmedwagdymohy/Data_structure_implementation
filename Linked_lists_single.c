/**
 * @file Linked_lists_single.c
 * @author Ahmed Wagdy
 * @brief   Creating and implementing the linked lists
 * @version 0.1
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024
 *
 */

////////<LIB/////////////
#include <stdlib.h>
#include<stdio.h>


///////<headers//////////


/**
 * @brief Create a node object with given data
 * 
 * @param data 
 * @return struct node* 
 */
struct node* create_node(int data );




/**
 * @brief delete the give node 
 *        NOTE: the node given should be a pointer to the node
 * 
 * @param user_node 
 * @return int 
 */
int delete_node(struct node *user_node);




/**
 * @brief pushes the nodes to the list
 * @param user_node
 * @param position : 0 -> to insert at beginging
 *                   1 -> to insert at the end
 */
void push_node(struct node* user_node, int position);


/**
 * @brief return the number of the elements in the list
 * 
 * @return int 
 */
int list_count();





/**
 * @brief  retrun the middle element of the list
 * 
 * @return struct node* 
 */
struct node* return_middle_element();







/// @brief the main structure of the node /////////
struct node{

struct node* next ;
int data;
};


///////<head of the list////////
struct node* head = NULL;



/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/************************************< Main function goes here > ****************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/

int main(){

    struct node * node1 = create_node(6);
    struct node * node2 = create_node(8);
    struct node * node3 = create_node(10);
    struct node * node4 = create_node(99);
    struct node * node5 = create_node(80);
    //don't forget that zero makes it inserts at the beginnings
    push_node(node1, 0);
    push_node(node2, 0);
    push_node(node3, 0);
    push_node(node4, 1);
    push_node(node5, 1);
    printf("the data is: ");
    list_print();
    printf("\n");
    printf("the count is: ");
    list_count();
    printf("\n");
    int status = 5;
    //status = delete_node(node2);
    //printf("the status of the delete is %i\n", status);
    //printf("the data after deletion is: ");
    list_print();
    struct node* middle_node = return_middle_element();
    int dataOfMiddleNode =middle_node->data;
    printf("the data of the middle node is %i", dataOfMiddleNode);
    return 0;
}
















/**
 * @brief Create a node object
 *
 * @param data
 * @return struct node*
 */
struct node* create_node(int data){

    struct node* newNode = (struct node*) (malloc(sizeof(struct node)));
    newNode->next = NULL;
    newNode->data = data;

}









/**
 * @brief Deleting the nodes
 * @note Note working properly yet!!!
 * @param nodee
 */
int delete_node(struct node *user_node){
    /*if there's only one node in the list*/
    if((head->next) ==NULL){
        free(user_node);
        head = NULL;
        return 0;

    }

    /*if the desired node is the first one*/
    struct node* tempp = head;
    if(user_node == head){
        head = tempp->next;
        free(user_node);
        return 1;
       } else{



    /**if the desired node is in the middle*/
    /*we will make a new temp pointer which will find the desired node*/
    struct node* temp = NULL;
    temp = head;
    while(temp->next != user_node){
        temp = temp->next;

    }
    temp->next = user_node->next;
    free(user_node);

       }/**end of else*/

}








/**
 * @brief pushes the nodes to the list
 * @param user_node
 * @param position : 0 -> to insert at beginging
 *                   1 -> to insert at the end
 */

void push_node(struct node* user_node, int position){
    //if the list is empty the entered node will be the header
    if (head == NULL){
        head = user_node;

    }else{
        /**inserting at the begining*/
        if(position == 0){
            user_node->next = head;
            head = user_node;

        }/**inserting at the end of the list*/
        else{

            /**looping till we reach the final node*/
            /*Creating another pointer to walk throught the nodes*/
            struct node* pointer = NULL;
            pointer = head;

            do{
                pointer = pointer->next ;
            }
            while(pointer->next != NULL);
            /*after reaching the last element*/
            /*putting the data*/
            pointer->next = user_node;
            user_node->next = NULL;


        }
    }
}



/**
 * @brief counting the number of the nodes in the list
 *
 * @return int
 */
int list_count(){
    struct node* counter_pointer = head;
    int num = 0;
    while(counter_pointer != NULL){

        counter_pointer = counter_pointer->next;
        num++;

    }
    printf("%i", num);
    return num;
}




/**
 * @brief printing the elements of the list
 * @return return and print the number!
 */
void list_print (){
    /*checking if the list is empty*/
    if(head == NULL){
        printf("the list is empty\n");
    }
    struct node* counter_pointer = head;
    while(counter_pointer != NULL){
        printf("%i ", counter_pointer->data);
        counter_pointer = counter_pointer->next; // Move to the next node
    }
    printf("\n");
}





struct node* return_middle_element(){
    /**creatring the two temp pointers that will traverse*/
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    temp1 = head;
    temp2= head;
    while(temp2->next !=NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    /**after this the temp two pointer will at the end node and the middle one will be in the middle*/
    return temp1;
}
