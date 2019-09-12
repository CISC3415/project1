/*
 *  CISC-3415 Robotics
 *  Project 1 - Part 1
 *  Date: 10th September 2019
 *
 *
 *  GROUP 5 - Members
 *    Benjamin Yi
 *    Emmanuel Desdunes
 *    Montasir Omi
 *    Shah Zada
 *
 *
 *  DESCRIPTION
 *  Instructs a robot, specifically a Roomba, to move forward for
 *  for an estimated 3 feet, and rotate for an estimated 90 degrees
 *  for four iterations, moving along a 3-feet square.
 *
 *
 *  ERROR MEASUREMENTS
 *  Based on an (x, y) distance between the start and end locations
 *  Round 1: ( 0.0, -2.0)
 *  Round 2: ( 0.0,  3.0)
 *  Round 3: (-2.0, -4.0)
 *  Round 4: (-2.0, -1.0)
 *  Round 5: (-2.0, -1.0)
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
    turnrate = 0.2;                   // A position value instructs the
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

  // Stops the robot
  pp.SetSpeed(0, 0);

      // First make the rbot go straight ahead, then make it turn, and
      // finally make it stop.
      // After running the roomba ends at the coordinates left turn
      // (0, -2) ; (0, 3) ; (-2, -4) ; (-2, -1) ; (-2, -1)
      // right turn
      // (0, 0) ; (0, 0) ; (-2.5, -2.5) ; (0, 0) ; (-2, 0)
      // when using the starting point as a reference.
      for (int i = 0; i < 4; i++) {
      	timer = 0;
      	speed = 0.2;
      	turnrate = 0.2;
      	//
        pp.SetSpeed(speed, 0);
        int a = clock()/CLOCKS_PER_SEC;
      	// move forward
      	while (timer < 5) {
      	    while (clock()/CLOCKS_PER_SEC-a < 1);
      	    a = clock()/CLOCKS_PER_SEC;
      		timer++;
      		std::cout << "Forward" << std::endl;
      	}

      	timer = 0;
      	pp.SetSpeed(0, turnrate);
      	a = clock()/CLOCKS_PER_SEC;
      	while (timer < 4) {
      	    while (clock()/CLOCKS_PER_SEC-a < 1);
      	    a = clock()/CLOCKS_PER_SEC;
      		timer++;
      		std::cout << "Rotate" << std::endl;
      	}
      }

      pp.SetSpeed(0, 0);


      //second loop doing the right turn
      for (int i = 0; i < 4; i++) {
      	timer = 0;
      	speed = 0.2;
      	turnrate = -0.2;
      	//
        pp.SetSpeed(speed, 0);
        int a = clock()/CLOCKS_PER_SEC;
      	// move forward
      	while (timer < 5) {
      	    while (clock()/CLOCKS_PER_SEC-a < 1);
      	    a = clock()/CLOCKS_PER_SEC;
      		timer++;
      		std::cout << "Forward" << std::endl;
      	}

      	timer = 0;
      	pp.SetSpeed(0, turnrate);
      	a = clock()/CLOCKS_PER_SEC;
      	while (timer < 4) {
      	    while (clock()/CLOCKS_PER_SEC-a < 1);
      	    a = clock()/CLOCKS_PER_SEC;
      		timer++;
      		std::cout << "Rotate" << std::endl;
      	}
      	// rotate
      }

      pp.SetSpeed(0, 0);

}