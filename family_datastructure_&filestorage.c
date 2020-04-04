#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct family_node{
    int age;
    char *gender;
    char *name;
    struct family_node *next;
};
struct family_node *member;
struct family_node *new_member;

void display_family()
{
    struct family_node *iter=member;
    while(iter!=NULL)
    {
        printf("AGE:%d\n",iter->age);
        printf("NAME:%s\n",iter->name);
        printf("GENDER:%s\n",iter->gender);
        iter=iter->next;
    }
    
}
void insert_in_file()
{
    FILE *fptr;
    struct family_node *iter=member;
    fptr=fopen("my_family.txt","w");
    while(iter!=NULL)
    {
        fprintf(fptr,"NAME:\t%s AGE:\t%d GENDER:\t%s",iter->name,iter->age,iter->gender);
        iter=iter->next;
    }
    fclose(fptr);
}
int main()
{
    int count=0;
    printf("enter the number of family members\n");
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
        if (i==0)
        {
            member=malloc(sizeof(struct family_node));
            new_member=member;
        }
        else
        {
            new_member->next=malloc(sizeof(struct family_node));
            new_member=new_member->next;
        }
        new_member->name=(char*)malloc(20* sizeof(char));
        printf("enter the name of family member\n");
        scanf("%s",new_member->name);
        new_member->gender=(char*)malloc(20* sizeof(char));
        printf("enter the gender\n");
        scanf("%s",new_member->gender);
        printf("enter the age\n");
        scanf("%d",&new_member->age);
    }
    new_member->next=NULL;
    display_family();
    insert_in_file();

}
