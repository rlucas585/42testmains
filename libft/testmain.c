/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:49:02 by rlucas        #+#    #+#                 */
/*   Updated: 2019/12/14 17:26:12 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void		test_memset(void)
{
	char		str1[] = "Testing memset";
	char		str2[] = "Testing memset";

	memset(str1, 'A', 6);
	ft_memset(str2, 'A', 6);
	printf("Memset result: %s\nMy_set result: %s\n", str1, str2);
}

void		test_memcpy(void)
{
	char mystring1[] = "12345abcde12345";
	char mystring2[] = "12345abcde12345";
	char mystring3[] = "12345abcde12345";
	char mystring4[] = "12345abcde12345";

	printf("\n\nMemcpy Test\n-----------------------\n");
	printf("Before memcpy:\nstring 1: %s\nstring 2: %s\n\n", mystring1, mystring2);
	memcpy(mystring1, mystring3, 9);
	ft_memcpy(mystring2, mystring4, 9);
	printf("Memcpy result: %s\nMy_cpy result: %s\n", mystring1, mystring3);
}	

void		test_memccpy(void)
{
	char mystring1[] = "12345abcde12345";
	char mystring2[] = "recoon";
	char mystring3[] = "12345abcde12345";
	char mystring4[] = "recoon";

	printf("Before memccpy:\nstring 1: %s\nstring 2: %s\n", mystring1, mystring2);
	printf("string 3: %s\nstring 4: %s\n", mystring3, mystring4);
	memccpy(mystring1, mystring2, 'c', 9);
	ft_memccpy(mystring3, mystring4, 'c', 9);
	printf("After memccpy:\nstring 1: %s\nstring 2: %s\n", mystring1, mystring2);
	printf("string 3: %s\nstring 4: %s\n", mystring3, mystring4);
}

void		test_memmove(void)
{
	char	*mystring1;
	char	*mystring2;
	char	*str2;
	char	*str4;

	mystring1 = ft_strdup("12345abcde12345");
	mystring2 = ft_strdup("12345abcde12345");
	str2 = ft_strdup("memmove can be very useful......");
	str4 = ft_strdup("memmove can be very useful......");
	printf("\n\nMemmove Test\n-----------------------\n");
	printf("Original strings:\nstring1: %s\nstring2: %s\n\n", mystring1, str2);
	memmove(mystring1, mystring1 + 5, 8);
	ft_memmove(mystring2, mystring2 + 5, 8);
	memmove(str4 + 20, str4 + 15, 13);
	ft_memmove(str2 + 20, str2 + 15, 13);
	printf("Memmove result: %s\nMy_move result: %s\n\n", mystring1, mystring2);
	printf("Memmove result: %s\nMy_move result: %s\n\n", str4, str2);
	free(mystring1);
	free(mystring2);
	free(str2);
	free(str4);
}

void		test_memcmp(void)
{
	char	str1[] = "A string to compare";
	char	str2[] = "A string to compare";
	char	str3[] = "A strang to compare";
	char	str4[] = "A strong to compare";
	char	str5[] = "A string to compare but it's too long";
	int		a;
	int		b;

	printf("\n\nMemcmp Test\n-----------------------\n");
	a = memcmp(str1, str2, 17);
	b = ft_memcmp(str1, str2, 17);
	printf("Test 1\n\nmemcmp result: %d\nmy result: %d\n\n", a, b);
	a = memcmp(str1, str3, 17);
	b = ft_memcmp(str1, str3, 17);
	printf("Test 2\n\nmemcmp result: %d\nmy result: %d\n\n", a, b);
	a = memcmp(str1, str4, 17);
	b = ft_memcmp(str1, str4, 17);
	printf("Test 3\n\nmemcmp result: %d\nmy result: %d\n\n", a, b);
	a = memcmp(str1, str5, 17);
	b = ft_memcmp(str1, str5, 17);
	printf("Test 4\n\nmemcmp result: %d\nmy result: %d\n\n", a, b);
}

void		test_memchr(void)
{
	char	str1[] = "Find the x and return the pointer to it";
	char	*ptr;
	char	*myptr;

	ptr = memchr(str1, 'x', 20);
	myptr = ft_memchr(str1, 'x', 20);
	printf("\n\nMemchr Test\n-----------------------\n");
	printf("Memchr result: %s\nMy_chr result: %s\n", ptr, myptr);
}

void		test_strlcpy(void)
{
	char	str1[] = "hello !";
	char	buff1[0xF00];
	char	buff2[0xF00];
	int		r1;
	int		r2;

	r1 = strlcpy(buff1, str1, 2);
	r2 = ft_strlcpy(buff2, str1, 2);
	printf("Strlcpy: %s\nMystcpy: %s\n", buff1, buff2);
	printf("r1: %d\nr2: %d\n", r1, r2);
}


void		test_strlcat(void)
{
	char	str1[40] = "A string to lengthen";
	char	str2[20] = "------ a tail";
	char	str3[40] = "A string to lengthen";
	char	str4[13] = "tiny";
	char	str5[20] = "------ a tail";
	char	str6[13] = "tiny";
	int		a;
	int		b;

	a = 0;
	b = 0;
	printf("\n\nStrlcat Test\n-----------------------\n");
	a = strlcat(str1, str2, 35);
	b = ft_strlcat(str3, str2, 35);
	printf("Test 1\n\nstrlcat result: %s\nmy result: %s\n\n", str1, str3);
	printf("strlcat return: %d\nmy return: %d\n\n", a, b);
	a = strlcat(str4, str5, 13);
	b = ft_strlcat(str6, str5, 13);
	printf("Test 2\n\nstrlcat result: %s\nmy result: %s\n\n", str4, str6);
	printf("strlcat return: %d\nmy return: %d\n\n", a, b);
}

void		test_strchr(void)
{
	char	str1[] = "This is a X string with an X and another one";
	char	str2[] = "Find the big x except it's not here";
	char	str3[] = "Cut off everything before the Q appears";
	char	*normalptr;
	char	*myptr;

	printf("\n\nStrchr Test\n-----------------------\n");
	normalptr = strchr(str1, 'X');
	myptr = ft_strchr(str1, 'X');
	printf("Test 1\n\nstrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strchr(str2, 'X');
	myptr = ft_strchr(str2, 'X');
	printf("Test 2\n\nstrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strchr(str3, 'Q');
	myptr = ft_strchr(str3, 'Q');
	printf("Test 3\n\nstrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
}

void		test_strrchr(void)
{
	char	str1[] = "This is a X string with an X and another one";
	char	str2[] = "Find the big x except it's not here";
	char	str3[] = "Cut off everything before the Q appears";
	char	*normalptr;
	char	*myptr;

	printf("\n\nStrrchr Test\n-----------------------\n");
	normalptr = strrchr(str1, 'X');
	myptr = ft_strrchr(str1, 'X');
	printf("Test 1\n\nstrrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strrchr(str2, 'X');
	myptr = ft_strrchr(str2, 'X');
	printf("Test 2\n\nstrrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strrchr(str3, 'Q');
	myptr = ft_strrchr(str3, 'Q');
	printf("Test 3\n\nstrrchr result: %s\nmy result: %s\n\n", normalptr, myptr);
}

void		test_strnstr(void)
{
	char	str1[] = "This is a X string with an X and another one";
	char	str2[] = "Find the big x except it's not here";
	char	str3[] = "Cut off everything before the Q appears";
	char	str4[] = "The function is not going to find the cake";
	char	str5[] = "This cake is invisible";
	char	*normalptr;
	char	*myptr;

	printf("\n\nStrnstr Test\n-----------------------\n");
	normalptr = strnstr(str1, "string", 40);
	myptr = ft_strnstr(str1, "string", 40);
	printf("Test 1\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strnstr(str2, "big x", 15);
	myptr = ft_strnstr(str2, "big x", 15);
	printf("Test 2\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strnstr(str3, "cake", 50);
	myptr = ft_strnstr(str3, "cake", 50);
	printf("Test 3\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strnstr(str4, "cake", 20);
	myptr = ft_strnstr(str4, "cake", 20);
	printf("Test 4\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strnstr(str5, "cake", 0);
	myptr = ft_strnstr(str5, "cake", 0);
	printf("Test 5\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
	normalptr = strnstr("", "cake", 20);
	myptr = ft_strnstr("", "cake", 20);
	printf("Test 6\n\nstrnstr result: %s\nmy result: %s\n\n", normalptr, myptr);
}

void		test_strncmp(void)
{
	char	str1[] = "A string to compare";
	char	str2[] = "A string to compare";
	char	str3[] = "A strang to compare";
	char	str4[] = "A strong to compare";
	char	str5[] = "A string to compare but it's too long";
	char	str6[] = "Je test un ft_strncmp, car j'aime bien ca!";
	char	str7[] = "Je test un ft_strncmp, car j'aime bien ca";
	int		a;
	int		b;

	printf("\n\nStrncmp Test\n-----------------------\n");
	a = strncmp(str1, str2, 17);
	b = ft_strncmp(str1, str2, 17);
	printf("Test 1\n\nstrncmp result: %d\nmy result: %d\n\n", a, b);
	a = strncmp(str1, str3, 17);
	b = ft_strncmp(str1, str3, 17);
	printf("Test 2\n\nstrncmp result: %d\nmy result: %d\n\n", a, b);
	a = strncmp(str1, str4, 17);
	b = ft_strncmp(str1, str4, 17);
	printf("Test 3\n\nstrncmp result: %d\nmy result: %d\n\n", a, b);
	a = strncmp(str1, str5, 17);
	b = ft_strncmp(str1, str5, 17);
	printf("Test 4\n\nstrncmp result: %d\nmy result: %d\n\n", a, b);
	a = strncmp(str6, str7, 42);
	b = ft_strncmp(str6, str7, 42);
	printf("Test 5\n\nstrncmp result: %d\nmy result: %d\n\n", a, b);
}

void		test_atoi(void)
{
	char	str1[] = "     782";
	char	str2[] = "jekjfsi3729hjks    ";
	char	str3[] = "		-3287E";
	char	str4[] = "     +2147483647";
	char	str5[] = "      -2147483648";
	char	str6[] = "      9223372036854775807";
	int		a;
	int		b;

	printf("\n\nAtoi Test\n-----------------------\n");
	a = atoi(str1);
	b = ft_atoi(str1);
	printf("\nTest 1\n\nstring 1: %s\n", str1);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
	a = atoi(str2);
	b = ft_atoi(str2);
	printf("\nTest 2\n\nstring 2: %s\n", str2);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
	a = atoi(str3);
	b = ft_atoi(str3);
	printf("\nTest 3\n\nstring 3: %s\n", str3);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
	a = atoi(str4);
	b = ft_atoi(str4);
	printf("\nTest 4\n\nstring 4: %s\n", str4);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
	a = atoi(str5);
	b = ft_atoi(str5);
	printf("\nTest 5\n\nstring 5: %s\n", str5);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
	a = atoi(str6);
	b = ft_atoi(str6);
	printf("\nTest 6\n\nstring 6: %s\n", str6);
	printf("Atoi result: %d\nMy result: %d\n", a, b);
}

void		test_isalpha(void)
{
	char	c;

	printf("\n\nIsalpha Test\n-----------------------\n");
	c = 'c';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = '!';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = 'X';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = '%';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = '+';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = 0;
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
	c = '\n';
	printf("Isalpha result: %d\nMy result: %d\n\n", isalpha(c), ft_isalpha(c));
}

void		test_isdigit(void)
{
	int		c;

	printf("\n\nIsdigit Test\n-----------------------\n");
	c = '6';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = '0';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = '%';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = 'X';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = '+';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = 0;
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
	c = '\n';
	printf("Isdigit result: %d\nMy result: %d\n\n", isdigit(c), ft_isdigit(c));
}

void		test_isalnum(void)
{
	char	c;

	printf("\n\nIsalnum Test\n-----------------------\n");
	c = '6';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = '0';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = '%';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = 'X';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = '+';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = 0;
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
	c = '\n';
	printf("Isalnum result: %d\nMy result: %d\n\n", isalnum(c), ft_isalnum(c));
}

void		test_isascii(void)
{
	char	c;

	printf("\n\nIsascii Test\n-----------------------\n");
	c = '6';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = '0';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = '%';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = 'X';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = '+';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = 0;
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
	c = '\n';
	printf("Isascii result: %d\nMy result: %d\n\n", isascii(c), ft_isascii(c));
}

void		test_isprint(void)
{
	char	c;

	printf("\n\nIsprint Test\n-----------------------\n");
	c = '6';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = '0';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = 'c';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = 'X';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = '+';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = 'm';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
	c = '\n';
	printf("Isprint result: %d\nMy result: %d\n\n", isprint(c), ft_isprint(c));
}

void		test_toupper(void)
{
	char	c;
	char	str1[] = "StrINg WITh rAndOM CaSEs!";
	char	str2[] = "StrINg WITh rAndOM CaSEs!";
	int		i;

	i = 0;
	printf("\n\nToupper Test\n-----------------------\n");
	c = '6';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	c = '0';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	c = 'c';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	c = 'X';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	c = '+';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	c = 'm';
	printf("Toupper result: %c\nMy result: %c\n\n", toupper(c), ft_toupper(c));
	while (str1[i] != '\0')
	{
		str1[i] = toupper(str1[i]);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		str2[i] = ft_toupper(str2[i]);
		i++;
	}
	printf("Toupper result: %s\nMy result: %s\n\n", str1, str2);
}

void		test_tolower(void)
{
	char	c;
	char	str1[] = "StrINg WITh rAndOM CaSEs!";
	char	str2[] = "StrINg WITh rAndOM CaSEs!";
	int		i;

	i = 0;
	printf("\n\nTolower Test\n-----------------------\n");
	c = '6';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	c = '0';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	c = 'c';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	c = 'X';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	c = '+';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	c = 'm';
	printf("Tolower result: %c\nMy result: %c\n\n", tolower(c), ft_tolower(c));
	while (str1[i] != '\0')
	{
		str1[i] = tolower(str1[i]);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		str2[i] = ft_tolower(str2[i]);
		i++;
	}
	printf("Tolower result: %s\nMy result: %s\n\n", str1, str2);
}

void		test_calloc(void)
{
	char		*memptr;

	printf("\n\nCalloc Test\n-----------------------\n");

	memptr = (char *)ft_calloc(15, sizeof(char));
	if (!memptr)
		printf("Failure to allocate memory\n");
	else if (*(memptr + 13) != '\0' && *(memptr + 7) != '\0')
		printf("Memory is not set to zero bytes\n");
	else
		printf("Memory allocated successfully\n");
	free(memptr);
}

void		test_strdup(void)
{
	char		*normstring;
	char		*mystring;

	printf("\n\nStrdup Test\n-----------------------\n");

	normstring = strdup("This is the right message");
	mystring = ft_strdup("This is the right message");
	printf("strdup result: %s\nmystrd result: %s\n", normstring, mystring);
	free(normstring);
	free(mystring);
}

void		test_substr(void)
{
	char	bigstr[] = "I am a big string";
	char	*smallstring;

	printf("\n\nSubstr Test\n-----------------------\n");

	smallstring = ft_substr(bigstr, 7, 20);
	printf("Original String: %s\n", bigstr);
	printf("Smaller String: %s\n", smallstring);
	free(smallstring);
}

void		test_strjoin(void)
{
	char	s1[] = "Join us ";
	char	s2[] = "together please";
	char	*tmp;

	printf("\n\nStrjoin Test\n-----------------------\n");
	printf("String 1: %s\nString 2: %s\n\n", s1, s2);
	tmp = ft_strjoin(s1, s2);
	printf("Result of ft_strjoin: %s\n", tmp);
	free(tmp);
}

void		test_strtrim(void)
{
	char	s1[] = "AAAAAAAAAA           Trim all the sides    AAAAAAA";
	char	s2[] = "A ";
	char	s3[] = "AFEJSAKLJ;ADEJKJFELKJKFkfjekjkfDKJFKJEFJEK";
	char	s4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	s5[] = " \t \t \n   \n\n\n\t";
	char	*tmp;

	printf("\n\nStrtrim Test\n-----------------------\n");

	printf("\nTest 1\n\n");
	printf("String to trim: %s\nChars to trim: '%s'\n\n", s1, s2);
	tmp = ft_strtrim(s1, s2);
	printf("Result: %s\n", tmp);
	free(tmp);

	printf("\nTest 2\n\n");
	printf("String to trim: %s\nChars to trim: '%s'\n\n", s3, s4);
	tmp = ft_strtrim(s3, s4);
	printf("Result: %s\n", tmp);
	free(tmp);

	printf("\nTest 3\n\n");
	printf("String to trim: %s(a lot of new lines and tabs)\nChars to trim: '%s'\n\n", s5, "' \\n\\t'");
	tmp = ft_strtrim(s5, "\n\t");
	printf("Result: %s\n", tmp);
	free(tmp);
}

void		free_array_of_strings(char **strarray, int elemcount)
{
	while (elemcount >= 0)
	{
		free(strarray[elemcount]);
		elemcount--;
	}
	if (strarray)
		free(strarray);
}

static int		ft_count_words(char const *s, char c)
{
	int				i;
	int				total;
	int				inword;

	i = 0;
	total = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && inword == 0)
		{
			total++;
			inword = 1;
		}
		if (s[i] == c && inword == 1)
			inword = 0;
		i++;
	}
	return (total);
}

void		test_split(void)
{
	char	bigstr[] = "split this into a bunch of different words";
	char	**str_array;
	int		i;
	int		wordcount;
	char	c;

	i = 0;
	c = ' ';
	str_array = ft_split(bigstr, c);
	wordcount = ft_count_words(bigstr, c);
	printf("\n\nSplit Test\n-----------------------\n");

	printf("Original String: %s\n\n", bigstr);
	printf("Resultant Array\n------------\n");
	while (*(str_array + i))
	{
		printf("Position %d: %s\n", i, str_array[i]);
		i++;
	}
	free_array_of_strings(str_array, wordcount);
}

void		test_itoa(void)
{
	int			n;
	char		*tmpstr;

	printf("\n\nItoa Test\n-----------------------\n");
	n = 140;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
	n = 0;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
	n = 1;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
	n = -1;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
	n = 2147483647;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
	n = -2147483648;
	tmpstr = ft_itoa(n);
	printf("Number: %d\nItoa result: %s\n\n", n, tmpstr);
	free(tmpstr);
}

char		func_for_strmapi(unsigned int n, char c)
{
	return (c + n);
}

void		test_strmapi(void)
{
	char		str1[] = "String to";
	char		*str2;

	printf("\n\nStrmapi Test\n-----------------------\n");
	str2 = ft_strmapi(str1, func_for_strmapi);
	printf("Original string: %s\n", str1);
	printf("New string: %s\n", str2);
	free(str2);
}

void		test_ft_putchar_fd(void)
{
	int		myfd;
	char	c;

	c = 'a';
	myfd = open("fd_tests", O_RDWR | O_APPEND | O_CREAT, 0644);
	while (c <= 'z')
	{
		ft_putchar_fd(c, myfd);
		c++;
	}
	ft_putchar_fd('\n', myfd);
}

void		test_ft_putstr_fd(void)
{
	int		myfd;
	char	str1[] = "This is a string\n";

	myfd = open("fd_tests", O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_putstr_fd(str1, myfd);
}

void		test_ft_putendl_fd(void)
{
	int		myfd;
	char	str1[] = "This is a new string which doesn't need to have \\n";

	myfd = open("fd_tests", O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_putendl_fd(str1, myfd);
}

void		test_ft_putnbr_fd(void)
{
	int		myfd;
	int		i;
	int		j;

	i = 1238047;
	j = 10067393;
	myfd = open("fd_tests", O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_putendl_fd("Testing ft_putnbr\n", myfd);
	ft_putnbr_fd(i, myfd);
	ft_putchar_fd('\n', myfd);
	ft_putnbr_fd(j, myfd);
	ft_putchar_fd('\n', myfd);
}

void		print_lst(t_list **alst, int n)
{
	t_list		*current;

	if (*alst == NULL)
	{
		printf("No list present, are you sure it wasn't freed?\n");
		return ;
	}
	current = *alst;
	printf("Size of list: %d\n", ft_lstsize(current));
	if (n == 1)
		while (current != NULL)
		{
			printf("Value of list member: %s\n", (char *)current->content);
			current = current->next;
		}
	else if (n == 2)
		while (current != NULL)
		{
			printf("Value of list member: %d\n", *(int *)current->content);
			current = current->next;
		}
}

void		test_lstnew(void)
{
	t_list		*HEAD;
	int			x;

	x = 51;
	HEAD = ft_lstnew(&x);
	printf("get the value: %d\n", *(int *)HEAD->content);
	free(HEAD);
}

void		delete(void *content)
{
	free(content);
}

void		test_lstadd_front(void)
{
	t_list		*HEAD;
	t_list		*newelem;
	char		*x;
	char		*y;
	char		*z;

	x = ft_strdup("a string");
	y = ft_strdup("another string");
	z = ft_strdup("the final string");
	newelem = ft_lstnew(y);
	HEAD = ft_lstnew(x);
	ft_lstadd_front(&HEAD, newelem);
	newelem = ft_lstnew(z);
	ft_lstadd_front(&HEAD, newelem);
	print_lst(&HEAD, 1);
	ft_lstclear(&HEAD, delete);
	print_lst(&HEAD, 1);
}

void		test_lstsize(void)
{
	t_list		*HEAD;
	t_list		*newelem;
	char		*x;
	char		*y;

	x = ft_strdup("a string");
	y = ft_strdup("another string");
	newelem = ft_lstnew(y);
	HEAD = ft_lstnew(x);
	ft_lstadd_front(&HEAD, newelem);
	ft_lstclear(&HEAD, delete);
}

void		print_lstelem(t_list *elem)
{
	printf("Value of last element: %d\n", *(int *)(elem->content));
}

void		test_lstlast(void)
{
	t_list		*HEAD;
	t_list		*newelem;
	int			*x;
	int			*y;
	int			*z;

	x = (int *)malloc(sizeof(int));
	y = (int *)malloc(sizeof(int));
	z = (int *)malloc(sizeof(int));
	if (!x || !y || !z)
		return ;
	*x = 69;
	*y = 420;
	newelem = ft_lstnew(y);
	HEAD = ft_lstnew(x);
	ft_lstadd_front(&HEAD, newelem);

	*z = -2000;
	newelem = ft_lstnew(z);
	ft_lstadd_front(&HEAD, newelem);

	print_lst(&HEAD, 2);
	print_lstelem(ft_lstlast(HEAD));
	ft_lstclear(&HEAD, delete);
}

void		test_lstadd_back(void)
{
	t_list		*HEAD;
	t_list		*newelem;
	int			*x;
	int			*y;
	int			*z;

	x = (int *)malloc(sizeof(int));
	y = (int *)malloc(sizeof(int));
	z = (int *)malloc(sizeof(int));
	*x = 69;
	*y = 420;
	if (!x || !y || !z)
		return ;
	newelem = ft_lstnew(y);
	HEAD = ft_lstnew(x);
	ft_lstadd_front(&HEAD, newelem);

	*z = -2000;
	newelem = ft_lstnew(z);
	ft_lstadd_back(&HEAD, newelem);

	print_lst(&HEAD, 2);
	ft_lstclear(&HEAD, delete);
}

void		*funnyfez(void *x)
{
	int		i;
	void	*str1;
	char	*tempx;
	char	*tempstr;
	size_t	len;

	len = ft_strlen(x);
	str1 = malloc((len + 1) * sizeof(char));
	tempx = x;
	tempstr = str1;
	i = 0;
	while (tempx[i] != '\0')
	{
		tempstr[i] = tempx[i] + 1;
		i++;
	}
	tempstr[i] = '\0';
	return (str1);
}

void		*fornumbers(void *x)
{
	void		*y;

	y = malloc(sizeof(int));
	*(int *)y = *(int *)x + 100;
	return (y);
}

void		*lstmap_f(void *content)
{
	(void)content;
	return ("OK ! but now the string is longer than allocated memory");
}

void		test_lstmap(void)
{

	t_list		*l;
	t_list		*new;


	l = ft_lstnew(ft_strdup(" 1 2 3 "));
	l->next = ft_lstnew(ft_strdup("ss"));
	l->next->next = ft_lstnew(ft_strdup("-_-"));

	print_lst(&l, 1);
	new = ft_lstmap(l, funnyfez, ((void *)0));
	print_lst(&new, 1);
	ft_lstclear(&l, delete);
	ft_lstclear(&new, delete);
}

void		test_lstmap2(void)
{
	t_list		*l;
	t_list		*new;
	int			*x;
	int			*y;
	int			*z;

	x = (int *)malloc(sizeof(int));
	y = (int *)malloc(sizeof(int));
	z = (int *)malloc(sizeof(int));
	*x = 69;
	*y = 420;
	*z = -2000;
	l = ft_lstnew(x);
	l->next = ft_lstnew(y);
	l->next->next = ft_lstnew(z);

	print_lst(&l, 2);
	new = ft_lstmap(l, fornumbers, delete);
	print_lst(&new, 2);
	ft_lstclear(&new, delete);
}

int			main(void)
{
	test_memset();
	test_memcpy();
	test_memccpy();
	test_memmove(); //Slight error may be due to valgrind's printf
	test_memcmp();
	test_memchr();
	test_strlcpy(); //Not in some libraries
	test_strlcat(); //Not in some libraries
	test_strchr();
	test_strrchr();
	test_strnstr(); //Not in some libraries
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_toupper();
	test_tolower();
	test_isprint();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstmap();
	test_lstmap2();

	return (0);
}
