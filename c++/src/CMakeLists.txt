cmake_minimum_required(VERSION 3.10)


# set the project name
project(SC_DP_CPP VERSION 1.0)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(SC_DP_CPP 
	app.cpp
	creational/factorymethod.cpp
	creational/abstractfactory.cpp
	creational/builder.cpp
	creational/singleton.cpp
	structural/adapter.cpp
	structural/bridge.cpp
	structural/composite.cpp
	structural/decorator.cpp
	structural/facade.cpp
	structural/flyweight.cpp
	structural/proxy.cpp
	behavior/cor.cpp
	behavior/command.cpp
	behavior/iterator.cpp
	behavior/mediator.cpp
	behavior/memento.cpp
	behavior/observer.cpp
	behavior/state.cpp
	behavior/strategy.cpp
)

target_link_libraries(SC_DP_CPP PUBLIC ${EXTRA_LIBS})

target_include_directories(SC_DP_CPP PUBLIC 
  "${PROJECT_BINARY_DIR}"
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/creational>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/structural>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/behavior>
)

target_include_directories(SC_DP_CPP PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/base>
)

install(TARGETS SC_DP_CPP DESTINATION bin)