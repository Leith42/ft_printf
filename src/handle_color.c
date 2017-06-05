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

int		handle_color(t_format *format)
{
	const char *s;

	s = format->string + format->pos;
	if (format->got_color == false)
	{
		if (s[0] == '{' && s[1] == 'R' && s[2] == 'E' && s[3] == 'D' && s[4] == '}')
		{
			ft_putstr(COLOR_RED);
			format->pos += 5;
			format->got_color = 1;
		}
		else if (s[0] == '{' && s[1] == 'G' && s[2] == 'R' &&
				 s[3] == 'E' && s[4] == 'E' && s[5] == 'N' && s[6] == '}')
		{
			ft_putstr(COLOR_GREEN);
			format->pos += 7;
			format->got_color = true;
		}
		else if (s[0] == '{' && s[1] == 'B' && s[2] == 'L' && s[3] == 'U' && s[4] == 'E' && s[5] == '}')
		{
			ft_putstr(COLOR_BLUE);
			format->pos += 6;
			format->got_color = true;
		}
		else
			return (false);
		return (true);
	}
	else
		return (handle_eoc(format, s));
}