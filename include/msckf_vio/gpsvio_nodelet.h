/*
 * COPYRIGHT AND PERMISSION NOTICE
 * Penn Software MSCKF_VIO
 * Copyright (C) 2017 The Trustees of the University of Pennsylvania
 * All rights reserved.
 */

#ifndef GPSVIO_NODELET_H
#define GPSVIO_NODELET_H

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <msckf_vio/gpsvio.h>

namespace msckf_vio {
class GPSVIONodelet : public nodelet::Nodelet {
public:
  GPSVIONodelet() { return; }
  ~GPSVIONodelet() { return; }

private:
  virtual void onInit();
  GPSVIOPtr gpsvio_ptr;
};
} // end namespace msckf_vio

#endif

