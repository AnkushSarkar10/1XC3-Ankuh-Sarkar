/**
 * @file student.c
 * @brief
 * This files defines functions to add grade to a student,
 * Calculate the average of a student, print information of 
 * a student and generate a random student
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Append grade to a student
 * 
 * @param student the student you want to append the grade to 
 * @param grade the grade to add
 */
void add_grade(Student* student, double grade)
{
  // increase the number of grades the student has by one
  student->num_grades++;

  // if student did not have any grades before, make a list to store a grade.
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  // else reallocate memory to store another grade in the array
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  // add the grade in the end of the list
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Calculate the average of a student
 * 
 * @param student Student to find the average of
 * @return students avg
 */

double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  //adds all the grades of a student
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  //returns the average
  return total / ((double) student->num_grades);
}

/**
 * @brief Print info regaurding a student such as
 *  Name: name_of_the_student
 *  ID: student_id
 *  Grades: list_of_the_grades_of_the_student
 * 
 * @param student 
 */

void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Genarates a random student with a given number of grades
 * 
 * @param grades number of grades the student will have 
 * @return Student* pointer to the randomly generated student
 */

Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  // creats a random first and last name
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  // makes a random student number
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  // make the grades array and fill it with random numbers
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  // Return random student
  return new_student;
}