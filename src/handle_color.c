#include "ft_printf.h"

static int	handle_eoc(t_format *format, const char *s)
{
	if (s[0] == '{' && s[1] == 'E' && s[2] == 'O' && s[3] == 'C' && s[4] == '}')
	{
		ft_putstr(COLOR_RESET);
		format->pos += 5;
		format->got_color = false;
		return (true);

	}
	return (false);
}

static int	red_checker(t_format *format, const char *s)
{
	if (s[0] == '{' && s[1] == 'R' && s[2] == 'E' && s[3] == 'D' && s[4] == '}')
	{
		ft_putstr(COLOR_RED);
		format->pos += 5;
		format->got_color = 1;
		return (true);
	}
	return (false);
}

static int	green_checker(t_format *format, const char *s)
{
	if (s[0] == '{' && s[1] == 'G' && s[2] == 'R' &&
			 s[3] == 'E' && s[4] == 'E' && s[5] == 'N' && s[6] == '}')
	{
		ft_putstr(COLOR_GREEN);
		format->pos += 7;
		format->got_color = true;
		return (true);
	}
	return (false);
}

static int	blue_checker(t_format *format, const char *s)
{
	if (s[0] == '{' && s[1] == 'B' && s[2] == 'L' && s[3] == 'U' && s[4] == 'E' && s[5] == '}')
	{
		ft_putstr(COLOR_BLUE);
		format->pos += 6;
		format->got_color = true;
		return (true);
	}
	return (false);
}

int		handle_color(t_format *format)
{
	const char *s;

	s = format->string + format->pos;
	if (format->got_color == false)
	{
		if (red_checker(format, s) == true)
			return (true);
		if (green_checker(format, s) == true)
			return (true);
		if (blue_checker(format, s) == true)
			return (true);
		return (false);
	}
	else
		return (handle_eoc(format, s));
}