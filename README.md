# Fillit

The goal of this project is to arrange every Tetriminos with each others in order to make
the smallest possible square. 
Among all the possible
candidates for the smallest square, the one where Tetriminos is placed on
their most upper-left position will be provided.

### Usage

```bash
$> make
$> ./fillit <sample_file>
```

Valid sample example and execution:
```bash
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
```

Backtracking algorithm. The square is a string.\
Tetrimino encoding logic (after check for valid input) is to find the first `#` in the tetrimino and transform other 3 `#` to 3 numbers using indexes which fully describes the tetrimino:

#### Map of indexes for each `#`
```bash
. . 0 . .
. 3 # 1 .
5 4 2 . .
```

#### Examples
```bash
#...$
###.$  ->  [2, 1, 1] 
....$
....$

....$
.##.$  ->  [1, 5, 1] 
##..$
....$
```
