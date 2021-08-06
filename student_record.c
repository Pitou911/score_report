#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_INT 0

struct Node{
    int score;
    char *id;
    char *name;
    struct Node *next;
}*first,*last;

void choice_list();
void insert_score();
void search_score();
void delete_score();
void modify_score();
void top_student();
void display_score();

int main()
{
    int choice = 0;

    // Initialize to first roll
    first = (struct Node*)malloc(sizeof(struct Node));
    first->id = "1234";
    first->name = "Pitou";
    first->score = 100;
    first->next = NULL;
    last = first;

    while(1){
        choice_list();
        printf("\nWhat do you want to do?:");
        scanf("%d",&choice);

        if(choice == 1){
            insert_score();
        }else if(choice == 2){            
            search_score();
        }else if(choice == 3){
            delete_score();
        }else if(choice == 4){
            modify_score();
        }else if(choice == 5){
            top_student();
        }else if(choice == 6){
            display_score(first);
        }else{
            exit(0);
        }
    }
}

void choice_list()
{
    printf("\n\nPress:\n\n\n");
    printf("1. Insert the score of student.\n");
    printf("2. Search for the score of student.\n");
    printf("3. Delete the score of student.\n");
    printf("4. Modify the score of student.\n");
    printf("5. Find the top student.\n");
    printf("6. Display all the scores that are saved.\n");
    printf("7. Exit the program.\n");
}

void insert_score()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p;
    p=first;

    //allocate the size of id and name in heap
    temp->id = (char*)malloc(5);
    temp->name = (char*)malloc(20);
    
    // Prompt the user to input the info of the student
    printf("Enter the ID you want to insert: ");
    scanf("%5s", temp->id);
    while(p != NULL){
        if(strcmp(p->id,temp->id) == 0){
            printf("\nThis student ID is already recorded!\n");
            return;
        }else{
            p=p->next;
        }
    }

    printf("Enter the name: ");
    scanf("%20s", temp->name);
    printf("Enter the mark: ");
    scanf("%d",&temp->score);
    if(temp->score > 100){
        printf("\n\t!!!The score can't be more than 100!!!\n");
        printf("Please enter the mark again: ");
        scanf("%d",&temp->score);
    }else if(temp->score < 0){
        printf("\n\t!!!The score can't be less than 0!!!\n");
        printf("Please enter the mark again: ");
        scanf("%d",&temp->score);
    }
    temp->next = NULL;
    last->next = temp;
    last = temp;
    printf("\nRecord successfully inserted!!\n");
    return;
}

void search_score()
{
    struct Node *p;
    p = first;
    /*Use for search */
    char *search;
    search = (char*)malloc(5);
    printf("\nEnter the ID you want to search: ");
    scanf("%5s",search);
    
    while(p != NULL){
        if(strcmp(p->id,search)== 0)
        {
            printf("\n\nInformation: \n");
            printf("Student Id: %s\n", search);
            printf("Student name: %s\n",p->name);
            printf("Student score: %d\n",p->score);
            return;
        }else{
            p=p->next;
        }
    }
    printf("\nStudent ID is not found!!\n");
}

void delete_score()
{
    struct Node *p;
    struct Node *q = NULL;
    p = first;
    /*Use for delete*/
    char *delete;
    delete=(char*)malloc(5);
    printf("Enter the roll you want to delete: ");
    scanf("%5s",delete);
    while(p != NULL)
    {
        if(strcmp(first->id,delete)==0){
            first=first->next;
            free(p);
            printf("\nThe student ID %s was deleted.\n",delete);
            return;
        }else{
            q=p;
            p=p->next;
            if(p != NULL && strcmp(p->id,delete) == 0){
                q->next = p->next;
                free(p);
                printf("\nThe student ID %s was deleted.\n",delete);
                return;
            }
        }

    }
    printf("Not found!!!\n");
}

void modify_score()
{
    struct Node*p;
    p = first;
    char *id_modify;
    id_modify = (char *)malloc(5);
    int modify;

    printf("\nEnter the id you want to modify: ");
    scanf("%5s",id_modify);
    while(p != NULL){
        if(strcmp(p->id,id_modify) == 0){
            printf("\nEnter the new score of student with ID %s: ",id_modify);
            scanf("%d",&modify);
            if(modify > 100 || modify < 0){
                printf("\n\t!!The score can't be more than 100 and less than 0!!\n");
                printf("Please enter the new score again: ");
                scanf("%d",&modify);
            }
            p->score = modify;
            printf("\nModified succesfully!!");
            printf("\nID: %s",p->id);
            printf("\nName: %s",p->name);
            printf("\nScore: %d",p->score);
            return;
        }else{
            p=p->next;
        }
    }
    printf("The student ID %s is not found.\n",id_modify);
}

void top_student()
{
    struct Node *p,*q;
    p = first;
    q = NULL;
    int m = MIN_INT;
    while(p)
    {
        if(p->score > m){
            m = p->score;
            q = p;
        }
        p=p->next;
    }
    printf("\nThe top student is %s with %d score.\n\n",q->name,m);
}

void display_score(struct Node *p)
{
    if(p == NULL){
        printf("No record!!\n");
    }else{
        printf("\n\nID\tName\tScore\n\n");
        while(p != NULL)
        {
            printf("%s\t%s\t%d\n",p->id,p->name,p->score);
            p=p->next;
        }
    }
}
