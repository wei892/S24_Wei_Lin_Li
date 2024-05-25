set(HEADER_FILES
    include/Empire.h
    src/EmpireApplication.h
    src/Ultility.h
    src/EmpireWindow.h
    src/WindowImpl.h 
    src/codeGLFW/WindowGLFW.h
    src/Renderer.h
    src/RendererImplement.h
    src/codeOpenGL/RendererOpenGL.h
    src/Shader.h
    src/ShaderImplement.h
    src/codeOpenGL/ShaderOpenGL.h
    src/Image.h
    src/ImageImplement.h
    src/codeOpenGL/ImageOpenGL.h
    src/EmpireEvents.h
    src/EmpireKeys.h
    src/Unit.h
)

set (SOURCE_FILES
    src/EmpireApplication.cpp
    src/EmpireWindow.cpp
    src/codeGLFW/WindowGLFW.cpp
    src/Renderer.cpp
    src/codeOpenGL/RendererOpenGL.cpp
    src/Shader.cpp
    src/codeOpenGL/ShaderOpenGL.cpp
    src/Image.cpp
    src/codeOpenGL/ImageOpenGL.cpp
    src/EmpireEvents.cpp
    src/Unit.cpp
)

add_library(Empire SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Empire 
    PUBLIC
        $<$<CONFIG:Debug>:EMPIRE_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:EMPIRE_DEBUG=1>
    PRIVATE 
        EMPIRE_LIB
        EMPIRE_GLFW_WINDOW
        EMPIRE_OPENGL
)

if (MSVC)
    target_compile_definitions(Empire PUBLIC EMPIRE_MS_COMPILER)
endif()

target_include_directories(Empire PRIVATE ../glfw/include)
target_include_directories(Empire PRIVATE ../Empire/src)
target_include_directories(Empire PRIVATE ../glad/include)
target_include_directories(Empire PRIVATE ../stbi)

target_precompile_headers(Empire PRIVATE src/pch.h)

target_link_libraries(Empire glfw)
target_link_libraries(Empire glad)
target_link_libraries(Empire stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Empire)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/Empire)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/Empire)