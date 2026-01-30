#include<stdio.h>
#include "student.h"
void delete_student(){
    printf("\n\n\t\t\t\t\t\tDELETE STUDENT RECORD MODULE\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t****************************\t\t\t\t\t\t\n\n");
    stu s,rec;

    int flag=0;
    FILE *file_ptr, *newfile_ptr;
    file_ptr=fopen("details.txt","r");                              //opened in read mode
    newfile_ptr=fopen("neww_details.txt","w");                      //opened in write mode

    if (file_ptr==NULL || newfile_ptr==NULL){
        printf("error!!!");
    }

    type("Enter the Id of Student whose record is to be deleted:\n");
    scanf("%d",&rec.student_id);
    getchar();
    printf("\n");

    char record[1000];
    while (fgets(record,sizeof(record),file_ptr)){
        fscanf(record, "%d\t%[^\t]\t%d\t%[^\t]\t%f\t%[^\t]\t%[^\t]\t%[^\n]",                //reads record from file
                            &s.student_id, s.student_name, &s.student_rollno, s.student_section,
                            &s.student_cgpa, s.student_course, s.student_branch, s.student_specialisation);
        if (s.student_id==rec.student_id){                                                  //if record present, iteration skipped
            flag=1;
            continue;
        }
        else{                                                                               //if record not present, record is added to newfile
            fputs(record,newfile_ptr);
        }
    }
    fclose(file_ptr);
    fclose(newfile_ptr);
    
    
    if (flag==1){   
        remove("details.txt");                                                              //if record found, old file is deleted and newfile is renamed as old file
        rename("neww_details.txt","details.txt");
        printf("Record deleted successfully!\n");
    }
    else{
        printf("\033[31mRecord not found.\033[0m\n");                                       //prints message in red
        remove("neww_details.txt");
    }
    
    return;
}
