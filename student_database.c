#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct subjects
{
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
};
struct student_struct{
    char *name;
    int roll_no;
    char *course_name;
    struct subjects *marks;
    char grade;
    float percentage;
    struct student *next;
};
struct  login
{
    char name[30];
    char password[20];
    char conf_pwd[20];
    int *next;
};
struct login *temp_admin;
struct login *ptr_admin=NULL;
struct login *user_ptr=NULL;
struct login *head=NULL;
struct student_struct *wrt_students=NULL;

struct login *temp_user;
void writeadmin(struct login *head)
{
    FILE *ppy=fopen("Admin.txt","a");
	int i;
	struct login *temp_admin;
    temp_admin=malloc(sizeof(struct login));
	temp_admin=head;
	if(temp_admin==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	for(i=0;temp_admin!=NULL;i++)
	{
	fprintf(ppy,"%s\t%s\n",temp_admin->name,temp_admin->password);
	temp_admin=temp_admin->next;
	}//for
	}//else
	fclose(ppy);
}
void write_user(struct login *head)
{
    FILE *ptr;
    struct login *temp_user;
    temp_user=malloc(sizeof(struct login));
    temp_user=head;
    ptr=fopen("Users.txt","a");
    if(ptr==NULL)
    {
        printf("\ncant open the file");
    }
    if(temp_user==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
     for(int i=0;temp_user!=NULL;i++)
	{
	fprintf(ptr,"%s\t%s\n",temp_user->name,temp_user->password);
	temp_user=temp_user->next;
	}//for
	}//else
	fclose(ptr);   
    }

void write_students_info(struct student_struct *wrt_students)
{
    FILE *ptr_student=fopen("Students_database.txt","a");
    struct student_struct *temp_info;
    temp_info=malloc(sizeof(struct student_struct));
    temp_info->marks=malloc(sizeof(struct subjects));
    //temp_info=head;
    temp_info=wrt_students;
    if(ptr_student==NULL)
    {
        printf("\ncant open the file");
    }
    if(temp_info==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
     for(int i=0;temp_info!=NULL;i++)
	{
        printf("ROLL NO:\t%d\n",temp_info->roll_no);
            printf("NAME:\t%s\n",temp_info->name);
            printf("COURSE NAME:\t%s\n",temp_info->course_name);
            printf("Physics marks:\t%d\n",temp_info->marks->m1);
            printf("Social marks:\t%d\n",temp_info->marks->m2);
            printf("Maths marks:\t%d\n",temp_info->marks->m3);
            printf("Biology marks:\t%d\n",temp_info->marks->m4);
            printf("c marks:\t%d\n",temp_info->marks->m5);
            printf("GRADE:\t%c\n",temp_info->grade);
            printf("PERCENTAGE:\t%f\n",temp_info->percentage);
        fprintf(ptr_student,"%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%c\t%f\n",temp_info->roll_no,temp_info->name,temp_info->course_name,temp_info->marks->m1,temp_info->marks->m2,temp_info->marks->m3,temp_info->marks->m4,temp_info->marks->m5,temp_info->grade,temp_info->percentage);
        temp_info=temp_info->next;
        //return;
	}//for
}//else
	fclose(ptr_student);   
    }

void admin_registration()
{
    struct login *new_node;
    new_node=malloc(sizeof(struct login));
    int i=0,j=0;
            printf("\nEnter the user name\t");
            scanf("%s",new_node->name);
            printf("\nenter the password\t");
            while(i<9)
            {
                new_node->password[i]=getch();
                if(new_node->password[i]==13)
                {
                    break;
                }
                else
                {
                    printf("*");
                    i++;
                }
            }
            new_node->password[i]='\0';
            printf("\nplease enter your password to reconfirm:\t");
            while(j<9)
                {
                    new_node->conf_pwd[j]=getch();
                    if(new_node->conf_pwd[j]==13)
                        {
                            break;
                        }
                    else
                        {
                            printf("*");
                            j++;
                        }
                }
            new_node->conf_pwd[j]='\0';
            if (strcmp(new_node->conf_pwd,new_node->password)==0)
                {
                    if(ptr_admin==NULL)
                    {
                        ptr_admin=new_node;
                        new_node->next=NULL;
                    }
                else
                    {
                        new_node->next=ptr_admin;
                        ptr_admin=new_node;
                    }
                    writeadmin(ptr_admin);
                }
            else
                {
                    printf("invalid");
                }
}

void display_admin()
{
    struct login *temp;
    temp=malloc(sizeof(struct login));
    temp=ptr_admin;
    printf("the list of active admins are\n");
    while(temp!=NULL)
    {
        printf("%s",temp->name);
        temp=temp->next;
    }
}

void user_registration()
{
    int i=0,j=0;
    struct login *new_node,*temp;
    new_node=malloc(sizeof(struct login));
    printf("\nenter the name:\t");
    scanf("%s",new_node->name);
    printf("\nenter the password:\t");
    while(i<9)
    {
        new_node->password[i]=getch();
        if(new_node->password[i]==13)
        {
            break;
        }
        else
        {
            printf("*");
            i++;
        }
    }
    new_node->password[i]='\0';
    j=0;
    printf("\nplease enter password to confirm password:\t");
    while(j<13)
    {
        new_node->conf_pwd[j]=getch();
        if(new_node->conf_pwd[j]==13)
        {
            break;
        }
        else
        {
            printf("*");
            j++;
            
        }    
    }
    new_node->conf_pwd[j]='\0';
    if(strcmp(new_node->conf_pwd,new_node->password)==0)
    {
        printf("yes");
        if(user_ptr==0)
        {
            user_ptr=new_node;
            new_node->next=NULL;
        }
        else
        {
            new_node->next=user_ptr;
            user_ptr=new_node;
        }
        write_user(user_ptr);
        
    }
}

void display_users()
{
    struct login *temp;
    temp=malloc(sizeof(struct login));
    temp=user_ptr;
    while(temp!=NULL)
    {
        printf("%s",temp->name);
        temp=temp->next;
    }
    
}
void insert_rec()
{
    struct  student_struct *temp;
    struct student_struct *new_node;
    new_node=malloc(sizeof(struct student_struct));
    new_node->marks=malloc(sizeof(struct subjects));
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    printf("enter the roll_no\n");
    scanf("%d",&new_node->roll_no);
    new_node->name=(char*)malloc(20* sizeof(char));
    printf("enter the name\n");
    scanf("%s",new_node->name);
    new_node->course_name=(char*)malloc(20* sizeof(char));
    printf("enter the course_name\n");
    scanf("%s",new_node->course_name);

    printf("enter the physics marks\n");
    scanf("%d",&new_node->marks->m1);
    //scanf("%d",&new_node->physics);


    printf("enter the social_marks\n");
    scanf("%d",&new_node->marks->m2);
    //scanf("%d",&new_node->social);


    printf("enter the maths_marks\n"); 
    //scanf("%d",&new_node->maths);
    scanf("%d",&new_node->marks->m3);
    printf("enter the bio marks\n"); 
    //scanf("%d",&new_node->maths);
    scanf("%d",&new_node->marks->m4);
    printf("enter the c marks\n"); 
    //scanf("%d",&new_node->maths);
    scanf("%d",&new_node->marks->m5);
    int marks1=new_node->marks->m1;
    int marks2=new_node->marks->m2;
    int marks3=new_node->marks->m3;
    int marks4=new_node->marks->m4;
    int marks5=new_node->marks->m5;
    int sum=0,total=500;
    double avg;
    sum=marks1+marks2+marks3+marks4+marks5;
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
    temp=wrt_students;
    /*if(temp==NULL)
    {
        temp=new_node;
        new_node->next=NULL;
        //wrt_students=new_node;
        //write_students_info(wrt_students);
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=wrt_students;
        //new_node=wrt_students;
        //write_students_info(wrt_students);
    }*/
    if(wrt_students==NULL)
    {
        wrt_students=new_node;
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
        wrt_students=new_node;
    }
    write_students_info(wrt_students);
}
    
void edit_rec()
{
    int roll_no;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    struct student_struct *new_node;
    new_node=malloc(sizeof(struct student_struct));
    new_node->marks=malloc(sizeof(struct subjects));
    printf("enter the roll_no to be edited\n");
    scanf("%d",&roll_no);
    temp=wrt_students;
    int flag=0;
    while(temp!=0)
    {
        if(temp->roll_no==roll_no)
        {
            printf("ROLL NO:\t%d\n",temp->roll_no);
            printf("NAME:\t%s\n",temp->name);
            printf("COURSE NAME:\t%s\n",temp->course_name);
            printf("Physics marks:\t%d\n",temp->marks->m1);
            printf("Social marks:\t%d\n",temp->marks->m2);
            printf("Maths marks:\t%d\n",temp->marks->m3);
            printf("Biology marks:\t%d\n",temp->marks->m4);
            printf("c marks:\t%d\n",temp->marks->m5);
            printf("GRADE:\t%c\n",temp->grade);
            printf("PERCENTAGE:\t%f\n",temp->percentage);
            flag=1;
            printf("changes to be made for %d is",temp->roll_no);
            temp->name=(char*)malloc(20* sizeof(char));
            printf("enter the name\n");
            scanf("%s",temp->name);
            temp->course_name=(char*)malloc(20* sizeof(char));
            printf("enter the course_name\n");
            scanf("%s",temp->course_name);

            printf("enter the physics marks\n");
            scanf("%d",&temp->marks->m1);
            //scanf("%d",&temp->physics);


            printf("enter the social_marks\n");
            scanf("%d",&temp->marks->m2);
            //scanf("%d",&temp->social);


            printf("enter the maths_marks\n"); 
            //scanf("%d",&temp->maths);
            scanf("%d",&temp->marks->m3);
            printf("enter the bio marks\n"); 
            //scanf("%d",&temp->maths);
            scanf("%d",&temp->marks->m4);
            printf("enter the c marks\n"); 
            //scanf("%d",&temp->maths);
            scanf("%d",&temp->marks->m5);
            int marks1=temp->marks->m1;
            int marks2=temp->marks->m2;
            int marks3=temp->marks->m3;
            int marks4=temp->marks->m4;
            int marks5=temp->marks->m5;
            int sum=0,total=500;
            double avg;
            sum=marks1+marks2+marks3+marks4+marks5;
            temp->percentage=(float)sum / total * 100.0;
            printf("eeeeeeeeeeeeeeeeeeeeeeeeeeee%f\n",temp->percentage);
            if(temp->percentage>=60)
            {
                temp->grade='A';
            }
            else if(temp->percentage>=50 && temp->percentage<60)
            {   temp->grade='B';
            }
            else if(temp->percentage>=33 && temp->percentage<50)
            {    temp->grade='C';
            }
            else
            {
                temp->grade='F';
            }
            printf("e%c\n",temp->grade);    
            }    
            temp=temp->next;
            }
            if(flag==0)
            {
                printf("user not found");
            }
}
void search()
{
    int roll_no;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    struct student_struct *new_node;
    new_node=malloc(sizeof(struct student_struct));
    new_node->marks=malloc(sizeof(struct subjects));
    printf("enter the roll_no to be searched\n");
    scanf("%d",&roll_no);
    temp=wrt_students;
    int flag=0;
    while(temp!=0)
    {
        if(temp->roll_no==roll_no)
        {
            printf("ROLL NO:\t%d\n",temp->roll_no);
            printf("NAME:\t%s\n",temp->name);
            printf("COURSE NAME:\t%s\n",temp->course_name);
            printf("Physics marks:\t%d\n",temp->marks->m1);
            printf("Social marks:\t%d\n",temp->marks->m2);
            printf("Maths marks:\t%d\n",temp->marks->m3);
            printf("Biology marks:\t%d\n",temp->marks->m4);
            printf("c marks:\t%d\n",temp->marks->m5);
            printf("GRADE:\t%c\n",temp->grade);
            printf("PERCENTAGE:\t%f\n",temp->percentage);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("user not found");
    }
}
void display_all_records()
{
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    temp=wrt_students;
    while(temp!=NULL)
    {
        //printf("    %d  ",temp->data);
        printf("ROLL NO:\t%d\n",temp->roll_no);
        printf("NAME:\t%s\n",temp->name);
        printf("COURSE NAME:\t%s\n",temp->course_name);
        printf("Physics marks:\t%d\n",temp->marks->m1);
        printf("Social marks:\t%d\n",temp->marks->m2);
        printf("Maths marks:\t%d\n",temp->marks->m3);
        printf("Biology marks:\t%d\n",temp->marks->m4);
        printf("c marks:\t%d\n",temp->marks->m5);
        printf("GRADE:\t%c\n",temp->grade);
        printf("PERCENTAGE:\t%f\n",temp->percentage);
        temp=temp->next;
    }
    
}
void display_one()
{
    int roll_no;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    struct student_struct *new_node;
    new_node=malloc(sizeof(struct student_struct));
    new_node->marks=malloc(sizeof(struct subjects));
    printf("enter the roll_no to be seen\n");
    scanf("%d",&roll_no);
    temp=head;
    int flag=0;
    while(temp!=0)
    {
        if(temp->roll_no==roll_no)
        {
            printf("ROLL NO:\t%d\n",temp->roll_no);
            printf("NAME:\t%s\n",temp->name);
            printf("COURSE NAME:\t%s\n",temp->course_name);
            printf("Physics marks:\t%d\n",temp->marks->m1);
            printf("Social marks:\t%d\n",temp->marks->m2);
            printf("Maths marks:\t%d\n",temp->marks->m3);
            printf("Biology marks:\t%d\n",temp->marks->m4);
            printf("c marks:\t%d\n",temp->marks->m5);
            printf("GRADE:\t%c\n",temp->grade);
            printf("PERCENTAGE:\t%f\n",temp->percentage);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("user not found");
    }
    
}
void user_panel()
{
    int choice;
    //display_all//display_one
    while(choice!=0)
    {
        printf("\n1.display all records\n2.display one record\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case(1):
        display_all_records();
        break;
        case(2):
        display_one();
        break;
        default:
        exit(0);
    }
    }

}
/*while(temp->next!=NULL)
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
*/
/*void delete_rec()
{
    int roll_no;
    struct student_struct *temp;
    temp=malloc(sizeof(struct student_struct));
    temp->marks=malloc(sizeof(struct subjects));
    struct student_struct *next_node;
    next_node=malloc(sizeof(struct student_struct));
    next_node->marks=malloc(sizeof(struct subjects));
    printf("enter the rollno to be deleted\n");
    scanf("%d",&roll_no);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->roll_no==roll_no)
        {
            printf("the record has been deleted\n");
            next_node=temp->next;
            if(next_node->next==NULL)
            {
                next_node->next=0;
            }
            temp->next=next_node->next;
            free(next_node);
            return;
        }
        temp=temp->next;
    }
    }*/
void admin_panel()
{
    //insert//edit//search//display_all//display_one
    int choice;
    while(choice!=0)
    {
        printf("\n1.insert record\n2.edit record\n3.search record\n4.display all records\n5.display one record\n6.delete a record\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case(1):
        insert_rec();
        break;
        case(2):
        edit_rec();
        break;
        case(3):
        search();
        break;
        case(4):
        display_all_records();
        break;
        case(5):
        display_one();
        break;
        case(6):
        //delete_rec();
        break;
        default:
        exit(0);
    }
    }
}

void admin_login()
{
    struct login *new_node;
    struct login *temp;
    int i=0,j=0;
    temp=ptr_admin;
    new_node=malloc(sizeof(struct login));
    printf("Enter the username\n");
    scanf("%s",new_node->name);
    printf("enter the password\n");
    while(i<9)
    {
        new_node->password[i]=getch();
        if(new_node->password[i]==13)
        {
            break;
        }
        else
        {
            printf("*");
            i++;
        }
    }
    new_node->password[i]='\0';
    
    while(temp!=NULL)
    {
    if((strcmp(temp->name,new_node->name)==0)&&(strcmp(temp->password,new_node->password)==0))
    {
        printf("\nwelcome %s\n",new_node->name);
        admin_panel();
    }
    else
    {
        printf("user not exist\n");
    }
    temp=temp->next;
    }
}
void user_login()
{
    struct login *temp;
    struct login *new_node;
    int i=0;
    new_node=malloc(sizeof(struct login));
    temp=malloc(sizeof(struct login));
    temp=user_ptr;
    printf("enter the name\n");
    scanf("%s",new_node->name);
    printf("enter the password\n");
    while(i<9)
    {
        new_node->password[i]=getch();
        if(new_node->password[i]==13)
        {
            break;
        }
        else
        {
            printf("*");
            i++;
        }
    }
    new_node->password[i]='\0';
    while (temp!=NULL)
    {
        if(strcmp(new_node->name,temp->name)==0 && strcmp(new_node->password,temp->password)==0)
        {
            printf("welcome %s",new_node->name);
            user_panel();
        }
        else
        {
            printf("invalid user credentials");
        }
        temp=temp->next;
    }
}
/*void check_file()
{
    FILE *check=fopen("Admin.txt","r");
    struct login *temp;
    char *user_name;
    user_name=malloc(20*sizeof(char));
    temp=malloc(sizeof(struct login));
    //temp->marks=malloc(sizeof(struct subjects));
    struct login *new_node;
    new_node=malloc(sizeof(struct login));
    //new_node->marks=malloc(sizeof(struct subjects));
    printf("please enter the username to be checked");
    scanf("%s",user_name);
    fseek(check,0,SEEK_END);
    temp=temp_admin;
    int len=(int)ftell(check);
    int file_check=0;
    if(len<=0)
    {
        printf("file is empty");
        temp=NULL;
        temp_admin=temp;
        file_check=1;
    }
    if(file_check==0)
    {
        rewind(check);
        while(fscanf(check,"\n%s\t%s",temp->name,temp->password));
        {
            if(feof(check))
            {
                break;
            }
            temp->next=malloc(sizeof(struct login));
            temp=temp=>next;
            last=p;
            temp->next=NULL;
        }
    }
}
*/
int main()
{
    int choice,i=0;
    while(choice!=0)
    {
    printf("to login as admin press1\nto login as student press2\nto exit press3\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case(1):
            admin_registration();
            break;
            case(2):
            display_admin();
            break;
            case(3):
            user_registration();
            break;
            case(4):
            display_users();
            break;
            case(5):
            admin_login();
            break;
            case(6):
            user_login();
            break;
            case(7):
            user_panel();//display_all//display_one
            break;
            case(8):
            admin_panel();//insert//edit//search//display_all//display_one
            break;
        }
    }
}
