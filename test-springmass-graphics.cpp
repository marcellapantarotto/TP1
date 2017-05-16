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
		:SpringMass(), figure("SpringMass")
		{
			figure.addDrawable(this);
		}

 		//void drawCircle(double x, double y, double radius) ;
  		//void drawLine(double x1, double y1, double x2, double y2, double thickness) ;
		void draw()
		{
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

	const double mass = 0.05 ;
	const double radius = 0.02 ;
	const double naturalLength = 0.95 ;
	const double stiffness = 1.0;
	const double damping = 0.01;
	const double dt = 1.0/120.0 ;

	Mass m1(Vector2(-.5,0), Vector2(), mass, radius) ;
	Mass m2(Vector2(+.5,0), Vector2(), mass, radius) ;
	Spring spring(&m1, &m2, naturalLength, stiffness, damping);
	springmass.setGravity(MOON_GRAVITY);
	springmass.addMass(&m1);
	springmass.addMass(&m2);
	springmass.addSpring(&spring);

	//springmass.getLength()
	for (int i = 0; i < springmass.size(); ++i)
	{
		springmass.display();
		springmass.draw();
	}
	run(&springmass, dt);
}