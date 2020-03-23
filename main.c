#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  const char *mode;
  const char *hexstring;

  if (argc == 2) {
    mode = "-h";
    hexstring = argv[1];
  } else if (argc == 3) {
    mode = argv[1];
    hexstring = argv[2];
  } else {
    exit(1);
  }


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

  if (strcmp(mode, "-d") == 0) {
    printf("%i\n", color16);
  } else {
    printf("0x%04X\n", color16);
  }
}
