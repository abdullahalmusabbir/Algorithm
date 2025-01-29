#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
int size=0;
void beginningInsert()
{
    struct node *ptr;
    int item;
    ptr=malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("Enter data: \n");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("Node Inserted.\n");
    }
    size++;
}
void endInsert()
{
    struct node *ptr,*temp;
    int item;
    ptr=malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr->data = item;
        temp = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        printf("Node inserted\n");
    }
    size++;
}
void specificInsert()
{
    int loc,item;
    struct node *ptr, *temp;
    ptr=malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr->data = item;
        printf("Enter the location: \n");
        scanf("%d",&loc);
        temp=head;
        for(int i=1; i<loc-1; i++)
        {
            temp = temp->next;
        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted\n");
    }
    size++;

}
void beginningDelete()
{
    struct node *ptr;
    if(ptr == NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("/nBeginning Delete done/n");
    }
    size--;

}
void endDelete()
{
    struct node *ptr,*temp;
    if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr ->next;
        }
        temp->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
    size--;

}
void specificDelete()
{
    struct node *ptr,*temp;
    int loc;
    ptr=head;
    printf("Enter the location: \n");
    scanf("%d",&loc);
    if(ptr == NULL)
    {
        printf("\nEmpty\n");
    }
    else if(loc==1)
    {
        beginningDelete();
    }
    else if(loc==size)
    {
        endDelete();
    }
    else
    {
        for(int i=0; i<=loc; i++)
        {
            temp = ptr;
            ptr = ptr ->next;

        }
        if(ptr == NULL)
        {
            printf("Invalid Position\n");
        }
        else
        {
            temp ->next =ptr->next;
            free(ptr);
        }
    }
    printf("\nDeleted node %d \n",loc);
    size--;
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->\n",temp->data);
        temp=temp->next;
    }
}
void search()
{
    struct node *temp;
    int item,flag,i=0;
    printf("Enter item: \n");
    scanf("%d",&item);
    temp=head;
    while (temp!= NULL)
    {
        if(temp->data==item)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
        temp = temp -> next;
        i++;
    }
    if(flag==1)
        printf("Can't Find\n");
    else if(flag==0)
        printf("Location: %d\n",i+1);
}
int main()
{
    int choice=0;
    do
    {
        printf("What you want?\n");
        printf("1.insert beginning.\n");
        printf("2.insert at the end.\n");
        printf("3.inset a specific index.\n");
        printf("4.Delete beginning.\n");
        printf("5.Delete at the end.\n");
        printf("6.Delete a specific index.\n");
        printf("7.Display.\n");
        printf("8.Search.\n");
        printf("9.Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            beginningInsert();
            break;
        case 2:
            endInsert();
            break;
        case 3:
            specificInsert();
            break;
        case 4:
            beginningDelete();
            break;
        case 5:
            endDelete();
            break;
        case 6:
            specificDelete();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        }
    }
    while (choice!=9);
}
