import matplotlib.pyplot as pp
import pandas as pd
import numpy as np
from scipy.stats import norm
import statistics

data = np.loadtxt(fname = 'output.txt')
# x_axis = np.arange(0, 1, .05)
mean = statistics.mean(data)
sd = statistics.stdev(data)


# pp.hist(data, bins = 100)
domain = np.linspace(np.min(data), np.max(data))
pp.plot(domain, norm.pdf(domain, mean, sd))
pp.hist(data, edgecolor='black',alpha=.5,density=True, bins=101)
pp.xlabel("Randomized Value 0-1")
pp.ylabel("Frequency of Appearance")
print("mean ")
print(mean)
print("\nstandard deviation ")
print(sd)
pp.show()