#define n 1000
int TOP = -1;
int arr[n];


#ifndef stack  // conditioned applied, to avoiding clash of execution of function twice at same time, iff same function declared in other header file.
void push(int item){
    arr[++TOP] = item;
}



int pop(){
    if(TOP == -1)
        return TOP;
    return arr[TOP--];
}

int peek(){
    if(TOP == -1)
        return TOP;
    return arr[TOP];
}

int isEmpty(){
    if(TOP == -1)// empty
        return 1;
    else
        return 0;// not empty
}

#define stack
#endif // stack
