*Este proyecto ha sido creado como parte del currículo de 42 por blromero, mruiz-ra.*
# Description
This project has made to sort any list of numbers using two stacks, a specifics set of instructions to manipulate them, and various algorithms with differents time complexity.

### **Validation input**
To properly sort a list of numbers, the input must comply with specific validation rules to be considered valid:
- **Numeric Values Only:** Even element must be a valid integer (positive or negative). Non numeric characters of floating-point numbers are not allowed.
- **No Duplicates:** The list cannot contain duplicate numbers.
- **Integer Limits:** All numbers must fit within the standard integer limits (INT_MIN and INT_MAX).  

### **Stack and Managment**  
A stack is a linear data structure with restricted access. 
Elements can only pushed, popped or transfered from the top of a stack to the top of the other one, and you can swap or rotate a certain n position of elements.
- **pa**: this instruction push the first node or element of the stack B to the top of the stack A. 
- **pb**:  this instruction push the first node or element of the stack A to the top of the stack B.
- **sa**: this instruction swap the first and second elements of the stack A.
- **sb**: this instruction swap the first and second elements of the stack B.
- **ss**: this instruction call to sa and sb at once.
- **ra**: this instruction rotate the top element to the end of the stack becoming the bottom in the stack A.

- **rb**: this instruction rotate the top element to the end of the stack becoming the bottom in the stack B.
- **rr**: this instruction call ra and rb at once.
- **rra**: this instruction moves the last element of the stack to the top in stack A.
- **rrb**: this instruction moves the last element of the stack to the top in stack B.
- **rrr**: this instruction call rra and rrb at once. 

### **Algorithms**
To understand correctly the process, A has been filled with all elements in default order and now we are going to sorted using both stacks, A and B.

- **Simple**: this algorithms finds the minimum value node in the stack A , moves it to top of the stack and push it to the top of B. It repeats the process until A is completely empty and B contains all elements in desceding order.
At the end, it pushes the elements to the top of B back to A until A is full and correctly sorted.

- **Medium**: this algorithm divides the elements of stack A into equal-sized chunks based on their values, using the square root of the stack size to determine the ideal chunk size.  
As we iterate, any element belonging to the current target chunk is pushed to stack B. Once all elements are transferred, stack B becomes fully populated, organized into distinct value ranges (with smaller values at the bottom and larger values near the top).
  
  Finally, the algorithm repeatedly finds the maximum value in stack B and pushes it back to stack A until B is empty. Because the elements are pre-sorted into ranges, locating and moving the maximum element requires significantly fewer instructions.

- **Complex**: This algorithm uses index normalization, assigning each node a target position relative to where it would end up if the stack were fully sorted.
  
  It then performs a bitwise comparison (bit-by-bit) on these indices. Based on the current bit (0 or 1), elements are pushed to stack B and then returned to stack A, progressively sorting the stack bit by bit from the least significant to the most significant bit.

The complexity of standard algorithms is needlessly high for small inputs, generating excessive operations. To ensure optimal performance, we implemented two lightweight routines for small lists ($N \le 5$):

- **sort_minors**: This method locates the smallest elements in stack A and pushes them to stack B until stack A is reduced to 3 elements. It then calls sort_three to handle the remaining elements before pushing the sorted values back from stack B to stack A.

- **sort_three**: Handles all possible permutations of a 3-element stack. It evaluates the current order of the numbers and applies the optimal, minimal set of instructions required to sort them in 2 moves or fewer.

These methods are not exposed directly.
They are automatically invoked by adaptive if the size of the list is equal or less than 5. 

### **Why have we chosen these algorithms?**

- **Simple**:While algorithms like Bubble Sort are easily implemented using sa and ra, their $O(N^2)$ instruction footprint is far too high for large sets. Insertion Sort is effective but requires complex positioning checks. We settled on an adapted Selection Sort for small lists because pulling the minimum/maximum elements directly into stack B provides a predictable, low-overhead approach with deterministic instruction counts.  

- **Medium**: We selected Chunk Sort because it offered the simplest, most direct logic for medium-sized lists while fully reusing key utility functions like ft_normalize and ft_move_to_top. Unlike QuickSort, which requires continuously calculating and updating pivots while shifting numbers back and forth, Chunk Sort relies on a single initial range calculation. Data moves cleanly in just two transfer phases—from A to B in chunks, and then from B back to A in order—minimizing instruction overhead.  

- **Complex**: Bitwise Radix Sort was chosen because it integrates seamlessly with ft_normalize and ft_move_to_top. Normalizing input values into non-negative index ranks eliminated the need to handle negative numbers during bitwise checks. Evaluating binary bits directly fits two-stack mechanics perfectly, offering a deterministic and predictable solution without comparison overhead. Algorithms like HeapSort were avoided because mapping tree-like behavior onto restricted stacks adds excessive, unnecessary complexity.  

### **Flags**

To allow users to select a sorting method, we implemented custom flags. However, since choosing the most efficient algorithm for a specific list size isn't always obvious, we also created an adaptive mode which call to the accurated method depending on the disorder of the list of numbers.

- **--simple**
- **--medium**
- **--complex**
- **--adaptive**

The disorder metric calculates the total position displacement of all elements relative to their fully sorted positions, divided by the total number of unique pairs in the list. This gives us a normalized disorder ratio to determine the most efficient sorting algorithm."

Adaptive choose the smallest ratio of mistakes in order to the complexity of the algorithm:

| Disorder Ratio | Selected Algorithm | Description |
| :--- | :--- | :--- |
| **`ratio < 0.2`** | `Simple` | Ideal for nearly sorted lists (minimal position displacement). |
| **`0.2 <= ratio < 0.5`** | `Medium` | Uses chunking strategy to group relative value ranges. |
| **`ratio >= 0.5`** | `Complex` | Uses Bitwise Radix Sort to efficiently process high disorder. |

These thresholds were set empirically, by measuring instruction counts on many random lists: below 0.2, Simple's minimum is almost always near the top, so it sorts in O(n) push_swap operations; between 0.2 and 0.5, Medium's fixed O(n√n) chunk cost still beats Simple's growing cost; above 0.5, Complex's O(n log n) bit by bit pass becomes the cheapest option. Space stays O(n) in every regime, since both stacks are just linked lists and no extra structures are allocated.

To compare the efficency of each algorithms and understand how they actually work, we have created "--bench", a flag to see the total of instructions invoked, percentage of disorder, algorithm used and complexity.

- **--bench**

    [bench] disorder: 70.00%  
    [bench] strategy: Adaptive / O(nlog(n))  
    [bench] total_ops: 9  
    [bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2   
    [bench] ra: 2 rb: 2 rr: 0 rra: 0 rrb: 1 rrr: 0 

Flag combination is strictly validated based on functionality:
- **No ducplicates:** The same flag cannot be passed more than once.
- **No strategy conflicts:** passing multiple flags specifying differents sorting algorithms is strictly forbbiden.
- **Syntax validation:** any unrecognized or misspelled flag triggers an error.

# Team Contributions  
We created a shared repository to manage changes collaboratively, with each of us working on our own dedicated branch. Both team members contributed equally to the codebase:  
- Miguel: Responsible for designing the core data structures and developing the sorting algorithms.

- Blanca: Responsible for handling parameter constraints, input validation logic, flag management, and function execution calls.

Both team members contributed equally to reviewing and refining each other's work.
# Instructions

### **Compilation**
The project is built with a standard Makefile, compiled using `cc` and the flags `-Wall -Wextra -Werror`. No relinking is performed: object files are only rebuilt when their source changes.

```bash
make        # builds libft, then compiles push_swap
make re     # fclean + all
make clean  # removes .o files (project and libft)
make fclean # clean + removes libft.a and the push_swap binary
```

Available rules: `$(NAME)` (`push_swap`), `all`, `clean`, `fclean`, `re`. Running `make` first triggers `libft`'s own Makefile to build `libft.a`, and only then compiles and links the project sources against it.

### **Restrictions**
- Written in C, following the 42 Norm on every file (including any extra file).
- No global variables.
- Only `read`, `write`, `malloc`, `free`, `exit`, and libft/`ft_printf`-equivalent functions are used.
- No memory leaks: every `malloc`ed node is freed, on both the success and the error paths.
- The program must never crash (segfault, bus error, double free) on any input; invalid input is rejected with a clean `Error` message instead.

### **Usage**
```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] list_of_integers
```
- The integer list is passed as separate arguments (or a single quoted, space-separated argument).
- The strategy flag is optional; `--adaptive` is used by default when none is given.
- `--bench` can be combined with any strategy flag (in either order) to print statistics to `stderr`, while the operations themselves are still printed to `stdout`.
- With no arguments at all, the program prints nothing and returns control immediately.

Examples:
```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --complex "4 67 3 87 23" | ./checker_linux "4 67 3 87 23"
./push_swap --bench --adaptive $(shuf -i 0-9999 -n 500) 2> bench.txt | wc -l
```

# Resources
**Libraries**  

"libft/libft.h"
<unistd.h>
<stdlib.h>
<limits.h>  

**Previous Projects**  

This project contains severals methods from our previous project Libft:  

- ft_putnbr_fd
- ft_strncmp
- ft_putstr_fd 
- ft_isdigit 

**AI**  

Artificial Intelligence (AI) was utilized as an educational and structural assistant throughout the development of this project. Specifically, AI tools were used for:

- Algorithmic Understanding: Grasping the theoretical concepts behind the sorting algorithms and adapting them to two-stack operations.

- Technical & C Language Clarifications: Resolving queries regarding pointer manipulation, memory management, and stack data structures.

- Project Architecture: Guidance on modularizing code, function splitting, and enforcing good C design practices.

- Documentation & Localization: Refining technical terminology and phrasing for the project's README.