#include <iostream>

class Log
{
	public :
		enum Level
		{
			levelError, levelWarning, levelInfo
		};
	private :
		int	m_LogLevel = levelInfo;
	public :
		void	SetLevel(Level level)
		{
			m_LogLevel = level;
		}
		void	Warn(const char *message)
		{
			if (m_LogLevel >= levelWarning)
				std::cout<<message<<std::endl;
		}
		void	Error(const char *message)
		{
			if (m_LogLevel >= levelError)
				std::cout<<message<<std::endl;
		}
		void	Info(const char *message)
		{
			if (m_LogLevel >= levelInfo)
				std::cout<<message<<std::endl;
		}
};

int	main(void)
{
	Log log;
	log.SetLevel(Log::levelInfo);
	log.Warn("Warning");
	log.Error("Error");
	log.Info("Info");
	return (0);
}