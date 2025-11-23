#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "./utils/utility.c"

extern double* imgCvtGrayIntToDouble(int height, int width, unsigned char *input);

unsigned char* generateRandomImage(int height, int width) {
    unsigned char* img = (unsigned char*) malloc(sizeof(unsigned char) * height * width);
    for (int i = 0; i < height * width; i++) {
        img[i] = rand() % 256;
    }
    return img;
}

int main() {
    int sizes[3] = {10, 100, 1000}; // Image sizes: 10x10, 100x100, 1000x1000
    int runs = 30;

    printf("Starting benchmark for imgCvtGrayIntToDouble...\n");
    fflush(stdout);

    for (int s = 0; s < 3; s++) {
        int height = sizes[s];
        int width = sizes[s];

        unsigned char* input = generateRandomImage(height, width);
        double totalTime = 0.0;

        for (int r = 0; r < runs; r++) {
            LARGE_INTEGER freq, start, end;
            QueryPerformanceFrequency(&freq);
            QueryPerformanceCounter(&start);

            double* output = imgCvtGrayIntToDouble(height, width, input);

            QueryPerformanceCounter(&end);

            double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
            totalTime += elapsed;
        }

        double averageTime = totalTime / runs;
        printf("Size: %dx%d, Average runtime for %d runs: %f seconds\n",
               height, width, runs, averageTime);
        fflush(stdout);

        free(input);
    }

    printf("Benchmark complete.\n");
    fflush(stdout);

    return 0;
}
