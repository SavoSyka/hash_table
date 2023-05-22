#pragma once

struct hash_table_t{
    size_t size;
    size_t dataSize;
    vector_t *buckets;
    unsigned int (*hash)( void *key );
    int (*comparator)( void *first , void *second); 
};

void HashTableInit( hash_table_t **hash_table, size_t dataSize, unsigned int (*hash)( void *key ), int (*comparator)( void *first , void *second) );
void HashTableAdd( hash_table_t **hash_table, void *data );
//void HashTableDelete( hash_table_t **hash_table, void *data );
bool HashTableFind( hash_table_t **hash_table, void *data );
void HashTableRemove(hash_table_t **hash_table, void *data);
void HashTableFree(hash_table_t **hash_table);
void HashTableRehash(hash_table_t **hash_table);