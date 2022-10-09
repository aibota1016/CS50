
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    // Some repeated random numbers are given, write a program to print them in increasing order with their frequency.
    int n, a[50];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int freq[50], b[50], found, i, k, j, t;
    for(i=0;i<n;i++) {
        printf("enter element %d ",i+1);
        scanf("%d",&a[i]);
    }
    for (i=0, k=0; i<n; i++) {
        found = 0;
        for (int j=0; j<k; j++) {
            if (a[i] == b[j]) {
                freq[i] += 1;
                found =1;
                break;
            }      
        }
        if (found == 0) {
            b[k] == a[i];
            freq[k++] = 1;
        }  
    }
    for(i=0;i<k-1;i++)
        for(j=i+1;j<k;j++)
            if(freq[i] < freq[j]){
                t = b[i];
                b[i] = b[j];
                b[j] = t;
                t = freq[i];
                freq[i] = freq[j];
                freq[j] = t;
            }
    
    for(i=0;i<k;i++)
        printf("%d\t%d\n",b[i],freq[i]);

         
    return 0;
}

