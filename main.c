#include "includes/ft_printf.h"
#include <locale.h>

// int main()
// {
// 	//setlocale(LC_ALL, "");
// 	printf("%d\n", ft_printf("khigh;kl,|%.0lc|", 1024));
// 	printf("%d\n", printf("hgjkml,;.|%.0lc|", 1024));
// 	return (0);
// }


int main()
{
	setlocale(LC_ALL, "");

	int i;
	i = 5;

	printf("%d\n", ft_printf("simple string\n"));
	printf("%d\n", printf("simple string\n"));

	printf("\n");
	printf("%d\n", ft_printf("%s\n", "simple string"));
	printf("%d\n", printf("%s\n", "simple string"));

	printf("\n");
	printf("%d\n", ft_printf("d = %d\n", INT_MAX));
	printf("%d\n", printf("d = %d\n", INT_MAX));

	printf("\n");
	printf("%d\n", ft_printf("%% = %%\n"));
	printf("%d\n", printf("%% = %%\n"));

	printf("\n");
	printf("%d\n", ft_printf("d1 = %d\nd2 = %d\nd3 = %d\n", 0, UINT_MAX, 1));
	printf("%d\n", printf("d1 = %d\nd2 = %d\nd3 = %d\n", 0, UINT_MAX, 1));

	printf("\n");
	printf("%d\n", ft_printf("S = %S\n", L"我是一只猫。"));
	printf("%d\n", printf("S = %S\n", L"我是一只猫。"));

	printf("\n");
	printf("%d\n", ft_printf("D = %D\n", LONG_MIN));
	printf("%d\n", printf("D = %D\n", LONG_MIN));

	printf("\n");
	printf("%d\n", ft_printf("i = %i\n", INT_MIN));
	printf("%d\n", printf("i = %i\n", INT_MIN));

	printf("\n");
	printf("%d\n", ft_printf("o = %o\n", 999988888));
	printf("%d\n", printf("o = %o\n", 999988888));

	printf("\n");
	printf("%d\n", ft_printf("O = %O\n", 666));
	printf("%d\n", printf("O = %O\n", 666));

	printf("\n");
	printf("%d\n", ft_printf("u = %u\n", 55555));
	printf("%d\n", printf("u = %u\n", 55555));

	printf("\n");
	printf("%d\n", ft_printf("U = %U\n", 100));
	printf("%d\n", printf("U = %U\n", 100));
	
	printf("\n");
	printf("%d\n", ft_printf("x = %x\n", UINT_MAX));
	printf("%d\n", printf("x = %x\n", UINT_MAX));

	printf("\n");
	printf("%d\n", ft_printf("X = %X\n", INT_MIN));
	printf("%d\n", printf("X = %X\n", INT_MIN));

	printf("\n");
	printf("%d\n", ft_printf("c = %c\n", 666));
	printf("%d\n", printf("c = %c\n", 666));

	printf("\n");
	printf("%d\n", ft_printf("C = %10{S\n", "red", 0));
	printf("%d\n", printf("C = %10S\n", 0));

	printf("\n");
	printf("%d\n", ft_printf("C = %C\n", 266));
	printf("%d\n", printf("C = %C\n", 266));

	printf("\n");
	printf("%d\n", ft_printf("s = %s\np = %p\nd = %d\n%%X = %X\nC = %C\n", "simple string", &i, 0, 0, L'😀'));
	printf("%d\n", printf("s = %s\np = %p\nd = %d\n%%X = %X\nC = %C\n", "simple string", &i, 0, 0, L'😀'));
	
	printf("\n");
	printf("%d\n", ft_printf("x with # = %#x\n", 42));
	printf("%d\n", printf("x with # = %#x\n", 42));

	printf("\n");
	printf("%d\n", ft_printf("d with 0 = %10d\n", 15));
	printf("%d\n", printf("d with 0 = %10d\n", 15));

	printf("\n");
	printf("%d\n", ft_printf("d with - = %-10.5d\n", 15));
	printf("%d\n", printf("d with - = %-10.5d\n", 15));

	printf("\n");
	printf("%d\n", ft_printf("d with + = %+10.5d\n", 15));
	printf("%d\n", printf("d with + = %+10.5d\n", 15));

	printf("\n");
	printf("%d\n", ft_printf("d with ' ' = % 010d\n", 777));
	printf("%d\n", printf("d with ' ' = % 010d\n", 777));

	printf("\n");
	printf("%d\n", ft_printf("%hd %hi %hu %ho %hx %hX %hc %hs %hO %hU %hD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%hd %hi %hu %ho %hx %hX %hc %hs %hO %hU %hD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));

	printf("\n");
	printf("%d\n", ft_printf("%hhd %hhi %hhu %hho %hhx %hhX %hhc %hhs %hhO %hhU %hhD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%hhd %hhi %hhu %hho %hhx %hhX %hhc %hhs %hhO %hhU %hhD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	
	printf("\n");
	printf("%d\n", ft_printf("%ld %li %lu %lo %lx %lX %lc %ls %lO %lU %lD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%ld %li %lu %lo %lx %lX %lc %ls %lO %lU %lD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	
	printf("\n");
	printf("%d\n", ft_printf("%lld %lli %llu %llo %llx %llX %llc %lls %llO %llU %llD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%lld %lli %llu %llo %llx %llX %llc %lls %llO %llU %llD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	
	printf("\n");
	printf("%d\n", ft_printf("%jd %ji %ju %jo %jx %jX %jc %js %jO %jU %jD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%jd %ji %ju %jo %jx %jX %jc %js %jO %jU %jD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	
	printf("\n");
	printf("%d\n", ft_printf("%zd %zi %zu %zo %zx %zX %zc %zs %zO %zU %zD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	printf("%d\n", printf("%zd %zi %zu %zo %zx %zX %zc %zs %zO %zU %zD\n", (long)INT_MAX + 1, 0, ULONG_MAX, ULONG_MAX, INT_MAX, 0, L'ح', L"لحم خنزير", USHRT_MAX, 0, USHRT_MAX));
	
	printf("\n");
	printf("%d\n", ft_printf("s = %s\np = %p\nd = %d\n%n%%%X = X\nC = %C\n", "simple string", &i, 0, &i, 0, L'😀'));
	printf("i = %d\n", i);
	printf("%d\n", printf("s = %s\np = %p\nd = %d\n%n%%%X = X\nC = %C\n", "simple string", &i, 0, &i, 0, L'😀'));
	printf("i = %d\n", i);

	printf("\n");
	printf("%d\n", ft_printf("d with - = %-*.*d\n", 10, 5, 15));
	printf("%d\n", printf("d with - = %-*.*d\n", 10, 5, 15));

	printf("\n");
	printf("%d\n", ft_printf("p = %{p\n", "yellow", &i));
 	printf("%d\n", printf("p = %p\n", &i));
	return (0);
}
