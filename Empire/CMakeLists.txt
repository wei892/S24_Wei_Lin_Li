set(HEADER_FILES
    include/Empire.h
    src/EmpireApplication.h
    src/Ultility.h
    src/EmpireWindow.h
    src/WindowImpl.h 
    src/codeGLFW/WindowGLFW.h
)

set (SOURCE_FILES
    src/EmpireApplication.cpp
    src/EmpireWindow.cpp
    src/codeGLFW/WindowGLFW.cpp
)

add_library(Empire SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Empire 
    PUBLIC
        $<$<CONFIG:Debug>:EMPIRE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:EMPIRE_DEBUG=1>
    PRIVATE 
        EMPIRE_LIB
        EMPIRE_GLFW_WINDOW
)


if (MSVC)
    target_compile_definitions(Empire PUBLIC EMPIRE_MS_COMPILER)
endif()

target_include_directories(Empire PRIVATE ../glfw/include)
target_include_directories(Empire PRIVATE ../Sun)

target_precompile_headers(Empire PRIVATE src/pch.h)

target_link_libraries(Empire glfw)