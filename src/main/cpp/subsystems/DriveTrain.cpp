/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::TeleopDrive(XboxController* m_joyStick) 
{
  //makes leftJoystickX and Y hook up to the left joystick on the controller
  //aka Arcade Drive. Sue me
double leftJoystickX = m_joyStick->GetX(GenericHID::kLeftHand);
double leftJoystickY = m_joyStick->GetY(GenericHID::kLeftHand);

  m_driveOne.Set(leftJoystickX + leftJoystickY);
  m_driveTwo.Set(leftJoystickX + leftJoystickY);
  m_driveThree.Set(leftJoystickX + leftJoystickY);
  m_driveFour.Set(leftJoystickX + leftJoystickY);
} 
void DriveTrain::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
//Emergency drive motor stop
void DriveTrain::StopDrive() 
{
 m_driveOne.Set(0.0);
  m_driveTwo.Set(0.0);
  m_driveThree.Set(0.0);
  m_driveFour.Set(0.0);
}
//Here to  "conviently" change motors inverted or not
void DriveTrain::InvertDriveMotors()
{
m_driveOne.SetInverted(false);
m_driveTwo.SetInverted(false);
m_driveThree.SetInverted(false);
m_driveFour.SetInverted(false);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
