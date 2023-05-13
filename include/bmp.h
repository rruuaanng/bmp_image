#ifndef __BMP_IMAGE_H
#define __BMP_IMAGE_H

/* 颜色滤波器色彩 */
#define FRED    2 
#define FGREEN  1
#define FBLUE   0

/* bmp头信息描述结构体 */
#pragma pack(1)
typedef struct __hdr{
    __UINT16_TYPE__ type;
    __UINT32_TYPE__ size;
    __UINT16_TYPE__ reserved1;
    __UINT16_TYPE__ reserved2;
    __UINT32_TYPE__ offset;
    __UINT32_TYPE__ hdr_size;
    __UINT32_TYPE__ width;
    __UINT32_TYPE__ height;
    __UINT16_TYPE__ planes;
    __UINT16_TYPE__ bits;
    __UINT32_TYPE__ compres;
    __UINT32_TYPE__ img_size;
    __UINT32_TYPE__ xresolut;
    __UINT32_TYPE__ yresolut;
    __UINT32_TYPE__ ncolors;
    __UINT32_TYPE__ impt_colors;
}BMP_hdr;

/* bmp图像结构体 */
struct __bmp_img{
    BMP_hdr img_hdr;
    __UINT32_TYPE__ data_size;
    __UINT32_TYPE__ width;
    __UINT32_TYPE__ height;
    __UINT32_TYPE__ byte_pixel;
    __UINT8_TYPE__ *data;
};
typedef struct __bmp_img BMP_img;

/* bmp处理函数 */
int bmp_color(BMP_img *,int); /* 颜色滤波器 */
int bmp_edge(BMP_img *,int); /* 边缘检测 */
int bmp_equalize(BMP_img *); /* 颜色均衡 */
int bmp_invert(BMP_img *); /* 颜色反转*/


#endif // __BMP_IMAGE_H
