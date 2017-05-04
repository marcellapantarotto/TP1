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
      h = 1 - this.getPosition().y;
    }else{
      h = 1 + this.getPosition().y;
    }
  */

  energy =  this.mass * gravity * h + 0.5 * this.mass * this.velocity.norm2();    // m*g*h + 0.5*m*v^2

  return energy ;
}

void Mass::step(double dt)
{

/* INCOMPLETE: TYPE YOUR CODE HERE

  F = m * a -> a = m/F;
  S = S0 + velocity * dt (a*dt^2)/2;
  velocity = velocity0 + a*dt;


  double xp = getPosition().x + getVelocity().x * dt ;
  double yp = getPosition().y + getVelocity().y * dt - 0.5 * gravity * dt * dt ;
  if (xmin + r <= xp && xp <= xmax - r) {
    setPosition().x = xp ;
  } else {
    vx = -vx ;
  }
  if (ymin + r <= yp && yp <= ymax - r) {
    y = yp ;
    vy = vy - gravity * dt ;
  } else {
    vy = -vy ;
  }

*/

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

Vector2 Spring::getForce() const
{
  Vector2 F ;
  double x1, x2, velocity1, velocity2, u12, v12, F1;

  if((x1-x1-naturalLength) != 0){
      if((x2-x1) < 0){
          u12 = -1;
      }else{
        u12 = 1;
      }
      v12 = dot((velocity2 - velocity1)*u12)*u12;
  }
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


