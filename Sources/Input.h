#pragma once

#include "InfraStructure.h"

#include <chrono>

namespace ESGI
{
	struct Input : public InfraStructure
	{
		std::chrono::system_clock::time_point lastIntentTimestamp;

		bool QuitButtonPressed = false;

		bool Initialize() final;

		void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		void Update();

		bool GetQuitButtonState();
	};
}