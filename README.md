# Binary de Bruijn Sequence Generator

This program implements the "prefer-one" algorithm to generate binary de Bruijn sequences. To generate the order-`n` sequence, we use a bitvector of length `2^n` to store the set of visited `n`-bit sequences, and we print the result to `stdout` using one byte per character. Therefore, generating the order-`n` sequence requires approximately `2^n / 8` bytes of memory and `2^n` bytes of disk space.

## Compiling

To compile, just run `make`. To clean up the directory, use `make clean`.

## Usage

To generate the order-`n` sequence, run `./preferone n` (Linux) or `preferone.exe n` (Windows). The value of `n` can be any integer between `1` and `64`, inclusive, although the maximum practical value is bounded by the amount of memory and disk space you have.

For example, to generate the order-`8` sequence and pipe the result to `output.txt`, run `./preferone 8 > output.txt` (Linux) or `preferone.exe 8 > output.txt` (Windows).

## Examples

Shown below are the order-`n` sequences generated by the program, for `1 <= n <= 6`:

n=1: `10`

n=2: `1100`

n=3: `11101000`

n=4: `1111011001010000`

n=5: `11111011100110101100010100100000`

n=6: `1111110111100111010111000110110100110010110000101010001001000000`

## Notes

* See H. Fredricksen, "A Survey of Full Length Nonlinear Shift Register Cycle Algorithms," for a description of the prefer-one algorithm.

* The algorithm implemented in the program is even simpler than the original. We skip the initial step of printing `n` zeros, since the algorithm naturally incorporates them at the end. Therefore, the program's algorithm can be simply stated as, "Print a 1 if you can. Otherwise, print a 0 if you can. Otherwise, stop."
