#include "stb-master/stb_image.h"
#include "CGL/include/CGL/CGL.h"
#include "texture.h"

int x = 100;
int y = 100;
int n = 3;

// loading image
// x = width, y = height, n = # 8-bit components per pixel
unsigned char *image1 = stbi_load("a.jpg", &x, &y, &n, 0);
unsigned char *image2 = stbi_load("b.jpg", &x, &y, &n, 0);
unsigned char *image3 = stbi_load("c.jpg", &x, &y, &n, 0);


// convert the image into texture
texture t1 = texture(image1);
texture t2 = texture(image2);
texture t3 = texture(image3);


// create sphere
sphere s1 = sphere(Vector3D(), t1);
sphere s2 = sphere(Vector3D(), t2);
sphere s3 = sphere(Vector3D(), t3);

// output it to file
