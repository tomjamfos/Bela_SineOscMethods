#pragma once

class Sine_neon {
	
	public:
	
		Sine_neon() {}
		Sine_neon(float sampleRate);
		void setup(float sampleRate);
		void setFreq(float freq) {_freq = freq;}
		float process();
		~Sine_neon() {}
		
	private:
	
		float _inverseSampleRate;
		float _freq;
		float _phase;
	
};