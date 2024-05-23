#include "pch.h"
#include "EmpireApplication.h"
#include "EmpireWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Image.h"

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

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            EMPIRE_ERROR("Failed to initialize GLAD");
            return;
        }

        // Blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        float vertices[] = {
            -0.5f, -0.5f, 0.0, 0.0, // left
            0.5f, -0.5f, 1.0, 0.0,  // right
            -0.5f, 0.5f, 0.0, 1.0,  // top
            0.5f, 0.5f, 1.0, 1.0    // bottom
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

        // Vertex Shader Source
        const char* vertexShaderSource = R"(
            #version 330 core
            layout (location = 0) in vec2 aPos;
            layout (location = 1) in vec2 aTexCoord;

            out vec2 TexCoord;
            void main()
            {
                gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);
                TexCoord = aTexCoord;
            }
        )";

        // Fragment Shader Source
        const char* fragmentShaderSource = R"(
            #version 330 core
            out vec4 FragColor;

            in vec2 TexCoord;

            uniform sampler2D myTex;

            void main()
            {
                FragColor = texture(myTex, TexCoord);
            }
        )";

        // Compile and link shaders
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);


        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            EMPIRE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            EMPIRE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
        }

        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            EMPIRE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // Texture
        Empire::Image pic{ "C:\\Users\\wli24\\Documents\\CXX_Projects\\S24_Wei_Lin_Li\\Empire\\Assets\\Textures\\Test.png" };

        Initialize();

        // Main loop
        while (true)
        {
            OnUpdate();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw first triangle
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            pic.Bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            EmpireWindow::GetWindow()->SwapBuffers();
            EmpireWindow::GetWindow()->PollEvents();
        }
        Shutdown();
        EmpireWindow::Shutdown();
    }
}
