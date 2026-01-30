#include <stdio.h>
#include <string.h>
#include "student.h"
void update_student()
{
    printf("\n\n\t\t\t\t\t\tUPDATE STUDENT RECORD MODULE\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t****************************\t\t\t\t\t\t\n\n");
    type("Enter the Id of Student whose record is to be updated:\n");
    stu s, rec;

    int flag = 0;
    FILE *file_ptr, *newfile_ptr;
    scanf("%d", &rec.student_id);
    getchar();
    printf("\n");
    file_ptr = fopen("details.txt", "r");                   //opened in read mode
    newfile_ptr = fopen("new_details.txt", "w");            //opened in write mode

    if (file_ptr==NULL || newfile_ptr==NULL){
        printf("error!!!");
    }

    char record[1000];
    while (fgets(record, sizeof(record), file_ptr))
    {
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\n]",            //reads records from file
                            &s.student_id, s.student_name, &s.student_rollno, s.student_section,
                            &s.student_cgpa, s.student_course, s.student_branch, s.student_specialisation);
        if (s.student_id == rec.student_id)                                         //compares the student id 
        {
            flag = 1;                                                               //if matches, asks for new details
            printf("Record Found!!\nEnter new details:\n");

            type("Student Id : ");
            scanf("%d", &s.student_id);
            while ((getchar()) != '\n');

            type("Student Name : ");
            fgets(s.student_name, 100, stdin);
            s.student_name[strcspn(s.student_name, "\n")] = '\0';

            type("Roll Number : ");
            scanf("%d", &s.student_rollno);
            while ((getchar()) != '\n');

            type("Section : ");
            fgets(s.student_section, 5, stdin);
            s.student_section[strcspn(s.student_section, "\n")] = '\0';

            type("Cgpa : ");
            scanf("%f", &s.student_cgpa);
            while ((getchar()) != '\n');

            type("Course : ");
            fgets(s.student_course, 100, stdin);
            s.student_course[strcspn(s.student_course, "\n")] = '\0';

            type("Branch : ");
            fgets(s.student_branch, 100, stdin);
            s.student_branch[strcspn(s.student_branch, "\n")] = '\0';

            type("Specialisation : ");
            fgets(s.student_specialisation, 100, stdin);
            s.student_specialisation[strcspn(s.student_specialisation, "\n")] = '\0';

            fprintf(newfile_ptr, "%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",
                    s.student_id, s.student_name, s.student_rollno, s.student_section,
                    s.student_cgpa, s.student_course, s.student_branch, s.student_specialisation);
        }
        else                                                                        //if id does not match, original record is written to the file
        {
            fputs(record, newfile_ptr);
        }
    }
    fclose(file_ptr);
    fclose(newfile_ptr);

    if (flag == 1)
    {
        remove("details.txt");                                                       //if record found, old file is deleted and newfile is renamed as old file
        rename("new_details.txt", "details.txt");
        printf("Record updated successfully!\n");
    }
    else
    {
        printf("\033[31mRecord not found.\033[0m\n");
        remove("new_details.txt");
    }

    return;
}
