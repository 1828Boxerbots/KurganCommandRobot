/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem") {}

void Shooter::TeleopShooter(XboxController* m_joyStick)
{
  //Shoot
  double strength = 1.0;
  bool shoot = m_joyStick->GetBumper(GenericHID::kRightHand);
  if (shoot)
  {
    m_shootOne.Set(strength);
    m_shootTwo.Set(strength);
    m_shootThree.Set(strength);
    m_shootFour.Set(strength);
  }
  if (!shoot)
  {
    StopMotors();
  }
}

void Shooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

//Emergency Shooter Motor Stop
void Shooter::StopMotors()
{
  m_shootOne.Set(0.0);
  m_shootTwo.Set(0.0);
  m_shootThree.Set(0.0);
  m_shootFour.Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
