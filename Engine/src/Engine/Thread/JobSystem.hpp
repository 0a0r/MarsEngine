#pragma once

#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <condition_variable>

namespace JobSystem
{
	class Job
	{
	public:
		Job() {}
		virtual ~Job() {}

		virtual void Excute() = 0;
	};

	class WorkerThread
	{
	public:
		WorkerThread();
		virtual ~WorkerThread();
		
		void WorkerThreadMain();
		void SetName(std::string const& name)	{ mName = name; }
		std::string GetName() const				{ return mName; }

	private:
		std::unique_ptr<std::thread>	mThread;
		std::string						mName;
	};
}

namespace JobSystem
{
	void Initialize();
	void Destroy();
	Job* FetchJob();

	extern std::vector<WorkerThread*>	gWorkerThreads;
	extern const unsigned int			gNumWorkerThreads;
	extern std::atomic<bool>			bQuitFlag;
}