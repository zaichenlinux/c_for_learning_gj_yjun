#include <stdio.h>
#include "1.h"

void two()
{
	one();
	printf("%s\n", __func__);
}
