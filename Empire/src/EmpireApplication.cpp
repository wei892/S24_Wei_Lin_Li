#include "pch.h"

#include "EmpireApplication.h"
#include "EmpireWindow.h"

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
		Initialize();

		while (true)
		{
			OnUpdate();

			EmpireWindow::GetWindow()->SwapBuffers();
			EmpireWindow::GetWindow()->PollEvents();
		}
		Shutdown();
		EmpireWindow::Shutdown();
	}
}


//#include "pch.h"
//
//#include "EmpireApplication.h"
//#include "EmpireWindow.h"
//#include "GLFW/glfw3.h"
//
//namespace Empire 
//{
//	void EmpireApplication::Initialize()
//	{
//
//	}
//	void EmpireApplication::OnUpdate()
//	{
//
//	}
//	void EmpireApplication::Shutdown()
//	{
//
//	}
//	void EmpireApplication::Run()
//	{
//		EmpireWindow::Init();
//		EmpireWindow::GetWindow()->Create(1000, 800);
//
//		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//		{
//			EMPIRE_ERROR("Failed to initialize GLAD");
//			return;
//		}
//
//		//blending
//
//		glEnable(GL_BLEND);
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//		unsigned int VBO, VAO;
//		glGenVertexArray(1, &VAO);
//		glBindVertextArray(VAO);
//
//		float vertices[] = {
//			-0.5f, -0.5f, 0.0, 0.0, // left
//			0.5f, -0.5f, 1.0, 0.0, // right
//			-0.5f, 0.5f, 0.0, 1.0, //top
//			0.5f, 0.5f, 1.0, 1.0 //bottom
//		};
//
//		unsigned int indices[] = {
//			0, 1, 2,
//			1, 2, 3
//		};
//
//		glGenBuffers(1, &VBO);
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
//		glEnableVertexAttribArray(1);
//
//		//shaders
//		const char* vertexShaderSource = R"(
//			#version 330 core
//			layout (location = 0) in vec2 aPost;
//			latout (location = 1) in vec2 aTexCoord;
//
//			out vec2 TexCoord;
//			void main()
//			{
//				gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);
//				TexCoord - aTexCoord;
//			}
//		)";
//
//		const char* fragmentShaderSource = R"(
//			#version 330 core
//			out vect4 FragColor;
//
//			in vec2 TexCoord;
//
//			uniform sampler2D myTex;
//
//			void main()
//			{
//				FragColor = texture(myTex, TexCoord);
//			}
//		)";
//
//		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//		glShaderSource(vertex, 1, &vertexShaderSource, NULL);
//		glCompileShader(vertexShader);
//		int success;
//		char infoLog(512);
//		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//			EMPIRE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
//		}
//
//		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//		glCompileShader(fragmentShader);
//		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//			EMPIRE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
//		}
//
//		unsigned int shaderProgram = glCreateProgram();
//		gltachShader(shaderProgram, vertexShader);
//		glAtachShader(shaderProgram, fragmentShader);
//		glLinkProgram(shaderProgram);
//		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//		if (!success) {
//			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//			EMPIRE_ERROR("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog);
//		}
//		glDeleteShader(vertexShader);
//		glDeleteShader(fragmentShader);
//
//		//texture
//
//		unsigned int texture;
//		glGenTextures(1, &texture);
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		int width, height, nrChannels;
//		stbi_set_flip_vertically_on_load(true);
//		unsigned char* data = stbi_load("../Assets/Textures/bear.png", &width, &height, &nrChannels, 0);
//
//		if (data)
//		{
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//			glGenerateMipmap(GL_TEXTURE_2D);
//		}
//		else {
//			EMPIRE_ERROR("Failed to load texture" << std::endl);
//		}
//		stbi_image_free(data);
//
//		Initialize();
//
//		while (true)
//		{
//			OnUpdate();
//
//			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//			glClear(GL_COLOR_BUFFER_BIT);
//
//			//draw first triangle
//			glUseProgram(shaderProgram);
//			glBindVertexArray(VAO);
//			glBindTexture(GL_TEXTURE_2D, texture);
//			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//			EmpireWindow::GetWindow()->SwapBuffers();
//			EmpireWindow::GetWindow()->PollEvents();
//		}
//		Shutdown();
//		EmpireWindow::Shutdown();
//	}
//}