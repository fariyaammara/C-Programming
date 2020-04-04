#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int age;
    int *name;
    struct node *next;
};
struct node *new_pets;
struct node *pet_record;

void print_pet_info()
{
    struct node *iter=pet_record;
    while(iter!=NULL)
    {
        printf("name of pet:%s\n",iter->name);
        printf("age of pet:%d\n\n",iter->age);
        iter=iter->next;
    }
}
void file_write()
{
    struct node * iterator=pet_record;
    FILE *fptr;
    fptr=fopen("pets.txt","w");
    if(fptr==NULL)
    {
        printf("file cant be open\n");
    }
    else
    {
        while(iterator!=NULL)
        {
            fprintf(fptr,"\n Pet Name :\t%s\n Age:\t%d ",iterator->name,iterator->age);
            iterator=iterator->next;
        }
    }
    
fclose(fptr);

}
int main()
{
    int count=0,i;
    printf("enter the no of pets\n");
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
        if(i==0)
        {
            pet_record=malloc(sizeof(struct node));
            new_pets=pet_record;
        }
        else
        {
            new_pets->next=malloc(sizeof(struct node));
            new_pets=new_pets->next;
        }
        new_pets->name=malloc(50* sizeof(char));
        printf("enter name\n");
        scanf("%s",new_pets->name);
        printf("enter age\n");
        scanf("%d",&new_pets->age);
    }
    new_pets->next=NULL;
    printf("\n\n");
    print_pet_info();
    file_write();
}

