cmake_minimum_required(VERSION 3.2)
project(server)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(EXECUTABLE_OUTPUT_PATH "..")

include_directories(../shared/include ../mobs include)

set(LDFLAGS)

set(HEADER_FILES
	../shared/include/game/component/ComponentType.hpp
	../shared/include/game/Vector2f.hpp
	../shared/include/game/map/Map.hpp
	../shared/include/game/map/Chunk.hpp
	../shared/include/game/map/MapEntity.hpp
	../shared/include/net/INetClient.hpp
	../shared/include/net/INetServer.hpp
	../shared/include/pool/ITask.hpp
	../shared/include/pool/Slave.hpp
	../shared/include/pool/TaskList.hpp
	../shared/include/pool/ThreadsPool.hpp
	../shared/include/thread/AStdThread.hpp
	../shared/include/thread/ICondVar.hpp
	../shared/include/thread/IMutex.hpp
	../shared/include/thread/IThread.hpp
	../shared/include/thread/StdCondVar.hpp
	../shared/include/thread/StdMutex.hpp
	../shared/include/tools/Singleton.hpp
	../shared/include/packet/exceptions/InvalidPacketError.hpp
	../shared/include/packet/PacketDeserializer.hpp
	../shared/include/packet/PacketSerializer.hpp
	../shared/include/packet/protocol/PacketIdentifier.hpp
	../shared/include/net/RingBuffer.hpp
	../shared/include/tools/Random.hpp
	../mobs/IMob.hpp
	include/exceptions/ArgumentParserException.hpp
	include/exceptions/LoaderException.hpp
	include/exceptions/LoadManagerException.hpp
	include/exceptions/SocketException.hpp
	include/json/JSONArray.hpp
	include/json/JSONObject.hpp
	include/json/JSONParser.hpp
	include/json/Parser.hpp
	include/loader/ALoader.hpp
	include/loader/ILoader.hpp
	include/loader/LoadManager.hpp
	include/net/ASocket.hpp
	include/net/TCPClientSocket.hpp
	include/net/ATCPSocket.hpp
	include/net/AUDPSocket.hpp
	include/net/ISocket.h
	include/net/Poll.hpp
	include/net/TCPServerSocket.hpp
	include/net/NetClient.hpp
	include/net/ANetClient.hpp
	include/net/TCPServer.hpp
	include/net/UDPSocket.hpp
	include/net/AUDPSocket.hpp
	include/net/SocketAddress.hpp
	include/packet/protocol/IProtocol.hpp
	include/packet/protocol/HelloPacket.hpp
	include/packet/protocol/MapPacket.hpp
	include/packet/protocol/PortPacket.hpp
	include/packet/protocol/ReadyPacket.hpp
	include/packet/protocol/EntityPacket.hpp
	include/packet/PacketReceiver.hpp
	include/packet/PacketSender.hpp
	include/packet/PacketProcesser.hpp
	include/game/component/Health.hpp
	include/game/component/IComponent.hpp
	include/game/component/Position.hpp
	include/game/component/Direction.hpp
	include/game/component/Velocity.hpp
	include/game/component/RigidBody.hpp
	include/game/component/Damage.hpp
	include/game/component/ACollidable.hpp
	include/game/component/Removable.hpp
	include/game/component/Sprite.hpp
	include/game/component/PlayerCollidable.hpp
	include/game/component/EnemyCollidable.hpp
	include/game/component/EnemyProjectileCollidable.hpp
	include/game/component/PlayerProjectileCollidable.hpp
	include/game/component/Fire.hpp
	include/game/component/AIComponent.hpp
	include/game/system/SystemManager.hpp
	include/game/system/ASystem.hpp
	include/game/system/MovementSystem.hpp
	include/game/system/HealthSystem.hpp
	include/game/system/CollisionSystem.hpp
	include/game/system/RemovingSystem.hpp
	include/game/system/FireSystem.hpp
	include/game/system/AISystem.hpp
	include/game/map/MapPool.hpp
	include/game/AEntity.hpp
	include/game/Entity.hpp
	include/game/EntityFactory.hpp
	include/game/World.hpp
	include/game/MobSpawner.hpp
	include/game/Player.hpp
	include/ArgumentParser.hpp
	include/ACore.hpp
	include/Core.hpp
	include/Converter.hpp
	include/GameUpdater.hpp
	../mobs/IMob.hpp)

set(SOURCE_FILES
	../shared/src/game/Vector2f.cpp
	../shared/src/game/map/Map.cpp
	../shared/src/game/map/Chunk.cpp
	../shared/src/game/map/MapEntity.cpp
	../shared/src/pool/Slave.cpp
	../shared/src/thread/AStdThread.cpp
	../shared/src/thread/StdCondVar.cpp
	../shared/src/thread/StdMutex.cpp
	../shared/src/packet/PacketDeserializer.cpp
	../shared/src/packet/PacketSerializer.cpp
	../shared/src/net/RingBuffer.cpp
	../shared/src/tools/Random.cpp
	src/json/JSONArray.cpp
	src/json/JSONObject.cpp
	src/json/JSONParser.cpp
	src/json/Parser.cpp
	src/net/ASocket.cpp
	src/net/TCPClientSocket.cpp
	src/net/ATCPSocket.cpp
	src/net/AUDPSocket.cpp
	src/net/Poll.cpp
	src/net/TCPServerSocket.cpp
	src/net/NetClient.cpp
	src/net/TCPServer.cpp
	src/net/UDPSocket.cpp
	src/net/AUDPSocket.cpp
	src/net/SocketAddress.cpp
	src/loader/LoadManager.cpp
	src/packet/protocol/HelloPacket.cpp
	src/packet/protocol/MapPacket.cpp
	src/packet/protocol/PortPacket.cpp
	src/packet/protocol/ReadyPacket.cpp
	src/packet/protocol/EntityPacket.cpp
	src/packet/PacketReceiver.cpp
	src/packet/PacketSender.cpp
	src/packet/PacketProcesser.cpp
	src/game/component/Health.cpp
	src/game/component/Position.cpp
	src/game/component/Direction.cpp
	src/game/component/Sprite.cpp
	src/game/component/Velocity.cpp
	src/game/component/RigidBody.cpp
	src/game/component/Damage.cpp
	src/game/component/ACollidable.cpp
	src/game/component/Removable.cpp
	src/game/component/PlayerCollidable.cpp
	src/game/component/EnemyCollidable.cpp
	src/game/component/EnemyProjectileCollidable.cpp
	src/game/component/PlayerProjectileCollidable.cpp
	src/game/component/Fire.cpp
	src/game/component/AIComponent.cpp
	src/game/system/SystemManager.cpp
	src/game/system/ASystem.cpp
	src/game/system/MovementSystem.cpp
	src/game/system/HealthSystem.cpp
	src/game/system/RemovingSystem.cpp
	src/game/system/ColllisionSystem.cpp
	src/game/system/FireSystem.cpp
	src/game/system/AISystem.cpp
	src/game/map/MapPool.cpp
	src/game/AEntity.cpp
	src/game/Entity.cpp
	src/game/EntityFactory.cpp
	src/game/World.cpp
	src/game/MobSpawner.cpp
	src/game/Player.cpp
	src/ArgumentParser.cpp
	src/ACore.cpp
	src/Core.cpp
	src/Converter.cpp
	src/GameUpdater.cpp
	src/main.cpp)

if (UNIX)
    set(HEADER_FILES ${HEADER_FILES}
	    include/loader/ASoLoader.hpp
	    include/loader/SoLoader.hpp)
    set(SOURCE_FILES ${SOURCE_FILES}
	    src/loader/ASoLoader.cpp
	    src/loader/SoLoader.cpp)
    set(LDFLAGS ${LDFLAGS} "-ldl")
    set(CMAKE_CXX_FLAGS_RELEASE "-W -Wall -Wextra -O2 -fomit-frame-pointer \
    -ffast-math -malign-double -msseregparm -msse3 -minline-all-stringops \
    -fgcse-lm -fgcse-sm -fforce-addr -pedantic-errors")
    set(CMAKE_CXX_FLAGS_DEBUG "-W -Wall -Wextra -O2 -fomit-frame-pointer \
    -ffast-math -malign-double -msseregparm -msse3 -minline-all-stringops \
    -fgcse-lm -fgcse-sm -fforce-addr -pedantic-errors -g3")
endif (UNIX)

if (WIN32)
    set(HEADER_FILES ${HEADER_FILES}
	    include/loader/ADllLoader.hpp
	    include/loader/DllLoader.hpp)
    set(SOURCE_FILES ${SOURCE_FILES}
	    src/loader/ADllLoader.cpp
	    src/loader/DllLoader.cpp)
endif (WIN32)

add_executable(server ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(
	server 
	PROPERTIES 
		OUTPUT_NAME "server"
		SUFFIX ".x86_64"
)

find_package(Threads)
target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT} ${LDFLAGS})

