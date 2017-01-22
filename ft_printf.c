/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leith <leith@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:26:24 by leith             #+#    #+#             */
/*   Updated: 2017/01/22 17:44:15 by leith            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
//#include <stdarg.h>

/*int somme(int a,...)
{
  int som=a,i=0;
  va_list ap;
  va_start(ap,a);
  int c=1;
  while(c!=0)
  {
    c=va_arg(ap,int);
    som+=c;
    i++;
  }
  va_end(ap);
  return som;
}*/

int main()
{
	ft_printf("Je suis un %s et numero %d", "test", 515);
	return (0);
}

void flag_d(va_list *ap)
{
	ft_putnbr(va_arg(ap, int));
}

void flag_s(va_list *ap)
{
	ft_putstr(va_arg(ap, char *));
}

void exec_falg(char c, void *ap)
{
  int  i = 0;
  t_func g_tab[] =
  {
	  {&flag_s, 's'},
	  {&flag_d, 'd'},
	  {NULL, -1}
  };

  while (g_tab[i].key != -1)
  {
    if (g_tab[i].key == c)
    {
      g_tab[i].ptrfunc(ap);
    }
    i++;
  }
}

int ft_browse(const char *str, va_list ap)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1])
		{
			exec_falg(str[i + 1], ap);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	ret = 0;
	va_list ap;

	va_start(ap, str);
	ft_browse(str, ap);
	va_end(ap);
	return ret;
}
