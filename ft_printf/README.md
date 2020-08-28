# Basic ft\_printf Unit Test

A unit test for the 42 curriculum ft\_printf project.
There are much more extensive and thorough tests out there, this one I just put
together in a couple of hours to perform a couple of peer evaluations.


## How to Run

First, place your library (must be named libftprint.a) inside the repo directory.
Then:

```bash
./compare.sh
```
This will compile the test executable, which requires your ft\_printf to
run correctly.
Then, it runs the executable, which produces two output files:
* **real.output** which contains the output of the actual printf function.
* **test.output** which contains the output of **your** ft\_printf.

Return values of printf and ft\_printf are also compared while the executable
runs.
After the output files are made, a diff file is produced (**diff.output**).
This file will be tested, and if it's size is greater than 0, the test is
considered failed.

## Extra commands

Delete all output files, object files, and the executable:
```
make fclean
```

Delete only object files:
```
make clean
```
