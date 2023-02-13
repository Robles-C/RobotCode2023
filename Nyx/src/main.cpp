#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "robot-config.h"
#include "chasisControl.h"
#include "autonomousRoutine.h"
#include "usercontrol.h"

#define TEST 0
#define RED_SIDE 1
#define BLUE_SIDE 2

robotChasis robot1 = robotChasis(2.5, 2.844, 2.875, 4.188);
odometry tracker = odometry(&robot1, 0, 0, 0);
autonomousControl autoChasis = autonomousControl(&robot1, &tracker);
autonomousRoutine autoRoutine = autonomousRoutine(&autoChasis);

int trackerWrapper(){
  tracker.updatePosition();
  return 0;
}

int printerWrapper(){
  tracker.updateScreen();
  return 0;
}

int autoWrapper(){
  autoChasis.autoMain();
  return 0;
}

pros::Task startTracking(trackerWrapper);
pros::Task startPrinting(printerWrapper);
pros::Task startAuto(autoWrapper);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 
void initialize() {
  robot1.gyroM.reset();
  pros::delay(500);
  //robot1.indexer.set_value(false);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch.
 */
void competition_initialize() {}

void autonomous() {
	//autoRoutine.run(TEST);
  int coutner = 1;
  int powe = 11200;
  
  robot1.fly1.move_voltage(powe);
  robot1.fly2.move_voltage(powe);

  if(coutner > 0){
  pros::delay(3000);
  robot1.indexer.set_value(true);
  pros::delay(1000);
  robot1.indexer.set_value(false);
  pros::delay(1000);
  robot1.indexer.set_value(true);
  pros::delay(1000);
  robot1.indexer.set_value(false);
  pros::delay(1000);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
    robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
    robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
    robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
    robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
    robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  robot1.expansion.set_value(false);
  pros::delay(150);
  robot1.expansion.set_value(true);
  pros::delay(150);
  coutner--;
  }else if(coutner == 0 || coutner < 0){
  powe = 0;
  powe = 0;
  }
}

void opcontrol() {
  //autoRoutine.run(RED_SIDE);
	//startAuto.remove();
  robot1.fly1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  robot1.fly2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	userControl driveMe = userControl(&robot1);
  driveMe.driveLoop();
}