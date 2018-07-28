#pragma once
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
using elapsed_resolution = std::chrono::milliseconds;

class WorldClock
{
private:
	std::chrono::steady_clock::time_point initTime, runTime;
public:
	WorldClock();
	~WorldClock();
	void startClock();
	void runClock();
	float diffClock();
};

