// A recursive binary search function. It returns
// the location of a value in given array arr[start..end] if it is present,
// otherwise -1.
#include <stdio.h>
#include <string.h>
int binarySearch(char** values, int start, int end, const char* value)
{
    if (end >= start) {
        int mid = start + (end - start) / 2;

        // If the element is present at the middle
        // itself
        if (strcmp(values[mid], value) == 0) {
            return mid;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (strcmp(values[mid], value) > 0) {
            return binarySearch(values, start, mid - 1, value);
        }
        // Else the element can only be present
        // in right subarray
        return binarySearch(values, mid + 1, end, value);
    }

    // This is reached when the value is not
    // present in the array of values.
    return -1;
}
int main() {
    char* names[] = {
        "Paul",
        "Raul",
        "Iris",
        "Laura",
        "Randy"
    };
    int find = binarySearch(names, 0, 4, "Randy");
    fprintf(stdout, "%d", find);
}
