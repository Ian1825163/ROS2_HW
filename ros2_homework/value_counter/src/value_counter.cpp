#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
// Hint: include the ROS2 integer 32 bit library for messaging

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv); // initialize arguments argc and argv
    auto node = rclcpp::Node::make_shared("publisher_node"); // create a share pointer to the new instance of the rclcpp::Node class, nad specify the name of the node  
    auto publisher = node->create_publisher<std_msgs::msg::Int32>("count_values", 10); // set the topic name "count_value" and the queue size 10
    
    // 
    rclcpp::Rate loop_rate(1);
        
    int count = 1;
    while (rclcpp::ok() && count <= 5)
    {
        auto msg = std_msgs::msg::Int32();
	msg.data = count;



        // Fill the missing line of code
        // Hint: makes the content of "msg" to be the value of "count" variable

        publisher->publish(msg);
        RCLCPP_INFO(node->get_logger(), "Publishing: %d", msg.data); // Explain this line
        // Fill the missing line of code
        // Hint: execute the callback function under the "node" node

        loop_rate.sleep();
        count++;
    }
    
    rclcpp::shutdown();
    return 0;    
}

