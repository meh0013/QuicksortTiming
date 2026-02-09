# QuickSort Performance Analysis in C
### Overview

This project analyzes the performance of the QuickSort algorithm by measuring its execution time for varying input sizes. The program records timing data, applies a moving average smoothing technique to reduce noise, and visualizes the results using gnuplot.

The experiment demonstrates how QuickSort’s runtime grows as input size increases and highlights real-world effects such as system noise, caching, and timing resolution.

## Purpose

This project demonstrates:

- Implementation of QuickSort in C

- Performance benchmarking techniques

- File I/O handling

- Data smoothing using moving averages

- Automated visualization using gnuplot

## How the Program Works

- Iterates through input sizes from 0 to 100,000 in steps of 1,000

- Generates an array of random integers for each size

- Sorts the array using the QuickSort algorithm

- Measures execution time using clock()

- Logs raw timing results to data.txt

- Applies a moving average filter (window size = 7) to smooth the data

- Writes smoothed values to smoothed_time_logs.txt

- Automatically invokes gnuplot to generate plot.png

## Output files
```
data.txt : Contains raw timing data in the format: <input_size> <time_taken_in_seconds>
```
```
smoothed_time_logs.txt : Contains smoothed timing data produced using a moving average to reduce measurement noise.
```

```
plot.png : A graph generated using gnuplot with:

  -  X-axis: Input Size

  -  Y-axis: Time Taken (seconds)
```

## Graph Characteristics

The graph is not perfectly smooth due to:

 - Limited resolution of clock()

 - Operating system scheduling effects

 - Cache and memory behavior

 - Variations in QuickSort partitioning

 - Despite these fluctuations, the overall trend reflects O(n log n) behavior, which is expected for QuickSort on average.

## Notes and Limitations

- Timing is performed using clock(), which may introduce noise for short execution times

- Each input size is tested once; averaging multiple runs would improve accuracy

- Stack allocation is used for arrays, which may limit very large input sizes

- Results may vary depending on system load and hardware