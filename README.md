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

However this structure isn't best, it will waste time(about O(logN)) to search the fix intersection function, but it can be **expand dynamicly**, which better than call template directly.

Well, I scan the paper of boost polygon, it calls the correct algorithm through dispatching the types of items, which is same!

Oh, let's use hash map to store.

### huge_vector

Why we need this?

std::vector reserve function alwaysly implemention by allocator and deallocator, which means it will copy all of elements to the new place even if the vector has millions of elements.

So, to improve preference, design your own allocator by **c style code**(like malloc, realloc...), and use it to implemention another vector.

However, it's a huge job to implemention a really container, so here's only a part without iterator.

If you want to use it in projects, you should do these works.

- [✖] add iterator to use algorithm
- [✖] provide a memory pool and implemention realloc function in your memory pool

### thread_pool

It's a simple job system rather than thread pool by locks which may loss preformance.

### job_system

To learn Lock-Free Programming firstly.

Here is the plan.

- [✔] Free lock deques
- [✔] Steal jobs
- [✖] **Three deque cache**
- [✖] Distribute jobs

Well, it like a factory, main thread creates jobs -> job poll distributes jobs -> deques in job pool stores jobs -> deques of threads get jobs -> threads do jobs.

Over all, I think the most important theroy in Lock-Free Programming is avoiding collision(like deque or cache).
