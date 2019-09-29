#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  int month = 12 - (working.months % 12);
  int retireAge  = (working.months / 12) + startAge;
  int endAge = (retired.months / 12) + retireAge;

  for (;startAge <= endAge; startAge++ ) {
    if( startAge <= retireAge ) {
      for (;month < 12; month++) {
	printf("Age %3d month %2d you have $%.2lf\n", startAge, month, initial);
	initial = initial * (working.rate_of_return + 1) + working.contribution;
      }
      month = 0;
    }
    else {
      for (;month < 12; month++) {
	printf("Age %3d month %2d you have $%.2lf\n", startAge, month, initial);
	initial = initial * (retired.rate_of_return + 1) + retired.contribution;
      }
      month = 0;
    }
  }
  return ;
}

int main(void) {
  int startAge = 27;
  double initial = 21345;
  
  retire_info working;
  working.months = 489;
  working.rate_of_return = 0.045/12;
  working.contribution = 1000;
  
  retire_info retired;
  retired.months = 384;
  retired.rate_of_return = 0.01/12;
  retired.contribution = -4000;
  retirement(startAge, initial, working, retired);
  return 0;
}
  

