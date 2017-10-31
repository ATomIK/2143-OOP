## After compiling,

```
Name of input file ('def' for 'input.txt'): def

Would you like to warp using pre-defined coordinates?

1. Yes
2. No.
1

Warping to (0,1)...


How many asteroids <9 tons would you like to collect before
 returning to earth? (integer): 5


Would you like to send the probe using pre-defined coordinates?

1. Yes
2. No.
1

Probe warped to (0,1)...


How many asteroids would you like the probe to scan before
 returning to earth? (integer): 5

== [ Beginning mission ] ==

Starship warped to: (4, 5). Mining asteroid...

Probe warped to: (4, 5). Scanning asteroid...
Asteroid did not contain precious metals...

Starship warped to: (5, 10). Mining asteroid...

Probe warped to: (5, 10). Scanning asteroid...
Asteroid contains precious metals!

Starship warped to: (0, 10). Mining asteroid...

Probe warped to: (0, 10). Scanning asteroid...
Asteroid did not contain precious metals...

Starship warped to: (20, 30). Mining asteroid...

Probe warped to: (20, 30). Scanning asteroid...
Asteroid contains precious metals!

Starship warped to: (30, 40). Mining asteroid...

Probe warped to: (30, 40). Scanning asteroid...
Asteroid did not contain precious metals...

== [ Mission complete ] ==

Our ship traveled: 581.82 miles!
Asteroids collected: 5

 ID | Coords | Weight
 0    (4, 5)  2.20
 1    (5, 10)  5.60
 2    (20, 30)  4.00
 3    (30, 40)  3.50
 7    (0, 10)  3.00

Our probe traveled: 581.82 miles!
It found 2 asteroids that contain precious metals!

 ID | Coords | Weight
 0    (5, 10)  5.60
 1    (20, 30)  4.00

```

## Strange bug...

```
Name of input file ('def' for 'input.txt'): def

Would you like to warp using pre-defined coordinates?

1. Yes
2. No.
2

Please enter an x coordinate followed by a y coordinate
 for the ship to warp to. ( Example: 5 25 ):50 50

Warping to (50,50)...


How many asteroids <9 tons would you like to collect before
 returning to earth? (integer): 3


Would you like to send the probe using pre-defined coordinates?

1. Yes
2. No.
1

Probe warped to (0,1)...


How many asteroids would you like the probe to scan before
 returning to earth? (integer): 3

== [ Beginning mission ] ==

Starship warped to: (50, 50). Mining asteroid...

Probe warped to: (4, 5). Scanning asteroid...
Asteroid did not contain precious metals...

Starship warped to: (40, 60). Mining asteroid...

Probe warped to: (5, 10). Scanning asteroid...
Asteroid contains precious metals!

Starship warped to: (40, 70). Mining asteroid...

Probe warped to: (0, 10). Scanning asteroid...
Asteroid did not contain precious metals...

== [ Mission complete ] ==

Our ship traveled: 241.42 miles!
Asteroids collected: 3

 ID | Coords | Weight
11    (40, 60)  8.70
12    (50, 50)  3.00
16    (40, 70)  4.50

Our probe traveled: 157.56 miles!
It found 1 asteroids that contain precious metals!

 ID | Coords | Weight

```
