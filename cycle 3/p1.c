#include <stdio.h>
#include <stdlib.h>

struct BinomialNode 
{
    int key;
    int degree;
    struct BinomialNode *parent, *child, *sibling;
};

struct BinomialNode *createNode(int key) 
{
    struct BinomialNode *newNode = (struct BinomialNode *)malloc(sizeof(struct BinomialNode));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = newNode->child = newNode->sibling = NULL;
    return newNode;
}

void linkNodes(struct BinomialNode *root1, struct BinomialNode *root2) 
{  
    root1->parent = root2;
    root1->sibling = root2->child;
    root2->child = root1;
    root2->degree++;
}

struct BinomialNode *mergeHeaps(struct BinomialNode *heap1, struct BinomialNode *heap2) 
{
    struct BinomialNode *mergedHeap = NULL, **pos = &mergedHeap;
    while (heap1 || heap2)
    {
        if (!heap2 || (heap1 && heap1->degree <= heap2->degree)) 
        {
            *pos = heap1;
            heap1 = heap1->sibling;
        }
        else 
        {
            *pos = heap2;
            heap2 = heap2->sibling;
        }
        pos = &(*pos)->sibling;
    }
    return mergedHeap;
}


struct BinomialNode *unionHeaps(struct BinomialNode *heap1, struct BinomialNode *heap2) 
{
    struct BinomialNode *mergedHeap = mergeHeaps(heap1, heap2), *prev = NULL, *x = mergedHeap, *next = x->sibling;
    while (next) 
    {
        if (x->degree != next->degree || (next->sibling && next->sibling->degree == x->degree)) 
        {
            prev = x;
            x = next;
        } 
        else 
        {
            if (x->key <= next->key) 
            {
                x->sibling = next->sibling;
                linkNodes(next, x);
            } 
            else 
            {
                prev ? (prev->sibling = next) : (mergedHeap = next);
                linkNodes(x, next);
                x = next;
            }
        }
        next = x->sibling;
    }
    return mergedHeap;
}

struct BinomialNode *insertKey(struct BinomialNode *heap, int key) 
{
    return unionHeaps(heap, createNode(key));
}

struct BinomialNode *findMinimum(struct BinomialNode *heap) 
{
    struct BinomialNode *minNode = NULL, *current = heap;
    while (current) 
    {
        if (!minNode || current->key < minNode->key)
            minNode = current;
        current = current->sibling;
    }
    return minNode;
}

struct BinomialNode *deleteMinimum(struct BinomialNode *heap) 
{
    struct BinomialNode *minNode = findMinimum(heap), *prev = NULL, *current = heap;
    while (current) 
    {
        if (current == minNode) 
        {
            prev ? (prev->sibling = current->sibling) : (heap = current->sibling);
            struct BinomialNode *child = current->child;
            while (child) 
            {
                struct BinomialNode *nextChild = child->sibling;
                child->sibling = NULL;
                heap = unionHeaps(heap, child);
                child = nextChild;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->sibling;
    }
    return heap;
}

void displayHeap(struct BinomialNode *heap) 
{
    while (heap) 
    {
        printf("Degree %d: ", heap->degree);
        struct BinomialNode *current = heap;
        while (current) 
        {
            printf("%d ", current->key);
            current = current->child;
        }
        printf("\n");
        heap = heap->sibling;
    }
}

int main() 
{
    struct BinomialNode *binomialHeap = NULL;
    int choice, key;

    do 
    {
        printf("\n1. Insert\n2. Delete\n3. Find Minimum\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the key to be inserted : ");
                scanf("%d", &key);
                binomialHeap = insertKey(binomialHeap, key);
                break;
            case 2:
                binomialHeap = deleteMinimum(binomialHeap);
                printf("\nBinomial Heap after deleting the minimum key:\n");
                displayHeap(binomialHeap);
            case 3:
                struct BinomialNode *minNode = findMinimum(binomialHeap);
                printf("\nMinimum Key: %d\n", minNode->key);
                break;
            case 4:
                printf("Binomial Heap: \n");
                displayHeap(binomialHeap);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
        
    }while(choice != 5);
    
    printf("\nThe program has been terminated!...");
    return 0;
}
