#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MultipleTopicsTalker : public rclcpp::Node
{
	public:
		MultipleTopicsTalker()
		: Node("multiple_topics_talker"), count_(0)
		{
			auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
			multiple_topics_talker1_ = this->create_publisher<std_msgs::msg::String>(
					"chatter1", qos_profile);
			multiple_topics_talker2_ = this->create_publisher<std_msgs::msg::String>(
					"chatter2", qos_profile);
			timer_ = this->create_wall_timer(
					1s, std::bind(&MultipleTopicsTalker::multiple_topics_msg, this));
		}

	private:
		void multiple_topics_msg()
		{
			auto chatter1_msg = std_msgs::msg::String();
			chatter1_msg.data = "Hello World : " + std::to_string(count_++);
			RCLCPP_INFO(this->get_logger(), "Chatter1 Published message : '%s'", chatter1_msg.data.c_str());
			multiple_topics_talker1_->publish(chatter1_msg);

			auto chatter2_msg = std_msgs::msg::String();
			chatter2_msg.data = "Hello World : " + std::to_string(count_++);
			RCLCPP_INFO(this->get_logger(), "Chatter2 Published message : '%s'", chatter2_msg.data.c_str());
			multiple_topics_talker2_->publish(chatter2_msg);
		}

		rclcpp::TimerBase::SharedPtr timer_;
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr multiple_topics_talker1_;
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr multiple_topics_talker2_;
		size_t count_;
};

int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<MultipleTopicsTalker>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}
