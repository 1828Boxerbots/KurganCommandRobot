/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <RobotMap.h>
#include <frc/Victor.h>
#include <frc/commands/Subsystem.h>
#include <frc/XboxController.h>

using namespace frc;

class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  //Victor Motors w/ Port numbs
  Victor m_driveOne {DRIVE_ONE};
  Victor m_driveTwo {DRIVE_TWO};
  Victor m_driveThree {DRIVE_THREE};
  Victor m_driveFour {DRIVE_FOUR};

  Victor m_shootOne {SHOOT_ONE};
  Victor m_shootTwo {SHOOT_TWO};
  Victor m_shootThree {SHOOT_THREE};
  Victor m_shootFour {SHOOT_FOUR};

  //variables to hook up motors to controller
  double contrX = m_joyStick.GetX(GenericHID::kLeftHand);
  double contrY = m_joyStick.GetY(GenericHID::kRightHand);
  XboxController m_joyStick{XBOX_CONTROLLER};
 public:
 // Definition of commands
  DriveTrain();
  void TeleopDrive(XboxController* m_joyStick);
  void InitDefaultCommand() override;
  void StopDrive();
  void InvertDriveMotors();

};
