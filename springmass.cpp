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
  double kinetic = 0.5 * mass * velocity.norm2() ;
  double potential = gravity * mass * (position.y - ymin - radius) ;
  energy = kinetic + potential ;

  return energy ;
}

void Mass::step(double dt)
{
  Vector2 accel = force / mass ;
  Vector2 position_ = position + dt * velocity + 0.5 * accel * (dt * dt) ;

  if (xmin + radius <= position_.x &&
      position_.x <= xmax - radius) {
    position.x = position_.x ;
    velocity.x = velocity.x + dt * accel.x ;
  } else {
    velocity.x = - velocity.x ;
  }

  if (ymin + radius <= position_.y &&
      position_.y <= ymax - radius) {
    position.y = position_.y ;
    velocity.y = velocity.y + dt * accel.y ;
  } else {
    velocity.y = - velocity.y ;
  }
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2),
naturalLength(naturalLength), stiffness(stiffness), damping(damping)
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

  Vector2 v1 = mass2->getVelocity() ;
  Vector2 v2 = mass1->getVelocity() ;
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  double length = u.norm() ;
  u = u / u.norm() ;
  double elongationVelocity = dot(v2 - v1, u) ;
  double force = (naturalLength - length) * stiffness + elongationVelocity * damping ;
  F = force * u ;

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
  // for(int i = 0; i < (this->masses).size(); ++i)
  // {
  //   std::cout << masses[i].getPosition().x << " " << masses[i].getPosition().y << std::endl ;
  // }

  for (int i = 0 ; i < (int)masses.size() ; ++i) {
    std::cout<<masses[i] ;
  }
  for (int i = 0 ; i < (int)springs.size() ; ++i) {
    std::cout<<springs[i] ;
  }
  std::cout<<" en:"<<getEnergy() ;
  std::cout<<std::endl ;
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

  for (int i = 0 ; i < (int)masses.size() ; ++i) {
    energy += masses[i].getEnergy(gravity) ;
  }
  for (int i = 0 ; i < (int)springs.size() ; ++i) {
    energy += springs[i].getEnergy() ;
  }

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ;

  for (int i = 0 ; i < (int)masses.size() ; ++i) {
    masses[i].setForce(g * masses[i].getMass()) ;
  }
  for (int i = 0 ; i < (int)springs.size() ; ++i) {
    Vector2 force = springs[i].getForce() ;
    springs[i].getMass1()->addForce(-1 * force) ;
    springs[i].getMass2()->addForce(+1 * force) ;
  }
  for (int i = 0 ; i < (int)masses.size() ; ++i) {
    masses[i].step(dt) ;
  }
}

int SpringMass::addMass(Mass m)
{
  masses.push_back(m) ;
  return (int)masses.size() -1 ;
}

void SpringMass::addSpring(int i, int j, double length, double stiffness)
{
  springs.push_back(Spring(&masses[i], &masses[j], length, stiffness)) ;
}

Mass SpringMass::getMass(int i)
{
  return this->masses[i];  
}