#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else
                return node;
}
treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the left sub tree to find the min element */
                FindMax(node->right);
        else
                return node;
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return node;

}

treeNode * Delete(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < node->data)
        {
                node->left = Delete(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = Delete(node->right, data);
        }
        else
        {
                /* Now We can delete this node and replace with either minimum element
                   in the right sub tree or maximum element in the left subtree */
                if(node->right && node->left)
                {
                        /* Here we will replace with minimum element in the right sub tree */
                        temp = FindMin(node->right);
                        node -> data = temp->data;
                        /* As we replaced it with some other node, we have to delete that node */
                        node -> right = Delete(node->right,temp->data);
                }
                else
                {
                        /* If there is only one or zero children then we can directly
                           remove it from the tree and connect its parent to its child */
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp); /* temp is longer required */
                }
        }
        return node;

}

treeNode * Find(treeNode *node, int data)
{
        if(node==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > node->data)
        {
                /* Search in the right sub tree. */
                return Find(node->right,data);
        }
        else if(data < node->data)
        {
                /* Search in the left sub tree. */
                return Find(node->left,data);
        }
        else
        {
                /* Element Found */
                return node;
        }
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node )
{
    int sum=0,sum1=0;
        if(node==NULL)
        {

                return;

        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        sum = sum + node->data;
        printf("%d",sum);
        PrintPreorder(node->right);
        sum1 =sum1+node->data;
        printf("%d",sum1);

}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        treeNode *root = NULL, *temp;
        int choice,item;


        while(1){

                printf("\n                MENU");
                printf("\n 1.Insert");
                printf("\n 2.Inorder");
                printf("\n 3.PreOrder");
                printf("\n 4.PostOrder");
                printf("\n 5.Search");
                printf("\n 6.FindMin");
                printf("\n 7.FindMax");
                printf("\n 8.Delete");
                printf("\n 9.Exit");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        printf("Input item:");
                                        scanf("%d",&item);
                                        root = Insert(root, item);
                                        break;
                        case 2:
                                        PrintInorder(root);
                                        break;
                        case 3:
                                        PrintPreorder(root);
                                        break;
                        case 4:
                                        PrintPostorder(root);
                                        break;
                        case 5:
                                        printf("Input item:");
                                        scanf("%d",&item);
                                        temp=Find(root,item);
                                        if(temp==NULL)
                                        {
                                                printf("Element not found\n");
                                        }
                                        else
                                        {
                                                printf("Element Found\n");
                                        }
                                        break;
                        case 6:
                                        temp = FindMin(root);
                                        printf("Minimum element is %d\n",temp->data);
                                        break;
                        case 7:
                                        temp = FindMax(root);
                                        printf("Maximum element is %d\n",temp->data);
                                        break;
                        case 8:
                                        printf("Input item:");
                                        scanf("%d",&item);
                                        root=Delete(root,item);
                                        break;

                        case 9:
                                        exit(0);
                                        break;

                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}
