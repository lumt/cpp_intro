#include <iostream>
#include "conversions.h"

using namespace std;

/* Converts fahr to celc */
double celcius_of(int fahr)
{
  return (fahr - 32) * (static_cast<double>(5)/9);
}

/* Converts celc to kelvin */
double kelvin_of(double celc)
{
  return celc + 273.15;
}

