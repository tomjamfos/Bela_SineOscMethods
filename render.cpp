/*
	A test for determining the computational costs of various methods for sine wave generation.
	3 methods are tested; generation using <cmath>, using the math-neon port for Bela & finally 
	a wavetable/lookup (with linear interpolation) method.
*/

#include <Bela.h>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Sine_cmath.h"
#include "Sine_neon.h"
#include "Sine_wavetable.h"

//number of oscillators
const unsigned int kNumOsc = 69;

//<cmath> method
Sine_cmath gOscBank[kNumOsc];

//math-neon method
// Sine_neon gOscBank[kNumOsc];

//wavetable method
// Sine_wavetable gOscBank[kNumOsc];

float gAmpScale;

bool setup(BelaContext *context, void *userData) {
	
	//comment out below when using wavetable method
	
	for(unsigned int i = 0; i < kNumOsc; ++i) {
		gOscBank[i].setup(context->audioSampleRate);
		float r = (float) rand() / (float) RAND_MAX * 770.0 + 110.0;
		gOscBank[i].setFreq(r);
	}
	
	//uncomment below when using wavetable method
	
	// const unsigned int tableSize = 1024;
	// std::vector<float> table;
	// table.resize(tableSize);
	// for(unsigned int i = 0; i < table.size(); ++i) {
	// 	table[i] = sinf(2.0 * M_PI * (float) i / (float) table.size());
	// }
	// for(unsigned int i = 0; i < kNumOsc; ++i) {
	// 	gOscBank[i].setup(context->audioSampleRate, table);
	// 	float r = (float) rand() / (float) RAND_MAX * 770.0 + 110.0;
	// 	gOscBank[i].setFreq(r);
	// }
	
	//calculate inverse of number of oscillators
	gAmpScale = 1.0 / (float) kNumOsc;
	
	return true;
	
}

void render(BelaContext *context, void *userData) {
	
	for(unsigned int n = 0; n < context->audioFrames; ++n) {
		
		//add outputs of oscillators
		float out = 0.0;
		for(unsigned int i = 0; i < kNumOsc; ++i) {
			out += gOscBank[i].process();
		}
		
		//scale by inverse of number of oscillators
		out *= gAmpScale;
		
		//scale before sending to output
		out *= .25;
		
		//send to audio output
		for(unsigned int channel = 0; channel < context->audioOutChannels; ++channel) {
			audioWrite(context, n, channel, out);
		}
		
	}
	
}

void cleanup(BelaContext *context, void *userData) {}