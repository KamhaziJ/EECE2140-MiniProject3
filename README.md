Mini Project 3 — Image Denoising

BUILD

g++ src/main.cpp -o denoise


RUN

./denoise tests/test1.txt


DESIGN NOTES

The program reads a grayscale image stored as a matrix.
It applies a 3x3 mean filter to reduce noise.
Border pixels are left unchanged (ignore-border policy).


COPILOT USAGE

Copilot helped with:
- File parsing logic
- Loop structure for the 3x3 filter

I verified:
- Matrix loading
- Output formatting

One issue fixed manually:
- Correct placement of output file writing so it runs before return 0.

DEMO

See demo.png for a screenshot of the program running successfully.
