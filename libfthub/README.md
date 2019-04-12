## Functions <a name="functions"></a>

Type         | List of Functions
:--------------------|:----------
Binary tree         | btree_create_node, btree_level_count, btree_add_node, btree_apply_infix, btree_apply_suffix, btree_apply_prefix, btree_search_item
Math        | ft_abs, ft_min, ft_min, ft_isprime, ft_sqrt, ft_trunc, ft_ceil, ft_round, ft_floor, ft_pow, ft_hypot, ft_sqrtl, ft_truncl, ft_ceill, ft_roundl, ft_floorl, ft_powl, ft_hypotl, ft_collatz_conjecture, ft_nextprime, ft_nbrlen, ft_factorial, ft_fibonacci, ft_find_next_prime
Linked list        | ft_lstfree, ft_lstadd, ft_lstaddback, ft_lstappend, ft_lstiter, ft_lstdel, ft_lstdelone, ft_lstreverse, ft_lstnew, ft_lstmap
wchar       | ft_wclen, ft_putwchar, ft_putwchar_fd, ft_putwstr, ft_putwstr_fd, ft_wcslen, ft_wcsdup, ft_wcscpy, ft_wcsnew, ft_wcsncpy
Array       | ft_array_max_value, ft_array_new, ft_array_copy, ft_array_rotate_left, ft_array_rotate_right, ft_array_pop, ft_array_do_op, ft_array_delete, ft_array_print, ft_array_bubble_sort, ft_array_insertion_sort, ft_array_repeated_count
Stack       | ft_stck_show, ft_stck_push, ft_stck_pop
Errno       | ft_errno, ft_strerror
Type       | ft_isascii, ft_isalnum, ft_isalpha, ft_isblank, ft_iscntrl, ft_isdigit, ft_isgraph, ft_islower, ft_isspace, ft_tolower, ft_toupper, ft_isprint, ft_ispunct, ft_isupper, ft_islower, ft_isxdigit, ft_iswspace, ft_ismathop
Stdio       | ft_putchar, ft_putchar_fd, ft_putnchar, ft_putnchar_fd, t_putstr, t_putstr_fd, ft_putendl, ft_putendl_fd, ft_putnbr, ft_putnbr_fd, ft_putnbr_base, ft_putnbr_base_fd, ft_putunbr, ft_putnstr, ft_putnstr_fd
Matrix      | ft_matrix_new, ft_matrix_delete
Printf      | ft_printf, parse_specifier, print_spaces, get_attributes, get_nbr_zeroes, get_nbr_spaces, get_nbr_unsigned, format_signed, format_unsigned, print_string, print_wide_string, print_hexadecimal, print_decimal, print_octal, print_character, print_wide_character, print_binary
Stdlib      | ft_atoi, ft_atoi_base, ft_itoa, ft_itoa_base, ft_realloc, ft_calloc
String      | ft_strequ, ft_strnequ, ft_memcmp, ft_strcmp, ft_strncmp, ft_strcat, t_strncat, ft_strchr, ft_strrchr, ft_strnchr, ft_strcpy, ft_strncpy, ft_strstr, ft_strnstr, ft_strdup, ft_strndup, ft_strnew, ft_strjoin, ft_strmap, ft_strmapi, ft_strrev, ft_strsub, ft_strtrim, ft_strtok, ft_strsplit, ft_strclr, ft_strdel, ft_striter, ft_striteri, ft_memdel, ft_memcpy, ft_memccpy, ft_memchr, ft_memmove, ft_memset, ft_memalloc, ft_strlen, ft_strnlen, ft_strlcat, ft_strlcpy
Strings     | ft_bzero
Classic  | ft_active_bits, ft_angle_to_degrees, ft_compact, ft_is_big_endian, ft_is_little_endian, ft_str_is_lowercase, ft_str_is_numeric, ft_str_is_printable, ft_str_is_uppercase, ft_str_is_palindrome, ft_str_starts_with, ft_str_ends_with, ft_do_op, ft_file_extension, ft_str_capitalize, ft_str_to_upcase, ft_str_to_lowcase, ft_program_name, ft_remove_extension, ft_str_remove_whitespace, ft_separated_values, ft_swap, ft_textstyle, ft_textstyle_reset, ft_puterror, ft_puterror_fd, ft_nbrcount, ft_wordcount, ft_wordlen, ft_char_count, ft_values_count


## Setup <a name="setup"></a>

Command       |  Description
:-------------|:-------------
`make`        | Compile the library.
`make clean`  | Remove objects files.
`make fclean` | Remove objects files and the library.
`make re`     | Re-compile the library.
`make test`   | Compile the library, runs a series of tests.
`make install`| Install the library.

The binary `libft.a` will be created at the root of the project's directory.
