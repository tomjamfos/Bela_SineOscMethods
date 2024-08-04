#include "Sine_wavetable.h"

Sine_wavetable::Sine_wavetable(float sampleRate, std::vector<float>& table) {
	
	//call setup function
	setup(sampleRate, table);
	
}

void Sine_wavetable::setup(float sampleRate, std::vector<float>& table) {
	
	//calculate inverse sample rate for faster computation
	_inverseSampleRate = 1.0 / sampleRate;
	
	_table = table;
	_readPointer = 0.0;
	
}

float Sine_wavetable::process() {
	
	//when table is empty return 0.0
	float out = 0.0;
	if(!_table.size()) {return out;}
	
	//advance phase
	_readPointer += _table.size() * _freq * _inverseSampleRate;
	
	//wrap phase
	while(_readPointer >= _table.size()) {_readPointer -= _table.size();}
	
	//perform linear interpolation
	int indexBelow = _readPointer;
	int indexAbove = indexBelow + 1;
	float fractAbove = _readPointer - indexBelow;
	float fractBelow = 1.0 - fractAbove;
	out = fractBelow * _table[indexBelow] + fractAbove * _table[indexAbove];
	
	//output
	return out;
	
}