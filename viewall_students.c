#include <stdio.h>
#include <string.h>
#include "student.h"

void viewall_students() {
    printf("\n\n\t\t\t\t\t\tVIEW ALL STUDENTS RECORD MODULE\n");
    printf("\t\t\t\t\t\t*******************************\n\n");

    stu s;
    FILE *file_ptr;
    file_ptr = fopen("details.txt", "r");                   //file is opened in read mode
    if (file_ptr==NULL){
        printf("error in opening file!!!");
    }
    char record[300];
    int count = 1;

    //prints record in tabular format
    printf("%-5s %-10s %-25s %-10s %-8s %-6s %-10s %-15s %-20s\n",
        "S.No", "ID", "Name", "Roll No", "Section", "CGPA", "Course", "Branch", "Specialisation");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    while (fgets(record, sizeof(record), file_ptr)) {                   //one by one records are read and then printed in tabular format
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\t]",
            &s.student_id,s.student_name,&s.student_rollno,s.student_section,&s.student_cgpa,s.student_course,s.student_branch,s.student_specialisation);
        printf("%-5d %-10d %-25s %-10d %-8s %-6.2f %-10s %-15s\n",count++,
            s.student_id,s.student_name,s.student_rollno,s.student_section,s.student_cgpa,s.student_course,s.student_branch,s.student_specialisation);
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    fclose(file_ptr);
    
    return;
}