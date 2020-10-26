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

    // 1: starting from end to find the decreasing point [9 2 4 3 1] (4 decreasing pont,           // 2 inverse point)
    // 2: starting from 4 to end to find the element bigger than inverse point 2(find 3)
    // 3: swap 2 and 3
    // 4: inverse the order of the elements after 3
theend:
    return ans;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
