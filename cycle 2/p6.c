#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node *root = NULL;

struct node* newNode(int value)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

struct node* insert(struct node *root, int value)
{
    struct node *ptr = newNode(value);
    if(root == NULL)
        return ptr;
    else if(root->data > value)
        root->left_child = insert(root->left_child, value);
    else if(root->data < value)
        root->right_child = insert(root->right_child, value);
        
    return root;
}

void inorder(struct node *root)
{
    if(root->left_child != NULL)
        inorder(root->left_child);
    
    printf("%d-->",root->data);

    if(root->right_child != NULL)
        inorder(root->right_child);

    return;
}

void search(struct node *temp, int value)
{
    if(root != NULL)
    {
        if(temp->data == value)
        {
            printf("\nThe %d is present in the tree.", value);
            return;
        }
        else if(temp->data > value)
        {
            if(temp->left_child != NULL)
                search(temp->left_child, value);
            else
                printf("\nThe %d is not present in the tree", value);
            return;
        }
        else if(temp->data < value)
        {
            if(temp->right_child != NULL)
                search(temp->right_child, value);
            else
                printf("\nThe %d is not present in the tree", value);
            return;
        }
    }
    else
    {
        printf("\nThe tree is empty");
    }
}

struct node* nextMinNode(struct node *temp)
{
    if(temp != NULL)
    {
        while(temp && temp->left_child != NULL)
            temp=temp->left_child;

        return temp;
    }
    else
    {
        printf("\nThe tree is empty");
        return temp;
    }
}

struct node* delete(struct node *temp, int value)
{
     if(temp != NULL)
     {
        if(temp->data == value)
        {
            //for leaf node
            if((temp->left_child==NULL) && (temp->right_child==NULL))
            {
                printf("The value %d has been deleted from the tree", temp->data);
                return NULL;
            }

            //for a node with a single child
            if((temp->left_child==NULL)&&(temp->right_child!=NULL))
            {
                printf("The value %d has been deleted from the tree", temp->data);
                return temp->right_child;
            }

            if((temp->left_child!=NULL)&&(temp->right_child==NULL))
            {
                printf("The value %d has been deleted from the tree", temp->data);
                return temp->left_child;
            }

            //for a node with both the childs
            if((temp->left_child!=NULL)&&(temp->right_child!=NULL))
            {
                printf("The value %d has been deleted from the tree", temp->data);
                struct node *ptr;
                ptr = nextMinNode(temp->right_child);
                temp->data = ptr->data;
                temp->right_child = delete(temp->right_child, ptr->data);
                return temp;
            }
        }
        else if(temp->data > value)
        {
            if(temp->left_child != NULL)
                temp->left_child = delete(temp->left_child, value);
            else
                printf("\nThe %d is not present in the tree", value);
            return temp;
        }
        else if(temp->data < value)
        {
            if(temp->right_child != NULL)
                temp->right_child = delete(temp->right_child, value);
            else
                printf("\nThe %d is not present in the tree", value);
            return temp;
        }
     }
      else
    {
        printf("\nThe tree is empty");
        return temp;
    }
}



int main() 
{
    int choice, value;
    struct node *ptr;
  
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Find Minimum\n5. Display\n6. Exit\n");
        printf("Enter your choice of operation : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted : ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("The value has been inserted : ");
                break;
            case 2:
                printf("Enter the value to be deleted : ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 3:
                printf("Enter the value to be searched : ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 4:
                ptr = nextMinNode(root);
                printf("The minimum value in the tree is %d\n", ptr->data);
                break;
            case 5:
                printf("Inorder traversal : ");
                inorder(root);
                break;
            case 6:
                break;
            default:
                printf("Invalid option. Please try again!\n");
        }
    }
    while(choice != 6);
    printf("The program has been terminated!...");
}
