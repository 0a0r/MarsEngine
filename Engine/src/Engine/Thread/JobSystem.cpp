#include "JobSystem.hpp"

#include "Engine/Core/Utility.hpp"
#include "Engine/Core/RingBuffer.hpp"

JobSystem::WorkerThread::WorkerThread()
{
	static int sThreadIndex = 0;

	std::unique_ptr<std::thread> workerThread(new std::thread(&WorkerThread::WorkerThreadMain, this));
	mThread = std::move(workerThread);
	SetName(Stringf("WorkerThread_%d", sThreadIndex++));
}

JobSystem::WorkerThread::~WorkerThread()
{
	mThread->join();
	mThread = nullptr;
}

void JobSystem::WorkerThread::WorkerThreadMain()
{
	while (!JobSystem::bQuitFlag)
	{
		Job* curJob = JobSystem::FetchJob();

		if (curJob != nullptr)
		{
			curJob->Excute();
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
	}
}

namespace JobSystem
{
	constexpr size_t JOB_QUEUE_MAX_SIZE = 512;
	FixedRingBuffer<Job*, JOB_QUEUE_MAX_SIZE>	mJobPool;

	std::vector<WorkerThread*>	gWorkerThreads;
	const unsigned int			gNumWorkerThreads = 3;
	std::atomic<bool>			bQuitFlag;
}

void JobSystem::Initialize()
{
	bQuitFlag = false;
	unsigned int numCores = std::min(gNumWorkerThreads, std::thread::hardware_concurrency() - 1);
	for (unsigned int threadID = 0; threadID < numCores; threadID++)
	{
		gWorkerThreads.emplace_back(new WorkerThread());
	}
}

void JobSystem::Destroy()
{
	bQuitFlag = true;
	for (int i = 0; i < gWorkerThreads.size(); i++)
	{
		delete gWorkerThreads[i];
		gWorkerThreads[i] = nullptr;
	}
	gWorkerThreads.clear();
}

JobSystem::Job* JobSystem::FetchJob()
{
	Job* job = nullptr;
	mJobPool.pop_front(job);
	return job;
}
