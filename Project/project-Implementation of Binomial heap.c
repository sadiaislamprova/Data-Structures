//                         CSE 207 Project
//             Problem-12: Implementation of Binomial heap
//               Sadia Islam Prova (2020-3-60-012)
//                Fima Faria Lisa (2020-1-60-026)
/*
In computer science,a binomial heap is a heap similiar to binary heap but also supports quick merging of two heaps.
This is achieved by using a special tree structure. Main application is used to implement priority queue.
It provides faster merge operations with other operations provided by the Binary heap.
A Binomial Tree of order k has the following properties.
a) It has exactly 2^k nodes.
b) It has depth as k.
c) The root has degree k and children of root are themselves Binomial Trees with order k-1, k-2,.. 0 from left to right.
*/
#include<stdio.h>
#include<malloc.h>

struct node {
    int n;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
};

struct node* heapBinMaking();
int linkBin(struct node*, struct node*);
struct node* nodeCreation(int);
struct node* unionBinHeap(struct node*, struct node*);
struct node* insertBinHeap(struct node*, struct node*);
struct node* mergeHeap(struct node*, struct node*);
struct node* minExtract(struct node*);
int revertingList(struct node*);
int display(struct node*);
struct node* nextFindNode(struct node*, int);
int decrease(struct node*, int, int);
int heapDelete(struct node*, int);

int count = 1;

struct node* heapBinMaking() {
    struct node* np;
    np = NULL;
    return np;
}

struct node * H = NULL;
struct node *Hr = NULL;

int linkBin(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

struct node* nodeCreation(int k) {
    struct node* p;//new node;
    p = (struct node*) malloc(sizeof(struct node));
    p->n = k;
    return p;
}

struct node* unionBinHeap(struct node* H1, struct node* H2) {
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = heapBinMaking();
    H = mergeHeap(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL) {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)
                && (next_x->sibling)->degree == x->degree))
        {
            prev_x = x;
            x = next_x;
        }
        else {
            if (x->n <= next_x->n)
            {
                x->sibling = next_x->sibling;
                linkBin(next_x, x);
            }
            else {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                    linkBin(x, next_x);
                    x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

struct node* insertBinHeap(struct node* H, struct node* x) {
    struct node* H1 = heapBinMaking();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = unionBinHeap(H, H1);
    return H;
}

struct node* mergeHeap(struct node* H1, struct node* H2) {
    struct node* H = heapBinMaking();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y = H1;
    z = H2;
    if (y != NULL)
        {
        if (z != NULL && y->degree <= z->degree)
            H = y;
        else if (z != NULL && y->degree > z->degree)
            H = z;
        else
            H = y;
        }
    else
        H = z;
    while (y != NULL && z != NULL)
    {
        if (y->degree < z->degree)
            y = y->sibling;
        else if (y->degree == z->degree)
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        }
        else
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}

int display(struct node* H) {
    struct node* p;
    if (H == NULL)
    {
        printf("\nHEAP EMPTY");
        return 0;
    }
    printf("\nTHE ROOT NODES ARE:-\n");
    p = H;
    while (p != NULL)
    {
        printf("%d", p->n);
        if (p->sibling != NULL)
            printf("-->");
        p = p->sibling;
    }
    printf("\n");
}

struct node* minExtract(struct node* H1) {
    int min;
    struct node* t = NULL;
    struct node* x = H1;
    struct node *Hr;
    struct node* p;
    Hr = NULL;
    if (x == NULL) {
        printf("\nNOTHING TO EXTRACT");
        return x;
    }
    //    int min=x->n;
    p = x;
    while (p->sibling != NULL)
        {
          if ((p->sibling)->n < min)
            {
                min = (p->sibling)->n;
                t = p;
                x = p->sibling;
            }
        p = p->sibling;
       }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL)
    {
        revertingList(x->child);
        (x->child)->sibling = NULL;
    }
    H = unionBinHeap(H1, Hr);
    return x;
}

int revertingList(struct node* y) {
    if (y->sibling != NULL)
    {
        revertingList(y->sibling);
        (y->sibling)->sibling = y;
    }
    else
    {
        Hr = y;
    }
}

struct node* nextFindNode(struct node* H, int k) {
    struct node* x = H;
    struct node* p = NULL;
    if (x->n == k) {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL)
    {
        p = nextFindNode(x->child, k);
    }

    if (x->sibling != NULL && p == NULL)
    {
        p = nextFindNode(x->sibling, k);
    }
    return p;
}

int decrease(struct node* H, int i, int k) {
    int temp;
    struct node* p;
    struct node* y;
    struct node* z;
    p = nextFindNode(H, i);
    if (p == NULL)
    {
        printf("\nINVALID CHOICE OF KEY TO BE REDUCED");
        return 0;
    }
    if (k > p->n)
    {
        printf("\nSORY!THE NEW KEY IS GREATER THAN CURRENT ONE");
        return 0;
    }
    p->n = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->n < z->n)
    {
        temp = y->n;
        y->n = z->n;
        z->n = temp;
        y = z;
        z = z->parent;
    }
    printf("\nKEY REDUCED SUCCESSFULLY!");
}

int heapDelete(struct node* H, int k) {
    struct node* np;
    if (H == NULL)
    {
        printf("\nHEAP EMPTY");
        return 0;
    }

    decrease(H, k, -1000);
    np = minExtract(H);
    if (np != NULL)
        printf("\nNODE DELETED SUCCESSFULLY");
}

int main() {
    int i, n, m, l;
    struct node* p;
    struct node* np;
    char ch;
    printf("\nENTER THE NUMBER OF ELEMENTS:");
    scanf("%d", &n);
    printf("\nENTER THE ELEMENTS:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        np = nodeCreation(m);
        H = insertBinHeap(H, np);
    }
    display(H);
    do {
        printf("\nMENU:-\n");
        printf(
                "\n1)INSERT AN ELEMENT\n2)EXTRACT THE MINIMUM KEY NODE\n3)DECREASE A NODE KEY\n4)DELETE A NODE\n5)QUIT\n");
        scanf("%d", &l);
        switch (l) {
        case 1:
            do {
                printf("\nENTER THE ELEMENT TO BE INSERTED:");
                scanf("%d", &m);
                p = nodeCreation(m);
                H = insertBinHeap(H, p);
                printf("\nNOW THE HEAP IS:\n");
                display(H);
                printf("\nINSERT MORE(y/Y)= \n");
                fflush(stdin);
                scanf("%c", &ch);
            } while (ch == 'Y' || ch == 'y');
            break;
        case 2:
            do {
                printf("\nEXTRACTING THE MINIMUM KEY NODE");
                p = minExtract(H);
                if (p != NULL)
                    printf("\nTHE EXTRACTED NODE IS %d", p->n);
                printf("\nNOW THE HEAP IS:\n");
                display(H);
                printf("\nEXTRACT MORE(y/Y)\n");
                fflush(stdin);
                scanf("%c", &ch);
            } while (ch == 'Y' || ch == 'y');
            break;
        case 3:
            do {
                printf("\nENTER THE KEY OF THE NODE TO BE DECREASED:");
                scanf("%d", &m);
                printf("\nENTER THE NEW KEY : ");
                scanf("%d", &l);
                decrease(H, m, l);
                printf("\nNOW THE HEAP IS:\n");
                display(H);
                printf("\nDECREASE MORE(y/Y)\n");
                fflush(stdin);
                scanf("%c", &ch);
            } while (ch == 'Y' || ch == 'y');
            break;
        case 4:
            do {
                printf("\nENTER THE KEY TO BE DELETED: ");
                scanf("%d", &m);
                heapDelete(H, m);
                printf("\nDELETE MORE(y/Y)\n");
                fflush(stdin);
                scanf("%c", &ch);
            } while (ch == 'y' || ch == 'Y');
            break;
        case 5:
            printf("\nTHANK YOU\n");
            break;
        default:
            printf("\nINVALID ENTRY...TRY AGAIN....\n");
        }
    } while (l != 5);
}
