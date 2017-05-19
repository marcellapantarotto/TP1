/** file: test-springmass-graphics.cpp
 ** brief: Tests the spring mass simulation with graphics
 ** author: Andrea Vedaldi
 **/

#include "graphics.h"
#include "springmass.h"

#include <iostream>
#include <sstream>
#include <iomanip>

/* ---------------------------------------------------------------- */
class SpringMassDrawable : public SpringMass, public Drawable
/* ---------------------------------------------------------------- */
{
	private:
		Figure figure;
	public:
		SpringMassDrawable()
		:SpringMass(), figure("Spring Mass")
		{
			figure.addDrawable(this);
		}

		void draw()
		{
			double x1, x2, y1, y2, radius, tickness = 0.5;

			x1 = this->getMass(0).getPosition().x;
			y1 = this->getMass(0).getPosition().y;
			x2 = this->getMass(1).getPosition().x;
			y2 = this->getMass(1).getPosition().y;

			radius = this-> getMass(0).getRadius();
			
			figure.drawCircle(x1, y1, radius);
			figure.drawCircle(x2, y2, radius);
			figure.drawLine(x1, y1, x2, y2, tickness);
		}

		void display()
		{
			figure.update();
		}
} ;

int main(int argc, char** argv)
{
  	glutInit(&argc,argv) ;
  	SpringMassDrawable springmass ;

	const double mass1 = 0.05 ;
	const double mass2 = 1.0;
	const double radius = 0.02 ;
	const double naturalLength = 0.95 ;
	const double dt = 1.0/120.0 ;

	Mass m1(Vector2(-.5,0), Vector2(), mass1, radius) ;
	Mass m2(Vector2(+.5,0.5), Vector2(), mass2, radius) ;
	springmass.addMass(m1);
	springmass.addMass(m2);
	springmass.addSpring(0,1, naturalLength, 1.0);

	springmass.display();
	springmass.draw();

	run(&springmass, dt);
}