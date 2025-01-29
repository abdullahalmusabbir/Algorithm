#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pev;
};

struct node *head=NULL;
int size=0;

void insertBeggening()
{
    int item;
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&item);
    if(ptr==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        if(head==NULL)
        {
            ptr->next=NULL;
            ptr->pev=NULL;
            ptr->data=item;
            head=ptr;
        }
        else
        {
            ptr->pev=NULL;
            ptr->next=head;
            ptr->data=item;
            head->pev=ptr;
            head=ptr;
        }
    }
    printf("\nInsertion Successful\n");
    size++;
}

void insertLast()
{
    int item;
    struct node *ptr,*temp;
    ptr=malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->pev=NULL;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr ->pev=temp;
            ptr->next = NULL;
        }
    }
    printf("\nSuccessful insert\n");
    size++;
}

void specificinsert()
{
    int item,loc;
    struct node *ptr,*temp;
    ptr=malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&item);
        printf("Enter the location: ");
        scanf("%d",&loc);
        temp = head;
        int i=1;
        while(temp->next!=NULL && i<loc)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp;
        ptr->pev=temp->pev;
        temp->pev->next=ptr;
        temp->pev=ptr;
        ptr->data = item;

    }
    printf("\nSuccessful insert");
    size++;
}

void deleteBeginning()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nEmpty\n");
    }
    else if(head->next==NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        head = head -> next;
        head -> pev = NULL;
        free(ptr);
    }
    printf("\nSuccessful deletion\n");
}

void deleteLast()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nEmpty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->pev->next=NULL;
        free(temp);
    }
    printf("\nSuccessful deletion\n");
}

void deleteSpecific()
{
    struct node *temp;
    int loc;
    printf("Enter location: ");
    scanf("%d",&loc);
    if(head==NULL)
    {
        printf("\nEmpty\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else if(loc==1)
    {
        deleteBeginning();
    }
    else if(loc==size)
    {
        deleteLast();
    }
    else
    {
        temp=head;
        for(int i=1;i<loc;i++)
        {

            temp=temp->next;
        }

        temp->pev->next=temp->next;
        temp->next->pev=temp->pev;
        free(temp);
    }
    printf("\nSuccessful deletion\n");
}

void reverse()
{
    struct node *ptr,*temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("%d-> ",temp->data);
    while(temp->pev!=NULL)
    {
        temp=temp->pev;
        printf("%d-> ",temp->data);
    }
}

void display()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
}

void search()
{
    struct node *ptr,*temp;
    int item;
    printf("Enter item: ");
    scanf("%d",&item);
    temp=head;
    while (temp -> next != NULL)
    {
        if(temp->data==item)
        {
            printf("%d \n",temp->data);
        }
        temp = temp -> next;
    }
}

void searchByP()
{
    struct node *temp;
    int loc;
    temp=head;
    printf("Enter the location: \n");
    scanf("%d",&loc);
    int i=1;
    while(temp->next!=NULL && i<=loc)
    {
        temp=temp->next;
        i++;
    }
    printf("%d \n",temp->data);
}

int main()
{
    printf("\n---------Doubly Linked List-----------\n");
    int choice=0;
    do
    {
        printf("What you want: \n");
        printf("1.Add item beginning.\n");
        printf("2.Add item last.\n");
        printf("3.Add item specific location.\n");
        printf("4.Delete beginning.\n");
        printf("5.Delete Last.\n");
        printf("6.Delete specific.\n");
        printf("7.Search by node value.\n");
        printf("8.Search by node position.\n");
        printf("9.Display\n");
        printf("10.Reverse\n");
        printf("0.Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertBeggening();
            break;
        case 2:
            insertLast();
            break;
        case 3:
            specificinsert();
            break;
        case 4:
            deleteBeginning();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            deleteSpecific();
            break;
        case 7:
            search();
            break;
        case 8:
            searchByP();
            break;
        case 9:
            display();
            break;
        case 10:
            reverse();
            break;
        }
    }while(choice!=0);
}
