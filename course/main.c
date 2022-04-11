/**
 * @file main.c
 * @brief Demonstrates creating courses and students.
 * 
 */

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

int main()
{
  srand((unsigned) time(NULL));

  // Create course math101 using the Course struct
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // enrolling 20 random stundents 
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  // print course info
  print_course(MATH101);

  // Get student with max avg
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // Get number of students passing the course and printing that out
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}