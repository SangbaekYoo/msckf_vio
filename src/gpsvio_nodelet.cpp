/*
 * COPYRIGHT AND PERMISSION NOTICE
 * Penn Software MSCKF_VIO
 * Copyright (C) 2017 The Trustees of the University of Pennsylvania
 * All rights reserved.
 */

#include <msckf_vio/gpsvio_nodelet.h>

namespace msckf_vio {
void GPSVIONodelet::onInit() {
  ROS_INFO("I am here gpsvio_nodelet");
  gpsvio_ptr.reset(new GPSVIO(getPrivateNodeHandle()));
  if (!gpsvio_ptr->initialize()) {
    ROS_ERROR("Cannot initialize MSCKF VIO...");
    return;
  }
  return;
}

PLUGINLIB_EXPORT_CLASS(msckf_vio::GPSVIONodelet,
    nodelet::Nodelet);

} // end namespace msckf_vio

