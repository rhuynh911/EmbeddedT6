#include "../Header/compare.h"
#include <stdint.h>

Compare isEqual(const char arr1[], const char arr2[]){
    uint8_t i = 0;
    while(arr1[i] == arr2[i]){
        if(arr1[i] == '\0'){ 
            return EQUAL;
        }
        i++;
    }
    
    if(arr1[i] - arr2[i] < 0){
        return SMALLER;
    }

    if(arr1[i] - arr2[i] > 0){
        return BIGGER;
    }

}
