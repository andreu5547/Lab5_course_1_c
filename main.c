#include <stdio.h>
#include "StringVectors.h"
#include "calc.h"

#define INIT_LENGTH 10

int main() {
    // num 1
    CVector* s1 = init_cvector(INIT_LENGTH);
    CVector* s2 = init_cvector(INIT_LENGTH);
    puts("Input string 1:");
    input_cvector(s1);
    puts("Input string 2:");
    input_cvector(s2);

    printf("Position: %d", find_pos_first_sym_ve1_in_ve2(s1, s2));

    free_CV(s1);
    free_CV(s2);

    //num 2 calc
    puts("\nINPUT YOUR DATA FOR CALC");
    return calk_main();
}