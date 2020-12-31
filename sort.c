#include <stdio.h>  
#define LEN 50


void printArr( int*arr, int len){
    for (int i=0; i<len-1; ++i){
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[len-1]);

}

void shift_element(int * arr, int i){
    for (; i>0; --i){
        *(arr+i) = *(arr+i-1);
    }
}

void insertion_sort(int *arr, int len){
    for (int i=1; i<len; ++i){
        int key = *(arr+i);
        int j = i-1;
        int move=0;
        while( j>=0 && *(arr+j)>key){
            move++;
            --j;
        }
        shift_element((arr+i-move), move);
        *(arr+j+1) = key;
    }

}


int main(){
    int num;
    int arr[LEN];
    scanf("%d", &num);
    *(arr) = num;
    int j=1;
    for (int i=1; i<LEN; ++i, ++j){
        scanf("%d", &num);
        *(arr+j) = num;
    }
    insertion_sort(arr, LEN);
    printArr(arr,LEN);

    return 0;
}
