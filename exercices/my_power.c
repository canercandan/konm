int	my_power(int d, int pwr)
{
  int	i;
  int	res;

  if (!pwr)
    return (1);
  res = 1;
  i = 0;
  while (i < pwr)
    {
      res *= d;
      i++;
    }
  return (res);
}
