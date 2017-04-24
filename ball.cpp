/** file: ball.cpp
 ** brief: Ball class - implementation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

#include <iostream>
#include <stdio.h>

Ball::Ball()
: r(0.1), /*x(0), y(0),*/ vx(0.3), vy(-0.1), g(9.8), m(1),
xmin(-1), xmax(1), ymin(-1), ymax(1)
{ }

Ball::Ball(double x, double y){
	this->x = x;
	this->y = y;
}

void Ball::step(double dt)
{
  double xp = x + vx * dt ;
  double yp = y + vy * dt - 0.5 * g * dt * dt ;
  if (xmin + r <= xp && xp <= xmax - r) {
    x = xp ;
  } else {
    vx = -vx ;
  }
  if (ymin + r <= yp && yp <= ymax - r) {
    y = yp ;
    vy = vy - g * dt ;
  } else {
    vy = -vy ;
  }
}

void Ball::display()
{
	std::cout<<x<<" "<<y<<std::endl ;
}

void Ball::setx(double x){
	do{
		std::cout << "\n" << std::endl;
		std::cout << "Enter a value for the ball's coordinate X (-1 < X < 1):" << std::endl;
		std::cin >> x;
		std::cout << "" << std::endl;
	}while(-1 >= x || x >= 1);
	this->x = x;
}

double Ball::getx(){
  return x;
}

void Ball::sety(double y){
	do{
		std::cout << "Enter a value for the ball's coordinate Y (-1 < Y < 1):" << std::endl;
		std::cin >> y;
		std::cout << "\n" << std::endl;
	}while(-1 >= y || y >= 1);
	this->y = y;
}

double Ball::gety(){
  return y;
}