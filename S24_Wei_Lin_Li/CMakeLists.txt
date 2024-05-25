add_executable(Game Source.cpp MyGame.h MyGame.cpp)

include_directories("../Empire/include")

target_link_libraries(Game Empire)