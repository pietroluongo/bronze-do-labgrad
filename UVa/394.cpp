//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=330
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct array {
    char name[10];
    int base_address;
    int element_size;
    int dimensions;
    int* lower_bounds;
    int* upper_bounds;
};

int main() {
    int array_count, array_references;
    scanf("%d %d\n", &array_count, &array_references);
    array arrays[array_count];

    // Arrays setup
    for(int i = 0; i < array_count; i++) {
        scanf("%s", arrays[i].name);
        scanf("%d %d %d", &arrays[i].base_address, &arrays[i].element_size, &arrays[i].dimensions);
        arrays[i].lower_bounds = (int*) malloc(arrays[i].dimensions * sizeof(int));
        arrays[i].upper_bounds = (int*) malloc(arrays[i].dimensions * sizeof(int));
        for(int j = 0; j < arrays[i].dimensions; j++) {
            scanf("%d %d", &arrays[i].lower_bounds[j], &arrays[i].upper_bounds[j]);
        }
    }

    // Array references setup
    for(int i = 0; i < array_references; i++)
    {
        char array_name[10];
        scanf("%s", array_name);
        array* tgt_array = nullptr;
        // Find array idx
        for(int j = 0; j < array_count; j++) {
            int tgt_array_idx = -1;
            if (strcmp(arrays[j].name, array_name) == 0) {
                tgt_array_idx = j;
                tgt_array = &arrays[tgt_array_idx];
                break;
            }
        }
        if(tgt_array == nullptr) {
            printf("ERRO; Nome de array invalido!!!");
            exit(1);
        }
        // Vector data reading
        int vector_data[tgt_array->dimensions];
        for(int j = 0; j < tgt_array->dimensions; j++)
        {
            scanf("%d ", &vector_data[j]);
        }
        int address = 0;
        // Inverse calculation
        int last_size = 0;
        int stored_c_sizes[tgt_array->dimensions];
        for(int j = tgt_array->dimensions; j >= 0; j--)
        {
            // Last element (i = dimension count)
            if(j == tgt_array->dimensions) {
                address += tgt_array->element_size * vector_data[j-1];
                stored_c_sizes[j-1] = tgt_array->element_size;
                continue;
            }
            // Element i, where i != 0
            else if(j != 0) {
                int current_dim_size = stored_c_sizes[j] * (tgt_array->upper_bounds[j] - tgt_array->lower_bounds[j] + 1);
                address += current_dim_size * vector_data[j-1];
                stored_c_sizes[j-1] = current_dim_size;
            }
        }
        // C0
        int dim_size = tgt_array->base_address;
        int aggregated_dimensions_sizes = 0;
        for(int k = 0; k < tgt_array->dimensions; k++) {
            int m = tgt_array->lower_bounds[k];
            aggregated_dimensions_sizes += tgt_array->lower_bounds[k] * stored_c_sizes[k];
        }
        dim_size -= aggregated_dimensions_sizes;
        address += dim_size;
        printf("%s[", tgt_array->name);
        for(int j = 0; j < tgt_array->dimensions; j++) {
            printf("%d", vector_data[j]);
            if(j != tgt_array->dimensions-1) {
                printf(", ");
            }
        }
        printf("] = %d\n", address);
    }
    return 0;
}

