# Usage

Try some tests when learning.

# Environment

g++, which maybe cause different physical memory model. 

# Introduction

## algorithm

### split

Compare three approachs: find, stringstream, tokenizer(boost), the main impact factor is the ratio of delimiter and letter, not just the letter number of string.

The result is:
1. When the ratio is low(like 1 : 100), find is the best.
2. When the ratio is high(like 1 : 10), tokenizer is the best.

So, you can suspect the ratio of delimiter and letter, and then choose the best approach.

## structure

### geometry

This method can hide the bottom implementation details.

### geometry_intersection

However this structure isn't best, it will waste time(about O(logN)) to search the fix intersection function, but it can be expand dynamicly, which better than call template directly.

### thread_pool

It's a simple job system rather than thread pool by locks which may loss preformance.

### job_system

To learn Lock-Free Programming firstly.

- [✔] Free lock deques
- [✔] Steal jobs(not enough, to avoid the collision between push_front and pop_front, you need add a job pool, which manage same structure deque(push_front called by main thread, pop_back called by correspondind thread))
- [✖] Distribute jobs(do by your self)

Well, it like a factory, main thread creates jobs -> job poll distributes jobs -> deques in job pool stores jobs -> deques of threads get jobs -> threads do jobs.

Over all, I think the most important theroy in Lock-Free Programming is avoiding collision(like deque or cache).
