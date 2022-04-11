/**
 * @file student.h
 * @brief Header file for student.c containing the function prototypes and struct definations.
 * 
 */

/**
 * @brief Struct to hold info about a student such as
 * first name
 * last name
 * student id 
 * 
 */

typedef struct _student 
{ 
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades; 
  int num_grades; 
} Student;

/**
 * @brief Funtion prototypes of the funcs defined in student.c
 */

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
