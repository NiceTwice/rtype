#include	"game/component/Health.hpp"

namespace Component
{
	Health::Health()
	{
		this->val = 100;
		this->changeAmount = 0;
	}

	Health::Health(int32_t health)
	{
		this->val = health;
		this->changeAmount = 0;
	}

	Health::~Health()
	{

	}

	Type		Health::getType() const
	{
		return (Type::HEALTH);
	}

	std::string	Health::toString(void) const
	{
		std::stringstream ss;

		ss << "Health { value: " << this->val << ", changeAmount: " << this->changeAmount << " }";
		return (ss.str());
	}

	void Health::serialize(PacketSerializer& packetSerializer)
	{
		packetSerializer << static_cast<uint32_t>(this->getType());
		packetSerializer << this->val;
	}
}

std::ostream& operator<<(std::ostream &os, Component::Health const& health)
{
  os << health.toString();
  return (os);
}