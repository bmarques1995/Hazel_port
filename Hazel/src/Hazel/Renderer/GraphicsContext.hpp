#ifndef GRAPHICS_CONTEXT_HPP
#define GRAPHICS_CONTEXT_HPP

#include "Hazel/Core.hpp"

namespace Hazel {

	class HAZEL_API GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void Present() = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() = 0;
	};

}

#endif