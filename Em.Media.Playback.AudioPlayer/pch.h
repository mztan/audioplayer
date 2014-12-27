#pragma once

#include <collection.h>
#include <ppltasks.h>

#include <wrl.h> 
#include <wrl\client.h> 

#include <xaudio2.h>

typedef unsigned int uint;

namespace DX
{
	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			throw Platform::Exception::CreateException(hr);
		}
	}
}