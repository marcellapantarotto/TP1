/** file: test-ball.cpp
 ** brief: Tests the bouncing ball simulation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"
#include <iostream>
using namespace std;

void run(Simulation & s, double dt){
	std::cout << "Output:" << std::endl;
  	for(int i=0; i<100; ++i){
  		s.step(dt); s.display();
  	}
}

int main(int argc, char** argv)
{
  Ball ball ;
  const double dt = 1.0/30 ;

  double x=0, y=0;
  ball.setx(x);
  ball.getx();
  ball.sety(y);
  ball.gety();
  
  // Adding run call.
  run(ball, dt);

  // Removing for loop
  /*for (int i = 0 ; i < 100 ; ++i) {
    ball.step(dt) ;
    ball.display() ;
  }*/

  return 0 ;
}

