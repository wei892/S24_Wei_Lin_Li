#pragma once

#include "RendererImplement.h"

namespace Empire
{
	class RendererOpenGL : public RendererImplement
	{
	public:
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int x, int y) override;
		virtual void Draw(Image& pic, Shader& shader, int x, int y) override;
		virtual void ClearScreen() override;

	private:
		std::unique_ptr <Shader> mShaderPtr;
	};
}