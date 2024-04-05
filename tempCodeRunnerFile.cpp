struct stack<int> CreateStack(){
    struct stack<int> stack;
    /**making the top pointer points to the empty space we should put into*/
    /**making the ==> & operator before the vector elements to get the address cuz the vector indexing returns values*/
    stack.topPointer = &(stack.stackData[0]); 
    return stack;

}