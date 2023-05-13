#include <stdio.h>
#include "include/bmp.h"


int bmp_color(BMP_img *img,int color){
    /**
     * @brief 颜色滤波器
     * @param 1 图像结构体
     * @param 2 待过滤的颜色
     * @return 是否执行
    */
    if(img == NULL) return 0;
    for(int pxl = color;pxl < (img->data_size);pxl++){
        if((pxl % 3) != color){
            img->data[pxl] = 0;
        }
    }
    return 1;
}