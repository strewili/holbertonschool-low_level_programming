#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_node - creates a new hash node
 * @key: key
 * @value: value
 *
 * Return: pointer to new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);

		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - adds an element to hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */

int hash_table_set(hash_table_t *ht,
		   const char *key,
		   const char *value)
{
	unsigned long int index;
	hash_node_t *tmp, *new_node;
	char *dup_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			dup_value = strdup(value);
			if (dup_value == NULL)
				return (0);

			free(tmp->value);
			tmp->value = dup_value;

			return (1);
		}

		tmp = tmp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
