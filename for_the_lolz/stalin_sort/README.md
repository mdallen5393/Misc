# Stalin (Elimination) Sort

This project is a joke algorithm based on this meme:

![StalinSort meme by @matthew@mastodon.social](https://i.redd.it/x9triplll1v11.jpg)

## Usage

To use the program, run the following command:

`./sort [-v] [-d] [-r] [array]`

- `-v`, `--verbose`: Run the program in verbose mode.
- `-d`, `--desc`: Sort the array in descending order.
- `-r`, `--repeats`: Keep repeated values in the sorted array.
- `array`: The array of integers to sort

## Examples

### Sorting an array, ascending

Command: `./sort 3 2 4 5 1 6 9 2 6 -1`
Output:

    5 elements in array
    Array: [3, 4, 5, 6, 9]

### Sorting an array, descending

Command: `./sort -d 3 2 4 5 1 6 9 2 6 -1`
Output:

    4 elements in array
    Array: [3, 2, 1, -1]

### Sorting an array, verbose

Command: `./sort -v 3 2 4 5 1 6 9 2 6 -1`
Output:

    Running in verbose mode...
    ...BEFORE SORTING: 11 elements in array
    ...Array: [3, 3, 2, 4, 5, 1, 6, 9, 2, 6, -1]
    ......VALUE 3 ELIMINATED
    ......VALUE 2 ELIMINATED
    ......VALUE 1 ELIMINATED
    ......VALUE 2 ELIMINATED
    ......VALUE 6 ELIMINATED
    ......VALUE -1 ELIMINATED
    ...AFTER SORTING: 5 elements in array
    ...Array: [3, 4, 5, 6, 9]
    Sorting complete
    5 elements in array
    Array: [3, 4, 5, 6, 9]

### Sorting an array, keeping repeated values

Command: `./sort -r 3 3 2 4 5 1 6 9 2 6 -1`
Output:

    6 elements in array
    Array: [3, 3, 4, 5, 6, 9]

## Author

Matthew Allen - [Github](https://github.com/mdallen5393) - [LinkedIn](https://www.linkedin.com/in/itsmatthewallen/)