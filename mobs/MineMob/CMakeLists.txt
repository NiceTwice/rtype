cmake_minimum_required(VERSION 3.2)
project(MineMob)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(LIBRARY_OUTPUT_PATH "..")

include_directories(../../server/include ../../shared/include ./ ../)

set(LDFLAGS)

set(HEADER_FILES
        ../IMob.hpp
        ../../server/include/game/Entity.hpp
        ../../server/include/game/component/Position.hpp
        MineMob.hpp)
        
set(SOURCE_FILES
        MineMob.cpp)

ADD_LIBRARY(MineMob SHARED ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(
	MineMob 
	PROPERTIES 
		OUTPUT_NAME "MineMob"
)
