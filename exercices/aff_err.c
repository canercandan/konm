void	aff_err(char *s)
{
  write(2, s, my_strlen(s));
}
