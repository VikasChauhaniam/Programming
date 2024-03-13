#include<istream>

using namespace std;

class Heap{
    public:
        int *arr;
        int size;
        int capacity;

        Heap(int capacity){
            this->arr = new int[capacity];
            this->size = 0;
            this->capacity = capacity;
        }

        void printheap(){
    
            for(int i = 1; i<=size; i++){
                printf("%d ", arr[i]);
            }
    
    
        }

        void insertHeap(int val){
            size++;

            if(size == capacity){
                printf("OverFlow");
                return;
            }

            int indx = size;
            arr[indx] = val;

            while(indx > 1){
                int parentIndx = indx/2;

                if(arr[indx] > arr[parentIndx]){
                    swap(arr[indx], arr[parentIndx]);
                    indx = parentIndx;
                }
                else{
                    break;
                }
            } 
        }


        int deleteHeap(){
            int ans = arr[1];
            arr[1] = arr[size];
            size--;


            int indx = 1;
            while(indx < size){
                int leftIndx = 2*indx;
                int rightIndx = 2*indx +1;
                int largestIndx = indx;

                if(leftIndx <= size && arr[leftIndx] > arr[largestIndx]){
                    largestIndx = leftIndx;
                }
                if(rightIndx <= size && arr[rightIndx] > arr[largestIndx]){
                    largestIndx = rightIndx;
                }

                if(largestIndx != indx){
                    swap(arr[largestIndx], arr[indx]);
                    indx = largestIndx;
                }
                else{
                    break;
                }
            }
            return ans;
        }
};



int main(){

    Heap hp = Heap(10);

    hp.insertHeap(10);
    hp.insertHeap(20);
    hp.insertHeap(5);
    hp.insertHeap(11);
    hp.insertHeap(6);
    hp.insertHeap(8);


    hp.printheap();
    hp.deleteHeap();
    printf("\n");

    hp.printheap();
    hp.deleteHeap();
    printf("\n");

    hp.printheap();
    hp.deleteHeap();

    


    return 0;
}