#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a):(b))

double findMedian(int A[], int m, int B[], int n) {
        int total = m + n;
        if ((total/2) * 2 != total) // if total is odd #
                return findKth(A, m, B, n, total/2 + 1);
        else
                return findKth(A, m, B, n, total/2)
                        + findKth(A, m, B, n, total/2 + 1) / 2.0;
}

int findKth(int A[], int m, int B[], int n, int k) {
       // always assume m <= n 
       if (m > n) return findKth(B, n, A, m, k);
       if (m == 0) return B[k - 1];
       if (k == 1) return MIN(A[0], B[0]);

       // divide k into 2 parts
       int ia = MIN(k / 2, m), ib = k - ia;
       if (A[ia - 1] < B[ib - 1])
               return findKth(A + ia, m - ia, B, n, k - ia);
       else if (A[ia - 1] > B[ib - 1])
               return findKth(A, m, B + ib, n - ib, k - ib);
       else
               return A[ia - 1];
}

int main () {
        int A[5] = {1, 2, 5, 7, 8};
        int B[2] = {3, 9};
        int m = 5, n = 2, ans;

        ans = findMedian(A, 5, B, 2);

        printf("The answer is %d.\n", ans);

        return 0;
}
