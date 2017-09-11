#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node* next;
};



void pushFront(struct Node** head_ref, int data)
{
struct Node* n=(struct Node*) malloc(sizeof(struct Node));

n->data=data;
n->next = (*head_ref);
*head_ref=n;
}

void display(struct Node *head)
{
  while(head!=NULL)
  {
    printf("%d",head->data);
    head=head->next;
  }

}



int main()
{
 int data;
 struct Node *head=NULL;
 head=(struct Node*)malloc(sizeof(struct Node));

 head->data=1;
 head->next=NULL;


 printf("Enter New Node Data");
 scanf("%d", &data);

 pushFront(&head, data);
 display(head);

 return 1;

}
