#pragma once
#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

/// Class for robot configuration.
///
/// A class for storing motor, sensor, brain, controller objects.
/// This class also holds most constants used throughout the program.
/// Classes \ref odometry, autonomousControl, and userControl will use
/// this class to access sensor data and motors.
class robotChasis{
  public:
    /// Gets pi value.
    ///
    /// PI value is derived from the pi approximation 355/113.
    /// @return pi value as a double
    double getPI();

    /// Gets left tracking wheel position.
    ///
    /// Current left tracking wheel position in degree units will be aqquired using this method.
    /// @return value of sL as a float.
    float getsL();

    /// Gets right tracking wheel position.
    ///
    /// Current right tracking wheel position in degree units will be aqquired using this method.
    /// @return value of sR as a float.
    float getsR();

    /// Gets back tracking wheel position.
    ///
    /// Current back tracking wheel position in degree units will be aqquired using this method.
    /// @return value of sS as a float.
    float getsS();

    /// Gets frbl value.
    ///
    /// Front right and back left wheel constant of 135 degrees.
    /// @return value frbl as a float
    float get_frbl();

    /// Gets flbr value.
    ///
    /// Front left and back right wheel constant of 45 degrees.
    /// @return value flbr as a float
    float get_flbr();

    /// Gets wheel circumference value of the tracking wheels.
    ///
    /// Wheel circumference of the right, left, back tracking wheels.
    /// @return value wheelCir as a double
    double getWheelCir();

    /// Controller Instance
    pros::Controller mController = pros::Controller(pros::E_CONTROLLER_MASTER);

    /// Front Right Motor Instance
    pros::Motor leftFront = pros::Motor(1, pros::E_MOTOR_GEARSET_18, true);

    /// Front Right Motor Instance
    pros::Motor leftMid = pros::Motor(12, pros::E_MOTOR_GEARSET_18, false);

    /// Front Left Motor Instance
    pros::Motor leftRear = pros::Motor(3, pros::E_MOTOR_GEARSET_18, true);

    /// Back Left Motor Instance
    pros::Motor rightFront = pros::Motor (4, pros::E_MOTOR_GEARSET_18, false);

    /// Back Right Motor Instance
    pros::Motor rightMid = pros::Motor(5, pros::E_MOTOR_GEARSET_18, true);

    /// Left Intake Motor Instance
    pros::Motor rightRear = pros::Motor(6, pros::E_MOTOR_GEARSET_18, false);

    /// Right Intake Motor Instance
    pros::Motor bottomIntake = pros::Motor(15, pros::E_MOTOR_GEARSET_18, true);

    /// Right Intake Motor Instance
    pros::Motor topIntake = pros::Motor(14, pros::E_MOTOR_GEARSET_18, true);

    /// Roller Motor Instance
    pros::Motor fly1 = pros::Motor(18, pros::E_MOTOR_GEARSET_06, false);

    /// Roller Motor Instance
    pros::Motor fly2 = pros::Motor(17, pros::E_MOTOR_GEARSET_06, true);

    //encoder leftTracker = encoder(Brain.ThreeWirePort.E);
    //encoder rightTracker = encoder(Brain.ThreeWirePort.A);
    //encoder backTracker = encoder(Brain.ThreeWirePort.C);
    /// Left Tracker Rotation Sensor Instance
    pros::Rotation leftTracker = pros::Rotation(7,true); //true

    /// Right Tracker Rotation Sensor Instance
    pros::Rotation rightTracker = pros::Rotation(8,false);

    /// Back Tracker Rotation Sensor Instance
    pros::Rotation backTracker = pros::Rotation(9,false);
    
    pros::ADIDigitalOut angler = pros::ADIDigitalOut('E');
    pros::ADIDigitalOut expansion = pros::ADIDigitalOut('G');
    pros::ADIDigitalOut indexer = pros::ADIDigitalOut('F');
    pros::ADIDigitalOut mouth = pros::ADIDigitalOut('H');

    /// IMU Sensor Instance
    pros::Imu gyroM = pros::Imu(10);

    /// Sets the brake type for the drive motors.
    ///
    /// Will set each drive motor to the brake type provided in the parameter field.
    /// @param B the type of break you want your to set your motors to.
    /// \see <a href="https://api.vexcode.cloud/v5/html/namespacevex.html#a2090f7d57d63c5cf693f269bc73568f1">vex::brakeType</a>
    void set_drive_break_type(pros::motor_brake_mode_e_t B);

    /// Stops all drive motors.
    ///
    /// Will brake all drive motors according their current brakeType.
    /// \see <a href="https://api.vexcode.cloud/v5/html/namespacevex.html#a2090f7d57d63c5cf693f269bc73568f1">vex::brakeType</a>
    void stopMotors();

    /// Constructor for the class \ref robotChasis.
    ///
    /// This constructor will create an instance of the class \ref robotChasis.
    /// It will set values to wheelDiameter, sL, sR, and sS.
    /// @param wD Wheel diameter in inches.
    /// @param tcL Left Tracking Wheel distance to tracking center. 
    /// @param tcR Right Tracking Wheel distance to tracking center. 
    /// @param tcB Back Tracking Wheel distance to tracking center. 
    robotChasis(float wD, float tcL, float tcR, float tcB);

  private:

    float wheelDiameter;
    double wheelCir;
    const double PI = 22/7;

    float sL;
    float sR;
    float sS;

    float frblWheels = 2.35619449;
    float flbrWheels = 0.7853981634;

    int autonSelect;
};

void  vexcodeInit( robotChasis *simp );