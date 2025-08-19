#include <stdio.h>

void transposeMatrix(int i, int j, int matrix[5][3]){
    int tMatrix[j][i];
    for(int p=0;p<i;p++){
        for(int q=0; q<j;q++){
            tMatrix[q][p]=matrix[p][q];
        }
    }

    for(int s=0;s<j;s++){
        for(int w=0;w<i;w++){
            printf("%d ",  tMatrix[s][w]);
        }
        printf("\n");
    }
}


// void hellicalOrSymm(int i, int j,int r,int d,int l,int u, int matrix[4][4]){
// printf("\n");
// printf("%d ,%d ,%d ,%d ,%d ,%d ,", i,j,r,d,l,u);
// printf("\n");
// if(i-1 == 1 || j-1==1) return;
// for(int p=r; p<l;p++){
//     printf("%d ", matrix[r][p]);
// }
// printf(",");
// for(int p=u; p<d;p++){
//     printf("%d ", matrix[p][d]);
// }
// printf(",");
// for(int p=l; p>r;p--){
//     printf("%d ", matrix[l][p]);
// }
// printf(",");
// for(int p=d; p>u;p--){
//     printf("%d ", matrix[p][u]);
// }
// printf(",");
// i--;
// j--;
// r++;
// d--;
// l--;
// u++;

// hellicalOrSymm(i,j,r,d,l,u,matrix);
// }
void hellicalOrAnSymm(int i, int j,int r,int d,int l,int u, int matrix[4][3]){
printf("\n");
printf("%d ,%d ,%d ,%d ,%d ,%d ,", i,j,r,d,l,u);
printf("\n");
if(i<j){
    if(i-1 == 0 || j-1==1) return;
     for(int p=r; p<l;p++){
    printf("%d ", matrix[r][p]);
}
printf(",");
for(int p=u; p<d;p++){
    printf("%d ", matrix[p][i]);
}
printf(",");
for(int p=l; p>r;p--){
    printf("%d ", matrix[l-1][p]);
}
printf(",");
for(int p=d; p>u;p--){
    printf("%d ", matrix[p][u]);
}
printf(",");
i--;
j--;
r++;
d--;
l--;
u++;

hellicalOrAnSymm(i,j,r,d,l,u,matrix);
}
else if(i>j){
    if(i-1 == 1 || j-1==0) return;
    for(int p=r; p<l;p++){
    printf("%d ", matrix[r][p]);
}
printf(",");
for(int p=u; p<d;p++){
    printf("%d ", matrix[p][l]);
}
printf(",");
for(int p=l; p>r;p--){
    printf("%d ", matrix[j][p]);
}
printf(",");
for(int p=d; p>u;p--){
    printf("%d ", matrix[p][u]);
}
printf(",");
i--;
j--;
r++;
d--;
l--;
u++;

hellicalOrAnSymm(i,j,r,d,l,u,matrix);
}
else{
if(i-1 == 1 || j-1==1){
    printf("%d ,",matrix[1][1]);
    return;
} 
for(int p=r; p<l;p++){
    printf("%d ", matrix[r][p]);
}
printf(",");
for(int p=u; p<d;p++){
    printf("%d ", matrix[p][d]);
}
printf(",");
for(int p=l; p>r;p--){
    printf("%d ", matrix[l][p]);
}
printf(",");
for(int p=d; p>u;p--){
    printf("%d ", matrix[p][u]);
}
printf(",");
i--;
j--;
r++;
d--;
l--;
u++;

hellicalOrAnSymm(i,j,r,d,l,u,matrix);
}

}


int main(){
    // int  i=2;
    // int j=3;
    int matrix[4][3]={{0,1,2},{2,3,4,},{3,5,6},{7,4,7}};
   hellicalOrAnSymm(4,3,0,3,2,0,matrix);
    return 0;
}