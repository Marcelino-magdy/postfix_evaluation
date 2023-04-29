#include <iostream>
#include <ctype.h>

using namespace std;

struct node {
    char data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void createStack(char* exp) {

    for (int i = 0; exp[i]; ++i) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = exp[i];

        
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            front->next = NULL;
            rear->next = NULL;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = NULL;
        }
    }
}



struct node* top = NULL;

void push(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL)
        cout << "stack overflow" << endl;
    else {
        int r =  top->data;
        top = top->next;
        return r;
    }
}

int emptyStack() {
    return top->data == -1;
}

void post_eval(struct node* start, struct node* end) {



    int go = 1;
  
    if (isdigit(start->data)) {

        push((start->data - '0'));
        start = start->next;


        post_eval(start, end);
    }
   
    else {

        int second = pop();
        int first = pop();
        int result;
        switch (start->data)
        {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        default:
            cout << "error" << endl;
        }

    
        push(result);

        if (start->next == NULL) {
            cout << "the result is : " << result << endl;
        }
        else {
            start = start->next;

            post_eval(start, end);
        }


        
        

       
       /* if (!emptyStack()) {

            push(result);
            start = start->next;

            post_eval(start, end);
        }
        else {
            int final_result = result;
            cout << final_result << endl;
        }*/

        
        
        
    }
}


int main()
{
    char exp[] = "231*+9-2*";

    // Function call
    createStack(exp);
    push(-1);
    post_eval(front, rear);
    return 0;
}