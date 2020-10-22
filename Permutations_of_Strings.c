#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s){
    int ans = 0;
    int i,j,k,x;
    char* temp = calloc(11, sizeof(char));
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    for (i=n-2;i>=0;i--){
        for (j=n-1; j>i; j--) {
            if (strcmp(s[i],s[j])<0) {
                temp = s[i];
                s[i]=s[j];
                s[j]=temp;
                for (x=i+1; x<=((int)(n-i-2)/2)+i+1; x++) {
                    temp = s[x];
                    s[x] = s[n-x+i];
                    s[n-x+i] = temp;
                }
                ans=1;
                goto theend;
            }            
        }
    }
theend:
    return ans;
}

int main()
