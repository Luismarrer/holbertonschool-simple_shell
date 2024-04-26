#include "simple_shell.h"

/**
 * _realloc - Reallocate memory block
 *
 * @ptr: Pointer to the previously allocated memory
 *
 * @old_size: Size of the previously allocated memory
 *
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the newly allocated memory, or NULL on failure
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr = malloc(new_size);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size <= old_size)
	{
		return (ptr);
	}

	memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * @name: The name of the variable to find.
 *
 * @env: The environment array.
 *
 * Return: Pointer to the value of the environment variable,
 * or NULL if the variable cannot be found.
 */

char *_getenv(const char *name, char **env)
{
	size_t name_len = strlen(name);
	int i;

	if (!name || !env)
	{
		return (NULL);
	}

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
		{
			return (env[i] + name_len + 1);
		}
	}
	return (NULL);
}
