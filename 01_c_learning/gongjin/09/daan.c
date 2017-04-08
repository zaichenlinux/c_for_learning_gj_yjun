#include <stdio.h>
 #include <stdlib.h>
//0x12345678  
#define CHANGE_DATA(data)  \
	( ((data & 0xff) << 24)    \
 |	((data & 0xff00) <<8) \
 |  ((data & 0xff0000) >> 8)   \
 | ((data & 0xff000000) >> 24) )

//p != NULL
#define  STR(expr)  #expr
#define my_assert(expr)  \
	if(!(expr)) {    \
            printf("%s, %s, %d, %s "STR(expr)" failed\n", argv[0], __FILE__, __LINE__, __func__);  \
            abort();    \
	}


  int main(int argc, char  *argv[])
  {
  	int a = 0x12345678;
       int b = CHANGE_DATA(a);
       printf("b = %#x\n", b);

       int *p = NULL;
       my_assert(p != NULL);
  	return 0;
  }
