# Usage

Try some tests when learning.

# Environment

g++, which maybe cause different physical memory model. 

# Introduction

## geometry

This method can hide the bottom implementation details.

## geometry_intersection

However this structure isn't best, it will waste time(about O(logN)) to search the fix intersection function, but it can be expand dynamicly, which better than call template directly.

## thread_pool

It's a simple job system rather than thread pool by locks which may loss preformance.

## job_system

To learn Lock-Free Programming firstly.

- [✔] Free lock deques
- [✔] Steal jobs
- [✖] Distribute jobs(do by your self)