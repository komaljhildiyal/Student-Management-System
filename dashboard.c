#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "student.h"                        //student.h is a header file that contains the definitions of all the user defined functions created
int main()
{
    int choice;
    while (1){                                  //used to create a continuous user interface
    system("cls");                           //comes under STDLIB.H and is used to clear the screen
    printf("\n\n\t\t\t\t\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t\t Dashboard\t\t\t\t\t\t\n");
    printf("=====================================================================================================================================\n\n");
    printf("1.\tAdd Student record\n");
    printf("2.\tUpdate Student record\n");
    printf("3.\tDelete Student record\n");
    printf("4.\tView all records\n");
    printf("5.\tSearch Student\n");
    printf("6.\tSort all records\n");
    printf("7.\tExit program\n\n");
    printf("=====================================================================================================================================\n\n");
    type("Enter your choice(1-7):\t");      //here, type is a function created using sleep from windows.h and fflush(stdout) to create a typing effect
    scanf("%d", &choice);
    getchar();

    switch (choice)                        //switchcase is used to execute different operations based on user input
    {
    case 1:
        system("cls");
        add_student();
        break;
    case 2:
        system("cls");
        update_student();
        break;
    case 3:
        system("cls");
        delete_student();
        break;
    case 4:
        system("cls");
        viewall_students();
        break;
    case 5:
        system("cls");
        search_student();
        break;
    case 6:
        system("cls");
        sort_students();
        break;
    case 7:
        system("cls");
        type("Exiting the program. Toodles!!!  \n");
        return 0;
    default:
        printf("\033[31mInvalid Choice. Please try again.\033[0m\n");        //here, colour codes are used to print the message in red
    }
    
    printf("\nPress Enter to return to the dashboard...");                                          
    getchar();
}
    return 0;
}