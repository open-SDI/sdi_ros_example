#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Listener : public rclcpp::Node
{
	public:
		Listener()
		: Node("listener1")
		{
			auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
			listener_ = this->create_subscription<std_msgs::msg::String>(
				"chatter1",
				qos_profile,
				std::bind(&Listener::listen_topic_msg, this, _1));
		}

	private:
		void listen_topic_msg(const std_msgs::msg::String::SharedPtr msg) const
		{
			RCLCPP_INFO(this->get_logger(), "Recv Msg : '%s'", msg->data.c_str());
		}
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr listener_;
};


int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<Listener>();
	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}
