#include "ref_pointers.h"

//

void ref_pointers(int & int1, int * int2)
{
	int1 = 100;
	*int2 = 66;
}
