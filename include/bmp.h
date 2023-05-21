#ifndef __BMP_IMAGE_H
#define __BMP_IMAGE_H

/* 颜色滤波器色彩 */
#define FRED    2 
#define FGREEN  1
#define FBLUE   0

/* bmp头信息描述结构体 */
#pragma pack(1)
typedef struct{
    unsigned int type;
    unsigned int size;
    unsigned short int reserved1;
    unsigned short int reserved2;
    unsigned int offset;
    unsigned int hdr_size;
    unsigned int width;
    unsigned int height;
    unsigned short int planes;
    unsigned short int bits;
    unsigned int compres;
    unsigned int img_size;
    unsigned int xresolut;
    unsigned int yresolut;
    unsigned int ncolors;
    unsigned int impt_colors;
}BMP_Hdr;

/* bmp图像结构体 */
typedef struct{
    BMP_hdr img_hdr;
    unsigned int data_size;
    unsigned int width;
    unsigned int height;
    unsigned int byte_pixel;
    unsigned char *data;
}BMP_Img;


/* bmp处理函数 */
int bmp_color(BMP_Img *,int); /* 颜色滤波器 */
int bmp_edge(BMP_Img *,int); /* 边缘检测 */
int bmp_equalize(BMP_Img *); /* 颜色均衡 */
int bmp_invert(BMP_Img *); /* 颜色反转*/


#endif // __BMP_IMAGE_H
