#include <stdio.h>
#include <malloc.h>
#include "include/bmp.h"

static int rgb2_gray(char red,char green,char blue){
    return (double)(0.2989 * red 
                  + 0.5870 * green
                  + 0.1140 * blue );
}

int bmp_edge(BMP_img *img,int thrshd){
    /**
     * @brief 边缘检测
     * @param 1 图像结构体
     * @param 2 检测阈值
     * @return 是否执行
    */
    if(img == NULL) return 0;
    int diff = 0;
    int width = img->width;
    int height = img->height;
    char **two_dgray = malloc(sizeof(char *) * height);
    for(int row = 0;row < height;row++){
        two_dgray[row] = malloc(sizeof(char *) * width);    
    }
    for(int row = 0,pxl = 0;row < height;row++){
        for(int col = 0;col < width;col++){
            two_dgray[row][col] = rgb2_gray(img->data[pxl + 2],
                                            img->data[pxl + 1],
                                            img->data[pxl]);
            pxl += 3;
        }
    }
    for(int row = 0,pxl = 0;row < height;row++){
        pxl += 3;
        for(int col = 1;col < width;col++){
            diff = two_dgray[row][col] - two_dgray[row][col - 1];
            if(diff < 0) diff = -diff;
            if(diff > thrshd){
                img->data[pxl + 2] = 255;
                img->data[pxl + 1] = 255;
                img->data[pxl] = 255;
            }else{
                img->data[pxl + 2] = 0;
                img->data[pxl + 1] = 0;
                img->data[pxl] = 0;
            }
            pxl += 3;
        }
    }
    for(int row = 0;row < height;row++){
        free(two_dgray[row]);
    }
    free(two_dgray);
    return 1;
}
