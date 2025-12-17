*This project has been created as part of the 42 curriculum by **pdiniz-l**.*

## push_swap_from_42

### Description

The **push_swap** project is a 42 School assignment that consists of implementing a sorting algorithm in C using two stacks (**A** and **B**) and a restricted set of **11 allowed operations**.

The program receives a list of integers as input, validates them, and prints to standard output the sequence of operations required to sort stack **A** in ascending order.  
The objective is not only correctness, but also efficiency, minimizing the number of operations used.

This project focuses on **algorithmic thinking**, **data structure manipulation**, **input validation**, and **memory safety**.

---

### Instructions

#### Compilation

The project is compiled using the provided `Makefile`.

From the project root directory:

```bash
make        # builds libft_applier and the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # full rebuild
```
The Makefile first compiles the custom libft located in libft_applier/ and then builds the push_swap executable.

## Requirements

* C compiler (cc, gcc, or clang)

* make

* Unix-like environment (Linux / macOS)

* libft is already included in libft_applier (no separate installation required)

## Usage

Valid inputs can be provided in two ways:
```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```
If the input is valid, the program prints to standard output the sequence of operations, for example:
```bash
./push_swap 2 1 3 
sa
```
In case of error (invalid argument, duplicate number, integer out of range, etc.), the program prints:
```text
Error
```
to `stderr` and exits with status code `1`.

### Allowed Operations

The program may use only the following operations:

* `sa`, `sb`, `ss` — swap : Swaps the first two elements of a stack.

* `pa`, `pb` — push : Moves the top element from one stack to the other.

* `ra`, `rb`, `rr` — rotate : Shifts the stack up: the first element becomes the last.

* `rra`, `rrb`, `rrr` — reverse rotate : Shifts the stack down: the last element becomes the first.

### Algorithm and Data Structure Choices
#### Stack Representation

The stacks are represented using a linked list from `libft`:
```c
typedef struct s_data
{
    t_list  *a;
    t_list  *b;
}   t_data;
```
This structure allows efficient rotations and pushes while keeping memory usage controlled.

### Parsing and Validation

Before sorting, the program ensures:

* All arguments are valid integers;

* Values fit within the 32-bit int range;

* There are no duplicate numbers.

#### Main parsing and validation helpers:

* `parse_args` — splits arguments and builds stack A

* `is_str_valid` — validates integer strings

* `safe_atoi` — converts char * to int with overflow checking

* `is_doubled` — checks for duplicate values

* `error_and_exit` — frees memory, prints Error, and exits

#### Indexing (Coordinate Compression)

To simplify sorting:

* All values are copied into an array.

* The array is sorted.

* Each node value is replaced by its index in the sorted array.

This reduces the problem to sorting values from 0 to n - 1, which is more suitable for efficient algorithms such as radix sort.

##### Sorting Strategies
* Small Cases (2–5 elements)

Specific functions handle small inputs using minimal combinations of operations:

`sort_two`

`sort_three`

`sort_four`

`sort_five`

These cases are hardcoded for optimal performance.

* Medium Cases (≤ 100 elements)

Chunk-based sorting:

Indices are divided into chunks (intervals).

Elements belonging to the current chunk are pushed to stack B using rotations.

Elements are pushed back from B to A, always bringing the largest value to the top.

This approach significantly reduces the number of operations.

* Large Cases (> 100 elements)

Binary radix sort on indices:

For each bit:

Traverse stack A

Push elements with the current bit set to 0 into stack **B`

Push everything back from B to A

This process is repeated until all relevant bits are processed, with time complexity approximately O(n log n).

#### Repository Structure
```text
push_swap_from_42/
├── libft_applier/      # Custom libft (libft.a + headers)
├── srcs/               # push_swap source code
│   ├── push_swap.h
│   ├── main.c
│   ├── parse_args.c
│   ├── create_head_with_ints.c
│   ├── is_str_valid.c
│   ├── safe_atoi.c
│   ├── is_doubled.c
│   ├── is_list_sorted.c
│   ├── error_and_exit.c
│   ├── swap_utils.c
│   ├── push_utils.c
│   ├── rotate_utils.c
│   ├── reverse_rotate_utils.c
│   ├── two_three_five_sort_utils.c
│   ├── sort_five_especific_utils.c
│   ├── indexing1.c
│   ├── indexing2.c
│   └── chunk_sort.c
└── Makefile
```
### Resources

42 School — push_swap subject

#### Algorithms:

* Radix Sort

* Chunk-based sorting strategies

* C Standard Library

#### POSIX documentation:

* write(2)

* stdlib(3)
