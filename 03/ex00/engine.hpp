#ifndef ENGINE_HPP
# define ENGINE_HPP

class Engine
{
public:
	Engine();

	void Start();
	void Stop();
	bool IsRunning() const;

private:
	bool m_running;
};

Engine::Engine() : m_running(false) {}

void Engine::Start()
{
	m_running = true;
}

void Engine::Stop()
{
	m_running = false;
}

bool Engine::IsRunning() const
{
	return m_running;
}

#endif
