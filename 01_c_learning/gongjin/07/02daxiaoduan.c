/*
大小段存储
*/

union ufoo{
	unsigned char c; 
	unsigned int  i;
};

int main(int argc, char const *argv[])
{
	union ufoo foo;
	foo.i = 0x11223344;

	if(foo.c == 0x44) {
		printf("小端存储\n");
	}else if(foo.c == 0x11){
		printf("大端\n");
	}

	return 0;
}