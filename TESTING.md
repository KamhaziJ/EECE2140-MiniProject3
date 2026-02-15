HOW TO RUN TESTS

Compile:
g++ src/main.cpp -o denoise

Run test1:
./denoise tests/test1.txt

Run test2:
./denoise tests/test2.txt

Run test3:
./denoise tests/test3.txt


EXPECTED RESULTS

The program should:

1. Load the matrix from the file
2. Apply a 3x3 mean filter
3. Print the filtered matrix
4. Save the filtered matrix to output.txt
