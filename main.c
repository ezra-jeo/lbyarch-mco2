#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ROW 3
#define COL 4

extern double* imgCvtGrayIntToDouble(int row, int col, unsigned char *input);

int main(int argc, char *argv[]) { 
    
    unsigned char input[ROW * COL] = {
        64,  89, 114,  84,
        140, 166, 191, 84,
        216, 242,  38, 84
    };


    double* output = imgCvtGrayIntToDouble(ROW, COL, input);


    printf("\nInput: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%hhu ", input[i * COL + j]);
            
        }
        printf("\n");
    }

    printf("\nOutput: \n"); 
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%0.2lf ", output[i * COL + j]);  
        }
        printf("\n");
    }

    return 0;
}