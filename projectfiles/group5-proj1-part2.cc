/*
 *  CISC-3415 Robotics
 *  Project 1 - Part 2
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
 *  Similar to part 1 of this project, this program instead negates the
 *  turnrate causing the robot to travel on a "clockwise square". Again, we
 *  measure the errors caused by dead reckoning.
 *
 ** Error Measurements ********************************************************
 *
 *  Based on an (x, y) distance between the start and end locations
 *  Round 1: ( 0.0,  0.0)
 *  Round 2: ( 0.0,  0.0)
 *  Round 3: (-2.0, -2.0)
 *  Round 4: ( 0.0,  0.0)
 *  Round 5: (-2.0,  0.0)
 * 
 ** Results *******************************************************************
 * 
 *  The results of this program was very different comparent to the first part.
 *  For most rounds, the robot landed with a very small error, which was
 *  recorded as (dx = 0.0, dy = 0.0). Since the value of the turnrate was only
 *  negated and not changed, the result should have shown a consistent dx of 
 *  -2.0 caused by a turn greater than 90 degrees. We believe was because the
 *  robot may not have the same left turnrate and a right turnrate. 
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
    turnrate = -0.2;                   // A negative value instructs the
                                       // robot to turn clockwise.

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

    // Rotates for ~ 4 seconds, (an estimated -90 degrees)
    while (timer < 4) {
      while (clock()/CLOCKS_PER_SEC-t < 1);
      t = clock()/CLOCKS_PER_SEC;
      timer++;
    }
  }
}
