#include <stdio.h>

int main()
{
	int m1 = 1, m2 = 100, age = 1;
   int arr[10] = {0}; 
    for (age = m1; age <= m2; age++) {
		if((age*age > 99) && (age*age < 1000) && (age*age*age > 999) && (age*age*age < 10000) && (age*age*age*age > 99999) && (age*age*age*age < 1000000)) {		
		
			int power3 = age*age*age; //年龄的三次方
			int power4 = power3*age; //年龄的四次方

			for (int i = 0; i < 4; i++) {
				arr[i] = power3 % 10; 
				power3 /= 10; 
			}

			for (int i = 4; i < 10; i++) {
				arr[i] = power4 % 10; 
				power4 /= 10; 
			}

    
			int brr[10] = {0}; //brr数组用于存放arr数组元素出现的次数
			for (int i = 0; i < 10; i++) {
				brr[arr[i]] += 1;
			}
			int result = 1; //判断brr数组中是否所有的元素值都是1，相乘起来结果必然是1，以得到最后结果
			for (int i = 0; i < 10; i++) {
            //printf("%d ", brr[i]);
				result *= brr[i];
			}
			//printf("\n");

			if (result == 1) {
				printf("该学生的年龄是%d岁.\n", age);
			}
		}
	}
}

