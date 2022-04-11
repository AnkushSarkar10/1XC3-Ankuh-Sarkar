/**
 * @file course.c
 * @brief 
 * This file provides us functions to Enroll Students
 * in courses, print courses, get student with the highest 
 * average and get a list of students passing a course. 
 *
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Enrolls a student into a course
 * 
 * @param course The course to enroll the student in
 * @param student The student to be enrolled
 */

void enroll_student(Course *course, Student *student)
{
  course->total_students++; // adds 1 to the total number of syudents in that course  
  
  // if the course was empty, then it creates a list to hold one student
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  // else it realocates memory to store an aditional student
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }

  // inserts the new student as the last element of the array
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints information about the course in the following format
 *  Name : Name_of_the_course
 *  Code : Course_code
 *  Total students : total_number_of_students
 *  *****************************************************************
 *  
 *  <List of all students>
 * 
 * @param course The course whose information needs to be printed
 */

void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief returns the pointer to the student with the highest average in a given course
 * 
 * @param course The course you are finding the top student in
 * @return Student* Pointer to the top student in that course
 */

Student* top_student(Course* course)
{
  // If no students in the course then it returns NULL 
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  // goes through all the students to find the student with max avg
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }
  }
  
  // returns pointer to the student with the highest avg
  return student;
}

/**
 * @brief returns the students passing in a course
 * 
 * @param course Course to get passing students from
 * @param total_passing pointer to an int storing the number of students passing
 * @return Student* List of passing students
 */


Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  // This gets the number of student with an average greater than 50
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  // Creates a list of the size of people passing the given course
  passing = calloc(count, sizeof(Student));

  // Populates the list
  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }
  
  *total_passing = count;

  // Returns List 
  return passing;
}