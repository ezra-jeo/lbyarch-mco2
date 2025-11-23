#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utility.c"

extern double* imgCvtGrayIntToDouble(int height, int width, unsigned char *input);

int main(int argc, char *argv[]) { 
    int height, width;
    int i, j; // Loop variables
    unsigned char* input;
    double* output;

    // Input
    scanf("%d %d", &height, &width);
    input = getImg(height, width);

    output = imgCvtGrayIntToDouble(height, width, input);

    printf("\nInput: \n");
    printf("%d %d\n", height, width);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%hhu ", input[i * width + j]);
            
        }
        printf("\n");
    }

    printf("\nOutput: \n"); 
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%0.2lf ", output[i * width + j]);  
        }
        printf("\n");
    }

    return 0;
}