#pragma once

#include "Sauropod/LayerStack.h"

namespace Sauropod {

	class SAUROPOD_API ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0;
	};

}