#include<stdio.h>
#include<stdlib.h>
struct student_struct{
    char *name;
    int roll_no;
    char *course_name;
    int physics;
    int maths;
    int social;
    char grade;
    float percentage;
    //struct subjects *marks;
    struct student *next;
};
struct student_struct *head;
void display()
{
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp=head;
    while(temp!=NULL)
    {
        //printf("    %d  ",temp->data);
        printf("ROLL NO:%d\n",temp->roll_no);
        printf("NAME:%s\n",temp->name);
        printf("COURSE NAME:%s\n",temp->course_name);
        //printf("Maths marks:%d\n",temp->marks->maths);
        //printf("Science marks:%d\n",temp->marks->physics);
        //printf("Social marks:%d\n",temp->marks->social);
        printf("Maths marks:%d\n",temp->maths);
        printf("Physics marks:%d\n",temp->physics);
        printf("Social marks:%d\n",temp->social);
        printf("GRADE:%c\n",temp->grade);
        printf("PERCENTAGE:%f\n",temp->percentage);
        temp=temp->next;
    }
}
void insert_beg()
{
    struct student_struct *new_node;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    new_node=malloc(sizeof(struct student_struct));
    //printf("enter the node to be inserted\n");
    //scanf("%d",&new_node->data);
    printf("enter the roll_no\n");
    scanf("%d",&new_node->roll_no);
    new_node->name=(char*)malloc(20* sizeof(char));
    printf("enter the name\n");
    scanf("%s",new_node->name);
    new_node->course_name=(char*)malloc(20* sizeof(char));
    printf("enter the course_name\n");
    scanf("%s",new_node->course_name);

    printf("enter the physics marks\n");
    //scanf("%d",&new_node->marks->physics);
    scanf("%d",&new_node->physics);


    printf("enter the social_marks\n");
    //scanf("%d",&new_node->marks->social);
    scanf("%d",&new_node->social);


    printf("enter the maths_marks\n"); 
    scanf("%d",&new_node->maths);
    //scanf("%d",&new_node->marks->maths);
    int m1=new_node->physics;
    int m2=new_node->social;
    int m3=new_node->maths;
    int sum=0,total=300;
    double avg;
    sum=m1+m2+m3;
    new_node->percentage=(float)sum / total * 100.0;
    printf("eeeeeeeeeeeeeeeeeeeeeeeeeeee%f\n",new_node->percentage);
    if(new_node->percentage>=60)
    {
        new_node->grade='A';
    }
    else if(new_node->percentage>=50 && new_node->percentage<60)
    {   new_node->grade='B';
    }
    else if(new_node->percentage>=33 && new_node->percentage<50)
    {    new_node->grade='C';
    }
    else
    {
        new_node->grade='F';
    }
    printf("e%c\n",new_node->grade);
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
    struct student_struct *new_node;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    new_node=malloc(sizeof(struct student_struct));
    //printf("enter the node to be inserted\n");
    //scanf("%d",&new_node->data);
    printf("enter the roll_no\n");
    scanf("%d",&new_node->roll_no);
    new_node->name=(char*)malloc(20* sizeof(char));
    printf("enter the name\n");
    scanf("%s",new_node->name);
    new_node->course_name=(char*)malloc(20* sizeof(char));
    printf("enter the course_name\n");
    scanf("%s",new_node->course_name);

    printf("enter the physics marks\n");
    scanf("%d",&new_node->physics);


    printf("enter the social_marks\n");
    scanf("%d",&new_node->social);


    printf("enter the maths_marks\n"); 

    scanf("%d",&new_node->maths);
        int m1=new_node->physics;
    int m2=new_node->social;
    int m3=new_node->maths;
    int sum=0,total=300;
    double avg;
    sum=m1+m2+m3;
    new_node->percentage=(float)sum / total * 100.0;
    printf("eeeeeeeeeeeeeeeeeeeeeeeeeeee%f\n",new_node->percentage);
    if(new_node->percentage>=60)
    {
        new_node->grade='A';
    }
    else if(new_node->percentage>=50 && new_node->percentage<60)
    {   new_node->grade='B';
    }
    else if(new_node->percentage>=33 && new_node->percentage<50)
    {    new_node->grade='C';
    }
    else
    {
        new_node->grade='F';
    }
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
    int pos,i=1,count=1;
    struct student_struct *temp;
    struct student_struct *new_node;
    /*struct student_struct *next;
    temp=malloc(sizeof(struct student_struct));
    new_node=malloc(sizeof(struct student_struct));
    next=malloc(sizeof(struct student_struct));*/
    temp=malloc(sizeof(struct student_struct));
    new_node=malloc(sizeof(struct student_struct));
    printf("enter the position at which data is to be inserted\n");
    scanf("%d",&pos);
    printf("enter the roll_no\n");
    scanf("%d",&new_node->roll_no);
    new_node->name=(char*)malloc(20* sizeof(char));
    printf("enter the name\n");
    scanf("%s",new_node->name);
    new_node->course_name=(char*)malloc(20* sizeof(char));
    printf("enter the course_name\n");
    scanf("%s",new_node->course_name);

    printf("enter the physics marks\n");
    scanf("%d",&new_node->physics);


    printf("enter the social_marks\n");
    scanf("%d",&new_node->social);


    printf("enter the maths_marks\n"); 

    scanf("%d",&new_node->maths);
    int m1=new_node->physics;
    int m2=new_node->social;
    int m3=new_node->maths;
    int sum=0,total=300;
    double avg;
    sum=m1+m2+m3;
    new_node->percentage=(float)sum / total * 100.0;
    printf("eeeeeeeeeeeeeeeeeeeeeeeeeeee%f\n",new_node->percentage);
    if(new_node->percentage>=60)
    {
        new_node->grade='A';
    }
    else if(new_node->percentage>=50 && new_node->percentage<60)
    {   new_node->grade='B';
    }
    else if(new_node->percentage>=33 && new_node->percentage<50)
    {    new_node->grade='C';
    }
    else
    {
        new_node->grade='F';
    }
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
    struct student_struct *temp,*next_node;
    temp=malloc(sizeof(struct student_struct));
    next_node=malloc(sizeof(struct student_struct));
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
    struct student_struct *temp;
    struct student_struct *prev_node;
    temp=malloc(sizeof(struct student_struct));
    prev_node=malloc(sizeof(struct student_struct));
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
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
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
    struct student_struct *temp;
    int search,i=1,flag=0;
    printf("enter the va;ue to be searched\n");
    scanf("%d",&search);
    temp=head;
    if(head->roll_no==search)
    {
        printf("found");
    }
    else
    {
    while(temp!=NULL)
    {
    if(temp->roll_no==search)
    {
        printf("data found at %d location",i);
        printf("the Student record is\n");
        printf("ROLL NO:%d\n",temp->roll_no);
        printf("NAME:%s\n",temp->name);
        printf("COURSE NAME:%s\n",temp->course_name);
        printf("Maths marks:%d\n",temp->maths);
        printf("Physics marks:%d\n",temp->physics);
        printf("Social marks:%d\n",temp->social);
        printf("GRADE:%c\n",temp->grade);
        printf("PERCENTAGE:%f\n",temp->percentage);
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
        printf("\n1.insert at first \n2.insert end\n3.insert at a position \n4.display employee records\n5.delete_a_record_at_pos\n6.delete at end\n7.delete at front\n8.search\n");
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
        default:
        exit(0);
    }
    }
    return 0;
}