/** file: ball.h
 ** brief: Ball class
 ** author: Andrea Vedaldi
 **/

#ifndef __ball__
#define __ball__

#include "simulation.h"

class Ball : public Simulation
{
public:
  // Constructors and member functions
  Ball() ;
  void step(double dt) ;
  void display() ;

  // Get and Fet of the position of the ball
  void setx(double _x);
  double getx();
  void sety(double _y);
  double gety();

protected:
  // Data members
  // Position and velocity of the ball
  double x ;
  double y ;
  double vx ;
  double vy ;

  // Mass and size of the ball
  double m ;
  double r ;

  // Gravity acceleration
  double g ;

  // Geometry of the box containing the ball
  double xmin ;
  double xmax ;
  double ymin ;
  double ymax ;
} ;

void Ball::setx(double _x){
  x = _x;
}

double Ball::getx(){
  return x;
}

void Ball::sety(double _y){
  y = _y;
}

double Ball::gety(){
  return y;
}

#endif /* defined(__ball__) */
