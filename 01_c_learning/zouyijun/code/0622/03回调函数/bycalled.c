
void show(void (*todo)(void *, void *), void *arg1, void *arg2)
{
	todo(arg1, arg2);
}
