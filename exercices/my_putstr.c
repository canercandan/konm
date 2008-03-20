void	my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}
