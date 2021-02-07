#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <cmath>

namespace husky_highlevel_controller
{
  HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle &nodeHandle):
   m_nodeHandle(&nodeHandle)
  {
    std::string scanTopicName;
    if (!m_nodeHandle->getParam("scan_topic_name", scanTopicName))
    {
      ROS_ERROR("Load scan_topic_name param fail!!");
      return;
    }

    int scanTopicQueueSize;
    if (!m_nodeHandle->getParam("scan_topic_queue_size", scanTopicQueueSize))
    {
      ROS_ERROR("Load scan_topic_queue_size param fail!!");
      return;
    }

    HuskyHighlevelController::m_laserScanSubscriber = m_nodeHandle->subscribe(scanTopicName, scanTopicQueueSize, &HuskyHighlevelController::laserCallBack, this);
  }

  HuskyHighlevelController::~HuskyHighlevelController()
  {
  }
  
  void HuskyHighlevelController::laserCallBack(const sensor_msgs::LaserScan::ConstPtr &msg)
  {
    float minVal = std::numeric_limits<float>::infinity();

    for (unsigned int i = 0; i < msg->ranges.size(); ++i)
    {
      if (std::isnormal(msg->ranges[i]))
      {
        minVal = std::min(minVal, msg->ranges[i]);
      }
    }

    ROS_INFO_STREAM(minVal);
  }

} /* namespace */