#include <stdio.h>

int dot_product_slow(int A[], int B[], int length);

int main(int argc, char *argv)
{
  int A[3] = {4,5,6};
  int B[3] = {7,8,9};
  int result = 0;

  for (int i = 0; i < 1000000000; i++)
  {
    result = dot_product_slow(A, B, 3);
  }
   
}
 
int dot_product_slow(int A[], int B[], int length)
{
  int result = 0;
  for (int i = 0; i < length; i++)
  {
    result += A[i] * B[i];
  }
  return result;
}
