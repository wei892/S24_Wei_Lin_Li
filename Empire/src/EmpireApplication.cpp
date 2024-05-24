#include "pch.h"
#include "EmpireApplication.h"
#include "EmpireWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Image.h"
#include "Shader.h"
#include "Renderer.h"

namespace Empire
{
    void EmpireApplication::Initialize()
    {

    }

    void EmpireApplication::OnUpdate()
    {

    }

    void EmpireApplication::Shutdown()
    {

    }

    void EmpireApplication::Run()
    {
        
        EmpireWindow::Init();
        EmpireWindow::GetWindow()->Create(1000, 800);

        Renderer::Init();

        // Vertex Shader Source
        Shader sProg{ "C:\\Users\\wli24\\Documents\\CXX_Projects\\S24_Wei_Lin_Li\\Empire\\Assets\\Shaders\\DefaultVertexShader.glsl", "C:\\Users\\wli24\\Documents\\CXX_Projects\\S24_Wei_Lin_Li\\Empire\\Assets\\Shaders\\DefaultFragmentShader.glsl" };

        // Texture
        Empire::Image pic{ "C:\\Users\\wli24\\Documents\\CXX_Projects\\S24_Wei_Lin_Li\\Empire\\Assets\\Textures\\Test.png" };

        Initialize();

        mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
        int x{ 50 };

        // Main loop
        while (true)
        {
            Renderer::ClearScreen();

            OnUpdate();

            Renderer::Draw(pic, x, 100);
            x += 20;

            std::this_thread::sleep_until(mNextFrameTime);
            mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

            EmpireWindow::GetWindow()->SwapBuffers();
            EmpireWindow::GetWindow()->PollEvents();
        }
        Shutdown();
        EmpireWindow::Shutdown();
    }
}
