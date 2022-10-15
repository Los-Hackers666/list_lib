# Conclusions

First, we decided to work on the algorithm for the `remove_duplicates()` function. The basic idea was to iterate over the elements, using the very first occurrence of a number as a pivot. Every ohter ocurrence gets removed from the list.
After this function was completed, and succesfully tested, we moved on to the file handling portion. At first we wrote all the code for this in the `main()` function, and once all worked, we moved all the functions coded to [`list_lib.h`](https://github.com/Los-Hackers666/list_lib/blob/main/source_code/list_lib.h) for modularity.
The `lread()` function was a bit complicated at first; we were struggling on how to figure out how to read the numbers from the input file, 
given that the function `fputs()` reads each line as an array of characters (a string), while searching for solutions we found multiple solutions, but the one 
that suited us best was using the function `strol()`, so that each line gets parsed as an integer. Once we figured that out, it worked on the fisrt try.
Once the `lread()` function was completed, coding the `lwrite()` function was easy. We found other solutions for this function too; one was intersting in that
it said that using the `snprintf()` function was safe against buffer overflows. In the end we ended up using `fprintf()` instead.
