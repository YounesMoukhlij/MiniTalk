
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(long n)

{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
void	print(unsigned char cote)
{
	int arr[7] ;
	int i = 7 ;
	
	while (i >= 0)
	{
		arr[i] = (cote >> i) | 1;
		i--; 
	}
	
	i = 7 ;
	while (i >= 0 )
	{
		ft_putnbr(arr[i]);
		i-- ;
	}
}
int main()
{
	unsigned char a = 'a' ;
	print(a);
}



