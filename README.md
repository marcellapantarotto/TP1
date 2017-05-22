# TP1
This project aims to simulate bouncing balls, in free fall, inside a delimited box (1x1). It is developed in C++ and compiled with G++ GNU Compiler version 5.4.0. It requests, the `iostream` and `stdio` libraries.

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
![ball class diagram](https://github.com/marcellapantarotto/TP1/blob/master/class_diagram.png?raw=true)

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
For this part of the project, I simulated two masses bouncing, in free fall, being both connected by a spring, witch has a force to contract, bringing them closer together, or expand, making the masses further apart. And the files used were: `simulation.h`, `springmass.h`, `springmass.cpp` and `test-springmass.cpp`.

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
![springmass class diagram](https://github.com/marcellapantarotto/TP1/blob/master/Springmass_classdiagram.png)

### Graphic
Expressed in the `springmass_graphic.png` file, it was created considering initial coordinates at: Mass1(x, y) = (-0.5, 0) and Mass2(x, y) = (0.5, 0), and with the use of GnuPlot version 5.0 patchlevel 3. The command lines used were:
```
$ gnuplot
gnuplot> plot 'output_springmass'
```
![springmass graphic](https://github.com/marcellapantarotto/TP1/blob/master/springmass_graphics.png)

### Output
This represents the programs first output, expressed in the `output_springmass` file, with the initial coordinates: Mass1 = (-0.5, 0) and Mass2 = (0.5, 0), one on top of the other. This output was necessary for the graph plotting.
```
-0.499444   -0.0009
 0.499444   -0.0009
-0.497798   -0.0036
 0.497798   -0.0036
-0.495123   -0.0081
 0.495123   -0.0081
-0.49153    -0.0144
 0.49153    -0.0144
-0.48717    -0.0225
 0.48717    -0.0225
-0.482231   -0.0324
 0.482231   -0.0324
-0.476927   -0.0441
 0.476927   -0.0441
-0.47149    -0.0576
 0.47149    -0.0576
-0.46616    -0.0729
 0.46616    -0.0729
-0.461176   -0.09
 0.461176   -0.09
-0.456762   -0.1089
 0.456762   -0.1089
-0.453119   -0.1296
 0.453119   -0.1296
-0.450417   -0.1521
 0.450417   -0.1521
-0.448783   -0.1764
 0.448783   -0.1764
-0.4483     -0.2025
 0.4483     -0.2025
-0.448999   -0.2304
 0.448999   -0.2304
-0.45086    -0.2601
 0.45086    -0.2601
-0.45381    -0.2916
 0.45381    -0.2916
-0.457729   -0.3249
 0.457729   -0.3249
-0.462449   -0.36
 0.462449   -0.36
-0.46777    -0.3969
 0.46777    -0.3969
-0.473459   -0.4356
 0.473459   -0.4356
-0.479267   -0.4761
 0.479267   -0.4761
-0.484938   -0.5184
 0.484938   -0.5184
-0.490217   -0.5625
 0.490217   -0.5625
-0.494866   -0.6084
 0.494866   -0.6084
-0.498674   -0.6561
 0.498674   -0.6561
-0.501464   -0.7056
 0.501464   -0.7056
-0.503102   -0.7569
 0.503102   -0.7569
-0.503506   -0.81
 0.503506   -0.81
-0.502646   -0.8649
 0.502646   -0.8649
-0.500551   -0.9216
 0.500551   -0.9216
-0.4973     -0.9216
 0.4973     -0.9216
-0.49303    -0.8649
 0.49303    -0.8649
-0.487921   -0.81
 0.487921   -0.81
-0.482192   -0.7569
 0.482192   -0.7569
-0.476092   -0.7056
 0.476092   -0.7056
-0.46989    -0.6561
 0.46989    -0.6561
-0.463859   -0.6084
 0.463859   -0.6084
-0.45827    -0.5625
 0.45827    -0.5625
-0.453375   -0.5184
 0.453375   -0.5184
-0.449398   -0.4761
 0.449398   -0.4761
-0.446523   -0.4356
 0.446523   -0.4356
-0.444888   -0.3969
 0.444888   -0.3969
-0.444577   -0.36
 0.444577   -0.36
-0.445615   -0.3249
 0.445615   -0.3249
-0.447969   -0.2916
 0.447969   -0.2916
-0.451545   -0.2601
 0.451545   -0.2601
-0.456195   -0.2304
 0.456195   -0.2304
-0.461722   -0.2025
 0.461722   -0.2025
-0.467888   -0.1764
 0.467888   -0.1764
-0.474426   -0.1521
 0.474426   -0.1521
-0.481047   -0.1296
 0.481047   -0.1296
-0.487458   -0.1089
 0.487458   -0.1089
-0.493372   -0.09
 0.493372   -0.09
-0.498522   -0.0729
 0.498522   -0.0729
-0.502673   -0.0576
 0.502673   -0.0576
-0.505631   -0.0441
 0.505631   -0.0441
-0.507254   -0.0324
 0.507254   -0.0324
-0.507457   -0.0225
 0.507457   -0.0225
-0.50622    -0.0144
 0.50622    -0.0144
-0.503584   -0.0081
 0.503584   -0.0081
-0.499655   -0.0036
 0.499655   -0.0036
-0.494595   -0.0009
 0.494595   -0.0009
-0.488618   -5.38198e-16
 0.488618   -5.38198e-16
-0.481984   -0.0009
 0.481984   -0.0009
-0.47498    -0.0036
 0.47498    -0.0036
-0.467915   -0.0081
 0.467915   -0.0081
-0.461102   -0.0144
 0.461102   -0.0144
-0.454846   -0.0225
 0.454846   -0.0225
-0.44943    -0.0324
 0.44943    -0.0324
-0.445102   -0.0441
 0.445102   -0.0441
-0.442065   -0.0576
 0.442065   -0.0576
-0.440465   -0.0729
 0.440465   -0.0729
-0.440385   -0.09
 0.440385   -0.09
-0.441843   -0.1089
 0.441843   -0.1089
-0.444787   -0.1296
 0.444787   -0.1296
-0.449101   -0.1521
 0.449101   -0.1521
-0.454604   -0.1764
 0.454604   -0.1764
-0.461062   -0.2025
 0.461062   -0.2025
-0.468197   -0.2304
 0.468197   -0.2304
-0.475698   -0.2601
 0.475698   -0.2601
-0.483235   -0.2916
 0.483235   -0.2916
-0.490473   -0.3249
 0.490473   -0.3249
-0.497087   -0.36
 0.497087   -0.36
-0.502778   -0.3969
 0.502778   -0.3969
-0.507286   -0.4356
 0.507286   -0.4356
-0.510398   -0.4761
 0.510398   -0.4761
-0.511965   -0.5184
 0.511965   -0.5184
-0.511903   -0.5625
 0.511903   -0.5625
-0.510201   -0.6084
 0.510201   -0.6084
-0.506918   -0.6561
 0.506918   -0.6561
-0.502188   -0.7056
 0.502188   -0.7056
-0.496208   -0.7569
 0.496208   -0.7569
-0.489232   -0.81
 0.489232   -0.81
-0.481561   -0.8649
 0.481561   -0.8649
-0.47353    -0.9216
 0.47353    -0.9216
-0.465494   -0.9216
 0.465494   -0.9216
-0.457808   -0.8649
 0.457808   -0.8649
-0.450819   -0.81
 0.450819   -0.81
```

And the second output, showing the coordinates for mass1 and mass2, and also the spring force and the energy, expressed below, is int the `output_springmass2` file.
```
(-0.499444,-0.0009)		(0.499444,-0.0009)	$0.998889 	en:0.160011
(-0.497798,-0.0036)		(0.497798,-0.0036)	$0.995595 	en:0.160014
(-0.495123,-0.0081)		(0.495123,-0.0081)	$0.990246 	en:0.160021
(-0.49153,-0.0144)		(0.49153,-0.0144)	$0.98306 	en:0.160033
(-0.48717,-0.0225)		(0.48717,-0.0225)	$0.974341 	en:0.16005
(-0.482231,-0.0324)		(0.482231,-0.0324)	$0.964462 	en:0.160071
(-0.476927,-0.0441)		(0.476927,-0.0441)	$0.953854 	en:0.160095
(-0.47149,-0.0576)		(0.47149,-0.0576)	$0.942979 	en:0.160118
(-0.46616,-0.0729)		(0.46616,-0.0729)	$0.93232 	en:0.16014
(-0.461176,-0.09)		(0.461176,-0.09)	$0.922352 	en:0.160159
(-0.456762,-0.1089)		(0.456762,-0.1089)	$0.913524 	en:0.160173
(-0.453119,-0.1296)		(0.453119,-0.1296)	$0.906239 	en:0.160181
(-0.450417,-0.1521)		(0.450417,-0.1521)	$0.900834 	en:0.160185
(-0.448783,-0.1764)		(0.448783,-0.1764)	$0.897566 	en:0.160186
(-0.4483,-0.2025)		(0.4483,-0.2025)	$0.8966 	en:0.160186
(-0.448999,-0.2304)		(0.448999,-0.2304)	$0.897998 	en:0.160187
(-0.45086,-0.2601)		(0.45086,-0.2601)	$0.90172 	en:0.160191
(-0.45381,-0.2916)		(0.45381,-0.2916)	$0.90762 	en:0.1602
(-0.457729,-0.3249)		(0.457729,-0.3249)	$0.915457 	en:0.160214
(-0.462449,-0.36)		(0.462449,-0.36)	$0.924899 	en:0.160234
(-0.46777,-0.3969)		(0.46777,-0.3969)	$0.93554 	en:0.160258
(-0.473459,-0.4356)		(0.473459,-0.4356)	$0.946918 	en:0.160285
(-0.479267,-0.4761)		(0.479267,-0.4761)	$0.958535 	en:0.160312
(-0.484938,-0.5184)		(0.484938,-0.5184)	$0.969875 	en:0.160337
(-0.490217,-0.5625)		(0.490217,-0.5625)	$0.980433 	en:0.160358
(-0.494866,-0.6084)		(0.494866,-0.6084)	$0.989732 	en:0.160373
(-0.498674,-0.6561)		(0.498674,-0.6561)	$0.997348 	en:0.160382
(-0.501464,-0.7056)		(0.501464,-0.7056)	$1.00293 	en:0.160387
(-0.503102,-0.7569)		(0.503102,-0.7569)	$1.0062 	en:0.160388
(-0.503506,-0.81)		(0.503506,-0.81)	$1.00701 	en:0.160388
(-0.502646,-0.8649)		(0.502646,-0.8649)	$1.00529 	en:0.160389
(-0.500551,-0.9216)		(0.500551,-0.9216)	$1.0011 	en:0.160394
(-0.4973,-0.9216)		(0.4973,-0.9216)	$0.994601 	en:0.160404
(-0.49303,-0.8649)		(0.49303,-0.8649)	$0.986061 	en:0.160421
(-0.487921,-0.81)		(0.487921,-0.81)	$0.975842 	en:0.160445
(-0.482192,-0.7569)		(0.482192,-0.7569)	$0.964384	en:0.160473
(-0.476092,-0.7056)		(0.476092,-0.7056)	$0.952184 	en:0.160503
(-0.46989,-0.6561)		(0.46989,-0.6561)	$0.93978 	en:0.160534
(-0.463859,-0.6084)		(0.463859,-0.6084)	$0.927719 	en:0.160562
(-0.45827,-0.5625)		(0.45827,-0.5625)	$0.916541 	en:0.160585
(-0.453375,-0.5184)		(0.453375,-0.5184)	$0.906751 	en:0.160602
(-0.449398,-0.4761)		(0.449398,-0.4761)	$0.898796 	en:0.160612
(-0.446523,-0.4356)		(0.446523,-0.4356)	$0.893046 	en:0.160616
(-0.444888,-0.3969)		(0.444888,-0.3969)	$0.889776 	en:0.160617
(-0.444577,-0.36)		(0.444577,-0.36)	$0.889154 	en:0.160617
(-0.445615,-0.3249)		(0.445615,-0.3249)	$0.891231 	en:0.160619
(-0.447969,-0.2916)		(0.447969,-0.2916)	$0.895938 	en:0.160625
(-0.451545,-0.2601)		(0.451545,-0.2601)	$0.903089 	en:0.160638
(-0.456195,-0.2304)		(0.456195,-0.2304)	$0.912389 	en:0.160658
(-0.461722,-0.2025)		(0.461722,-0.2025)	$0.923444 	en:0.160685
(-0.467888,-0.1764)		(0.467888,-0.1764)	$0.935777 	en:0.160717
(-0.474426,-0.1521)		(0.474426,-0.1521)	$0.948851 	en:0.160752
(-0.481047,-0.1296)		(0.481047,-0.1296)	$0.962093 	en:0.160787
(-0.487458,-0.1089)		(0.487458,-0.1089)	$0.974915 	en:0.160819
(-0.493372,-0.09)		(0.493372,-0.09)	$0.986744 	en:0.160844
(-0.498522,-0.0729)		(0.498522,-0.0729)	$0.997045 	en:0.160863
(-0.502673,-0.0576)		(0.502673,-0.0576)	$1.00535 	en:0.160874
(-0.505631,-0.0441)		(0.505631,-0.0441)	$1.01126 	en:0.160878
(-0.507254,-0.0324)		(0.507254,-0.0324)	$1.01451 	en:0.160879
(-0.507457,-0.0225)		(0.507457,-0.0225)	$1.01491 	en:0.160879
(-0.50622,-0.0144)		(0.50622,-0.0144)	$1.01244 	en:0.160881
(-0.503584,-0.0081)		(0.503584,-0.0081)	$1.00717 	en:0.160889
(-0.499655,-0.0036)		(0.499655,-0.0036)	$0.99931 	en:0.160904
(-0.494595,-0.0009)		(0.494595,-0.0009)	$0.989189 	en:0.160928
(-0.488618,-5.38198e-16)        (0.488618,-5.38198e-16)	$0.977237 	en:0.160959
(-0.481984,-0.0009)		(0.481984,-0.0009)	$0.963968 	en:0.160997
(-0.47498,-0.0036)		(0.47498,-0.0036)	$0.94996 	en:0.161037
(-0.467915,-0.0081)		(0.467915,-0.0081)	$0.93583 	en:0.161076
(-0.461102,-0.0144)		(0.461102,-0.0144)	$0.922204 	en:0.161112
(-0.454846,-0.0225)		(0.454846,-0.0225)	$0.909692 	en:0.16114
(-0.44943,-0.0324)		(0.44943,-0.0324)	$0.89886 	en:0.161161
(-0.445102,-0.0441)		(0.445102,-0.0441)	$0.890205 	en:0.161173
(-0.442065,-0.0576)		(0.442065,-0.0576)	$0.88413 	en:0.161178
(-0.440465,-0.0729)		(0.440465,-0.0729)	$0.880929 	en:0.161178
(-0.440385,-0.09)		(0.440385,-0.09)	$0.88077 	en:0.161178
(-0.441843,-0.1089)		(0.441843,-0.1089)	$0.883686 	en:0.161181
(-0.444787,-0.1296)		(0.444787,-0.1296)	$0.889575 	en:0.161191
(-0.449101,-0.1521)		(0.449101,-0.1521)	$0.898202 	en:0.161209
(-0.454604,-0.1764)		(0.454604,-0.1764)	$0.909208 	en:0.161237
(-0.461062,-0.2025)		(0.461062,-0.2025)	$0.922124 	en:0.161273
(-0.468197,-0.2304)		(0.468197,-0.2304)	$0.936395 	en:0.161316
(-0.475698,-0.2601)		(0.475698,-0.2601)	$0.951397 	en:0.161362
(-0.483235,-0.2916)		(0.483235,-0.2916)	$0.96647 	en:0.161407
(-0.490473,-0.3249)		(0.490473,-0.3249)	$0.980945 	en:0.161447
(-0.497087,-0.36)		(0.497087,-0.36)	$0.994174 	en:0.161479
(-0.502778,-0.3969)		(0.502778,-0.3969)	$1.00556 	en:0.161501
(-0.507286,-0.4356)		(0.507286,-0.4356)	$1.01457 	en:0.161514
(-0.510398,-0.4761)		(0.510398,-0.4761)	$1.0208 	en:0.161519
(-0.511965,-0.5184)		(0.511965,-0.5184)	$1.02393 	en:0.161519
(-0.511903,-0.5625)		(0.511903,-0.5625)	$1.02381 	en:0.161519
(-0.510201,-0.6084)		(0.510201,-0.6084)	$1.0204 	en:0.161523
(-0.506918,-0.6561)		(0.506918,-0.6561)	$1.01384 	en:0.161535
(-0.502188,-0.7056)		(0.502188,-0.7056)	$1.00438 	en:0.161557
(-0.496208,-0.7569)		(0.496208,-0.7569)	$0.992416 	en:0.161589
(-0.489232,-0.81)		(0.489232,-0.81)	$0.978463 	en:0.161632
(-0.481561,-0.8649)		(0.481561,-0.8649)	$0.963122 	en:0.161681
(-0.47353,-0.9216)		(0.47353,-0.9216)	$0.947061 	en:0.161734
(-0.465494,-0.9216)		(0.465494,-0.9216)	$0.930988 	en:0.161785
(-0.457808,-0.8649)		(0.457808,-0.8649)	$0.915617 	en:0.161829
(-0.450819,-0.81)		(0.450819,-0.81)	$0.901637 	en:0.161865
```

## 3rd Part
In this part, I projected an animation of the falling ball and springmass from the other parts. And the files used were: `simulation.h`, `ball.cpp`, `springmass.cpp`, `graphics.h`, `graphics.cpp` and `test-springmass-graphics.cpp`.

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
- **test-springmass-graphics.cpp** desenvolves the class `SpringMassDrawable()`, with the void methods `draw()` and `display()`. And has the main function that initializes the masses and spring, to animate.

### Class Diagram
Created with the help of `https://www.lucidchart.com/`, expressed in the `graphics_classdiagram.png` file.
![graphics class diagram](https://github.com/marcellapantarotto/TP1/blob/master/graphics_classdiagram.png)

### Graphics
Since I was not able to save the animation itself, I print screened some instances of the animation.

**Ball:**

![ball animation](https://github.com/marcellapantarotto/TP1/blob/master/ball_animation.png)

**Springmass:**

![springmass animation](https://github.com/marcellapantarotto/TP1/blob/master/springmass_animation.png)
