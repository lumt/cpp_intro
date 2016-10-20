#include <iostream>
#include <cmath>
#include "stats.h"

using namespace std;

/* average functions*/
double average(float num1, float num2)
{
  return ((num1 + num2)/2);
}

double average(float num1, float num2, float num3)
{
  return ((num1 + num2 + num3)/3);
}

double average(float num1, float num2, float num3, float num4)
{
  return ((num1 + num2 + num3 + num4)/4);
}

/* standard deviation functions*/
double standard_dev(float num1, float num2)
{
  double avg = average(num1, num2);
  return sqrt((pow((num1 - avg),2)+pow((num2 - avg),2))/2);
}

double standard_dev(float num1, float num2, float num3)
{
  double avg = average(num1, num2, num3);
  return sqrt((pow((num1-avg),2)+pow((num2-avg),2)+pow((num3-avg),2))/3);
}
  
double standard_dev(float num1, float num2, float num3, float num4)
{
  double avg = average(num1, num2, num3, num4);
  return sqrt((pow((num1-avg),2)+pow((num2-avg),2)+pow((num3-avg),2)+pow((num4-avg), 2))/4);
}
