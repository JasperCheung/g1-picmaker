#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(){
  srand(time(NULL));
  int r = 255; //this
  int g = 99; //is
  int b = 71;//tomato
  char line[23];

  float g_over_b = 99/71;
  
  int fd = open("pic.ppm",  O_CREAT | O_WRONLY, 0777);
  write(fd, "P3\n", sizeof("P3\n"));
  write(fd, "600 600\n", sizeof("600 600\n"));
  write(fd, "255\n", sizeof("255\n"));

  //drawing
  for( int pixie = 0; pixie < 600 * 600; pixie++){
    g = 99 + ((rand() % 66) - 33);
    b = (int) g * g_over_b;
      
    sprintf(line, "255 %d %d ", g, b);
    write(fd, line, sizeof(line));
  }

  close(fd);
    
	


}
