/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Victor.h>
#include <frc/XboxController.h>
#include "RobotMap.h"

using namespace frc;

class Shooter : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  //Victor Motors w/ Port Numbers
  Victor m_shootOne {SHOOT_ONE};
  Victor m_shootTwo {SHOOT_TWO};
  Victor m_shootThree {SHOOT_THREE};
  Victor m_shootFour {SHOOT_FOUR};

 public:
 // Definition of Commands
  Shooter();
  void TeleopShooter(XboxController* m_joyStick);
  void StopMotors();
  void InitDefaultCommand() override;
};
