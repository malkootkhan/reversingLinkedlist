#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;

};

struct Node* createNode(int data)
{
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

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
void display(struct Node* head)
{
    struct Node* tmp = head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
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
