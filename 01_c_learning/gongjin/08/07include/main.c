#include "f1.h"
#include "f2.h"

/*
#ifndef _LINUX_ERR_H
#define _LINUX_ERR_H

#endif
形如上面三个句，为了防止头文件被重复包含 


#ifndef  __文件名_H
#define __文件名_H
xxxxxxxx
#endif

#pargma once和上面的三句话一样
*/



int main(int argc, char const *argv[])
{
	f1();
	f2();
	return 0;
}