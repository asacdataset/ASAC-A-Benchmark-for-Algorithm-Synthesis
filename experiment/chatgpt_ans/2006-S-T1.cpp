#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int max_energy = 0;
    for(int i=0;i<n;i++){
        int energy = a[i]*a[(i+1)%n]*a[(i+2)%n];
        max_energy = energy > max_energy ? energy : max_energy;
    }
    printf("%d",max_energy);
    return 0;
}
