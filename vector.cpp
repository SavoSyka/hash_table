#include <iostream>
#include <cstring>

#include "vector.h"

#define VECTOR_MIN_CAPACITY 2


void VectorInit( vector_t **vector, size_t dataSize ){
    (*vector) = static_cast<vector_t*>( malloc( sizeof(vector_t) ) );
    (*vector)->dataSize = dataSize;
    (*vector)->capacity = VECTOR_MIN_CAPACITY;
    (*vector)->size = 0;
    (*vector)->data = malloc( VECTOR_MIN_CAPACITY * (*vector)->dataSize );
}

void VectorPushBack( vector_t **vector, void *data ){

    if( (*vector)->size == (*vector)->capacity ){
        (*vector)->capacity *= 2;
        void *newData = realloc( (*vector)->data, (*vector)->capacity * (*vector)->dataSize );
        if( newData != NULL ){
            (*vector)->data = newData;
        }
    }

    // #include <cstring>
    memcpy( reinterpret_cast<void*>(static_cast<char*>((*vector)->data) + (*vector)->size * (*vector)->dataSize ), data, (*vector)->dataSize );
    ++(*vector)->size;
}

void VectorPopBack(vector_t** vector) {
    if ((*vector)->size > 0) {
        --(*vector)->size;
    }
}

void VectorGetByIndex( vector_t ** vector, size_t index, void **data ){
    *data = reinterpret_cast<void*>( static_cast<char*>((*vector)->data) + index * (*vector)->dataSize );
}

void VectorRemoveByIndex(vector_t** vector, size_t index) {
    if (index >= (*vector)->size) {
        return;
    }

    for (size_t i = index; i < (*vector)->size - 1; ++i) {
        void* currentData;
        void* nextData;
        VectorGetByIndex(vector, i, &currentData);
        VectorGetByIndex(vector, i + 1, &nextData);
        memcpy(currentData, nextData, (*vector)->dataSize);
    }

    --(*vector)->size;
}

void VectorFree( vector_t **vector ){
    free( (*vector)->data );
    free( (*vector) );
    *vector = NULL;
}

void VectorResize(vector_t **vector, size_t newCapacity) {
    if (newCapacity < (*vector)->size) {
        // Если новая емкость меньше текущего размера вектора,
        // обрезаем вектор до новой емкости
        (*vector)->size = newCapacity;
    }

    // Изменяем емкость вектора
    (*vector)->capacity = newCapacity;
    void *newData = realloc((*vector)->data, newCapacity * (*vector)->dataSize);
    if (newData != NULL) {
        (*vector)->data = newData;
    }
}

