# Bela_SineOscMethods
An evaluation of a few different methods for real-time computation of sine wave oscillators on the Bela platform.

3 methods are tested:

  - using cmath library
  - using the math-neon port for Bela (https://github.com/giuliomoro/math-neon)
  - using a wavetable/lookup method (with both table sizes of both 512 & 1024 samples)

For the wavetable method linear interpolation was used.

Each oscillator was given a random frequency between 110 & 880 Hz, the outputs mixed and then sent to the audio output.

The total number of oscillators used was increased untill Bela reported underuns (using a block size of 16). The previous value was recorded, the process repeated 4 times and the results averaged (using the mean). 

    
![alt text](https://github.com/tomjamfos/Bela_SineOscMethods/blob/main/bar_graph.png "Plotted results")
