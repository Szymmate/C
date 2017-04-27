
project(point3d)

set(HEDEAR_FILES Point.h Point3d.h)
set(SOURCE_FILES Point.cpp Point3d.cpp)

add_library(libpoint3d STATIC ${SOURCE_FILES})
target_include_directories(libpoint3d PUBLIC .)

add_executable(point3d ${SOURCE_FILES} main.cpp)

target_link_libraries(point3d libpoint3d)

