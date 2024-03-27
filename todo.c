#include <stdio.h>
#include <stdlib.h>

typedef struct TODO todo;

struct TODO
{
    char buffer[101];

    // pointer part to access addresses
    todo *next;

    // integer part to count the number of nodes
    int count;
};

// declare start pointer as null in the beginning

todo *start = NULL;
void adjustcount();
void interface();
void seetodo();
void createtodo();
void deletetodo();

int main()
{
    int choice;
    interface();

    while (1)
    {
        system("Color 3f");
        system("clear");
        printf("1. To see your ToDo list \n");
        printf("2. To create new ToDo \n");
        printf("3. To delete your ToDo \n");
        printf("4. To exit \n");
        printf("\n\nEnter your choice\t:\t");

        scanf("%d", &choice);
        while (getchar() != '\n')
            ; // Clear input buffer

        switch (choice)
        {
        case 1:
            seetodo();
            break;
        case 2:
            createtodo();
            break;
        case 3:
            deletetodo();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("\nInvalid Choice: :-(\n");
            while (getchar() != '\n');
        }
    }
    return 0;
}

void interface()
{
    // code for splashcreen
    system("Color 4F");
    printf("\n\n\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("     #############  #######    ######       #######\n");
    printf("          #         #     #    #     #      #     #\n");
    printf("          #         #     #    #      #     #     #\n");
    printf("          #         #     #    #      #     #     #\n");
    printf("          #         #     #    #      #     #     #\n");
    printf("          #         #     #    #     #      #     #\n");
    printf("          #         #######    ######       #######\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("~~~~~~~~~~~~~~~Press S Then Enter To Start~~~~~~~~~~~~~~~\n\n");

    // pause screen until user press any key
    while (getchar() != '\n');
};

void seetodo()
{
    todo *temp = start;
    if (temp == NULL)
    {
        printf("ToDo list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d.) %s\n", temp->count, temp->buffer);
            temp = temp->next;
        }
    }
    while (getchar() != '\n');
}

void createtodo()
{
    char c;
    todo *add, *temp;
    system("clear");

    while (1)
    {
        printf("\nWant to add a new ToDo? Press 'y' for yes and 'n' for no\t:\t");
        c = getchar();
        while (getchar() != '\n')
            ; // Clear input buffer

        if (c == 'n')
            break;
        else
        {
            add = (todo *)calloc(1, sizeof(todo));
            if (add == NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }

            printf("\nType it...\n");
            fgets(add->buffer, 101, stdin);

            if (start == NULL)
            {
                start = add;
                add->count = 1;
                start->next = NULL;
            }
            else
            {
                temp = start;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = add;
            }
            adjustcount();
        }
    }
}

void deletetodo()
{
    int x, deleted = 0;
    todo *del, *prev;
    system("clear");
    printf("\nEnter the ToDo's number that you want to remove. \n\t\t");

    if (start == NULL)
    {
        printf("\n\nThere is no ToDo for today\n\n\n");
    }
    else
    {
        scanf("%d", &x);
        while (getchar() != '\n')
            ; // Clear input buffer

        del = start;
        prev = NULL;
        while (del != NULL)
        {
            if (del->count == x)
            {
                if (prev == NULL)
                { // Deleting first node
                    start = del->next;
                }
                else
                {
                    prev->next = del->next;
                }
                free(del);
                adjustcount();
                deleted = 1;
                break;
            }
            prev = del;
            del = del->next;
        }

        if (!deleted)
        {
            printf("ToDo not found.\n");
        }
    }
    while (getchar() != '\n');
}

void adjustcount()
{
    todo *temp;
    int i = 1;
    temp = start;
    while (temp != NULL)
    {
        temp->count = i++;
        temp = temp->next;
    }
}