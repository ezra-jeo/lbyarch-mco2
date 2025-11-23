#include <stdlib.h>

double* imgCvtGrayIntToDouble(int height, int width, unsigned char *input) {
    int i, j;
    double* output = (double*) malloc(sizeof(double) * height * width);

    for (i = 0; i < height*width; i++) {
        double buffer = (double) input[i];
        
        buffer /= 255.0;

        output[i] = buffer;
    }

    return output;

}