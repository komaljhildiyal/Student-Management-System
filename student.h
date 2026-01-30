#ifndef STUDENT_H
#define STUDENT_H
void type();
void add_student();
typedef struct student_details{
    int student_id;
    char student_name[100];
    int student_rollno;
    char student_section[5];
    float student_cgpa;
    char student_course[100];
    char student_branch[100];
    char student_specialisation[100];
}stu;

void update_student();
void delete_student();
void viewall_students();
void search_student();
void sort_students();
#endif