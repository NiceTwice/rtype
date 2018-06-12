cmake_minimum_required(VERSION 3.2)
project(client)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH "..")

include_directories(../shared/include include)

set(HEADER_FILES
        ../shared/include/game/Vector2f.hpp
        ../shared/include/game/map/Map.hpp
        ../shared/include/game/map/Chunk.hpp
        ../shared/include/game/map/MapEntity.hpp
        ../shared/include/game/map/MovableEntity.hpp
        ../shared/include/net/INetClient.hpp
        ../shared/include/net/INetServer.hpp
	../shared/include/net/RingBuffer.hpp
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
        ../shared/include/tools/Chrono.hpp
        ../shared/include/tools/Random.hpp
        ../shared/include/tools/Singleton.hpp
	../shared/include/net/ISocket.h
	../shared/include/packet/PacketDeserializer.hpp
	../shared/include/packet/PacketSerializer.hpp
	../shared/include/packet/protocol/PacketIdentifier.hpp
        include/core/GameCore.hpp
        include/game/AEntity.hpp
        include/game/Player.hpp
        include/gui/anim/FadeAnimation.hpp
        include/gui/anim/FrameAnimation.hpp
        include/gui/anim/IAnimation.hpp
        include/gui/anim/KeyAnimation.hpp
        include/gui/res/ResImageLoader.hpp
        include/gui/res/ResLoader.hpp
        include/gui/res/ResPool.hpp
        include/gui/scenes/AScene.hpp
        include/gui/scenes/GameMenuScene.hpp
        include/gui/scenes/LoadingScene.hpp
        include/gui/sfml/SFMLClock.hpp
        include/gui/sfml/SFMLImage.hpp
        include/gui/sfml/SFMLInputHandler.hpp
        include/gui/sfml/SFMLTexture.hpp
        include/gui/sfml/SFMLWindow.hpp
        include/gui/IInputHandler.hpp
        include/gui/IView.hpp
        include/gui/IWindow.hpp
        include/gui/MainWindow.hpp
        include/gui/SceneManager.hpp
	include/packet/protocol/IProtocol.hpp
	include/packet/protocol/HelloPacket.hpp
	include/packet/protocol/MapPacket.hpp
	include/packet/protocol/PortPacket.hpp
	include/packet/protocol/ReadyPacket.hpp
	include/packet/protocol/EntityPacket.hpp
	include/packet/protocol/SpawnPacket.hpp
	include/packet/protocol/EndPacket.hpp
	include/packet/PacketProcesser.hpp
	include/packet/PacketSender.hpp
	include/packet/PacketReceiver.hpp
	include/net/exceptions/DisconnectionException.hpp
	include/net/IClientSocket.hpp
	include/net/IServerSocket.hpp
	include/net/UDPClientSocket.hpp
	include/net/UDPServerSocket.hpp
	include/net/TCPClientSocket.hpp
	include/net/UDPManager.hpp
	include/net/TCPManager.hpp
	include/net/Network.hpp
	include/Printer.hpp
	include/ArgParser.hpp
        include/Client.hpp
        include/gui/scenes/GameBoardScene.hpp include/gui/IEvent.hpp include/gui/sfml/SFMLEvent.hpp ../shared/include/tools/Random.hpp include/gui/sfml/SFMLRectangle.hpp include/gui/gfx/BlueStarsBackground.hpp include/gui/gfx/ABackground.hpp include/gui/gfx/InsideShipBackground.hpp ../shared/include/game/map/MovableEntity.hpp include/gui/gfx/PlayerDrawable.hpp include/gui/gfx/ADrawable.hpp include/gui/gfx/ImageDrawable.hpp include/gui/gfx/InsideMineBackground.hpp include/gui/sfml/SFMLMusic.hpp include/gui/res/ResMusicLoader.hpp include/gui/IMusic.hpp include/gui/sfml/SFMLSound.hpp include/gui/res/ResSoundLoader.hpp include/gui/gfx/MobDrawable.hpp include/gui/res/ResFontLoader.hpp include/gui/sfml/SFMLFont.hpp include/gui/sfml/SFMLText.hpp)

set(SOURCE_FILES
        ../shared/src/game/Vector2f.cpp
        ../shared/src/game/map/Map.cpp
        ../shared/src/game/map/Chunk.cpp
        ../shared/src/game/map/MapEntity.cpp
        ../shared/src/game/map/MovableEntity.cpp
        ../shared/src/pool/Slave.cpp
        ../shared/src/tools/Chrono.cpp
        ../shared/src/thread/AStdThread.cpp
        ../shared/src/thread/StdCondVar.cpp
        ../shared/src/thread/StdMutex.cpp
	../shared/src/net/RingBuffer.cpp
	../shared/src/packet/PacketDeserializer.cpp
	../shared/src/packet/PacketSerializer.cpp
        src/core/GameCore.cpp
        src/game/AEntity.cpp
        src/game/Player.cpp
        src/gui/anim/FadeAnimation.cpp
        src/gui/anim/FrameAnimation.cpp
        src/gui/anim/KeyAnimation.cpp
        src/gui/res/ResImageLoader.cpp
        src/gui/res/ResLoader.cpp
        src/gui/res/ResPool.cpp
        src/gui/scenes/AScene.cpp
        src/gui/scenes/GameMenuScene.cpp
        src/gui/scenes/LoadingScene.cpp
        src/gui/sfml/SFMLClock.cpp
        src/gui/sfml/SFMLImage.cpp
        src/gui/sfml/SFMLInputHandler.cpp
        src/gui/sfml/SFMLTexture.cpp
        src/gui/sfml/SFMLWindow.cpp
        src/gui/MainWindow.cpp
        src/gui/SceneManager.cpp
	src/packet/protocol/HelloPacket.cpp
	src/packet/protocol/MapPacket.cpp
	src/packet/protocol/PortPacket.cpp
	src/packet/protocol/ReadyPacket.cpp
	src/packet/protocol/EntityPacket.cpp
	src/packet/protocol/SpawnPacket.cpp
	src/packet/protocol/EndPacket.cpp
	src/packet/PacketProcesser.cpp
	src/packet/PacketSender.cpp
	src/packet/PacketReceiver.cpp
	src/net/UDPClientSocket.cpp
	src/net/UDPServerSocket.cpp
	src/net/TCPClientSocket.cpp
	src/net/UDPManager.cpp
	src/net/TCPManager.cpp
	src/net/Network.cpp
	src/Printer.cpp
	src/ArgParser.cpp
        src/Client.cpp
        src/Main.cpp
        src/gui/scenes/GameBoardScene.cpp src/gui/sfml/SFMLEvent.cpp ../shared/src/tools/Random.cpp src/gui/sfml/SFMLRectangle.cpp src/gui/gfx/BlueStarsBackground.cpp src/gui/gfx/ABackground.cpp src/gui/gfx/InsideShipBackground.cpp ../shared/src/game/map/MovableEntity.cpp src/gui/gfx/PlayerDrawable.cpp src/gui/gfx/ADrawable.cpp src/gui/gfx/ImageDrawable.cpp src/gui/gfx/InsideMineBackground.cpp src/gui/sfml/SFMLMusic.cpp src/gui/res/ResMusicLoader.cpp src/gui/sfml/SFMLSound.cpp src/gui/res/ResSoundLoader.cpp src/gui/gfx/MobDrawable.cpp src/gui/res/ResFontLoader.cpp src/gui/sfml/SFMLFont.cpp src/gui/sfml/SFMLText.cpp)

if (UNIX)
    set(CMAKE_CXX_FLAGS_RELEASE "-W -Wall -Wextra -O2 -fomit-frame-pointer \
    -ffast-math -malign-double -msseregparm -msse3 -minline-all-stringops \
    -fgcse-lm -fgcse-sm -fforce-addr -pedantic-errors")
endif (UNIX)

add_executable(client ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(
	client 
	PROPERTIES 
		OUTPUT_NAME "client"
		SUFFIX ".x86_64"
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/client/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package (Threads)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(client ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()
