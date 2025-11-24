#include <string.h>
#include <stdio.h>

unsigned char* getImg(int height, int width) {
    unsigned char* img = (unsigned char*) malloc(sizeof(unsigned char) * height * width);
    unsigned char buffer;
    int i = 0; // loop variable;

    while (i < height*width && scanf("%hhu", &buffer) == 1) {
        img[i] = buffer;
        i++;
    }

    return img;
}

void printImg(int height, int width, void* img, int type) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (type == 0) {
                unsigned char* int_img = (unsigned char*) img;
                printf("%hhu ", int_img[i * width + j]);
            }
            else if (type == 1) {
                double* double_img = (double*) img;
                printf("%0.2lf ", double_img[i * width + j]);
            }

        }
        printf("\n");
    }
}


