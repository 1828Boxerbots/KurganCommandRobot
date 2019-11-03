/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LoaderCMD.h"
#include "Robot.h"

LoaderCMD::LoaderCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_loader.get());
}

// Called just before this Command runs the first time
void LoaderCMD::Initialize() 
{
  Robot::m_loader->StopMotors();
}

// Called repeatedly when this Command is scheduled to run
void LoaderCMD::Execute() 
{
  Robot::m_loader->TeleopLoader(Robot::m_oi.GetController());
}

// Make this return true when this Command no longer needs to run execute()
bool LoaderCMD::IsFinished() 
{ 
  return false; 
}

// Called once after isFinished returns true
void LoaderCMD::End() 
{
  Robot::m_loader->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderCMD::Interrupted() 
{
  
}
