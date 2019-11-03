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
  double leftY = m_joyStick->GetY(GenericHID::kLeftHand);
  double rightY = m_joyStick->GetY(GenericHID::kRightHand);
  m_driveOne.Set(leftY);
  m_driveTwo.Set(leftY);
  m_driveThree.Set(rightY);
  m_driveFour.Set(rightY);
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
