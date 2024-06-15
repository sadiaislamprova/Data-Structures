#include <stdio.h>

#include <stdlib.h>



struct stack{

    int data;

    struct stack *next;

} *top = NULL, *newNode;



int main(){

    int choice, data, y;

    for(;;){

        printf("            => MENU <=           \n");

        printf("1. Display\n");

        printf("2. Push\n");

        printf("3. Pop\n");

        printf("4. Parsing Unmatched Parenthesis\n");

        printf("5. Reversing Data\n");

        printf("6. Exit\n");

        printf("---------------------------------\n");

        printf("Enter your choice between (1-7): ");



        scanf("%d", &choice);

        switch(choice){

            case 1:

                display();

                break;

            case 2:

                printf("Enter your value: ");

                scanf("%d", &y);

                push(y);

                break;

            case 3:

                pop();

                break;

            case 4:

                parsing();

                break;

            case 5:

                reversing();

                break;

            case 6:

                exit(0);

                break;

        }

        printf("\n");

    }

    return 0;

}



void display(){

    printf("    ->> Display value <<-   \n");

    struct stack *temp = top;

    if(temp==NULL){

        printf("Stack is empty");

    }

    while(temp != NULL){

        printf("%d  ", temp -> data);

        temp = temp -> next;

    }

    printf("\n");

}

void push(int a){

    newNode = (struct stack *)malloc(sizeof(struct stack));

    newNode->data = a;

    if(top == NULL){

        newNode->next = NULL;

        top = newNode;

    }else{

        newNode->next = top;

        top = newNode;

    }

}



int pop(){

    struct stack *temp;

    if(top==NULL){

        printf("Stack is empty");

    }

    if(top != NULL){

        temp = top;

        top = top->next;

        free(temp);

    }

}



struct stack1{

    char data1;

    struct stack1 *next1;

} *top1 = NULL, *newNode1;



void push1(){

        newNode1 = (struct stack1 *)malloc(sizeof(struct stack1));

        newNode1->data1 = '(';

        if(top1 == NULL){

            newNode1->next1 = NULL;

            top1 = newNode1;

        }else{

            newNode1->next1 = top1;

            top1 = newNode1;

        }

    }



int pop1(){

    struct stack *temp1;

    if(top1 != NULL){

        temp1 = top1;

        top1 = top1->next1;

        free(temp1);

    }

}



void parsing(){

    int i, c = 0;

    char equation[20];

    printf("Enter equation: ");

    scanf("%s", &equation);

    for(i = 0; i < sizeof(equation); i++){

        if(equation[i] == '('){

            push1();

            ++c;

        }

        if(equation[i] == ')'){

            if(c != 0){

                pop1();

                --c;

            }

            else{

                printf("Closing parentheses not matched..!!");

            }

        }

    }

    if(top1 != NULL && top1->data1 == '('){

        printf("Opening parentheses not end..!!");

        pop1();

    }

}



void reversing(){

    struct stack *temp;

    int x, c = 0, i;

    printf("Enter decimal number: ");

    scanf("%d", &x);

    for(;x > 0;){

        push(x % 2);

        c++;

        x = x /2;

    }

    for(;c>0;){

        temp = top;

        printf("%d", temp -> data);

        top = top -> next;

        free(temp);

        c--;

    }

    printf("\n");

}

