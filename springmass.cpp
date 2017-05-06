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

/* INCOMPLETE: TYPE YOUR CODE HERE */

  double h = position.y - radius - ymin;

  /*
    if(this.getPosition().y < 0){
      h = 1 - this->getPosition().y;
    }else{
      h = 1 + this->getPosition().y;
    }
  */

  energy =  this->mass * gravity * h + 0.5 * this->mass * this->velocity.norm2();    // m*g*h + 0.5*m*v^2

  return energy ;
}

void Mass::step(double dt)  //incomplete
{

/* INCOMPLETE: TYPE YOUR CODE HERE

  F = m * a -> a = m/F;
  S = S0 + velocity * dt (a*dt^2)/2;
  velocity = velocity0 + a*dt;
*/

  double a = mass / force.y;
  double xp = getPosition().x + getVelocity().x * dt ;
  double yp = getPosition().y + getVelocity().y * dt - 0.5 * a * dt * dt ;

  if (xmin + radius <= xp && xp <= xmax - radius) {
    position.x = xp ;
  } else {
    velocity.x = -velocity.x ;
  }
 
  if (ymin + radius <= yp && yp <= ymax - radius) {
    position.y = yp ;
    velocity.y = velocity.y - a * dt ;
  } else {
    velocity.y = -velocity.y ;
  }


}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

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

Vector2 Spring::getForce() const  //incomplete
{
  Vector2 F ;

  /* INCOMPLETE: TYPE YOUR CODE HERE */

  double l = getLength();
  Vector2 u12 = (1.0/l)*(mass2->getPosition() - mass1->getPosition());
  Vector2 unitary = u12/l;
  double v12 = dot((mass2->getVelocity() - mass1->getVelocity()),unitary);
  double forceMode = (naturalLength - l) * stiffness + v12*damping;
  F = forceMode * unitary;

  /*
  double u12, v12, F1;

  Vector2 x1 = mass1->getPosition();
  Vector2 x2 = mass2->getPosition();

  Vector2 velocity1 = mass1->getVelocity();
  Vector2 velocity2 = mass2->getVelocity();

  if((x1.x - x2.x - naturalLength) != 0){
      if((x2.x - x1.x) < 0){
          u12 = -1;
      }else{
        u12 = 1;
      }
      v12 = dot((velocity2 - velocity1), u12)*u12;
  }*/

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
  int i;

  for(i = 0; i < masses.size(); ++i){
    std::cout << masses[i] << std::endl;
  }

  for(i = 0; i < springs.size(); ++i){
    std::cout << springs[i] << std::endl;
  }

  //print total energy -> missing
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

/* INCOMPLETE: TYPE YOUR CODE HERE */
  energy = mass1->getEnergy(gravity) + mass2->getEnergy(gravity) + spring->getEnergy() ;
  //energy = mass1->getEnergy(gravity) + mass2->getEnergy(gravity) + spring->getEnergy();

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ; // gravity vector: acceleration pointing down

/* INCOMPLETE: TYPE YOUR CODE HERE */
  int i;

  for(i = 0; i < masses.size(); ++i){
    masses[i].setForce(g * masses[i].getMass());
  }

  for(i = 0; i < masses.size(); ++i){
    Vector2 force = springs[i].getForce();
    springs[i].getMass1()->addForce(-1 * force);
    springs[i].getMass2()->addForce(+1 * force);  
  }

  for(i = 0; i < masses.size(); ++i){
    masses[i].step(dt);
  }


  // mass1->setForce(g);
  // mass2->setForce(g);
  // mass1->addForce(spring->getForce());
  // mass2->addForce(-1.0*spring->getForce());
  // mass1->step(dt);
  // mass2->step(dt);
}


/* INCOMPLETE: TYPE YOUR CODE HERE */

int SpringMass::addMass(Mass m)
{  
  masses.push_back(m);
  return (int)masses.size() -1;
}

int SpringMass::addSpring(Mass * mass1, Mass * mass2, Spring * spring, double naturalLength, double stiffness, double damping)
{
  springs.push_back(Spring &spring);
  return (int)springs.size();
}


