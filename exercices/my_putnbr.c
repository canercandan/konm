void	my_putnbr(int d)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while ((d / (my_power(10, i))) % 10)
    i++;
  i--;
  while (i >= 0 && (res = (d / (my_power(10, i))) % 10))
    {
      my_putchar(res + '0');
      i--;
    }
}
