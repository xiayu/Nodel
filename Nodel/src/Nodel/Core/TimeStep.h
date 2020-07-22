#pragma once
namespace Nodel {
	class TimeStep {
	public:
		TimeStep(float time = 0.0f):
			m_Time(time)
		{
		}

		operator float() const { return m_Time; }

		float GetSecondes() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}
