#pragma once

#include "pch.h"
#include "Image.h"
#include "Shader.h"

namespace Empire
{
	class RendererImplement
	{
	public:
		virtual void Draw(Image& pic, int x, int y) = 0;
		virtual void Draw(Image& pic, Shader& shader, int x, int y) = 0;
		virtual void ClearScreen() = 0;
		virtual ~RendererImplement() {};
	};
}