#pragma once
#include "pch.h"

#include "Ultility.h"
#include "ImageImplement.h"

namespace Empire
{
	class EMPIRE_API Image
	{
	public:
		Image(const std::string& filePath);
		Image(std::string&& filePath);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();
	private:
		std::unique_ptr<ImageImplement> mImplementation;
	};
}
