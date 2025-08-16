#include <iostream>
using namespace std;
#include <vector>
int pattern13(int n){
    int count=0;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<< " "<< count+j;
        }
        count+=i;
        cout<< endl;

    }
   return 0; 
}
void pattern14(int n){
    for (int i =1; i <=n; i++)
    {
        char r= 'A'+i - 1;
        for(char j= 0; j<i; j++){
            cout<< " "<<r;
        }
        cout<<endl;

    }
}


void pattern17(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j>i; j--)
        {
            cout<< " ";
        }

        for (char r = 'A'; r <= 'A'+i; r++)
        {
            cout<< r;
        }

        for (char r = 'A'+i; r>'A'; r--)
        {   char z = r-1;
            cout<< z;
        }
        
        for (int j = n-1; j>i; j--)
        {
            cout<< " ";
        }
        cout << endl;
    }
    
}

int reverseNumber(int n) {
        int revNum=0;
        while(n!=0){
            revNum= revNum * 10 + n%10;
            n/=10;           
        }
        cout<< n;
        return revNum;
     }

    int GCD(int n1,int n2) {
        int c;
        while(n1!=0){
            c=n2%n1;
            n2=n1;
            if(c==0) break;
            n1=c;
        }
        return n1;
    }


     bool isArmstrong(int n) {
        int digits=0;
        int ogNum=n;
        int m=n;
        int  sum=0;
        int p;
        while(n!=0){
            n/=10;
            digits++;
        }
        while(m!=0){
            p= m%10;
            int t =1;
            for(int i =0; i< digits; i++){
                t*=p;
            }
            sum+=t;
            m/=10;
        }

        if(sum==ogNum) return true;
        else return false;
    }
int divisors(int n) {
        int count=0;
        int divisorsN[n];
        for(int i=1; i<=n; i++){
            if(n%i==0){
                count++;
                divisorsN[count]=i;
            }
        }
        for (int i = 1; i <= count; i++) {
    cout << divisorsN[i] << " ";
}

 return 0;
    }

int main(){
    cout<<divisors(4);
    return 0;
}