#include<stdio.h>

#include<stdlib.h>



void create();

void display();

void insert_at_beginning();

void insert_at_end();

void insert_at_any_position();

void delete_at_beginning();

void delete_at_end();

void delete_at_any_position();

void delete_a_particular_node();

void reverse_list();

void remove_any_douplcate_value();



struct node{

    int val;

    struct node *next;

};



struct node *curr, *tail = NULL, *head = NULL;



int main(){

    for(;;){

    printf("...............MENU...............\n");

    printf("..................................\n");

    printf("1.  Crate\n");

    printf("2.  Display\n");

    printf("3.  Insert at the beginning\n");

    printf("4.  Insert at the end\n");

    printf("5.  Insert at any position\n");

    printf("6.  Delete at the beginning\n");

    printf("7.  Delete at the end\n");

    printf("8.  Delete at the any position\n");

    printf("9.  delete a particular node\n");

    printf("10. reverse the list\n");

    printf("11. remove all duplicate values\n");

    printf("12. Exit\n");

    printf("..................................\n");

    printf("Enter number between 1-12 here: ");

    int x;

    scanf("%d", &x);

    if(x==1){

       create();

    }

    if(x==2){

       display();

    }

    if(x==3){

       insert_at_beginning();

    }

    if(x==4){

       insert_at_end();

    }

    if(x==5){

       insert_at_any_position();

    }

    if(x==6){

       delete_at_beginning();

    }

    if(x==7){

       delete_at_end();

    }

    if(x==8){

       delete_at_any_position();

    }

    if(x==9){

       delete_a_particular_node();

    }

    if(x==10){

       reverse_list();

    }

    if(x==11){

       remove_any_douplcate_value();

    }

    if(x==12){

       printf("\n");

       break;

    }

}



}

void create(){

    int i, n;

    printf("Enter how many node you want: ");

    scanf("%d", &n);

    printf("Enter node value what you want: ");

    for(i = 0; i < n; i++){

        curr = (struct node *) malloc(sizeof(struct node));

        scanf("%d", &(curr -> val));

        curr -> next = NULL;

        if(head == NULL){

            head = curr;

            tail = curr;

        } else{

            tail -> next = curr;

            tail = curr;

        }

    }

}

void display(){

    printf("------>> Display value ------>>\n");

    struct node *temp = head;

    while(temp != NULL){

        printf("%d  ", temp -> val);

        temp = temp -> next;

    }

    printf("\n");

}



void insert_at_beginning(){

     curr = (struct node *) malloc(sizeof(struct node));

     printf("Enter a new node value here: ");

     scanf("%d", &curr -> val);

     curr -> next = NULL;

     if(head == NULL){

            head = curr;

            tail = curr;

    } else{

        curr -> next = head;

        head = curr;

    }

}



void insert_at_end(){

     struct node *temp;

     curr = (struct node *) malloc(sizeof(struct node));

     printf("Enter a new node value here: ");

     scanf("%d", &curr -> val);

     curr -> next = NULL;

     if(head == NULL){

            head = curr;

            tail = curr;

    } else{

        temp = head;

        while(temp-> next!=NULL){

            temp = temp -> next;

        }

        temp -> next = curr;

        tail = curr;

    }

}



void insert_at_any_position(){

     int posi, i;

     struct node *temp, *temp1;

     curr = (struct node *) malloc(sizeof(struct node));

     printf("Enter node position where you want to store value here: ");

     scanf("%d", &posi);

     printf("Enter new node value at position %d : ",posi);

     scanf("%d", &curr -> val);

     curr -> next = NULL;

     if(head == NULL){

            head = curr;

            tail = curr;

    } else{

        temp = head;

        for(i = 1; i <= posi-1; i++){

            temp1 = temp;

            temp = temp->next;

        }

        temp1 -> next = curr;

        curr -> next = temp;

    }

}



void delete_at_beginning(){

    struct node *temp;

    temp = head;

    head = head->next;

    free(temp);

}



void delete_at_end(){

    struct node *temp,*temp1;

    if(head!=NULL) {

        temp = head;

        while(temp->next!=NULL) {

            temp1 = temp;

            temp = temp->next;

        }

        temp1->next = NULL;

        free(temp);

    }

}



void delete_a_particular_node(){

    struct node *temp,*temp1;

    int key;

    printf("Enter key here: ");

    scanf("%d", &key);

    printf("\n");

    if(head!=NULL) {

        temp = head;

        if(temp -> next != NULL && temp -> val != key) {

            temp1 = temp;

            temp = temp->next;

        }

        if (temp -> val == key){

            temp1 -> next = temp -> next;

            free(temp);

        } else{

            printf("Search key not found\n");

        }

    }

}



void delete_at_any_position(){

    int posi, i, c=0;

    struct node *temp, *temp1;

    printf("Enter node position which one you want to remove: ");

    scanf("%d", &posi);

    if(head != NULL){

        temp = head;

        for(i = 1; i <= posi-1; i++){

            temp1 = temp;

            temp = temp->next;

            c++;

        }

        if(c!=0){

            temp1 -> next = temp -> next;

            free(temp);

        }

    }

}



void reverse_list(){

    struct node *prev = NULL, *curre = head, *next;

    while(curre!=NULL){

        next = curre->next;

        curre->next = prev;

        prev = curre;

        curre = next;

    }

    head = prev;

    printf("List has been reverse....\n");

}



void remove_any_douplcate_value(){

    struct node *temp, *temp1, *dup;

    temp = head;

    while(temp!=NULL && temp->next!=NULL){

        temp1 = temp;

        while(temp1->next!=NULL){

            if(temp->val == temp1->next->val){

                dup = temp1->next;

                temp1->next = temp1->next->next;

                free(dup);

            }

            else{

                temp1 = temp1->next;

            }

        }

        temp = temp->next;

    }

    printf("All duplicate item has been deleted....\n");

}
