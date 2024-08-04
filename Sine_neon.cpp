#include "Sine_neon.h"
#include <libraries/math_neon/math_neon.h>

Sine_neon::Sine_neon(float sampleRate) {
	
	//call setup function
	setup(sampleRate);
	
}

void Sine_neon::setup(float sampleRate) {
	
	//calculate inverse sample rate for faster computation
	_inverseSampleRate = 1.0 / sampleRate;
	
	_freq = 0.0;
	_phase = 0.0;
	
}

float Sine_neon::process() {
	
	//advance phase
	_phase += 2.0 * M_PI * _freq * _inverseSampleRate;
	
	//wrap phase
	while (_phase >= 2.0 * M_PI) {_phase -= 2.0 * M_PI;}
	
	//compute sine
	float out = sinf_neon(_phase);
	
	//output
	return out;
	
}