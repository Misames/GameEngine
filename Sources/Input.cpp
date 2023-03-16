
#include "Input.h"

// pour quitter la boucle : a ne pas utiliser dans une vraie application
#include <conio.h>

#include <iostream>

namespace ESGI
{

	bool Input::Initialize()
	{
#if defined(_DEBUG)
		m_DebugName = "Input";
#endif
		std::cout << "[Input] initialized\n";
		return true;
	}

	void Input::DeInitialize()
	{
		std::cout << "[Input] deinitialized\n";
	}

	// ce n'est pas une fonction virtuelle !
	void Input::Update()
	{
		QuitButtonPressed = GetQuitButtonState();
		std::cout << "[Input] update\n";
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(lastIntentTimestamp);
		auto value = now_ms.time_since_epoch().count();
		std::cout << "Timestamp: " << value << std::endl;
	}

	bool Input::GetQuitButtonState()
	{
		if (_kbhit())
		{
			// Enregistre la dernière timestamp de l'input pressé
			this->lastIntentTimestamp = std::chrono::system_clock::now();

			int ch = _getch();
			if (ch == 27) // ESC
				return true;
		}
		return false;
	}
}