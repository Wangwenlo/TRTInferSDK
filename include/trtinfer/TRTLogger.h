#pragma once
#include <NvInfer.h>

namespace trtinfer
{
	class TrtLogger final : public nvinfer1::ILogger
	{
	public:
		void log(Severity severity, const char* msg) noexcept override;
	};
}