#include <stdio.h>
#include <stdlib.h>

struct retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct retire_info retire;

void retirement (int startAge, double initial, retire working, retire retired) {
  int i = 12 - (working.months % 12);
  int a = (working.months / 12) + startAge;

  while (startAge <= a) {
    while (i < 12) {
      printf("Age %3d month %2d you have $%.2lf\n", startAge, i, initial);
      initial = initial * (working.rate_of_return + 1) + working.contribution;
      i++;
    }
    i = 0;
    startAge++;
  }

  int b = (retired.months / 12) + startAge;
  int j = 0;
  while (startAge < b) {
    while (j < 12) {
      printf("Age %3d month %2d you have $%.2lf\n", startAge, j, initial);
      initial = initial * (retired.rate_of_return + 1) + retired.contribution;
      j++;
    }
    j = 0;
    startAge++;
  }
  return ;
}

int main(void) {
  retire working;
  retire retired;
  int startAge = 27;
  double initial = 21345;
  working.months = 489;
  working.rate_of_return = 0.045/12;
  working.contribution = 1000;
  retired.months = 384;
  retired.rate_of_return = 0.01/12;
  retired.contribution = -4000;
  retirement(startAge, initial, working, retired);
  return 0;
}
  

