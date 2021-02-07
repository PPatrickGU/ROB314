#pragma once

#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

namespace husky_highlevel_controller
{

  /*!
   * Class containing the Husky Highlevel Controller
   */
  class HuskyHighlevelController
  {
  public:
    /*!
     * Constructor.
     */
    HuskyHighlevelController(ros::NodeHandle &nodeHandle);

    /*!
     * Destructor.
     */
    virtual ~HuskyHighlevelController();

  private:
    ros::NodeHandle* m_nodeHandle;
    ros::Subscriber m_laserScanSubscriber;

    void laserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg);
  };

} /* namespace */