#include<stdio.h>
#include<string.h>

char out[10];

char * solution(int m){
    int num[7] = {1000,500,100,50,10,5,1};
    char cipher[8] = {'M','D','C','L','X','V','I','\0'};
    int count = 0, n = m;
    for(int i = 0, j = 0, k = 0; i<7; i++, j = 0, k = 0){
        while (k<5 && n>0){
            if(i%2==0){
                if(n/num[i] > 0){
                    out[count++] = cipher[i];
                    n -= num[i];
                    j++;
                }
                else if(n/(num[i]-num[i+2]) > 0){
                    out[count++] = cipher[i+2];
                    out[count++] = cipher[i];
                    n = n - num[i] + num[i+2];
                }
            }
            else{
                if(n/num[i]>0){
                    out[count++] = cipher[i];
                    n -= num[i];
                    j++;
                }
            }
            if (j == 4){
                count -= 3;
                out[count++] = cipher[i-1];
                j = 0;
            }
            k++;
        }
    }
    out[count] = '\0';
    return out; 
}

int main(){
    for(int i = 1; i<1001; i++)
        printf("%d\t%s\n",i,solution(i));
    return 0;
}
