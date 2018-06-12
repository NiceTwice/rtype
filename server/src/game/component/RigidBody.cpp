#include	"game/component/RigidBody.hpp"

namespace Component {


    RigidBody::RigidBody(float width, float height) {
        this->width = width;
        this->height = height;
    }

    RigidBody::RigidBody(const Vector2f &size)
    {
        this->width = size.getX();
        this->height = size.getY();
    }

    RigidBody::~RigidBody()
    {

    }

    Type	RigidBody::getType() const
    {
        return (Type::RIGIDBODY);
    }

    std::string RigidBody::toString(void) const
    {
        std::stringstream ss;

        ss << "RigidBody { width: " << this->width << ", height: " << this->height << " }";
        return (ss.str());
    }

    void RigidBody::serialize(PacketSerializer&)
    {
        /**
         * packetSerializer << static_cast<uint32_t>(this->getType());
         * packetSerializer << this->width;
         * packetSerializer << this->height;
         */
    }
}

std::ostream& operator<<(std::ostream &os, Component::RigidBody const& rb)
{
  os << rb.toString();
  return (os);
}