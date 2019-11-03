/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Loader.h"

Loader::Loader() : Subsystem("Loader") {}

void Loader::TeleopLoader(XboxController* m_joyStick)
{
  //Loading
  bool pullIn = m_joyStick->GetAButton();
  if (pullIn){
    m_loader.Set(-1.0);
  }
  //Ejecting
  bool eject = m_joyStick->GetBButton();
  if (eject){
    m_loader.Set(1.0);
  }
  //Stationary
  if((!pullIn && !eject) || (pullIn && eject))
  {
    m_loader.Set(0.0);
  }
}

void Loader::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

//Emergency Loader Motor stop
void Loader::StopMotors()
{
  m_loader.Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
