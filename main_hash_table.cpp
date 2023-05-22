#include <iostream>
#include <cstring>
#include <chrono>
#include <fstream>
#include "vector.h"
#include "hash_table.h"

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

unsigned int employee_hash(void *key) {

    Employee *e = reinterpret_cast<Employee*>(key);
    unsigned int hash = 5381;
    unsigned int id_hash = e->id;
    float salary_hash = e->salary;
    // хеш для id
    hash = ((hash << 5) + hash) + id_hash;

    // хеш для имени
    for (int i = 0; e->name[i] != '\0'; ++i) {
        hash = ((hash << 5) + hash) + e->name[i];
    }

    // хеш для salary
    unsigned char *salary_bytes = (unsigned char *)&salary_hash;
    for (int i = 0; i < sizeof(float); ++i) {
        hash = ((hash << 5) + hash) + salary_bytes[i];
    }

    return hash;
}

int comparator( void *first, void *second ){

    Employee *e0 = static_cast<Employee*>(first);
    Employee *e1 = static_cast<Employee*>(second);

    if( e0->id == e1->id && e0->salary == e1->salary && strncmp( e0->name, e1->name, 50 ) == 0 ){
        return 0;
    }

    return 1;
}

int main(){

    hash_table_t *hash_table;

    HashTableInit( &hash_table, sizeof(Employee), employee_hash, comparator );


    /*Employee e0 { 1, "Andrew", 99999.99 };
    HashTableAdd( &hash_table, &e0 );

    Employee e1 { 2, "Alex", 999969.99 };
    HashTableAdd( &hash_table, &e1 );

    Employee e2 { 3, "Nikolay", 795999.99 };
    HashTableAdd( &hash_table, &e2 );

    Employee e3 { 4, "Egor", 5000.0 };
    HashTableAdd( &hash_table, &e3 );

    Employee e4 { 5, "Artem", 6250.0 };
    HashTableAdd( &hash_table, &e4 );

    Employee find { 3, "Nikolay", 795999.99 };
    HashTableAdd( &hash_table, &find );

    //std::cout << HashTableFind( &hash_table, &find ) << std::endl;

    HashTableRemove( &hash_table, &e2 );
    //HashTableRemove( &hash_table, &find );

    std::cout << HashTableFind( &hash_table, &find ) << std::endl;
    //HashTableFree(&hash_table);
    std::cout << HashTableFind( &hash_table, &e1 )<<HashTableFind( &hash_table, &e2 )<<HashTableFind( &hash_table, &e3 )<<HashTableFind( &hash_table, &e4 )<<HashTableFind( &hash_table, &e0)<<  std::endl;
    std::cout<<'\n';
     for( int i = 0 ; i < hash_table->buckets->size ; ++i ){
         vector_t *currentBucket;
         VectorGetByIndex( &hash_table->buckets, i, reinterpret_cast<void**>(&currentBucket) );
         std::cout << currentBucket->size << std::endl;
     }
    HashTableRehash(&hash_table);
     std::cout<<'\n';
     for( int i = 0 ; i < hash_table->buckets->size ; ++i ){
         vector_t *currentBucket;
         VectorGetByIndex( &hash_table->buckets, i, reinterpret_cast<void**>(&currentBucket) );
         std::cout << currentBucket->size << std::endl;
     }

    //std::cout << HashTableFind( &hash_table, &find ) << std::endl;
   *//* for( int i = 0 ; i < hash_table->buckets->size ; ++i ){
        vector_t *currentBucket;
        VectorGetByIndex( &hash_table->buckets, i, reinterpret_cast<void**>(&currentBucket) );
        std::cout << currentBucket->size << std::endl;
    }*//*

}
*/

    std::ofstream fout("Remove.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    /*int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,*//*115000,140000,165000,
                   195000,225000,250000,295000,335000,375000,420000,465000,499999, 510000*//*

    };*/
    for ( int i = 1; i<100000; i=i+100 ){
        fout << i << " ,";

    }
    fout << "]\n";
    /*int amount = sizeof(value)/sizeof(int);
    int Size[amount];*/
    fout << "time = [";
    Employee find { -5, "unknown_name" , 999999 };
    for ( int i = 1; i<100000; i=i+100 ){

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j<100;++j) {
            Employee e { i, "name" , static_cast<float>(i-j) };
            HashTableAdd( &hash_table, &e );
        }
;
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        fout << time_span.count() << " ,";

        std::cout<<i<<std::endl;
        }
    /*for( int i = 0 ; i < hash_table->buckets->size ; ++i ){
        vector_t *currentBucket;
        VectorGetByIndex( &hash_table->buckets, i, reinterpret_cast<void**>(&currentBucket) );
        std::cout << currentBucket->size << std::endl;
    }*/
    std::cout<<hash_table->size;

    fout << "]\n";
    fout << "plt.grid()";
    fout << "\n";
    fout << "plt.plot(am_of_ells, time, '.')";
    fout << "\n";
    fout << "plt.savefig('Remove')";
    fout << "\n";
    fout << "plt.show()";
    return 0;
    }