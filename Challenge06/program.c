#include <stdio.h>
int main()
{
int a[12], n, i, k, reg, d;
int s = 0, mn, mx, sec = -1;
int p = 0, r = 1, b = 1, c = 0;
do {
printf("Enter number of readings (5-12): ");
scanf("%d", &n);
} while (n < 5 || n > 12);
for (i = 0; i < n; i++) {
do {
printf("Enter reading %d (0-1000): ", i + 1);
scanf("%d", &a[i]);
} while (a[i] < 0 || a[i] > 1000);
}
mn = mx = a[0];
for (i = 0; i < n; i++) {
s += a[i];
if (a[i] < mn) mn = a[i];
if (a[i] > mx) mx = a[i];
}
printf("Sum = %d\nAverage = %.2f\n", s, (float)s / n);
printf("Min = %d\nMax = %d\n", mn, mx);
for (i = 0; i < n; i++)
if (a[i] < mx && a[i] > sec)
sec = a[i];
if (sec == -1)
printf("No second largest\n");
else
printf("Second largest = %d\n", sec);
for (i = 1; i < n; i++) {
if (a[i] > a[i-1]) {
r++;
if (r > b) b = r;
if (i < n-1 && a[i] > a[i+1]) p++;
} else
r = 1;
}
printf("Local peaks = %d\n", p);
printf("Longest increasing run = %d\n", b);
printf("Enter K: ");
scanf("%d", &k);
k = (k % n + n) % n;
printf("Rotated: ");
for (i = 0; i < n; i++)
printf("%d ", a[(i + n - k) % n]);
printf("\nEnter last two digits of reg no: ");
 scanf("%d", &reg);
 d = reg % 9 + 1;
for (i = 0; i < n; i++)
if (a[i] % d == 0)
c++;
printf("\nD = %d\nDivisible readings = %d\n", d, c);
return 0;
}
