#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolutuion(vector<int> pagesArray,int books,int student,int mid){
    int page_Sum = 0;
    int Student_Number = 1;

    for(int i=0; i<books; i++){
        if(pagesArray[i] > mid){
            return false;
        }

        if(page_Sum + pagesArray[i] > mid){
            Student_Number++;
            page_Sum = pagesArray[i];

            if(Student_Number > student){
                return false;
            }
        }
        else{
            page_Sum += pagesArray[i];
        }

        
    }
    return true;
}

int bookAllocationProblem(vector<int> pages,int books,int student){

    if(student > books){
        return 0;
    }

    int totalPages =0;

    for(int i=0; i<books; i++){
        totalPages += pages[i];
    }

    int s = 0;
    int e = totalPages-1;
    int ans = -1;

    while(s<=e){

        int mid = (s+e)/2;

        if(isPossibleSolutuion(pages, books, student, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

    }

    return ans;
}

int main(){

    int student;
    int books;

    

    cout << "Enter Number of students : ";
    cin >> student;

    cout <<endl<< "Enter Number of Books : ";
    cin >> books;

    vector<int> pages(books, -1);

    cout<<endl<<"enter pages of "<<books<<" books in increasing order : ";
    
    for(int i=0; i<books; i++){
        cin >>pages[i];
    }

    int found = bookAllocationProblem(pages, books, student);

    if(found){
        cout << found;
    }
    else{
        cout << "Invalid Data";
    }

    return 0;
}