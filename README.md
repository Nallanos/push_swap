*This project has been created as part of the 42 curriculum by moabdess and abenameu.*

## Description

The Push swap project requires us to sort a set of n different integer values using 2 stacks and a set of operations imposed by the subject.

## Instructions

In order to compile this project, use the provided `Makefile` :

```bash
make
```
or
```bash
make all
```
creates the `push_swap` executable at the root of the repository.

```bash
make clean
```
deletes all created object files.

```bash
make fclean
```
deletes all created object files as well as the push_swap executable.

```bash
make re
```
deletes all created object files and the push_swap executable library then recompiles the project.

## Algorithms

### Simple — selection sort, O(n²)

While a is not empty, we find the index of the minimum of a and bring it to the top
with the shortest rotation (`ra` if it is in the upper half, `rra` otherwise), then `pb`.
Once a is empty, b holds the elements from largest (top) to smallest, so n `pa` rebuild a sorted.

**Time**: each extraction costs at most size/2 rotations + 1 `pb`, so the total is at most
n²/4 + 2n operations → O(n²).
**Space**: O(1) besides the two stacks.

### Medium — chunk sort, O(n√n)

1. **Ranking**: every value is replaced by its rank (number of smaller values), so values
   become 0..n-1 and chunk boundaries are trivial to compute.
2. **Push phase**: ranks are split into k = √n / 2 chunks of size s = n / k. We scan a with `ra`
   and `pb` every element of the current chunk. Elements in the lower half of their chunk are
   sent to the bottom of b with `rb`, so b ends up roughly ordered, largest values near both ends.
3. **Pull phase**: we repeatedly bring the maximum of b to the top (`rb`/`rrb`, shortest way) and `pa`.

**Why √n**: the push phase scans a once per chunk (≈ n·k operations) and the pull phase pays
roughly the chunk size per element (≈ n·s). Since k·s = n, the sum k + s is minimal when
k = s = √n, giving O(n√n). The constant 1/2 was chosen experimentally (best results on 100 and 500).

**Optimisations**:
- a pending `rb` followed by an `ra` is merged into a single `rr`;
- max-1 trick: if the second largest value is cheaper to reach than the largest, we push it first,
  then the largest, then `sa`.

**Space**: O(n) for the temporary rank array, O(1) otherwise.

### Complex

For the complex strategy, i implemented the quick sort algorith that runs in O(n log n) operations.\
Quicksort is a recursive algorithm that sorts the stack in segments.\
We have 2 recursive functions
- `quicksort_a(int n);` : sorts the first n elements of the a stack leaving the second half untouched.
- `quicksort_b(int n);` : sorts the first n elements of the b stack then pushes it to the top of a. The algorithm guarantees that the part already in a is larger that what is being sent from b so we end up with 2 sorted segments in a in the right order.

The way we sort is that for every segment we assign a pivot, then we find the pivot's position which allows us to get two parts, a part composed of numbers smaller that the pivot and a part of the bigger values. The larger part is sorted first then the smaller part is sorted on top of it.

To choose the pivot, `get_pivot(int *array, int n, int k)` returns the value that has exactly k smaller values in the given segment of n first elements of my array.

### Sorting a (quicksort_a)
n <= 1, n == 1 and n == 2 are handled as our base case to stop the recursion.\
Otherwise partition_a splits the segment into three groups, using the pivots of the first half (n / 2) and the first quarter (n / 4) :
- the upper half (high) stays in a
- the next quarter (mid) and lowest quarter (low) are sent to b with low being sent first so mid ends up on top of it.
Then :
- `quicksort_a` on the high part so it ends up at the bottom
- `quicksort_b` on mid
- `quicksort_b` on low so ends up at the top.
- the part that stayed in a is rotated out of the way with ra.
To optimize the algorithm :
- we merge rotations so the rb that places a pushed element is kept waiting (is_next is set to 1). If the next element stays in a, the two rotations become a single rr. When the rotations are reversed later, rra, rrb become a single rrr.
- in our struct, full tells whether the segment is all of a meaning that all elements are in a : if so, the order of the rotated elements does not matter and a is not restored. had_elements tracks whether b already holds other segments: if so, the group that gets rotated is the mid group (so that after the rrb restore, it ends up above low and above the older segment). if not, the low group is rotated to the bottom of b and nothing needs to be restored. This effectively saves all the unecessary operations from restoring if it's not needed.

### Sorting b (quicksort_b)
n == 1, n == 2 and n == 3 are handled as our base case to stop the recursion.\
Otherwise partition_b pushes the larger half to a and rotates past the smaller half, then restores with rrb only if there is other segments below the current segment (if is_next is 1). Then quicksort_a sorts the pushed half in place and quicksort_b moves the smaller half on top of it.

For the base cases we use these functions :
`sort_three_a`, `sort_three_b`, `push_two_b`, these ensure that we optimize the algorithm instead of letting it just sort itself out with only a base case for n == 1. These functions are used to sort 2 or 3 elements using only sa, sb, pa and pb. This is important because we should not use rotations if the segment  happens to be on top of another segment, rotating would mix everything up.

### Adaptive

The disorder (fraction of inverted pairs, measured before any operation) selects the strategy:

| Disorder | Strategy | Complexity |
|---|---|---|
| < 0.2 | Simple (selection sort) | O(n²) |
| 0.2 – 0.5 | Medium (chunk sort) | O(n√n) |
| ≥ 0.5 | Complex (quicksort) | O(n log n) |

**Rationale for the thresholds**: with a low disorder, most elements are already close to their
final place, so the minimum is usually near the top of a and selection sort pays very few rotations,
with no preprocessing overhead. As the disorder grows, elements are spread further and the chunk
sort's grouping pays off. Above 0.5 (random or reversed input), quicksort gives the lowest
operation counts.

**Measured results** (default mode, verified with checker_linux):
100 numbers ≈ 616 operations (max 654), 500 numbers ≈ 4 888 operations (max 5 297).

**Space**: O(n) for the stacks and the rank array; the quicksort recursion adds O(log n).


## Labor repartition

moabdess : first version of the input validation, complex algorithm (quicksort), benchmark mode, norm

abenameu : argument parsing and validation (rewrite), stack setup and memory, disorder, sort operations, simple algorithm, medium algorithm

## Resources

- Manual pages of the Libc functions
- The 42 Libft subject pdf
- Quick sort wikipedia page : https://en.wikipedia.org/wiki/Quicksort
- Video explanation of the quick sort algorithm : https://www.youtube.com/watch?v=Vtckgz38QHs
- In depth explanation of how to implement the quick sort algorithm : https://www.youtube.com/watch?v=pM-6r5xsNEY
### AI usage

abenameu used an AI assistant (Claude) during the project, as a reviewer and a tutor rather than as a code generator:

- **Understanding the algorithms**: explanations of the chunk sort (ranking, chunks, the `rb` trick), of why √n chunks balance the push and pull phases, and of the `rr` merge and max-1 optimisations, before implementing them.
- **Debugging and code review**: spotting bugs in the argument parsing, the input validation (int overflow, sign handling), the stack setup (memory errors, uninitialised values, off-by-one) and the medium algorithm.
- **Testing**: running test series with valgrind and the provided checker, and measuring operation counts on random inputs to tune the number of chunks.
