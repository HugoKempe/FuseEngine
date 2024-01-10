#pragma once

#include <glm/glm.hpp>

namespace Fuse
{
	class Color
	{
	public:
		enum ColorConstants
		{
			Undefined = 0,
			Red,
			Green,
			Blue
		};

		Color() = default;

		Color(float r, float g, float b, float a)
			: r(r), g(g), b(b), a(a)
		{
		}

		Color(ColorConstants color)
			: Color(FromColorConstant(color))
		{
		}

		Color(const glm::vec4& color)
			: r(color.r), g(color.g), b(color.b), a(color.a)
		{
		}

		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
			: r((float)r / 255.0f), g((float)g / 255.0f), b((float)b / 255.0f), a((float)a / 255.0f)
		{
		}

		float r = 0.0f, g = 0.0f, b = 0.0f, a = 1.0f;

		operator glm::vec4() const { return { r, g, b, a }; }
		operator ColorConstants() const
		{
			return r > b ? Red : Blue;
		}

	private:
		static constexpr Color FromColorConstant(ColorConstants color)
		{
			switch (color)
			{
			case Undefined:	return { 0.0f, 0.0f, 0.0f, 1.0f };
			case Red:		return { 1.0f, 0.0f, 0.0f, 1.0f };
			case Green:		return { 0.0f, 1.0f, 0.0f, 1.0f };
			case Blue:		return { 0.0f, 0.0f, 1.0f, 1.0f };
			}
			return  { 0.0f, 0.0f, 0.0f, 1.0f };
		}
	};
}
