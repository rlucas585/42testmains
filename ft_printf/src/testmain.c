/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 10:41:11 by rlucas        #+#    #+#                 */
/*   Updated: 2020/08/28 13:07:24 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);

/* -----------------------------------------------------------------------------
** Color defines
** ---------------------------------------------------------------------------*/

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

/* -----------------------------------------------------------------------------
** Utility functions
** ---------------------------------------------------------------------------*/

int		redirect_output(int real_fd) {
	int		saved = dup(fileno(stdout));

	if (dup2(real_fd, fileno(stdout)) == -1)
	{
		dprintf(2, "Failed to redirect output to file");
		exit(1);
	}

	return (saved);
}

/* -----------------------------------------------------------------------------
** Tests
** ---------------------------------------------------------------------------*/

int		test_chars(int real_file, int test_file)
{
	int		save_out = redirect_output(real_file);
	int		rets1[3];
	int		rets2[3];
	int		fail = 0;

	rets1[0] = printf("testing simple chars: %c %-40c %13c\n", 'a', 'x', '+');
	rets1[1] = printf("Test with null char: %5c\n", '\0');
	rets1[2] = printf("Test with null char: %-10c\n", '\0');
	fflush(stdout);

	redirect_output(test_file);

	rets2[0] = ft_printf("testing simple chars: %c %-40c %13c\n", 'a', 'x', '+');
	rets2[1] = ft_printf("Test with null char: %5c\n", '\0');
	rets2[2] = ft_printf("Test with null char: %-10c\n", '\0');
	fflush(stdout);

	dup2(save_out, fileno(stdout));
	close(save_out);

	for (unsigned int i = 0; i < 3; i++)
	{
		if (rets1[i] != rets2[i])
		{
			dprintf(2, "Error in return of test %d in char tests\n", i);
			fail = 1;
		}
	}

	return (fail);
}

int		test_strings(int real_file, int test_file)
{
	int		save_out = redirect_output(real_file);
	int		rets1[8];
	int		rets2[8];
	int		fail = 0;

	rets1[0] = printf("Simple string\n");
	rets1[1] = printf("Simple string with %s\n", "another string");
	rets1[2] = printf("With %10s and %.6s\n", "width", "precision");
	rets1[3] = printf("Combining and negative %-14.5s\n", "all of the tough tests");
	/* rets1[4] = printf("Adding %*.*s with width and precision args\n", 13, 4, (char *)NULL); */
	rets1[4] = 0;
	rets1[5] = printf("Negative %10.*s as arg?\n", -6, "precision");
	rets1[6] = printf("%s %s %s %s %% %% %s\n", "Just", "a", "lot", "of", "strings");
	rets1[7] = printf("Well done if you passed all the test\n");
	fflush(stdout);

	redirect_output(test_file);

	rets2[0] = ft_printf("Simple string\n");
	rets2[1] = ft_printf("Simple string with %s\n", "another string");
	rets2[2] = ft_printf("With %10s and %.6s\n", "width", "precision");
	rets2[3] = ft_printf("Combining and negative %-14.5s\n", "all of the tough tests");
	/* rets2[4] = ft_printf("Adding %*.*s with width and precision args\n", 13, 4, NULL); */
	rets2[4] = 0;
	rets2[5] = ft_printf("Negative %10.*s as arg?\n", -6, "precision");
	rets2[6] = ft_printf("%s %s %s %s %% %% %s\n", "Just", "a", "lot", "of", "strings");
	rets2[7] = ft_printf("Well done if you passed all the test\n");
	fflush(stdout);

	dup2(save_out, fileno(stdout));
	close(save_out);

	for (unsigned int i = 0; i < 8; i++)
	{
		if (rets1[i] != rets2[i])
		{
			dprintf(2, "Error in return of test %d in char tests\n", i);
			fail = 1;
		}
	}

	return (fail);
}

int		test_pointers(int real_file, int test_file)
{
	int		save_out = redirect_output(real_file);
	int		rets1[2];
	int		rets2[2];
	int		fail = 0;
	char	*stackstr = "I'm a string literal on the stack";

	rets1[0] = printf("Simple pointer: %p\n", &save_out);
	rets1[1] = printf("Pointer with some flags: %-*p\n", 20, stackstr);
	fflush(stdout);

	redirect_output(test_file);

	rets2[0] = ft_printf("Simple pointer: %p\n", &save_out);
	rets2[1] = ft_printf("Pointer with some flags: %-*p\n", 20, stackstr);
	fflush(stdout);

	dup2(save_out, fileno(stdout));
	close(save_out);

	for (unsigned int i = 0; i < 2; i++)
	{
		if (rets1[i] != rets2[i])
		{
			dprintf(2, "Error in return of test %d in char tests\n", i);
			fail = 1;
		}
	}

	return (fail);
}

int		test_integers(int real_file, int test_file)
{
	int		save_out = redirect_output(real_file);
	int		rets1[10];
	int		rets2[10];
	int		fail = 0;

	rets1[0] = printf("Basic number: %d\n", 12345678);
	rets1[1] = printf("Negative number: %d", -666);
	rets1[2] = printf("Width: %25d\n", 9876543);
	rets1[3] = printf("Precision: %.15d", 9876543);
	rets1[4] = printf("Width and precision and left align: %-30.16d\n", 12345678);
	rets1[5] = printf("Width and precision args & named 'i': %-*.*i\n", -15, 18, 12021);
	rets1[6] = printf("With maths?: %d%d%%%d\n", 101 - 1500, 101 + 1500, 99999);
	rets1[7] = printf("Unsigned ints also: %50.30u", 3147483647u);
	rets1[8] = printf("??%24.4d%u%d\n", 12345678, 3999999999u, 0);
	rets1[9] = printf("Try some 0's: %d%u%20.5d\n", 0, 0, 0);
	fflush(stdout);

	redirect_output(test_file);

	rets2[0] = ft_printf("Basic number: %d\n", 12345678);
	rets2[1] = ft_printf("Negative number: %d", -666);
	rets2[2] = ft_printf("Width: %25d\n", 9876543);
	rets2[3] = ft_printf("Precision: %.15d", 9876543);
	rets2[4] = ft_printf("Width and precision and left align: %-30.16d\n", 12345678);
	rets2[5] = ft_printf("Width and precision args & named 'i': %-*.*i\n", -15, 18, 12021);
	rets2[6] = ft_printf("With maths?: %d%d%%%d\n", 101 - 1500, 101 + 1500, 99999);
	rets2[7] = ft_printf("Unsigned ints also: %50.30u", 3147483647u);
	rets2[8] = ft_printf("??%24.4d%u%d\n", 12345678, 3999999999u, 0);
	rets2[9] = ft_printf("Try some 0's: %d%u%20.5d\n", 0, 0, 0);
	fflush(stdout);

	dup2(save_out, fileno(stdout));
	close(save_out);

	for (unsigned int i = 0; i < 10; i++)
	{
		if (rets1[i] != rets2[i])
		{
			dprintf(2, "Error in return of test %d in char tests\n", i);
			fail = 1;
		}
	}

	return (fail);
}

int		test_hexadecimals(int real_file, int test_file)
{
	int		save_out = redirect_output(real_file);
	int		rets1[10];
	int		rets2[10];
	int		fail = 0;

	rets1[0] = printf("Basic number: %x\n", 12345678);
	rets1[1] = printf("Negative number: %x", -666);
	rets1[2] = printf("Width: %25x\n", 9876543);
	rets1[3] = printf("Precision: %.15x", 9876543);
	rets1[4] = printf("Width and precision and left align: %-30.16x\n", 12345678);
	rets1[5] = printf("Width and precision args & named 'i': %-*.*x\n", -15, 18, 12021);
	rets1[6] = printf("With maths?: %x%x%%%X\n", 101 - 1500, 101 + 1500, 99999);
	rets1[7] = printf("Unsigned ints also: %50.30X", 3147483647u);
	rets1[8] = printf("??%24.4x%X%x\n", 12345678, 3999999999u, 0);
	rets1[9] = printf("Try some 0's: %x%X%20.5x\n", 0, 0, 0);
	fflush(stdout);

	redirect_output(test_file);

	rets2[0] = ft_printf("Basic number: %x\n", 12345678);
	rets2[1] = ft_printf("Negative number: %x", -666);
	rets2[2] = ft_printf("Width: %25x\n", 9876543);
	rets2[3] = ft_printf("Precision: %.15x", 9876543);
	rets2[4] = ft_printf("Width and precision and left align: %-30.16x\n", 12345678);
	rets2[5] = ft_printf("Width and precision args & named 'i': %-*.*x\n", -15, 18, 12021);
	rets2[6] = ft_printf("With maths?: %x%x%%%X\n", 101 - 1500, 101 + 1500, 99999);
	rets2[7] = ft_printf("Unsigned ints also: %50.30X", 3147483647u);
	rets2[8] = ft_printf("??%24.4x%X%x\n", 12345678, 3999999999u, 0);
	rets2[9] = ft_printf("Try some 0's: %x%X%20.5x\n", 0, 0, 0);
	fflush(stdout);

	dup2(save_out, fileno(stdout));
	close(save_out);

	for (unsigned int i = 0; i < 2; i++)
	{
		if (rets1[i] != rets2[i])
		{
			dprintf(2, "Error in return of test %d in char tests\n", i);
			fail = 1;
		}
	}

	return (fail);
}

int		main(void)
{
	int		real_output;
	int		test_output;

	real_output = open(REAL_OUTPUT_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	test_output = open(TEST_OUTPUT_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (test_chars(real_output, test_output))
		dprintf(2, RED"Failure in character tests\n"NORMAL);
	if (test_strings(real_output, test_output))
		dprintf(2, RED"Failure in string tests\n"NORMAL);
	if (test_pointers(real_output, test_output))
		dprintf(2, RED"Failure in pointer tests\n"NORMAL);
	if (test_integers(real_output, test_output))
		dprintf(2, RED"Failure in integer tests\n"NORMAL);
	if (test_hexadecimals(real_output, test_output))
		dprintf(2, RED"Failure in hexadecimal tests\n"NORMAL);

	return (0);
}
