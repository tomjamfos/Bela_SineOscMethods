#include "Sine_cmath.h"
#include <cmath>

Sine_cmath::Sine_cmath(float sampleRate) {
	
	//call setup function
	setup(sampleRate);
	
}

void Sine_cmath::setup(float sampleRate) {
	
	//calculate inverse sample rate for faster computation
	_inverseSampleRate = 1.0 / sampleRate;
	
	_freq = 0.0;
	_phase = 0.0;
	
}

float Sine_cmath::process() {
	
	//advance phase
	_phase += 2.0 * M_PI * _freq * _inverseSampleRate;
	
	//wrap phase
	while(_phase >= 2.0 * M_PI) {_phase -= 2.0 * M_PI;}
	
	//compute sine
	float out = sinf(_phase);

	//output
	return out;
	
}