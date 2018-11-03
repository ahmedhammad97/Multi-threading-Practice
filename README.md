# Multi-threading-Practice
Illustration of how does breaking the process into multiple threads, can vary the performance significantly.

## Algorithms tested
- 2D Matrix Mutliplication
- Merge Sort

## Compilation instruction
Compiling the programs on a Linux system requires specifying the threading library exclusively as follows:

	g++ main.cpp -std=c++14 -pthread -o run.out
    
 ## Conclusion
 When using a multi-core machine, breaking the program into separate threads that can run dependently on different cores, can significantly enhance the performance.
 
 However, increasing the number of threads does not guarantee by any means an increase in performance, a sweet spot of reasonable number of thread -_that minimize the overhead cost and maximize the division of performance load_-, must be chosen wisely.
 
 Mutli-threading only works fine for large amounts of data, as the overhead cost of scheduling and handling the threads, is divided among all of them, resulting in a good performance from an amortized analysis perspective.
