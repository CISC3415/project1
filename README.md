# CISC3415 - Project 1
_Group Members: Benjamin Yi, Emmanuel Desdunes, Montasir Omi, Shah Zada_

This project uses the [Player/Stage](http://playerstage.sourceforge.net/index.php) software to control a iRobot Roomba with the goal of instructing the robot to move along a 3-feet square both clockwise (Part 2) and counter-clockwise (Part 1). The team runs five tests for each part, measuring the error as the difference in distance between the start and end points using (x, y) coordinates.

## Part 1 - Counter-Clockwise

### Description
Instructs a robot, specifically a Roomba, to move forward for an estimated 3 feet, and rotate for an estimated 90 degrees for four iterations, moving along a 3-feet square.

### Results
_based on an (x, y) distance between the start and end locations in inches_

| Round #        | (Δx, Δy) _in._  |
|:-------------:|:-------------:|
| 1 | (  0.0, -2.0) |
| 2 | (  0.0, +3.0) |
| 3 | ( -2.0, -4.0) |
| 3 | ( -2.0, -1.0) |
| 3 | ( -2.0, -1.0) |

## Part 2 - Clockwise

### Description
Instructs a robot, specifically a Roomba, to move forward for an estimated 3 feet, and rotate for an estimated 90 degrees for four iterations, moving along a 3-feet square.

### Results
_based on an (x, y) distance between the start and end locations in inches_

| Round #        | (Δx, Δy) _in._  |
|:-------------:|:-------------:|
| 1 | (  0.0,  0.0) |
| 2 | (  0.0,  0.0) |
| 3 | ( -2.5, -2.5) |
| 3 | (  0.0,  0.0) |
| 3 | ( -2.0, 0.0) |
