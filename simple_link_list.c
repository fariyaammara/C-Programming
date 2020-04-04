#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int *next;

};
struct node *head;
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("    %d  ",temp->data);
        temp=temp->next;
    }
}
void insert_beg()
{
    struct node *new_node;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    new_node=malloc(sizeof(struct node));
    printf("enter the node to be inserted\n");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
    head=new_node;
    new_node->next=NULL;
    //head=temp;
    }
    else
    {
        temp=head;
        head=new_node;
        new_node->next=temp;
        //temp=new_node;

    }
}
void insert_at_end()
{
    struct node *temp;
    struct node *new_node;
    temp=malloc(sizeof(struct node));
    new_node=malloc(sizeof(struct node));
    printf("enter the value to be inserted at end\n");
    scanf("%d",&new_node->data);
    temp=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
}
void insert_at_pos()
{
    int pos,i=1,count=0;
    struct node *temp;
    struct node *new_node;
    struct node *next;
    temp=malloc(sizeof(struct node));
    new_node=malloc(sizeof(struct node));
    next=malloc(sizeof(struct node));
    printf("enter the position at which data is to be inserted\n");
    scanf("%d",&pos);
    printf("enter the value to be inserted at %d position\n",pos);
    scanf("%d",&new_node->data);
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(pos>count)
    {
        printf("these many number of nodes does not exit please enter within %d nodes",count);
    }
    else
    {
        temp=head;
        printf("in else\n");
        while(i<pos)
        {
            printf("in while\n");
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;

    }
}
void delete_at_pos()
{
    int pos,i=1,count=0;
    struct node *temp,*next_node;
    temp=malloc(sizeof(struct node));
    next_node=malloc(sizeof(struct node));
    printf("enter the position at hich data is to be deleted\n");
    scanf("%d",&pos);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(pos>count)
    {
        printf("the given position does not exit (limit %d)\n",count);
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }

        next_node=temp->next;
        temp->next=next_node->next;
        free(next_node);

    }
}
void del_at_end()
{
    struct node *temp;
    struct node *prev_node;
    temp=malloc(sizeof(struct node));
    prev_node=malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL)
    {
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=NULL;
    free(temp);
}
void del_at_front()
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp=head;
    if(temp==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        head=head->next;
        free(temp);
    }
}
void search()
{
    struct node *temp;
    int search,i=1,flag=0;
    printf("enter the va;ue to be searched\n");
    scanf("%d",&search);
    temp=head;
    if(head->data==search)
    {
        printf("found");
    }
    else
    {
    while(temp->next!=NULL)
    {
    if(temp->data==search)
    {
        printf("data found at %d location",i);
        flag=1;
        
    }
    temp=temp->next;
    i++;
    }
    }
    if(flag==0)
    {
        printf("data not found\n");
    }

}
int main()
{
    int choice,count=0;
    while(choice!=0)
    {
        printf("\n1.insert at first \n2.insert after\n3.insert at end \n4.display a single student record\n5.delete_a_record_at_pos\n6.delete at end\n7.delete at front\n8.search\n9.reverse");
        scanf("%d",&choice);
        switch(choice)
        {
        case(1):
        
        insert_beg();
        break;
        case(2):
        insert_at_end();
        break;
        case(3):
        insert_at_pos();
        break;
        case(4):
        display();
        break;
        case(5):
        delete_at_pos();
        case(6):
        del_at_end();
        break;
        case(7):
        del_at_front();
        break;
        case(8):
        search();
        break;
        case(9):
        reverse();
        break;
        default:
        exit(0);
    }
    }
    return 0;
}