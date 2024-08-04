#pragma once
#include <vector>

class Sine_wavetable {
	
	public:
	
		Sine_wavetable() {}
		Sine_wavetable(float sampleRate, std::vector<float>& table);
		void setup(float sampleRate, std::vector<float>& table);
		void setFreq(float freq) {_freq = freq;}
		float process();
		~Sine_wavetable() {}
		
	private:
	
		float _inverseSampleRate;
		std::vector<float> _table;
		float _freq;
		float _readPointer;
	
};