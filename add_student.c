#include <stdio.h>
#include <string.h>
#include "student.h"

int duplicate_record_check(int id)                          
{
    stu s;
    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");                           //file is opened in read mode
    if (file_ptr==NULL){
        print("error!!!");
        return 0; 
    }
    char record[200];
    while (fgets(record, sizeof(record), file_ptr))                
    {
        fscanf(record, "%d", &s.student_id);                        //reads record from the file
        if (s.student_id == id)
        {
            fclose(file_ptr);
            return 1;
        }
    }
    fclose(file_ptr);
    return 0;
}

void add_student()
{
    FILE *file_ptr;
    file_ptr = fopen("details.txt", "a");                   //file is opened in append mode so that new record is added at the end of file
    if (file_ptr==NULL) {
        printf("Error in opening file!\n");
        return;
    }
    stu s;  

    printf("\n\n\t\t\t\t\t\tADD STUDENT RECORD MODULE\n");
    printf("\t\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\tEnter the following details:\n");
    printf("\t\t\t\t\tx-------------------------------------------x\n");

    do {
        printf("\t\t\t\t\t\t");
        type("Student Id : ");
        scanf("%d", &s.student_id);
        if (duplicate_record_check(s.student_id))
        {
            printf("\n\t\t\t\t\t\tRecord already exists.\n\t\t\t\t\t\tPlease enter a unique student id.\n\n");
        }
    } while (duplicate_record_check(s.student_id));
    while (getchar() != '\n');                                  //clears the buffer after using scanf if present

    printf("\t\t\t\t\t\t");
    type("Student Name : ");
    fgets(s.student_name, 100, stdin);
    s.student_name[strcspn(s.student_name, "\n")] = '\0';           //clears the buffer after fgets if present

    do
    {
        printf("\t\t\t\t\t\t");
        type("Roll Number : ");
        scanf("%d", &s.student_rollno);
        if (s.student_rollno < 0)                                         //roll number must be positive value
        {
            printf("\t\t\t\t\t\t\033[31mInvalid Roll number!! Please enter a valid value.\033[0m\n");
        }
    } while (s.student_rollno < 0);
    while (getchar() != '\n');

    printf("\t\t\t\t\t\t");
    type("Section : ");
    fgets(s.student_section, 5, stdin);
    s.student_section[strcspn(s.student_section, "\n")] = '\0';

    do
    {
        printf("\t\t\t\t\t\t");
        type("Cgpa : ");
        scanf("%f", &s.student_cgpa);
        if (s.student_cgpa < 0 || s.student_cgpa > 10)                  //cgpa must be in between 0 to 10, otherwise error
        {
            printf("\t\t\t\t\t\t\033[31mInvalid CGPA!! Please enter value between 0 and 10.\033[0m\n");
        }
    } while (s.student_cgpa < 0 || s.student_cgpa > 10);
    while (getchar() != '\n');

    printf("\t\t\t\t\t\t");
    type("Course : ");
    fgets(s.student_course, 100, stdin);
    s.student_course[strcspn(s.student_course, "\n")] = '\0';

    printf("\t\t\t\t\t\t");
    type("Branch : ");
    fgets(s.student_branch, 100, stdin);
    s.student_branch[strcspn(s.student_branch, "\n")] = '\0';

    printf("\t\t\t\t\t\t");
    type("Specialisation : ");
    fgets(s.student_specialisation, 100, stdin);
    s.student_specialisation[strcspn(s.student_specialisation, "\n")] = '\0';

    printf("\t\t\t\t\tx-------------------------------------------x\n");

    // Write record to the file with newline
    fprintf(file_ptr, "%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",
            s.student_id, s.student_name, s.student_rollno, s.student_section,
            s.student_cgpa, s.student_course, s.student_branch, s.student_specialisation);

    printf("\n\t\t\t\t\t\tRecord saved successfully!!\n");

    fclose(file_ptr);
}