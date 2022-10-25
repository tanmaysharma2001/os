#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void *newRealloc(void *p1, int newSize)
{
	size_t size = malloc_usable_size(p1);

	void *resultPtr;

	if (newSize == 0)
	{
		free(p1);
		return NULL;
	}

	if (p1 == NULL)
	{
		return malloc(newSize);
	}

	if (newSize > size)
	{
		resultPtr = malloc(newSize);

		for (int i = 0; i < size; i++)
		{
			*((char *)resultPtr + i) = *((char *)p1 + i);
		}
	}
	else
	{
		resultPtr = malloc(size);

		for (int i = 0; i < newSize; i++)
		{
			*((char *)resultPtr + i) = *((char *)p1 + i);
		}
	}

	free(p1);

	return resultPtr;
}

int main()
{
	int n1 = 0;
	scanf("%d", n1);

	int *arr1 = (int *)malloc(n1 * sizeof(int));

	int n2 = 0;
	scanf("%d", n2);
}
