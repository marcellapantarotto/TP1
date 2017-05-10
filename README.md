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
- **ball.h**    has the class Ball with it's attributes and methods, this class inherits virtual methods from Simulation class.
- **ball.cpp**  desenvolves the methods and constructors of the class Ball and where you will find the set() and get() methods.
- **test-ball.cpp** defines the time interval (dt) and, besides having the main functions, it has the run function and also calls the functions: `step(dt)`, `display()`, `set()` and `get()`.

### Class Diagram
Created with the help of `https://www.lucidchart.com/`
![diagram](https://github.com/marcellapantarotto/TP1/blob/master/class_diagram.png?raw=true)

### Graphic
Created, with the use of GnuPlot version 5.0 patchlevel 3, considering the ball's initial coordinates (x, y) = (0, 0). Using these command lines:
```
$ gnuplot
gnuplot> plot 'result_output'
```
![grafic](https://github.com/marcellapantarotto/TP1/blob/master/result_grafic_plotting.png?raw=true)

### Output
This represents the programs output, expressed in the `result_output` file. With the ball's initial coordinates (x, y) = (0, 0).
```
0.01 -0.00877778
0.02 -0.0284444
0.03 -0.059
0.04 -0.100444
0.05 -0.152778
0.06 -0.216
0.07 -0.290111
0.08 -0.375111
0.09 -0.471
0.1  -0.577778
0.11 -0.695444
0.12 -0.824
0.13 -0.824
0.14 -0.695444
0.15 -0.577778
0.16 -0.471
0.17 -0.375111
0.18 -0.290111
0.19 -0.216
0.2 -0.152778
0.21 -0.100444
0.22 -0.059
0.23 -0.0284444
0.24 -0.00877778
0.25 -8.1532e-17
0.26 -0.00211111
0.27 -0.0151111
0.28 -0.039
0.29 -0.0737778
0.3  -0.119444
0.31 -0.176
0.32 -0.243444
0.33 -0.321778
0.34 -0.411
0.35 -0.511111
0.36 -0.622111
0.37 -0.744
0.38 -0.876778
0.39 -0.876778
0.4  -0.744
0.41 -0.622111
0.42 -0.511111
0.43 -0.411
0.44 -0.321778
0.45 -0.243444
0.46 -0.176
0.47 -0.119444
0.48 -0.0737778
0.49 -0.039
0.5  -0.0151111
0.51 -0.00211111
0.52 -4.90059e-16
0.53 -0.00877778
0.54 -0.0284444
0.55 -0.059
0.56 -0.100444
0.57 -0.152778
0.58 -0.216
0.59 -0.290111
0.6  -0.375111
0.61 -0.471
0.62 -0.577778
0.63 -0.695444
0.64 -0.824
0.65 -0.824
0.66 -0.695444
0.67 -0.577778
0.68 -0.471
0.69 -0.375111
0.7  -0.290111
0.71 -0.216
0.72 -0.152778
0.73 -0.100444
0.74 -0.059
0.75 -0.0284444
0.76 -0.00877778
0.77 -7.47666e-16
0.78 -0.00211111
0.79 -0.0151111
0.8  -0.039
0.81 -0.0737778
0.82 -0.119444
0.83 -0.176
0.84 -0.243444
0.85 -0.321778
0.86 -0.411
0.87 -0.511111
0.88 -0.622111
0.89 -0.744
0.89 -0.876778
0.88 -0.876778
0.87 -0.744
0.86 -0.622111
0.85 -0.511111
0.84 -0.411
0.83 -0.321778
0.82 -0.243444
0.81 -0.176
0.8  -0.119444
0.79 -0.0737778
```

## 2nd Part
For this part of the project, the attempt is to simulate two masses bouncing, in free fall, being both connected by a spring, witch has a force to contract, bringing them closer together, or expand, making the masses further apart. And the files used were: `simulation.h`, `springmass.h`, `springmass.cpp` and `test-springmass.cpp`.

### Compilation
The command line used was: `g++ -g springmass.cpp test-spring.cpp -o springmass`

And to execute: `./springmass`

### Files
- **simulation.h**  has the class `Simulation()` witch contains only virtual methods, that are responsible to build the interface between programs.
- **springmass.h**  library used to declare the main classes, with each of their methods, used in this part of the project. The classes,  witch can be examined in the class diagram shown below, are `Vector2()` `Mass()` `Spring()` `SpringMass()`. This last one inherits from `Simulation()` class, from the `simulation.h` file.
- **springmass.cpp**  desenvolves the methods of the classes declared in `springmass.h`. After that, the void method `Mass::step(double dt, double gravity)` takes the time and gravity force to calculate a new position, with it's respective velocity and acceleration. Then the void method `SpringMass::step(double dt)` calls some methods of `Mass()` and `Spring` to calculate the energy and the force of the move.  
- **test-springmass.cpp** creates the objects mass1 and mass2, with a connecting spring, end calculates the movement of the balls while they are in free fall. The time interval `(dt)` determined here helps to create the frames for an output, that latter was used to generate the plot analyses. 

### Class Diagram
Created with the help of `https://www.lucidchart.com/`
![diagram](https://github.com/marcellapantarotto/TP1/blob/master/Springmass_classdiagram.png)

### Graphic
Created considering initial coordinates at: Mass1(x, y) = (-0.5, 0) and Mass2(x, y) = (0.5, 0), and with the use of GnuPlot version 5.0 patchlevel 3. The command lines used were:
```
$ gnuplot
gnuplot> plot 'output_springmass'
```
![grafic](https://github.com/marcellapantarotto/TP1/blob/master/springmass_graphic.png)

### Output
This represents the programs output, expressed in the `output_springmass` file, with the initial coordinates: Mass1 = (-0.5, 0) and Mass2 = (0.5, 0).
```
-0.500556   -0.0189
0.499444    -0.0189
-0.502222   -0.0774
0.497778    -0.0774
-0.505      -0.1755
0.495       -0.1755
-0.508889   -0.3132
0.491111    -0.3132
-0.513889   -0.4905
0.486111    -0.4905
-0.52       -0.7074
0.48        -0.7074
-0.527222   -0.9639
0.472778    -0.9639
-0.535556   -0.9639
0.464444    -0.9639
-0.545      -0.7056
0.455       -0.7056
-0.555556   -0.4869
0.444444    -0.4869
-0.567222   -0.3078
0.432778    -0.3078
-0.58       -0.1683
0.42        -0.1683
-0.593889   -0.0684
0.406111    -0.0684
-0.608889   -0.0081
0.391111    -0.0081
-0.625       0.0126
0.375        0.0126
-0.642222   -0.0063
0.357778    -0.0063
-0.660556   -0.0648
0.339444    -0.0648
-0.68       -0.1629
0.32        -0.1629
-0.700556   -0.3006
0.299444    -0.3006
-0.722222   -0.4779
0.277778    -0.4779
-0.745      -0.6948
0.255       -0.6948
-0.768889   -0.9513
0.231111    -0.9513
-0.793889   -0.9513
0.206111    -0.9513
-0.82       -0.693
0.18        -0.693
-0.847222   -0.4743
0.152778    -0.4743
-0.875556   -0.2952
0.124444    -0.2952
-0.905      -0.1557
0.095       -0.1557
-0.935556   -0.0558
0.0644444   -0.0558
-0.967222    0.0045
0.0327778    0.0045
-0.967222    0.0252
4.02131e-16  0.0252
-0.935431    0.0063
-0.0337648   0.0063
-0.903745   -0.0522
-0.0676341  -0.0522
-0.870531   -0.1503
-0.0999757  -0.1503
-0.833897   -0.288
-0.128897   -0.288
-0.791622   -0.4653
-0.152177   -0.4653
-0.741063   -0.6822
-0.167174   -0.6822
-0.679023   -0.9387
-0.17069    -0.9387
-0.601557   -0.9387
-0.15878    -0.9387
-0.503669   -0.6804
-0.126447   -0.6804
-0.378832   -0.4617
-0.0671657  -0.4617
-0.218152   -0.2826
0.0279589   -0.2826
-0.00879416 -0.1431
0.171761    -0.1431
0.269382    -0.0432
0.384382    -0.0432
0.652359     0.0171
0.701803     0.0171
0.652359     0.0378
0.701803     0.0378
0.496984     0.0189
0.611984     0.0189
0.730562    -0.0396
0.911118    -0.0396
0.730562    -0.1377
0.911118    -0.1377
0.440432    -0.2754
0.555432    -0.2754
0.255101    -0.4527
0.304546    -0.4527
0.246914    -0.6696
0.230803    -0.6696
0.246914    -0.9261
0.230803    -0.9261
0.339906    -0.9261
0.38935     -0.9261
0.922446    -0.6678
0.38935     -0.6678
0.922446    -0.4491
0.00988522  -0.4491
0.0495831   -0.27
-0.391271   -0.27
-0.826589   -0.1305
-0.795737   -0.1305
0.275407    -0.0306
0.777965    -0.0306
0.275407     0.0297
0.777965     0.0297
0.275407     0.0504
0.777965     0.0504
0.275407     0.0315
0.777965     0.0315
0.275407    -0.027
0.777965    -0.027
0.275407    -0.1251
0.777965    -0.1251
0.275407    -0.2628
0.777965    -0.2628
0.275407    -0.4401
0.777965    -0.4401
0.275407    -0.657
0.777965    -0.657
0.275407    -0.9135
0.777965    -0.9135
0.275407    -0.9135
0.777965    -0.9135
0.275407    -0.6552
0.777965    -0.6552
0.275407    -0.4365
0.777965    -0.4365
0.275407    -0.2574
0.777965    -0.2574
0.275407    -0.1179
0.777965    -0.1179
0.275407    -0.018
0.777965    -0.018
0.275407     0.0423
0.777965     0.0423
0.275407     0.063
0.777965     0.063
0.275407     0.0441
0.777965     0.0441
0.275407    -0.0144
0.777965    -0.0144
0.275407    -0.1125
0.777965    -0.1125
0.275407    -0.2502
0.777965    -0.2502
0.275407    -0.4275
0.777965    -0.4275
0.275407    -0.6444
0.777965    -0.6444
0.275407    -0.9009
0.777965    -0.9009
0.275407    -0.9009
0.777965    -0.9009
0.275407    -0.6426
0.777965    -0.6426
0.275407    -0.4239
0.777965    -0.4239
0.275407    -0.2448
0.777965    -0.2448
0.275407    -0.1053
0.777965    -0.1053
0.275407    -0.0054
0.777965    -0.0054
0.275407     0.0549
0.777965     0.0549
0.275407     0.0756
0.777965     0.0756
0.275407     0.0567
0.777965     0.0567
0.275407    -0.0018
0.777965    -0.0018
0.275407    -0.0999
0.777965    -0.0999
0.275407    -0.2376
0.777965    -0.2376
0.275407    -0.4149
0.777965    -0.4149
0.275407    -0.6318
0.777965    -0.6318
0.275407    -0.8883
0.777965    -0.8883
0.275407    -0.8883
0.777965    -0.8883
0.275407    -0.63
0.777965    -0.63
0.275407    -0.4113
0.777965    -0.4113
```
