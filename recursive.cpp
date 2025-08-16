#include <iostream>
using namespace std;
#include <string.h>



    void printNumbers(int n) {
        if(n==0) return;
        printNumbers(n-1);
        cout<< " "<< n ;
    }
int NnumbersSum(int N){
			//your code goes here
           if(N==1) return 1;
            return N*=NnumbersSum(N-1);
		}

void reverse(int arr[], int n){
        // for(int i =0; i<n/2; i++){
            // int t= arr[i];
            // arr[i]=arr[n-1-i];
            // arr[n-1-i]=t;
            // cout<<t<<" ";
            // cout<<arr[i]<<" ";


        // }
    }


    bool palindromeCheck(string s){
			//your code goes here
            int t= s.length();
            for(int i=0; i<t; i++){
                if(s[i]!=s[t-1-i]) return false;
            }
            return true;
		}


        int fib(int n) {
        //your code goes here
        if(n<=1) return n;
        int last= fib(n-1);
        int slast= fib(n-2);

        return last+slast;
    }

    int fib1(int n) {
        //your code goes here
        int fnum=0;
        int snum=1;
        int sum;
        for(int i=1; i<=n-1; i++){
            sum=fnum+snum;
            fnum= snum;
            snum=sum;
        }
        return sum;
    }
int main(){
    cout<<fib(10);
    return 0;
}