<<<<<<< HEAD
#pragma region VEXcode Generated Robot Configuration
#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;

//定义intake模式
int intake_mode = 0;//0：无模式，1：暂存，2：发射

// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
/*vex-vision-config:begin*/
vision::signature Vision13__BLUE_BALL = vision::signature (1, -2705, -1873, -2289,7615, 10485, 9050,2.1, 0);
vision Vision13 = vision (PORT13, 50, Vision13__BLUE_BALL);
/*vex-vision-config:end*/
#pragma endregion VEXcode Generated Robot Configuration

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int Brain_precision = 0, Console_precision = 0, Vision13_objectIndex = 0;

float myVariable;

// "when started" hat block
int whenStarted1() {
  //printf("1");
  Brain.Screen.print("VEXcode");
  
  
  int j = 0;
  while(true){
    Vision13.takeSnapshot(Vision13__BLUE_BALL);
    j++;
    Brain.Screen.setCursor(1, 1);
    //Brain.Screen.print('1');
    //Brain.Screen.newLine();
    Brain.Screen.print("N: %d", Vision13.objectCount);
    Brain.Screen.newLine();
    for(int i = 0; i < Vision13.objectCount; i++) {
      Brain.Screen.print("X: %d", Vision13.objects[i].centerX);
      Brain.Screen.newLine();
      Brain.Screen.print("Y: %d", Vision13.objects[i].centerY);
      Brain.Screen.newLine();
    }
    Brain.Screen.print(j);
    wait(0.1, seconds);
    Brain.Screen.clearScreen();

  }
  
  return 0;
}


int main() {
  whenStarted1();
}
=======
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Mar 18 2021                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Control_Motors.h"
#include "MyAutoPro.h"
#include "Remote_Control.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
 
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  AutoSetup();
  //RunPaw(50);


  int lineTrackerVal = 2880;
  AutoProRight(lineTrackerVal);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  RemoteSetUp();
  ShowTeamNum("16076A");
  int vehicle = 50, Roll = 50;
  while(1) MyRemote(vehicle,Roll);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods. 
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
 
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
>>>>>>> 9910aca (deshit)
