#include "WorldClock.hpp"

WorldClock::WorldClock()
{
}


WorldClock::~WorldClock()
{
}

void WorldClock::startClock() {
	initTime = Clock::now();
}

void WorldClock::runClock() {
	runTime = Clock::now();
}

float WorldClock::diffClock() {
	return static_cast<float>(std::chrono::duration_cast<elapsed_resolution>(runTime - initTime).count() / 1000.0);
}