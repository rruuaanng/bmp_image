#include <stdio.h>
#include <stdint.h>
#include "include/bmp.h"

int bmp_equalize(BMP_img *img){
    /**
     * @brief 颜色均衡
     * @param 1 图像结构体
     * @return 是否执行
    */
    if(img == NULL) return 0;
    uint8_t red,green,blue;
    uint8_t rmin = 255;
    uint8_t rmax = 0;
    uint8_t gmin = 255;
    uint8_t gmax = 0;
    uint8_t bmin = 255;
    uint8_t bmax = 0;
    for(int pxl = 0;pxl < (img->data_size);pxl+=3){
        red = img->data[pxl + 2];
        green = img->data[pxl + 1];
        blue = img->data[pxl];
        if(red < rmin) rmin = red;
        if(red > rmax) rmax = red;
        if(green < gmin) green = gmin;
        if(green > gmax) green = gmax;
        if(blue < bmin) blue = bmin;
        if(blue > bmax) blue = bmax;
    }
    double rscale = 1.0;
    double gscale = 1.0;
    double bscale = 1.0;
    if(rmax > rmin) rscale = 255.0 / (rmax - rmin);
    if(gmax > gmin) gscale = 255.0 / (gmax - gmin);
    if(bmax > bmin) bscale = 255.0 / (bmax - bmin);
    for(int pxl = 0;pxl < (img->data_size);pxl+=3){
        if(rmax > rmin){
            img->data[pxl + 2] = (int)(rscale * (img->data[pxl + 2] - rmin));
        }
        if(gmax > gmin){
            img->data[pxl + 1] = (int)(gscale * (img->data[pxl + 1] - gmin));
        }
        if(bmax > bmin){
            img->data[pxl] = (int)(bscale * (img->data[pxl] - bmin));
        }
    }
    return 1;
}