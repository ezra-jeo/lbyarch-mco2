#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./utils/utility.c"

// remove this since its already in main
extern double* imgCvtGrayIntToDouble(int height, int width, unsigned char *input);

// remove this since its already in main
double* imgCvtGrayIntToDouble_C(int height, int width, unsigned char *input) {
    int size = height * width;
    double* output = (double*) malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++) {
        output[i] = input[i] / 255.0;  
    }
    return output;
}

unsigned char* generateRandomImage(int height, int width) { //add this to main.c
    unsigned char* img = malloc(sizeof(unsigned char) * height * width);
    for (int i = 0; i < height * width; i++) {
        img[i] = rand() % 256;
    }
    return img;
}

int main() {  //make this benchmark func
    int sizes[3] = {10, 100, 1000};
    int runs = 30;

    printf("Benchmarking C vs Assembly implementation...\n");

    for (int s = 0; s < 3; s++) {
        int height = sizes[s];
        int width = sizes[s];

        unsigned char* input = generateRandomImage(height, width);
        double totalC = 0.0, totalASM = 0.0;

        // Benchmark C 
        for (int r = 0; r < runs; r++) {
            clock_t start = clock();
            double* outC = imgCvtGrayIntToDouble_C(height, width, input);
            clock_t end = clock();
            totalC += (double)(end - start) / CLOCKS_PER_SEC;
            free(outC);
        }

        // Benchmark ASM 
        for (int r = 0; r < runs; r++) {
            clock_t start = clock();
            double* outASM = imgCvtGrayIntToDouble(height, width, input);
            clock_t end = clock();
            totalASM += (double)(end - start) / CLOCKS_PER_SEC;
        }

        printf("Image Size: %dx%d\n", height, width);
        printf("  C implementation avg:   %f seconds\n", totalC / runs);
        printf("  ASM implementation avg: %f seconds\n", totalASM / runs);
        printf("----------------------------------------------------\n");

        free(input);
    }

    printf("Benchmark complete.\n");
    return 0;
}
