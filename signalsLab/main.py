import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
duration = 5
amplitude = 0.2
fs = 80000
timeSamples = np.arange(np.ceil(duration * fs)) / fs
signal = amplitude * np.sin(duration * np.pi * 200 * timeSamples)
plt.plot(timeSamples[:10000] * 1000, signal[:10000])
sd.play(signal, fs)
signal2 = amplitude * np.sin(2 * np.pi * 2500 * timeSamples)
signal3 = amplitude * np.sin(3 * np.pi * 1500 * timeSamples)
signal4 = amplitude * np.sin(4 * np.pi * 1000 * timeSamples)
signal5 = amplitude * np.sin(5 * np.pi * 500 * timeSamples)
signal6 = amplitude * np.sin(5 * np.pi * 2000 * timeSamples)
signalSumm = signal + signal2 + signal3 + signal4 + signal5 + signal6
sd.play(signalSumm, fs)
