#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  
  char matrix[10][10];
  int ch;
  int row = 0;
  int col = 0;
  while ((ch = fgetc(f)) != EOF) {
    if (col < 10) {
      if (ch == '\n') {
	perror("Line is too short.\n");
	return EXIT_FAILURE;
      }	
      matrix[row][col] = ch;
      col++;
    }
    else { // col = 10
      if (ch != '\n') {
	perror("Line is too long.\n");
	return EXIT_FAILURE;
      }
      row++;
      if (row == 10) {
	break;
      }
      col = 0;
    }
  }
  if (row < 9 || col < 10) {
    perror("File is too short.\n");
    return EXIT_FAILURE;
  }
  if ((ch = fgetc(f)) != EOF) {
    perror("File is too long.\n");
    return EXIT_FAILURE;
  }
     
  for (int i = 0; i < 10; i++) {
    for (int j = 9; j >= 0; j--) {
      printf("%c", matrix[j][i]);
    }
    printf("\n");
  }
  
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
