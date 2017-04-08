#include <stdio.h>

int main()
{
	struct stu {
		char *name;
		int age;
	};

 	struct stu students[3] = {
		{.age = 10, .name = "tim"}, 
		[2] = {"jim"},
	};

	struct stu *pstudents[3] = {students, students+1, students+2};

	printf("name = %s\n", (students + 2)->name);
	printf("name = %s\n", (*(students + 2)).name);
	
	printf("name = %s\n", (*(pstudents + 2))->name);

	return 0;
}
