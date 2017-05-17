# TP1
This project aims to simulate bouncing balls, in free fall, inside a delimited box (1x1). It is desenvolved in C++ and compiled with G++ GNU Compiler version 5.4.0. It requests, the `iostream` and `stdio` libraries.

## 1st Part
For this part, the aim is to simulate one singular ball bouncing in free fall. And the files used were: `simulation.h`, `ball.h`, `ball.cpp` and `test-ball.cpp`.

### Compilation
The command line used to compile the program was first this one: `g++ ball.cpp test-ball.cpp -o ball`

Then, with the use of GDB it became: `g++ -g ball.cpp test-ball.cpp -o ball`

And to execute: `./ball`

### Files
- **simulation.h**  has the class `Simulation()` witch contains only virtual methods, that are responsible to build the interface between programs.
- **ball.h**    has the class `Ball()` with it's attributes and methods, this class inherits virtual methods from Simulation class.
- **ball.cpp**  desenvolves the methods and constructors of the class Ball and where you will find the set() and get() methods.
- **test-ball.cpp** defines the time interval (dt) and, besides having the main functions, it has the run function and also calls the methods: `step(dt)`, `display()`, `set()` and `get()`.

### Class Diagram
Created with the help of `https://www.lucidchart.com/`, expressed in the `class_diagram.png` file.
![ball diagram](https://github.com/marcellapantarotto/TP1/blob/master/class_diagram.png?raw=true)

### Graphic
Expressed in the `result_grafic_plotting.png` file, it was created with the use of GnuPlot version 5.0 patchlevel 3, considering the ball's initial coordinates (x, y) = (0, 0). Using these command lines:
```
$ gnuplot
gnuplot> plot 'result_output'
```
![ball graphic](https://github.com/marcellapantarotto/TP1/blob/master/result_grafic_plotting.png?raw=true)

### Output
This represents the programs output, expressed in the `result_output` file. With the ball's initial coordinates (x, y) = (0, 0).
```
0.01 	-0.00877778
0.02 	-0.0284444
0.03 	-0.059
0.04 	-0.100444
0.05 	-0.152778
0.06 	-0.216
0.07 	-0.290111
0.08 	-0.375111
0.09 	-0.471
0.1  	-0.577778
0.11 	-0.695444
0.12 	-0.824
0.13 	-0.824
0.14 	-0.695444
0.15 	-0.577778
0.16 	-0.471
0.17 	-0.375111
0.18 	-0.290111
0.19 	-0.216
0.2  	-0.152778
0.21 	-0.100444
0.22 	-0.059
0.23 	-0.0284444
0.24 	-0.00877778
0.25 	-8.1532e-17
0.26 	-0.00211111
0.27 	-0.0151111
0.28 	-0.039
0.29 	-0.0737778
0.3  	-0.119444
0.31 	-0.176
0.32 	-0.243444
0.33 	-0.321778
0.34 	-0.411
0.35 	-0.511111
0.36 	-0.622111
0.37 	-0.744
0.38 	-0.876778
0.39 	-0.876778
0.4  	-0.744
0.41 	-0.622111
0.42 	-0.511111
0.43 	-0.411
0.44 	-0.321778
0.45 	-0.243444
0.46 	-0.176
0.47 	-0.119444
0.48 	-0.0737778
0.49 	-0.039
0.5  	-0.0151111
0.51 	-0.00211111
0.52 	-4.90059e-16
0.53 	-0.00877778
0.54 	-0.0284444
0.55 	-0.059
0.56 	-0.100444
0.57 	-0.152778
0.58 	-0.216
0.59 	-0.290111
0.6  	-0.375111
0.61 	-0.471
0.62 	-0.577778
0.63 	-0.695444
0.64 	-0.824
0.65 	-0.824
0.66 	-0.695444
0.67 	-0.577778
0.68 	-0.471
0.69 	-0.375111
0.7  	-0.290111
0.71 	-0.216
0.72 	-0.152778
0.73 	-0.100444
0.74 	-0.059
0.75 	-0.0284444
0.76 	-0.00877778
0.77 	-7.47666e-16
0.78 	-0.00211111
0.79 	-0.0151111
0.8  	-0.039
0.81 	-0.0737778
0.82 	-0.119444
0.83 	-0.176
0.84 	-0.243444
0.85 	-0.321778
0.86 	-0.411
0.87 	-0.511111
0.88 	-0.622111
0.89 	-0.744
0.89 	-0.876778
0.88 	-0.876778
0.87	-0.744
0.86 	-0.622111
0.85 	-0.511111
0.84 	-0.411
0.83 	-0.321778
0.82 	-0.243444
0.81 	-0.176
0.8  	-0.119444
0.79 	-0.0737778
```

## 2nd Part
For this part of the project, the attempt is to simulate two masses bouncing, in free fall, being both connected by a spring, witch has a force to contract, bringing them closer together, or expand, making the masses further apart. And the files used were: `simulation.h`, `springmass.h`, `springmass.cpp` and `test-springmass.cpp`.

### Compilation
The command line used was: `g++ -g springmass.cpp test-spring.cpp -o springmass`

And to execute: `./springmass`

### Files
- **simulation.h**  has the class `Simulation()` witch contains only virtual methods, that are responsible to build the interface between programs.
- **springmass.h**  library used to declare the main classes, with each of their methods, used in this part of the project. The classes,  witch can be examined in the class diagram shown below, are `Vector2()` `Mass()` `Spring()` `SpringMass()`. This last one inherits from `Simulation()` class, from the `simulation.h` file.
- **springmass.cpp**  desenvolves the methods of the classes declared in `springmass.h`. After that, the void method `Mass::step(double dt, double gravity)` takes the time and gravity force to calculate a new position, with it's respective velocity and acceleration. Then the void method `SpringMass::step(double dt)` calls some methods of `Mass()` and `Spring()` to calculate the energy and the force of the move.
- **test-springmass.cpp** creates the objects mass1 and mass2, with a connecting spring, end calculates the movement of the balls while they are in free fall. The time interval `(dt)` determined here helps to create the frames for an output, that latter was used to generate the plot analyses. 

### Class Diagram
Created with the help of `https://www.lucidchart.com/`, expressed in the `Springmass_classdiagram.png` file.
![springmass diagram](https://github.com/marcellapantarotto/TP1/blob/master/Springmass_classdiagram.png)

### Graphic
Expressed in the `springmass_graphic.png` file, it was created considering initial coordinates at: Mass1(x, y) = (-0.5, 0) and Mass2(x, y) = (0.5, 0), and with the use of GnuPlot version 5.0 patchlevel 3. The command lines used were:
```
$ gnuplot
gnuplot> plot 'output_springmass'
```
![springmass graphic](https://github.com/marcellapantarotto/TP1/blob/master/springmass_graphic.png)

### Output
This represents the programs output, expressed in the `output_springmass` file, with the initial coordinates: Mass1 = (-0.5, 0) and Mass2 = (0.5, 0).
```
-0.499444 	-0.0189
 0.500556 	-0.0189
-0.5 		-0.0774
 0.5 		-0.0774
-0.501667	-0.1755
 0.498333 	-0.1755
-0.504444	-0.3132
 0.495556 	-0.3132
-0.508333 	-0.4905
 0.491667 	-0.4905
-0.513333 	-0.7074
 0.486667 	-0.7074
-0.519444 	-0.9639
 0.480556 	-0.9639
-0.526667 	-0.9639
 0.473333 	-0.9639
-0.535 		-0.7056
 0.465 		-0.7056
-0.544444 	-0.4869
 0.455556 	-0.4869
-0.555 		-0.3078
 0.445 		-0.3078
-0.566667 	-0.1683
 0.433333	-0.1683
-0.579444	-0.0684
 0.420556	-0.0684
-0.593333	-0.0081
 0.406667	-0.0081
-0.608333	 0.0126
 0.391667	 0.0126
-0.624444	-0.0063
 0.375556	-0.0063
-0.641667	-0.0648
 0.358333	-0.0648
-0.66 		-0.1629
 0.34 		-0.1629
-0.679444 	-0.3006
 0.320556	-0.3006
-0.7 		-0.4779
 0.3 		-0.4779
-0.721667 	-0.6948
 0.278333	-0.6948
-0.744444 	-0.9513
 0.255556 	-0.9513
-0.768333 	-0.9513
 0.231667 	-0.9513
-0.793333 	-0.693
 0.206667 	-0.693
-0.819444 	-0.4743
 0.180556 	-0.4743
-0.846667 	-0.2952
 0.153333 	-0.2952
-0.875 		-0.1557
 0.125 		-0.1557
-0.904444	-0.0558
 0.0955556	-0.0558
-0.935		 0.0045
 0.065		 0.0045
-0.966667	 0.0252
 0.0333333	 0.0252
-0.966667        0.0063
 0.000555556	 0.0063
-0.932894 	-0.0522
-0.0334495      -0.0522
-0.900785 	-0.1503
-0.0691179      -0.1503
-0.868894 	-0.288
-0.105005 	-0.288
-0.83556 	-0.4653
-0.139449 	-0.4653
-0.798853 	-0.6822
-0.170519 	-0.6822
-0.756502 	-0.9387
-0.195947 	-0.9387
-0.705805 	-0.9387
-0.213027 	-0.9387
-0.643485 	-0.6804
-0.218485 	-0.6804
-0.565503 	-0.4617
-0.208281 	-0.4617
-0.466764 	-0.2826
-0.17732 	-0.2826
-0.340684 	-0.1431
-0.119017 	-0.1431
-0.178532 	-0.0432
-0.0246427 	-0.0432
 0.0314095 	 0.0171
 0.117521 	 0.0171
 0.304172	 0.0378
 0.322505 	 0.0378
 0.927468 	 0.0189
 0.878024 	 0.0189
 0.927468 	-0.0396
 0.878024	-0.0396
 0.736721 	-0.1377
 0.755054 	-0.1377
 0.736721 	-0.2754
-0.934616 	-0.2754
 0.736721 	-0.4527
-0.934616 	-0.4527
 0.21309 	-0.6696
-0.934616 	-0.6696
-0.309855 	-0.9261
-0.934616 	-0.9261
-0.78902 	-0.9261
-0.934616 	-0.9261
-0.78902 	-0.6678
 0.745595 	-0.6678
-0.252321 	-0.4491
 0.745595 	-0.4491
 0.292241 	-0.27
 0.745595 	-0.27
 0.755002 	-0.1305
 0.745595 	-0.1305
 0.755002 	-0.0306
 0.745595 	-0.0306
 0.755002 	 0.0297
 0.745595 	 0.0297
 0.755002 	 0.0504
 0.745595 	 0.0504
 0.755002 	 0.0315
 0.745595 	 0.0315
 0.755002 	-0.027
 0.745595 	-0.027
 0.755002 	-0.1251
 0.745595 	-0.1251
 0.755002 	-0.2628
 0.745595 	-0.2628
 0.755002 	-0.4401
 0.745595 	-0.4401
 0.755002 	-0.657
 0.745595 	-0.657
 0.755002 	-0.9135
 0.745595 	-0.9135
 0.755002 	-0.9135
 0.745595 	-0.9135
 0.755002 	-0.6552
 0.745595 	-0.6552
 0.755002 	-0.4365
 0.745595 	-0.4365
 0.755002 	-0.2574
 0.745595 	-0.2574
 0.755002 	-0.1179
 0.745595 	-0.1179
 0.755002 	-0.018
 0.745595 	-0.018
 0.755002 	 0.0423
 0.745595 	 0.0423
 0.755002 	 0.063
 0.745595 	 0.063
 0.755002 	 0.0441
 0.745595 	 0.0441
 0.755002 	-0.0144
 0.745595 	-0.0144
 0.755002 	-0.1125
 0.745595 	-0.1125
 0.755002 	-0.2502
 0.745595 	-0.2502
 0.755002 	-0.4275
 0.745595 	-0.4275
 0.755002 	-0.6444
 0.745595	-0.6444
 0.755002 	-0.9009
 0.745595 	-0.9009
 0.755002 	-0.9009
 0.745595 	-0.9009
 0.755002 	-0.6426
 0.745595 	-0.6426
 0.755002 	-0.4239
 0.745595 	-0.4239
 0.755002 	-0.2448
 0.745595 	-0.2448
 0.755002 	-0.1053
 0.745595 	-0.1053
 0.755002 	-0.0054
 0.745595 	-0.0054
 0.755002	 0.0549
 0.745595 	 0.0549
 0.755002 	 0.0756
 0.745595 	 0.0756
 0.755002 	 0.0567
 0.745595 	 0.0567
 0.755002 	-0.0018
 0.745595 	-0.0018
 0.755002 	-0.0999
 0.745595 	-0.0999
 0.755002 	-0.2376
 0.745595 	-0.2376
 0.755002 	-0.4149
 0.745595 	-0.4149
 0.755002 	-0.6318
 0.745595 	-0.6318
 0.755002 	-0.8883
 0.745595 	-0.8883
 0.755002 	-0.8883
 0.745595 	-0.8883
 0.755002 	-0.63
 0.745595 	-0.63
 0.755002 	-0.4113
 0.745595 	-0.4113
```
## 3rd Part
In ths part, I tried to project and animation for the falling ball and springmass from the other parts. And the files used were: `simulation.h`, `ball.cpp`, `springmass.cpp`, `graphics.h`, `graphics.cpp` and `test-springmass-graphics.cpp`.

### Compilation
The command line used to execute the **ball's** animation was: `g++ graphics.cpp ball.cpp test-ball-graphics.cpp -lGL -lGLU -lglut -o ball-graphics`

And to execute: `./ball-graphics`

The command line used to execute the **springmass's** animation was: `g++ graphics.cpp springmass.cpp test-springmass-graphics.cpp -lGL lGLU -lglut -o springmass-graphics`

And to execute: `./springmass-graphics`

### Files
- **simulation.h**  has the class `Simulation()` witch contains only virtual methods, that are responsible to build the interface between programs.
- **ball.cpp**  desenvolves the methods and constructors of the class `Ball()`, set() and get() methods.
- **springmass.cpp**  desenvolves the methods of the classes `Springmass()`, that calls the method `Mass::step()` to calculate new position and new velocity for the masses and, also calls some methods of `Mass()` and `Spring()` to calculate the energy and the force of the move.
- **graphics.h** inherets from class `Simulation()` and this is the library that defines the classes `Drawable()` and `Figure()`.
- **graphics.cpp** desenvolves methods for the animations.
- **test-springmass-graphics.cpp**
