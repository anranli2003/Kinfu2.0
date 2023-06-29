#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <iostream>
#include <string>

using namespace std;

void callback(const sensor_msgs::Image::ConstPtr& img_msg)
{
    std:: cout<< img_msg->header.seq<< "Image recieved"<< endl;
};

int main(int argc, char** argv)
{   string topic = "/rgb_to_depth/image_raw";
    ros::init(argc, argv, "robot");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<sensor_msgs::Image> (topic, 200, callback);
    ros::spin();
}