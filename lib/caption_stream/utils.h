#ifndef UTILS_H
#define UTILS_H

#include <cstring>
#include <cstdlib>
#ifndef _SSTREAM_
#include <sstream>
#endif // !_SSTREAM_
#include <vector>
#ifndef _MUTEX_
#include <mutex>
#endif // !_MUTEX_

#include <iostream>
#include <algorithm>

#include <random>

static std::mutex wp_rnd_mut;
static std::unique_ptr<std::mt19937> wp_rnd_ins;

static void wp_rnd_init() {
	if (wp_rnd_ins)
		return;
	try {
		std::random_device dev;
		wp_rnd_ins = std::make_unique<std::mt19937>(dev());
	}
	catch (...) {
		printf("wp_rnd_init fail\n");
	}
}

static unsigned int wp_rnd_num() {
	if (wp_rnd_ins)
		return wp_rnd_ins->operator()();
	return rand();
}

static std::string random_string(const int count) {
	std::lock_guard<std::mutex> lock(wp_rnd_mut);
	wp_rnd_init();

	std::string output;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < count; ++i) {
		output.push_back(alphanum[wp_rnd_num() % (sizeof(alphanum) - 1)]);
	}

	return output;
}


#endif // !UTILS_H
