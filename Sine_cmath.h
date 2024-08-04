#pragma once 

class Sine_cmath {
	
	public:
	
		Sine_cmath() {}
		Sine_cmath(float sampleRate);
		void setup(float sampleRate);
		void setFreq(float freq) {_freq = freq;}
		float process();
		~Sine_cmath() {}
		
	private:
	
		float _inverseSampleRate;
		float _freq;
		float _phase;
	
};