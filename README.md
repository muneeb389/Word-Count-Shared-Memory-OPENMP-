# Word-Count-Shared-Memory-OPENMP-


1.	Objective: 
Parallel programming is a type of computation in which many calculations or the execution of processes are carried out simultaneously.
Large problems can often be divided into smaller ones, which can then be solved at the same time to obtain the result much quicker. 
There are many ways to achieve parallel programming, but we have implemented using Open MP.
Our algorithm counts the frequency of each word present in the file.

2.	Introduction:
This project was developed in Ubuntu Linux 18.04 and Windows. We have used Open MP to achieve parallelism using shared memory.
The application was developed in C++ language and the library used for parallelism was OpenMP.


3.	Methodology:
For calculating the frequency of each word, we have created a data structure called TRIE.
TRIE is an efficient information retrieval and a tree like data structure. Using TRIE, search complexities can be brought to optimal limit (key length). Using TRIE,
we can search the key in O(M) time. Similarly using TRIE we can calculate each word frequency and stored in the variable occurrence mentioned in the code. 
To achieve parallelism, main file is divided into 5 equal parts and 5 threads are created and each thread is responsible to solve a part.
Using #pragma omp section each thread is assigned a section to count the frequency of each word present in that part of the file.


graph.PNG
