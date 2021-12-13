static void merge(T* left, T* middle, T* right){
    /*TODO*/
    int sum1 = middle - left + 1 ;
    int sum2 = right - middle;
    int* result = new int [sum1+sum2];
    int i = 0;
    int j = 0;
    int k = 0;
    while ( i < sum1 && j < sum2){
        if (left[i] <= middle[j+1] ){
            result[k] = left[i];
            i++;
            k++;
            continue;
        }
        else{
            result[k] = middle[j+1];
            j++;
            k++;
            continue;
        }
    }
    while ( i < sum1){
        result[k] = left[i];
        i++;
        k++;
        continue;
    }
    while ( j < sum2){
        result[k] = middle[j+1];
        j++;
        k++;
        continue;
    }
    for ( int d = 0 ; d < sum1 + sum2 ; d++){
        left[d]=result[d];
    }
    delete [] result;

}
static void mergeSort(T* start, T* end){
    /*TODO*/
    int size = end - start + 1;
    if ( size <= 1 ) return;
    int middle = (size-1)/2;
    mergeSort(start,&start[middle]);
    mergeSort(&start[middle + 1],end);
    merge(start,&start[middle],end);
    Sorting<T>::printArray(start, end);
    
}