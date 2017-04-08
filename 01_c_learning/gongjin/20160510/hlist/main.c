#include "hash.h"

int main(void)
{
	struct hash_list hlist;
	hash_init(&hlist);

#define CNT 10
	struct hash_node s[CNT] = {
		{"hello1", "HELLO"},
		{"hello1", "你好"}, 
		{"welcome", "欢迎"},
		{"world", "世界"},
		{"kernel", "核心"}, 
		{"hellowww", "你好"}, 
		{"word", "单词"}, 
		{"unix", "操作系统"}, 
		{"windows", "操作系统"}, 
		{"feebsd", "操作系统"},
	};

	int i = 0;
	for (; i < CNT; i++) {
		INIT_LIST_HEAD(&(s + i)->list);
		hlist.insert(&hlist, (s + i)->key, (s + i)->content);
	}
	hlist.print_list(&hlist);

	printf("查找：\n");
	struct hash_node *find = hlist.search(&hlist, "你好");

	if (find) {
		printf("找到了，content = %s\n", find->content);
	} else {
		printf("sorry, 没找到！\n");
	}

	printf("删除：\n");
	hlist.del(&hlist, "hello1");
	hlist.print_list(&hlist);

	hash_destroy(&hlist);

	return 0;
}
