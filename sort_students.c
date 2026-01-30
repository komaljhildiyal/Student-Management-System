#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

void sort_names(){
    stu s[100];
    char record[200];
    int i,j,count=0;

    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");
    if (file_ptr==NULL){
        printf("error in opening file!!!");
    }
    while (fgets(record, sizeof(record), file_ptr))
    {
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\t]",
            &s[count].student_id, &s[count].student_name, &s[count].student_rollno, &s[count].student_section,
            &s[count].student_cgpa, &s[count].student_course, &s[count].student_branch,&s[count].student_specialisation);
            count++;
    }
    fclose(file_ptr);
    //bubble sort is used here to sort records on the basis of names
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if (strcmp(s[j].student_name,s[j+1].student_name)>0){
                stu temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    //prints the sorted records in tabular format
    printf("\n\t\t\t\t\tSORTED STUDENT RECORDS BY STUDENT NAMES\n");
    printf("%-5s %-10s %-25s %-10s %-8s %-6s %-10s %-15s %-20s\n","S.No", "ID", "Name", "Roll No", "Section", "CGPA", "Course", "Branch", "Specialisation");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0;i<count;i++) {
        printf("%-5d %-10d %-25s %-10d %-8s %-6.2f %-10s %-15s %-20s\n",i+1,s[i].student_id,s[i].student_name,s[i].student_rollno,s[i].student_section,s[i].student_cgpa,s[i].student_course,s[i].student_branch,s[i].student_specialisation);
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void sort_rollnumbers(){
    stu s[100];
    char record[200];
    int i,j,count=0;

    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");
    while (fgets(record, sizeof(record), file_ptr))
    {
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\t]",
            &s[count].student_id, &s[count].student_name, &s[count].student_rollno, &s[count].student_section,
            &s[count].student_cgpa, &s[count].student_course, &s[count].student_branch, &s[count].student_specialisation);
            count++;
    }
    fclose(file_ptr);
    //bubble sort is used here to sort records on the basis of roll numbers
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if (s[j].student_rollno>s[j+1].student_rollno){
                stu temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    //prints the sorted records in tabular format
    printf("\n\t\t\t\t\tSORTED STUDENT RECORDS BY STUDENT ROLL NUMBERS\n");
    printf("%-5s %-10s %-25s %-10s %-8s %-6s %-10s %-15s %-20s\n","S.No", "ID", "Name", "Roll No", "Section", "CGPA", "Course", "Branch", "Specialisation");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0;i<count;i++) {
        printf("%-5d %-10d %-25s %-10d %-8s %-6.2f %-10s %-15s %-20s\n",i+1,s[i].student_id,s[i].student_name,s[i].student_rollno,s[i].student_section,s[i].student_cgpa,s[i].student_course,s[i].student_branch,s[i].student_specialisation);
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void sort_cgpa(){
    stu s[100];
    char record[200];
    int i,j,count=0;

    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");
    while (fgets(record, sizeof(record), file_ptr))
    {
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\t]",
            &s[count].student_id, &s[count].student_name, &s[count].student_rollno, &s[count].student_section,
            &s[count].student_cgpa, &s[count].student_course, &s[count].student_branch), &s[count].student_specialisation;
            count++;
    }
    fclose(file_ptr);
    //bubble sort is used here to sort records on the basis of cgpa
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if (s[j].student_cgpa>s[j+1].student_cgpa){
                stu temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    //prints the sorted records in tabular format
    printf("\n\t\t\t\t\tSORTED STUDENT RECORDS BY STUDENT CGPA\n");
    printf("%-5s %-10s %-25s %-10s %-8s %-6s %-10s %-15s %-20s\n","S.No", "ID", "Name", "Roll No", "Section", "CGPA", "Course", "Branch", "Specialisation");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0;i<count;i++) {
        printf("%-5d %-10d %-25s %-10d %-8s %-6.2f %-10s %-15s %-20s\n",i+1,s[i].student_id,s[i].student_name,s[i].student_rollno,s[i].student_section,s[i].student_cgpa,s[i].student_course,s[i].student_branch),s[i].student_specialisation;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}


void sort_students(){
    printf("\n\n\t\t\t\t\t\tSORT STUDENT RECORDS MODULE\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************\t\t\t\t\t\t\n\n\n");
    printf("Sort records on basis of:\n");
    printf("1. Name\n");
    printf("2. Roll Number\n");
    printf("3. Cgpa\n");
    int choice;
    type("Enter your choice: ");
    scanf("%d",&choice);
    getchar();
    system("cls");
    switch (choice){                                //used to implement different operations based on user input
        case 1: 
        sort_names();
        break;
        case 2:
        sort_rollnumbers();
        break;
        case 3:
        sort_cgpa();
        break;
        default:
        printf("\033[31mInvalid choice. Please try again.\033[0m\n");
    }    
return;
}