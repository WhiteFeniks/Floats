#include "floats.h"

int main()
{
	f_floats *new;

	new = (f_floats*)malloc(sizeof(f_floats));
	write_number(1000014583.0000001225331212214755542, &new);
	printf("\n%d", new->len_stroka);
	printf("\n%d", printf("\n%.23f", 1000014583.0000001225331212214755542) - 1);
}