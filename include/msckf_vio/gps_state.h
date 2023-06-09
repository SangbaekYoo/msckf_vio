/*
 * COPYRIGHT AND PERMISSION NOTICE
 * Penn Software MSCKF_VIO
 * Copyright (C) 2017 The Trustees of the University of Pennsylvania
 * All rights reserved.
 */

#ifndef MSCKF_VIO_GPS_STATE_H
#define MSCKF_VIO_GPS_STATE_H

#include <map>
#include <vector>
#include <Eigen/Dense>

#include "imu_state.h"

namespace msckf_vio {
/*
 * @brief GPS state in order to
 *    form measurement model.
 */
struct GPSState {
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  // An unique identifier for the GPS state.
  StateIDType id;

  // Time when the state is recorded
  double time;

  // Orientation
  // Take a vector from the vio frame to the ENU frame.
  Eigen::Vector4d orientation;

  // Position of the vio frame in the ENU frame.
  Eigen::Vector3d position;

  // These two variables should have the same physical
  // interpretation with `orientation` and `position`.
  // There two variables are used to modify the measurement
  // Jacobian matrices to make the observability matrix
  // have proper null space.
  Eigen::Vector4d orientation_null;
  Eigen::Vector3d position_null;

  // Takes a vector from the gps frame to the imu frame.
  Eigen::Vector3d t_gps_imu;

  GPSState(): id(0), time(0),
    orientation(Eigen::Vector4d(0, 0, 0, 1)),
    position(Eigen::Vector3d::Zero()),
    orientation_null(Eigen::Vector4d(0, 0, 0, 1)),
    position_null(Eigen::Vector3d(0, 0, 0)) {}

  GPSState(const StateIDType& new_id ): id(new_id), time(0),
    orientation(Eigen::Vector4d(0, 0, 0, 1)),
    position(Eigen::Vector3d::Zero()),
    orientation_null(Eigen::Vector4d(0, 0, 0, 1)),
    position_null(Eigen::Vector3d::Zero()) {}
};

}// namespace msckf_vio

#endif // MSCKF_VIO_GPS_STATE_H
