#include <stdio.h>
#include "student.h"
void search_student()
{
    printf("\n\n\t\t\t\t\t\tSEARCH STUDENT RECORD MODULE\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t****************************\t\t\t\t\t\t\n\n");

    stu s, search;
    type("Enter Student Id: ");
    scanf("%d", &search.student_id);
    getchar();
    printf("\n");
    char record[200];
    int flag = 0;

    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");                    //file is opened in read mode
    if (file_ptr==NULL){
        printf("error in opening file!!!");
    }
    while (fgets(record, sizeof(record), file_ptr))
    {
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\t]", &s.student_id, &s.student_name,
            &s.student_rollno, &s.student_section, &s.student_cgpa, &s.student_course, &s.student_branch,&s.student_specialisation);
        if (s.student_id == search.student_id)              //if found, all details are displayed
        {
            flag = 1;
            printf("Record found !!\n\nDetails of student:-\n");
            printf("Student Name: %s\n", s.student_name);
            printf("Roll Number: %d\n", s.student_rollno);
            printf("Section: %s\n", s.student_section);
            printf("Cgpa: %.2f\n", s.student_cgpa);
            printf("Course: %s\n", s.student_course);
            printf("Branch: %s\n", s.student_branch);
            printf("Specialisation: %s\n", s.student_specialisation);
            break;
        }
    }

    if (flag == 0)                                          //if not found, appropriate message is printed
    {
        printf("\033[31mRecord not found.\033[0m\n");
    }
    fclose(file_ptr);
    return;
}