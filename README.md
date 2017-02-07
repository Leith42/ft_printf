# ft_printf @ 42

As printf in C:  
\#include \<ft_printf.h\>  
int ft_printf(const char *format, ...);


<h2>Format:</h2>
%[flags][width][.precision][length]specifier


<h2>Specifier:</h2>
<b>sSpdDioOuUxXcC</b>

<h2>Flags:</h2>
<b>\#0-+ and space</b>
<table>
  <tr>
    <td>-</td>
    <td>Left-justify within the given field width; Right justification is the default (see width sub-specifier).</td>
  </tr>
  <tr>
    <td>+</td>
    <td>Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.</td>
  </tr>
  <tr>
    <td>(space)</td>
    <td>If no sign is going to be written, a blank space is inserted before the value.</td>
  </tr>
  <tr>
    <td>#</td>
    <td>Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).</td>
  </tr>
</table>

<h2>Width:</h2>
Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

<h2>Precision:</h2>
For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).
For g and G specifiers: This is the maximum number of significant digits to be printed.
For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
If the period is specified without an explicit value for precision, 0 is assumed.

<h2>Length sub-specifier:</h2>
<b>hh h l ll j z</b>
<table>
  <tr>
    <td><b>length</b></td>
    <td><b>d i</b></td>
    <td><b>u o x X</b></td>
    <td><b>f F e E g G a A</b></td>
    <td><b>c</b></td>
    <td><b>s</b></td>
    <td><b>p</b></td>
  </tr>
  <tr>
    <td>hh</td>
    <td>int</td>
    <td>unsigned int</td>
    <td>double</td>
    <td>int</td>
    <td>char*</td>
    <td>void*</td>
  <tr>
    <td>h</td>
    <td>short int</td>
    <td>unsigned short int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>l</td>
    <td>long int</td>
    <td>unsigned long int</td>
    <td></td>
    <td>wint_t</td>
    <td>wchar_t*</td>
    <td></td>
  </tr>
  <tr>
    <td>ll</td>
    <td>long long int</td>
    <td>unsigned long long int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
    <tr>
    <td>j</td>
    <td>intmax_t</td>
    <td>uintmax_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  </tr>
    <tr>
    <td>z</td>
    <td>size_t</td>
    <td>size_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  
</table>
