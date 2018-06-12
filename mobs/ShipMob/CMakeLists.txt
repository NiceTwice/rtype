cmake_minimum_required(VERSION 3.2)
project(ShipMob)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(LIBRARY_OUTPUT_PATH "..")

include_directories(../../server/include ../../shared/include ./ ../)

set(LDFLAGS)

set(HEADER_FILES
        ../IMob.hpp
        ../../server/include/game/Entity.hpp
        ../../server/include/game/component/Position.hpp
        ShipMob.hpp)
        
set(SOURCE_FILES
        ShipMob.cpp)

ADD_LIBRARY(ShipMob SHARED ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(
	ShipMob 
	PROPERTIES 
		OUTPUT_NAME "ShipMob"
)
