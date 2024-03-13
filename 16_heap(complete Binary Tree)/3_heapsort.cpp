#include<istream>
// using namespace std;
#include<algorithm>

void heapify(int arr[],int n,int indx){

    int leftIndx = 2*indx;
    int rightIndx = 2*indx +1;
    int largestIndx = indx;

    if(leftIndx <= n && arr[leftIndx] > arr[largestIndx]){
        largestIndx = leftIndx;
    }
    if(rightIndx <= n && arr[rightIndx] > arr[largestIndx]){
        largestIndx = rightIndx;
    }

    if(largestIndx != indx){
        std::swap(arr[largestIndx], arr[indx]);
         indx = largestIndx;
         heapify(arr, n, indx);
    }
    

}
void buildheap(int arr[], int n){

    for(int indx =n/2 ; indx>0; indx--){

        heapify(arr, n, indx);
    }

}
void printheap(int arr[],int n){
    
    for(int i = 1; i<=n; i++){
        printf("%d ", arr[i]);
    }
    
    
}

void heapSort(int arr[],int n){

    
    while(n>1){
        std::swap(arr[1], arr[n]);
        n--;

        heapify(arr, n, 1);

    }
    

}


int main(){

    int arr[] = {-1, 5, 10, 15, 20, 25, 12, 60};

    int n = 7;

    buildheap(arr, n);
    printheap(arr, n);
    printf("\n");
    heapSort(arr, n);
    printheap(arr, n);

    return 0;
}