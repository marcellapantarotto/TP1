/** file: test-srpingmass.cpp
 ** brief: Tests the spring mass simulation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"
#include <iostream>

int main(int argc, char** argv)
{
  const double mass = 0.05 ;
  const double radius = 0.02 ;
  const double naturalLength = 0.95 ;
  const double stiffness = 1;
  const double damping = 0.01;
  const double dt = 1.0/30 ;

  Mass m1(Vector2(-.5,0), Vector2(), mass, radius) ;
  Mass m2(Vector2(+.5,0), Vector2(), mass, radius) ;

  masses_t masses;
  masses.push_back(&m1);
  masses.push_back(&m2);
  Spring spring(&m1, &m2, naturalLength, stiffness, damping);
  SpringMass springmass(masses, &spring, MOON_GRAVITY);

  for (int i = 0 ; i < 100 ; i++) {
    springmass.step(dt) ;
    springmass.display() ;
  }

  return 0 ;
}