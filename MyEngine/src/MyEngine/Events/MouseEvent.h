#pragma once

#include "Event.h"
#include <sstream>

namespace MyEngine {

	class MYENGINE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline int GetX() const { return m_MouseX; }
		inline int GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent:" << m_MouseX << "," << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class MYENGINE_API MouseScrolledEvent: public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline int GetXOffset() const { return m_XOffset; }
		inline int GetYOffset() const { return m_XOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent:" << m_XOffset << "," << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class MYENGINE_API MouseButtonEvent: public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		// this should be a virtual class and no object can be created
		// so the constructor is set protected
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class MYENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MYENGINE_API MouseButtonReleasedEvent: public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

}