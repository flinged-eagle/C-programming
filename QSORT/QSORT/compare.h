#ifndef _COMPARE_H__
#define _CPMPARE_H__

int intGreat(void *x, void *y)
{
	return *(int *)x - *(int *)y;
}

int intLess(void *x, void *y)
{
	return intGreat(y, x);
}

int charGreat(void *x, void *y)
{
	return *(char *)x - *(char *)y;
}

int charLess(void *x, void *y)
{
	return charGreat(y, x);
}


#endif