cmake_minimum_required(VERSION 3.10)


# set the project name
project(SC_DP_CPP VERSION 1.0)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(SC_DP_CPP app.cpp)

target_link_libraries(SC_DP_CPP PUBLIC ${EXTRA_LIBS})

target_include_directories(SC_DP_CPP PUBLIC 
  "${PROJECT_BINARY_DIR}" 
)

install(TARGETS SC_DP_CPP DESTINATION bin)