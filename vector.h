#pragma once

struct vector_t{
    size_t size;
    size_t capacity;
    size_t dataSize;
    void *data;
};

void VectorInit( vector_t **vector, size_t dataSize );
void VectorPushBack( vector_t **vector, void *data );
void VectorPopBack(vector_t** vector);
void VectorGetByIndex( vector_t ** vector, size_t index, void **data );
void VectorRemoveByIndex(vector_t** vector, size_t index);
void VectorFree( vector_t **vector );
void VectorResize(vector_t **vector, size_t newCapacity);