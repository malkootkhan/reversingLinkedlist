/**
 * @files
 * include the necessary library files
 */
#include <stdlib.h>
#include <stdio.h>
/**
 * Node structure for holding the data and address
 * 
 */
struct Node
{
    int data;               ///data variable
    struct Node *next;      ///Address holder

};
/**
 * createNode function, creates new node every time it is called
 * @param: data (in this case integer type)
 * @return: pointer to new node
 */
struct Node* createNode(int data)
{
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));               ///Dynamically allocating memory to new node
    tmp->data = data;           
    tmp->next = NULL;
    return tmp;
}
/**
 * insert function, adds data to the linkedlist
 * @param: head pointer
 * @param: data to be stored in the linkedlist
 */
void insert(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    struct Node* tmp = (*head);

    if(!tmp){
        (*head) = newNode;
        return;
    }
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = newNode;
}
/**
 * display function, displays the linkedlist data on the screen 
 * @param: head pointer to the linkedlist is passed in argument
 */
void display(struct Node* head)
{
    struct Node* tmp = head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
/**
 * reverse function, reverses the existing linkedlist
 * @param: head pointer is passed as argument
 */
void reverse(struct Node** head)
{

    struct Node *curr = (*head);
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

/**
 * @main function
 * this function implements the linkedlist
 */
int main()
{
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    display(head);

    reverse(&head);

    display(head);
    
    return 0;
}
