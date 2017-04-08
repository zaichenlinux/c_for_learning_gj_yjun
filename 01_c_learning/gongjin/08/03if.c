/*
条件编译  选择性
#if  0/1 
表达式 根据这个表达式的真假来判断是否需要编译进去
。。。。。。。。。。。。。
#elif  表达式  
#else
#endif

#ifdef  宏
如果该宏被定义那么就编译
如果宏未定义，跳过去
#define  R
对于宏来说  只要有#define 宏名，哪怕后面什么都没有，预处理就会判断该宏是被定义了

#ifndef
如果该宏未被定义，就编译
如果宏定以了，就跳过去
*/
//#define   R    1
#define   L    0

int main(int argc, char const *argv[])
{
	//#if 1
	//#endif

	//#if   R
	#ifdef  R
	printf("园的面积 = %f\n",3.14 * R * R );
	#elif   L
	printf("正方形的面积 = %d\n", L*L);
	#else
	printf("无法计算面积 \n");
	#endif

	return 0;
}


