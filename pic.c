#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(){
  srand(time(NULL));
  int rT = 255; //this
  int gT = 99; //is
  int bT = 71;//tomato
  int r = 71; //complementary color
  int g = 227;
  int b = 255;
  char line[23];
  float r_over_g = 71.0/227;
  float bT_over_gT = 71.0/99;
  
  int fd = open("pic.ppm",  O_CREAT | O_WRONLY, 0777);
  write(fd, "P3\n", sizeof("P3\n"));
  write(fd, "600 600\n", sizeof("600 600\n"));
  write(fd, "255\n", sizeof("255\n"));

  //drawing
  for( int pixie = 0; pixie < 600 * 600; pixie++){
    if ( rand() % 5){//tomato
      gT = 99 + ((rand() % 70) - 35);
      bT = (int) (gT * bT_over_gT);
      
      sprintf(line, "255 %d %d ", gT, bT);
    
    }else{//not tomate
      g = 227 + ((rand() % 40) - 21);
      r = (int) (b * r_over_g);
      sprintf(line, "%d %d 255 ", r,g );
      
    }
      
      
    

    write(fd, line, sizeof(line));
  }

  close(fd);
    
	


}
