#include "pch.h"

#include "RendererOpenGL.h"
#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "EmpireWindow.h"

namespace Empire
{
	RendererOpenGL::RendererOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			EMPIRE_ERROR("Failed to initialize GLAD");
			return;
		}
        mShaderPtr = std::unique_ptr<Shader>{ new Shader { "../Empire/Assets/Shaders/defaultVertexShader.glsl", "../Empire/Assets/Shaders/defaultFragmentShader.glsl" } };

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	RendererOpenGL::~RendererOpenGL()
	{

	}

	void RendererOpenGL::Draw(Image& pic, int x, int y)
	{
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        float vertices[] = {
            x, y, 0.0, 0.0, // left
            x + pic.GetWidth(), y, 1.0, 0.0,  // right
            x, y + pic.GetHeight(), 0.0, 1.0,  // top
            x + pic.GetWidth(), y + pic.GetHeight(), 1.0, 1.0    // bottom
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Draw first triangle
        mShaderPtr->Bind();
        mShaderPtr->SetUniform2Ints("ScreenSize",EmpireWindow::GetWindow()->GetWidth(), EmpireWindow::GetWindow()->GetHeight());
        glBindVertexArray(VAO);
        pic.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

    void RendererOpenGL::Draw(Image& pic, Shader& shader, int x, int y)
    {
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        float vertices[] = {
            x, y, 0.0, 0.0, // left
            x + pic.GetWidth(), y, 1.0, 0.0,  // right
            x, y + pic.GetHeight(), 0.0, 1.0,  // top
            x + pic.GetWidth(), y + pic.GetHeight(), 1.0, 1.0    // bottom
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Draw first triangle
        shader.Bind();
        glBindVertexArray(VAO);
        pic.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void RendererOpenGL::ClearScreen()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}