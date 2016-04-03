// TRAIN GAME SOLVER
// PROBLEM SET 1: EXTRA SPICY
// AUTHOR: GUY SEGEV

#include <stdio.h>
#include <stdlib.h>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

float perform_operation (float numA, float numB, int op);
void calculate (int num1, int num2, int num3, int num4, int op1, int op2, int op3);
void find_combinations (int num1, int num2, int num3, int num4);
void print_answer(int num1, int num2, int num3, int num4, int op1, int op2, int op3);

int main (int argc, char *argv[]){
   int num1, num2, num3, num4;

   printf ("enter a 4 integers separated by spaces: ");
   scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

   find_combinations(num1, num2, num3, num4);

   return EXIT_SUCCESS;
}

void print_answer(int num1, int num2, int num3, int num4, int op1, int op2, int op3){
   char allOps[5]; // To be used for printing final answer
   allOps[0] = '+';
   allOps[1] = '-';
   allOps[2] = '*';
   allOps[3] = '/';
   allOps[4] = 0;

   printf ("%d %c ", num1, allOps[op1]);
   printf ("%d %c ", num2, allOps[op2]);
   printf ("%d %c ", num3, allOps[op3]);
   printf ("%d = 10\n", num4);
}

// Applies operation to two numbers
float perform_operation (float numA, float numB, int op){
   float solution = 0;

   if (op == ADD){
      solution = numA + numB;
   } else if (op == SUB){
      solution = numA - numB;
   } else if (op == MUL){
      solution = numA * numB;
   } else if (op == DIV){
      if (numB != 0){
         solution = numA / numB;
      } else {
         // do something
        solution = 0;
      }
   }

   return (solution);
}

void calculate (int num1, int num2, int num3, int num4, int op1, int op2, int op3){
   float part1, part2, solution;

   part1 = perform_operation (num1, num2, op1);
   part2 = perform_operation (part1, num3, op2);
   solution = perform_operation (part2, num4, op3);

   if (solution == 10){
      print_answer(num1, num2, num3, num4, op1, op2, op3);
   }
}

void find_combinations(int num1, int num2, int num3, int num4){
   int op1, op2, op3;
   op1 = 0;
   op2 = 0;
   op3 = 0;

   while (op1 < 4){
      while (op2 < 4){
         while (op3 < 4){
            calculate (num1, num2, num3, num4, op1, op2, op3);
            // printf ("%d  %d  %d\n", op1, op2, op3); // for testing
            op3 ++;
         }
         op2 ++;
         op3 = 0;
      }
      op1 ++;
      op2 = 0;
   }
}



