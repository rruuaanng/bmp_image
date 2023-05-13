#include <stdio.h>
#include "include/bmp.h"


int bmp_invert(BMP_img *img){
    /**
     * @brief 颜色反转
     * @param 1 图像结构体
     * @return 是否执行
    */
    if(img == NULL) return 0;
    for(int pxl = 0;pxl < (img->data_size);pxl++){
        img->data[pxl] = 255 - (img->data[pxl]);
    }
    return 1;
}