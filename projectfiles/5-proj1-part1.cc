/*
 *  CISC-3415 Robotics
 *  Project 1 - Part 1
 *  Date: 10th September 2019
 *
 ** Group Members *************************************************************
 *    
 *  Benjamin Yi
 *  Emmanuel Desdunes
 *  Montasir Omi
 *  Shah Zada
 *
 ** Description ***************************************************************
 * 
 *  The purpose of this project is to test errors in movement caused by dead 
 *  reckoning. The program instructs a robot, specifically a Roomba, to move
 *  forward for an estimated 3 feet, and rotate for an estimated 90 degrees for
 *  four iterations, moving along a 3-foot square. The program is run five
 *  times, and the dx and dy of the start and end locations are recorded each
 *  round. 
 *
 ** Error Measurements ********************************************************
 *
 *  Based on an (x, y) distance between the start and end locations
 *  Round 1: ( 0.0, -2.0)
 *  Round 2: ( 0.0, +3.0)
 *  Round 3: (-2.0, -4.0)
 *  Round 4: (-2.0, -1.0)
 *  Round 5: (-2.0, -1.0)
 * 
 ** Results *******************************************************************
 * 
 *  On average, the start and end locations differ by about (-2.0, -1.0) in the
 *  y direction . This was the average dx and dy even through the additional
 *  test rounds. Since this difference seemed consistent, it is probable that
 *  there is an error with the turnrate value in the program. A consistent
 *  (-)dx is probably the result of the robot turning a bit beyond 90 degrees,
 *  which can be observed by increasing the anglesof a square by a small amount,
 *  assuming it is a "counter-clockwise square".Any inconsistencies with this
 *  result was most likely due to dead reckoning, since each step of the
 *  program may have caused the robot to travel and turn at a rate inconsistent
 *  to a perfect simulation.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <libplayerc++/playerc++.h>
#include <time.h>

int main(int argc, char *argv[])
{
  using namespace PlayerCc;

  // Set up proxy. Proxies are the datastructures that Player uses to
  // talk to the simulator and the real robot.

  PlayerClient    robot("localhost");
  Position2dProxy pp(&robot,0);       // The 2D proxy is used to send
                                      // motion commands.

  // A timer which increments per 1 second, estimated by the CPU clock
  // using the <time.h> library.
  int timer, t = 0;

  // Speed adjusts forward motion speed
  // Turnrate adjusts rotational speed
  double speed, turnrate;

  // Allow the program to take charge of the motors (take care now)
  pp.SetMotorEnable(true);

  // Read from the proxies.
  robot.Read();

  for (int i = 0; i < 4; i++) {
    // Sets speed, estimated based on 3 feet per (X) seconds
    // Sets turnrate, estimated based on 90 degrees per (Y) seconds
    speed = 0.2;
    turnrate = 0.2;                   // A positive value instructs the
                                      // robot to rotate counter-clockwise

    // Sets physical movement to forward motion at rate of (speed)
    pp.SetSpeed(speed, 0);

    t = clock()/CLOCKS_PER_SEC;
    timer = 0;

    // Moves for ~ 5 seconds, (an estiamted 3 feet)
    while (timer < 5) {
      while (clock()/CLOCKS_PER_SEC-t < 1);
      t = clock()/CLOCKS_PER_SEC;
      timer++;
    }

    // Sets physical movement to rotational motion at rate of (turnrate)
    pp.SetSpeed(0, turnrate);

    t = clock()/CLOCKS_PER_SEC;
    timer = 0;

    // Rotates for ~ 4 seconds, (an estimated 90 degrees)
    while (timer < 4) {
      while (clock()/CLOCKS_PER_SEC-t < 1);
      t = clock()/CLOCKS_PER_SEC;
      timer++;
    }
  }
}
