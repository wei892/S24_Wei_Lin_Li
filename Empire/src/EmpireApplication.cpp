#include "pch.h"
#include "EmpireApplication.h"
#include "EmpireWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Image.h"
#include "Shader.h"
#include "EmpireKeys.h"

namespace Empire
{
    EmpireApplication::EmpireApplication()
    {
         EmpireWindow::Init();
         EmpireWindow::GetWindow()->Create(1000, 1000);

         SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });

         Renderer::Init();
    }

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
        Initialize();

        mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

        // Main loop
        while (mShouldContinue)
        {
            Renderer::ClearScreen();

            OnUpdate();

            std::this_thread::sleep_until(mNextFrameTime);
            mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

            EmpireWindow::GetWindow()->SwapBuffers(); 
            EmpireWindow::GetWindow()->PollEvents();
        }
        Shutdown();
        EmpireWindow::Shutdown();
    }

    void EmpireApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
    {
        EmpireWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
    }

    void EmpireApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
    {
        EmpireWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
    }

    void EmpireApplication::SetWindowCloseCallback(std::function<void()> callbackFunc)
    {
        EmpireWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
    }

    void EmpireApplication::DefaultWindowCloseHandler()
    {
        mShouldContinue = false;
    }
}
