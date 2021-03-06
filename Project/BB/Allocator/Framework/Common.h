#pragma once
#include <cstdint>

namespace BB
{
	template<typename Tag>
	union FrameworkHandle
	{
		FrameworkHandle(uint32_t a_Index, uint32_t a_ExtraIndex = 0)
		{
			index = a_Index;
			extraIndex = a_ExtraIndex;
		};
		struct
		{
			//The handle's main index. Always used and is the main handle.
			uint32_t index;
			//A extra handle index, can be used to track something else. Usually this value is 0.
			uint32_t extraIndex;
		};

		uint64_t handle;

		inline bool operator ==(FrameworkHandle a_Rhs) const { return handle == a_Rhs.handle; }
		inline bool operator !=(FrameworkHandle a_Rhs) const { return handle != a_Rhs.handle; }
	};

	using WindowHandle = FrameworkHandle<struct WindowHandleTag>;
}