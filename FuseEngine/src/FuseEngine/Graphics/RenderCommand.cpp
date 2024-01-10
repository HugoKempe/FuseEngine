#include "fepch.h"
#include "RenderCommand.h"

#include "glad/glad.h"

#define FUSE_ENGINE_DISABLE_GL_NOTIFIACTION

namespace Fuse
{
	void OpenGLMessageCallback(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		GLchar const* message,
		void const* user_param)
	{
		auto const src_str = [source]() {
			switch (source)
			{
			case GL_DEBUG_SOURCE_API: return "API";
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "WINDOW SYSTEM";
			case GL_DEBUG_SOURCE_SHADER_COMPILER: return "SHADER COMPILER";
			case GL_DEBUG_SOURCE_THIRD_PARTY: return "THIRD PARTY";
			case GL_DEBUG_SOURCE_APPLICATION: return "APPLICATION";
			case GL_DEBUG_SOURCE_OTHER: return "OTHER";
			default: return "UNKNOWN";
			}
			}();

			auto const type_str = [type]() {
				switch (type)
				{
				case GL_DEBUG_TYPE_ERROR: return "ERROR";
				case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
				case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
				case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
				case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
				case GL_DEBUG_TYPE_MARKER: return "MARKER";
				case GL_DEBUG_TYPE_OTHER: return "OTHER";
				default: return "UNKNOWN";
				}
				}();

		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:			FE_CORE_CRITICAL("{0}, {1}, {2}, {3}", src_str, type_str, id, message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:			FE_CORE_ERROR("{0}, {1}, {2}, {3}", src_str, type_str, id, message); return;
		case GL_DEBUG_SEVERITY_LOW:				FE_CORE_WARN("{0}, {1}, {2}, {3}", src_str, type_str, id, message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION:	FE_CORE_TRACE("{0}, {1}, {2}, {3}", src_str, type_str, id, message); return;
		default: break;
		}

		FE_CORE_ASSERT(false, "Unknown severity level!");
	}

	void EnableDebug(bool notifications = false)
	{
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, notifications ? GL_TRUE : GL_FALSE);
	}

	void RenderCommand::Init()
	{
		FE_WRAP_DEBUG(EnableDebug(true));

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
		//glEnable(GL_MULTISAMPLE);
		glEnable(GL_LINE_SMOOTH);
	}

	void RenderCommand::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		FE_CORE_DEBUG("Viewport Set To {} x {}", width, height);
		glViewport(x, y, width, height);
	}

	void RenderCommand::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void RenderCommand::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderCommand::SetLineWidth(float width)
	{
		glLineWidth(width);
	}
}
