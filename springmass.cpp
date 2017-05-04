/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

Mass::Mass()
: position(), velocity(), force(), mass(1), radius(1)
{ }

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
: position(position), velocity(velocity), force(), mass(mass), radius(radius),
xmin(-1),xmax(1),ymin(-1),ymax(1)
{ }

void Mass::setForce(Vector2 f)
{
  force = f ;
}

void Mass::addForce(Vector2 f)
{
  force = force + f ;
}

Vector2 Mass::getForce() const
{
  return force ;
}

Vector2 Mass::getPosition() const
{
  return position ;
}

Vector2 Mass::getVelocity() const
{
  return velocity ;
}

double Mass::getRadius() const
{
  return radius ;
}

double Mass::getMass() const
{
  return mass ;
}

double Mass::getEnergy(double gravity) const
{
  double energy = 0 ;

/* INCOMPLETE: TYPE YOUR CODE HERE 

  height = radius /position(centro)

  e_potential = mass * gravity * height;
  e_kinetics = (mass * |velocity|^2) / 2;
  energy = e_potential + e_kinetics;

*/

  return energy ;
}

void Mass::step(double dt)
{

/* INCOMPLETE: TYPE YOUR CODE HERE

  F = m * a -> a = m/F;
  S = S0 + velocity * dt (a*dt^2)/2;
  velocity = velocity0 + a*dt;


*/

}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */
/*
Spring::Spring()
: mass1(), mass2(), naturalLength(), stiffness(), damping()
{ }*/

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2), naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{ }

Mass * Spring::getMass1() const
{
  return mass1 ;
}

Mass * Spring::getMass2() const
{
  return mass2 ;
}

Vector2 Spring::getForce() const
{
  Vector2 F ;

/* INCOMPLETE: TYPE YOUR CODE HERE */

  return F ;
}

double Spring::getLength() const
{
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  return u.norm() ;
}

double Spring::getEnergy() const {
  double length = getLength() ;
  double dl = length - naturalLength;
  return 0.5 * stiffness * dl * dl ;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
  os<<"("
  <<m.getPosition().x<<","
  <<m.getPosition().y<<")" ;
  return os ;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
  return os<<"$"<<s.getLength() ;
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

SpringMass::SpringMass(double gravity)
: gravity(gravity)
{ }

void SpringMass::display()
{
  // f = m * a;

/* INCOMPLETE: TYPE YOUR CODE HERE */

}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

/* INCOMPLETE: TYPE YOUR CODE HERE */

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ;

/* INCOMPLETE: TYPE YOUR CODE HERE */
  masses[i].setForce(g * masses[i].getMass());
  springs[i].getMass1()->addForce(-1 * force);
  springs[i].getMass2()->addForce(+1 * force);
  step();

}


/* INCOMPLETE: TYPE YOUR CODE HERE */

void SpringMass::addMass()
{   //use method push_back()
  return (int)masses.size() -1;
}

void SpringMass::addSpring()
{
  //use method push_back()
}


