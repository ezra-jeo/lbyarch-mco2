#include <string.h>
#include <stdio.h>

unsigned char* getImg(int height, int width) {
    unsigned char* img = (unsigned char*) malloc(sizeof(char) * height * width);
    unsigned char buffer;
    int i = 0; // loop variable;

    while (i < height*width && scanf("%hhu", &buffer) == 1) {
        img[i] = buffer;
        i++;
    }

    return img;
}



