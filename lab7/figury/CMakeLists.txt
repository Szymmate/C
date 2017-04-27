project(figure)

set(HEDEAR_FILES Ksztalt.h Kolo.h Kwadrat.h Trojkat.h)
set(SOURCE_FILES Ksztalt.cpp Kolo.cpp Kwadrat.cpp Trojkat.cpp)

add_library(libfigure STATIC ${SOURCE_FILES})
target_include_directories(libfigure PUBLIC .)

add_executable(figure ${SOURCE_FILES} main.cpp)

target_link_libraries(figure libfigure)

