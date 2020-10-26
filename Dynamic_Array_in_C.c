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
                    temp = s[x];#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    total_number_of_books = (int *)malloc(total_number_of_shelves*sizeof(int));
    total_number_of_pages = (int **)malloc(total_number_of_shelves*sizeof(int*));
    for (int i=0; i<total_number_of_shelves; i++) {
        total_number_of_books[i]=0;
        total_number_of_pages[i]=(int*)malloc(sizeof(int));
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            *(total_number_of_books+x)+=1;
            *(total_number_of_pages+x)=realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
            *(*(total_number_of_pages+x)+*(total_number_of_books+x)-1)=y;

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
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
