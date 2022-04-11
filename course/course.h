/**
 * @file course.h
 * @brief Header file for course.c containing the function prototypes and struct definations.
 * 
 */

#include "student.h"
#include <stdbool.h>

/**
 * @brief Struct to hold info about a course such as
 * Name of the course
 * Course code
 * List of students 
 * Number of students enrolled
 */
 
typedef struct _course 
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

/**
 * @brief Funtion prototypes of the funcs defined in course.c
 */

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);