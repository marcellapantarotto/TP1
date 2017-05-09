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

  double h = position.y - radius - ymin;
  double e_potential = this->mass * gravity * h;;
  double e_kinetic = 0.5 * this->mass * this->velocity.norm2();
  energy = e_potential + e_kinetic;
  std::cout << "Mass getEnergy" << std::endl;

  return energy ;
}

void Mass::step(double dt, double gravity)  
{

/* INCOMPLETE: TYPE YOUR CODE HERE */

  //std::cout << "Mass step" << std::endl;

  Vector2 acceleration, newVelocity, newPosition;
  acceleration.x = this->getForce().x / this->getMass();
  acceleration.y = this->getForce().y / this-> getMass();

  // calculating new velocity and position por X
  newVelocity.x = this->getVelocity().x + acceleration.x * dt;
  newPosition.x = this->position.x + (this->getVelocity().x * dt) + (0.5 * acceleration.x * dt * dt);
  // moving X
  if (xmin + radius <= newPosition.x && newPosition.x <= xmax - radius)
  {
    this->position.x = newPosition.x;
    this->velocity.x = this->getVelocity().x + acceleration.x * dt;
    std::cout << "Mass step if1" << std::endl;
  } else {
    this->velocity.x = -(this->velocity.x);
    std::cout << "Mass step if1else" << std::endl;
  }

  //calculating new velocity and position for Y
  newVelocity.y = this->getVelocity().y + (- gravity + acceleration.y) * dt;
  newPosition.y = this->position.y + (this->getVelocity().y * dt) + (0.5 * (- gravity + acceleration.y) * dt * dt);
  // moving Y
  if (ymin + radius <= newPosition.y && newPosition.y <= ymax - radius)
  {
    this->position.y = newPosition.y;
    this->velocity.y = newVelocity.y - gravity * dt;
    std::cout << "Mass step if2" << std::endl;
  } else {
    this->velocity.y = -(this->velocity.y);
    std::cout << "Mass step if2else" << std::endl;
  }
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass *mass1, Mass *mass2, double naturalLength, double stiffness, double damping)
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

  double l = getLength();
  Vector2 u12 = (1.0/l) * (mass2->getPosition() - mass1->getPosition());
  Vector2 unitary = u12/l;
  double v12 = dot((mass2->getVelocity() - mass1->getVelocity()), unitary);
  double forceMode = (naturalLength - l) * stiffness + v12 * damping;
  F = forceMode * unitary;
  std::cout << "Spring getForce" << std::endl;

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

SpringMass::SpringMass(masses_t masses, Spring *s, double gravity)
: masses(masses), spring(s), gravity(gravity)
{ }

void SpringMass::display()
{
  for(int i = 0; i < (this->masses).size(); ++i)
  {
    std::cout << (this->masses[i])->getPosition().x << " " << (this->masses[i])->getPosition().y << std::endl ;

  // for(int i = 0; i < springs.size(); ++i){
  //   std::cout << "Spring Length " << (this->springs[i])->getLength() << std::endl;
  }
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

  for(int i = 0; i < (this->masses).size(); ++i)
  {
    energy += (this->masses[i])->getEnergy(this->gravity);
    std::cout << "SpringMass getEnergy for" << std::endl;
  }
  energy += (this->spring)->getEnergy();
  std::cout << "SpringMass getEnergy" << std::endl;

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ; // gravity vector: acceleration pointing down

  for(int i = 0; i < (this->masses).size(); ++i)
  {
    (this->masses[i])->setForce(g);
    std::cout << "SpringMass step for1" << std::endl;
  }
  
  for (int i = 0; i < (this->masses).size(); ++i)
  {
    (this->masses[i])->addForce(spring->getForce());
    std::cout << "SpringMass step for2" << std::endl;
  }

  for (int i = 0; i < (this->masses).size(); ++i)
  {
    (this->masses[i])->step(dt, gravity);
    std::cout << "SpringMass step for3" << std::endl;
  }
}
