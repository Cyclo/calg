#include <stdio.h>
#include <stdlib.h>


/**
 * Simple hash table implementation for strings WITHOUT collision
 * support, so is pretty useless at the moment.
 *
 * Just an experiment will improve over time.
 *
 * Eddie - eblundell@gmail.com Feb 2013
 */


struct ht {

  int size;
  char **data;

};


/**
 * Initialize a hash table to the given size
 * If no size given, use default of 100
 *
 * @param size of table
 * @return structure ht
 */

struct ht*
ht_init(int size) 
{
  if(size <= 0) {
    size = 100;
  }

  struct ht *tmp;

  tmp = malloc(sizeof(struct ht));
  tmp->size = size;
  tmp->data = malloc(sizeof(char*) * tmp->size);

  if(!tmp->data) {
    fprintf(stderr,"out of memory\n");
    exit(1);
  }

  return tmp;
}

/**
 * Frees the hashtable structure
 * 
 * @param table to free
 * @todo do better testing before freeing
 */
void 
ht_free(struct ht *table) 
{
  if(table) {
    free(table->data);
    free(table);
  }
}

/**
 * Calculates hash for the given string
 *
 * @param hash table
 * @param string to calculate hash for
 *
 * @return hash index or -1 on failure
 */

int 
ht_hash(struct ht *table, char *string)
{
  int hash = 0;

  if(!string) return -1;

  while(*string++) {
    hash += *string;
  }

  return hash % table->size;
}

/**
 * Inserts a string value into the hash table
 * and returns the correct index
 *
 * @param hash table
 * @param key
 * @param value to insert
 * @todo better error handling
 *
 * @return index in hash table
 */

int 
ht_set(struct ht *table, char *key, char *value)
{

  if(!key) return -1;

  int hash = ht_hash(table, key);

  table->data[hash] = value;

  return hash;
}

/**
 * Returns the value in the hash table at 
 * the given key
 *
 * @param table
 * @param key for lookup
 *
 * @return string at index
 */

char*
ht_get(struct ht *table, char *key)
{
  if(!key) return 0;

  int hash = ht_hash(table,key);

  return table->data[hash];
}


int
main()
{

  struct ht *table;
  table = ht_init(100);

  ht_set(table,"myKey","Hello World!");
  ht_set(table,"myKey2","Hello World 2!");

  char *myValue = ht_get(table,"myKey");
  printf("Value for key [myKey]=[%s]\n", myValue);

  myValue = ht_get(table,"<myKey2></myKey2>");
  printf("Value for key [myKey2]=[%s]\n", myValue);

  ht_free(table);

  return 0;
}