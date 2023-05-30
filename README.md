/*The code provided is an implementation of a simplified version of the printf function in C. It includes several source files, each responsible for a specific aspect of the functionality.

Here is a breakdown of the different files and their purposes:

1-_printf.c: This file contains the main _printf function, which serves as the entry point for the custom printf implementation. It takes a format string and a variable number of arguments, and it iterates over the format string to process the format specifiers and print the corresponding values.

2-find_flags.c: This file includes the find_flags function, which is responsible for identifying and calculating the active flags specified in the format string. It iterates over the format string starting from the position specified by *i, and for each character found in format, it checks if it matches any of the flag characters defined in FLAGS_CH. If a match is found, the corresponding flag value is bitwise ORed with the flag variable. The function then updates the value of *i and returns the final flag value.

3-find_precision.c: This file contains the find_precision function, which is responsible for extracting the precision value specified in the format string. It checks if the character following the current position *i is a dot (indicating a precision specification). If it is, the function iterates over the subsequent characters to extract the precision value. The precision can be a positive integer or an asterisk character '*', which means the value will be provided as an argument from the variable argument list (va_list list). The function returns the extracted precision value.

4-find_size.c: This file includes the get_size function, which determines the size specifier used in the format string. The function checks if the character following the current position *i is 'l' (indicating a long size specifier) or 'h' (indicating a short size specifier). If a valid size specifier is found, the function updates the value of *i accordingly and returns the corresponding size value.

5-find_width.c: This file contains the get_width function, which extracts the width specifier from the format string. It iterates over the characters following the current position *i until it encounters a non-digit character. The width specifier can be a positive integer or an asterisk character '*', indicating that the width value will be provided as an argument from the variable argument list (va_list list). The function returns the extracted width value.

6-type_to_print.c: This file includes the type_to_print function, which determines the type of the argument to be printed based on the format specifier. It iterates over the fmt_types array, which contains structs mapping format specifiers to corresponding print functions. If a match is found, the corresponding print function is called, passing the necessary arguments. If no match is found, the function handles the case of a literal percent sign '%%' and prints it. The function returns the number of characters printed.

7-functions_char_string.c: This file contains the print functions for the 'c', 's', and '%' format specifiers. These functions are responsible for formatting and printing characters, strings, and percent signs, respectively. They use the provided arguments and handle various flags, widths, and precisions specified in the format string.

8-functions_num.c: This file includes the print functions for integer-based format specifiers, such as 'd', 'i', 'u', 'o', 'x', and 'X'. These functions handle the conversion and printing of signed and unsigned integers in decimal, octal, and hexadecimal formats. They also consider the specified flags, widths,.
*/
