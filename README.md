# push_swap
_This project has been created as part of the 42 curriculum by @adorofei and @aartyush._

## About the Project

**push_swap** is an algorithmic sorting project where integers stored in a stack (Stack A) must be sorted in ascending order using a secondary helper stack (Stack B) and a restricted instruction set. The objective is to produce the minimal sequence of operations needed to achieve a fully sorted state.

The program initializes with two data structures:
*   **Stack A:** Contains a random, unsorted list of unique integers.
*   **Stack B:** Begins completely empty.

The goal is to sort the numbers so that Stack A is ordered from smallest (top) to largest (bottom), while Stack B is empty. We are not allowed to use standard C library sorting algorithms (like *qsort*) or access elements directly by their index. Manipulation is strictly limited to a specific set of stack operations.

### Team Contributions
This project was implemented by two core students in accordance with subject requirements.

**adorofei:**
*  **Sorting Architecture**: Designed the core algorithmic logic, managing dynamic pivot selection and stack state transitions.
*   **Median Search**: Implemented a targeted Bubble Sort on temporary arrays to calculate precise median values for balanced stack partitioning.
*   **In-Place Edge Sorting**: Engineered safe, localized sorting functions for small datasets (1-5 nodes) to sort the stack apex without corrupting the base structure.
*   **Project Organization & Routing**: Structured the entire project architecture, developed the main function, and implemented the core routing logic to dynamically select the appropriate sorting strategy based on input size.

**aartyush:**
*   **Operator Implementation**: Designing the doubly linked list manipulations required for swap, push, rotate and reverse operations.
*   **Data Structures and Parsing**: Establishing the initial linked list structures and writing full parsing logic.
*   **Initial Debugging**: Conducting early-stage memory leak hunting, handled structural memory issues (like Segmentation Faults), comprehensive code review and logical error identification.
*   **Algorithmic Modification**: Conceptualized the critical pivot from a purely recursive Quick Sort to the much more stable and efficient iterative chunk-based partitioning model.

## The Operators

The algorithm utilizes the following specific operations to manipulate the stacks:

**Swaps (Top Elements)**
*   **sa**: Swaps the top two numbers in stack A.
*   **sb**: Swaps the top two numbers in stack B.
*   **ss**: Executes *sa* and *sb* simultaneously.

**Pushes (Transferring Elements)**
*   **pa**: Takes the top element from stack B and pushes it to the top of stack A.
*   **pb**: Takes the top element from stack A and pushes it to the top of stack B.

**Rotations (Shifting Up)**
*   **ra**: Shifts all elements of stack A up by one. The top element becomes the new bottom element.
*   **rb**: Shifts all elements of stack B up by one. The top element becomes the new bottom element.
*   **rr**: Executes *ra* and *rb* simultaneously.

**Reverse Rotations (Shifting Down)**
*   **rra**: Shifts all elements of stack A down by one. The bottom element becomes the new top element.
*   **rrb**: Shifts all elements of stack B down by one. The bottom element becomes the new top element.
*   **rrr**: Executes *rra* and *rrb* simultaneously.

## Sorting Algorithms

To achieve the best possible operational efficiency, the program dynamically selects its sorting strategy based on the amount of numbers provided.

### 1. Tiny Sort (3 Elements)
For stacks of exactly 3 numbers, we use a deterministic, hardcoded algorithm. 

*   **How it works:** The algorithm finds the maximum value among the three elements. If the maximum is at the top, it rotates the stack (*ra*). If the maximum is in the middle, it reverse-rotates (*rra*). Finally, it checks the top two elements and swaps them (*sa*) if the first is greater than the second. This guarantees sorting in a maximum of 2 moves.

### 2. Small Sort (5 Elements)
For 5 numbers, running a full recursive algorithm is inefficient.

*   **How it works:** The algorithm scans Stack A to find the minimum value and pushes it to Stack B (*pb*). It repeats this process one more time for the new minimum. With only 3 elements left in Stack A, it calls the *Tiny Sort* algorithm. Once Stack A is sorted, it pushes the two minimum values back from Stack B to Stack A (*pa*, *pa*).

### 3. Medium Sort (Up to 100 Elements)
Mid-sized stacks need to be broken down, but full recursion is still slightly too heavy.

* **How it works:** The algorithm calculates a median value for the entire stack. Elements smaller than the median are pushed to Stack B, while larger elements are kept in Stack A. It then sorts these smaller chunks by pushing elements back to Stack A sequentially, using smart rotations (*ra*, *rra*, *rb*, *rrb*) to find the most cost-effective path to the top.


### 4. Custom Quick Sort (Large Stacks)
Traditional recursive Quick Sort was initially implemented but proved to be highly unstable and inefficient within the constraints of a two-stack architecture, often leading to excessive operational overhead. To resolve this, we engineered an Iterative Chunk-Based Partitioning model. It preserves the mathematical efficiency of Quick Sort's divide-and-conquer logic but removes the recursive instability.

*   **Finding the Median (via Bubble Sort):** To partition efficiently, the program copies the current segment into a temporary array, applies a standard Bubble Sort, and extracts the exact middle element to serve as the pivot point.
*   **Partitioning:** Instead of deep recursion, the algorithm iteratively scans the stack. Elements smaller than the median pivot are pushed to Stack B, while larger elements are kept in Stack A. This effectively creates "chunks" of progressively sorted numbers.
*   **Iterative Reassembly:** Once the stack is partitioned into manageable chunks based on these medians, the algorithm sorts these smaller blocks by pushing elements back to Stack A sequentially. It utilizes calculated, cost-effective rotations *(ra, rra, rb, rrb)* to find the shortest path to route the correct numbers to the top, significantly minimizing the operation count compared to standard recursive rewinding.


## Benchmarking Mode

The program includes a dedicated benchmarking feature for performance analysis.
*   **How to use:** Run the executable with the flag `--bench` alongside your list of numbers.
*   **What it does:** Instead of printing every single operation (*sa*, *pb*, etc.) to the standard output, the program suppresses the instruction printouts. Once the sorting is complete, it outputs a statistical summary, primarily showing the total number of operations executed. This is highly useful for testing and optimizing the algorithm against the strict grading limits (e.g., scoring full points requires sorting 500 numbers in under 5500 operations).

## Compilation and Execution

The project comes with a Makefile that handles the compilation process.

### Makefile Rules
*   **`make`**: Compiles the source files and generates the `push_swap` executable.
*   **`make clean`**: Removes all the compiled object files (`.o`), leaving the source code and executable intact.
*   **`make fclean`**: Executes `clean` and also removes the `push_swap` executable.
*   **`make re`**: Executes `fclean` followed by `make`, completely recompiling the project from scratch.

### How to Run
To run the program, pass a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```
Alternatively, you can pass them as a single formatted string:
```bash
./push_swap "4 67 3 87 23"
```
Here are the example how to use flags to sort integers.
```bash
./push_swap --medium "4 324 67 54 3 87 1 23 256 28 32"
```

To verify the accuracy of the sorting algorithm, you can pipe the output directly into the provided Linux checker tool:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
If the algorithm correctly sorts the stack, the checker will output `OK`.

## Resources

During the development of this project, the following resources and methods were utilized:

**Classic References and Documentation:**
* **GeeksforGeeks & Wikipedia:** Used to study the foundational logic and time complexities of Quick Sort and Bubble Sort algorithms.
* **42 Network Subject PDF:** The primary source of truth for all operational constraints and project rules.

**Use of Artificial Intelligence:**
As permitted by the curriculum guidelines regarding AI usage, Large Language Models were used strictly as an educational and structural assistant in the following specific ways:
* **Debugging Assistance:** AI was used to analyze segmentation fault patterns in Valgrind output, specifically pointing out synchronization issues with recursive pointer management.