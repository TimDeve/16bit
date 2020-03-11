#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  const char *hexstring = argv[1];

  int color24 = (int)strtol(hexstring, NULL, 0);

  int red = (color24 & 0xFF0000) >> 16;
  int green = (color24 & 0xFF00) >> 8;
  int blue = color24 & 0xFF;

  red = (red * 249 + 1014) >> 11;
  green = (green * 253 + 505) >> 10;
  blue = (blue * 249 + 1014) >> 11;

  int color16 = color16 | (red << 11);
  color16 = color16 | (green << 5);
  color16 = color16 | blue;

  printf("0x%04X\n", color16);
}
