#include <stdio.h>

int main(){

    // int a[]={1,2,3,3,4};
    // int b[]={1,3,5,7};
    // int i,j;

    // int intsctnArr[10];
    // int k=0;
    // for ( i = 0; i < 5; i++)
    // {
    //     for ( j = 0; j <4; j++)
    //     {
    //         if(a[i]==b[j]){
    //             int count=0;
    //             for (int l = 0; l < k; l++)
    //             {
    //                 if (intsctnArr[l]==a[i])
    //                 {
    //                     count=1;
    //                     break;
    //                 }
    //             }
    //                 if(!count){
    //                     intsctnArr[k++]=a[i];
    //                 }
    //                 break;  

    //         }
    //     }
        
    // }


    // int unionArr[10];
    // int k1=0;


    // for (int i = 0; i < 5; i++)
    // {
    //     int count1=0;
    //     for (int j = 0; j < k1; j++)
    //     {
            
    //         if(unionArr[j]==a[i]){
    //             count1=1;
    //             break;
    //         }
    //     }
    //     if (!count1)
    //     {
    //         unionArr[k1++]=a[i];
    //     }
        
        
    // }
    //     for (int i = 0; i < 4; i++)
    // {
    //     int count1=0;
    //     for (int j = 0; j < k1; j++)
    //     {
            
    //         if(unionArr[j]==b[i]){
    //             count1=1;
    //             break;
    //         }
    //     }
    //     if (!count1)
    //     {
    //         unionArr[k1++]=b[i];
    //     }
        
        
    // }
    
    // for (int i = 0; i < k1; i++)
    // {
    //     printf("%d  \n", unionArr[i]);
    // }
    
    


    int n=5;
    int count =0, num=2;
    while(count<n){
     int isprime=1;
     for(int i=2; i<num;i++){
        if(num%i==0){
            isprime=0;
            break;
        }
     }
     if(isprime){
        printf("%d \n ", num);
        count++;
     }
     num++;
    }
    return 0;
}