#include <stdio.h>
/*#include <string.h>
#include <stdlib.h>
#define True 1
*/
#include <time.h>
#define MOD 1000000007

void tribonacci(long long int l, long long int r){
    long long int x=1, y=1, z=1, tmp;
    long long int result=0;
    long long int i;

    if (l < 3){
        for(i = l; i <= r && i < 3; i++)
            result += 1;
    }
    for(i = 3; i <= r; i++){ // the i number is z
        tmp = x;
        x = y;
        y = z;
        z = (tmp + x + y) % MOD;
        if(i >= l)
            result = (result + z) % MOD;
    }
    printf("%lld\n", result);
    return;
}
int main(void){
    long long int l=0, r=1;
    long long int start, end;
    /*while(scanf("%lld %lld", &l, &r) != EOF){
        tribonacci(l, r);
    }*/
    for(int i = 0; i < 10; i++){
        r *= 10;
        start = clock();
        tribonacci(l, r);
        end = clock();
        printf("end-start: %lld\n", end-start);
    }
    return 0;
}

/*
// six
typedef struct{
    int bool;
    long long num;
    long long parter[4];
}prime;

int main(void){
    long long num[9], mid[9];
    int i;
    prime primes[9];
    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", 
                num, num+1, num+2, num+3, num+4, num+5, num+6, num+7, num+8) != EOF){
        for(i = 0; i < 9; i++){
            get_prime(num, i, primes);
        }
        
    }
    return 0;
}
*/
/*
// seven
int compare(const void *x, const void *y){
    return *(int *)y - *(int *)x;
}

int main(void){
    int n, k, i, last, m, tag;
    long long int sum;
    while(scanf("%d %d", &n, &k) != EOF){
        sum = 0;
        m = k - 1;
        tag = 0;
        long long num[n], tmp;
        for(i = 0; i < n; i++)
            scanf("%lld", num+i);
        qsort(num, n, sizeof(long long), compare); // sort
        if (n <= k){
            for(i = 0; i < n; i++)
                sum += num[i];
            n = 1;
        }
        else{
            last = n % m;
            if (last && last != 1){ // this if's goal: after this operation, n % m == 1
                for(n=n-last+1, i = 0; i < (last-1); i++)
                    num[n-1] += num[n+i];
                sum += num[n-1];
                tag = 1;
            }
            else if(m != 1 && !last){
                for(n=n-m+1, i = 0; i < (m-1); i++)
                    num[n-1] += num[n+i];
                sum += num[n-1];
                tag = 1;
            }
        }
        while(n > 1){
            if (tag){
                for(i = 0; i < n; i++) // insertion sort
                    if (num[i] < num[n-1]){
                        tmp = num[n-1];
                        for(last = n-1; last != i; last--)
                            num[last] = num[last-1];
                        num[last] = tmp;
                        break;
                    }
                tag = 0;
            }
            for(n-=m, i=0; i < m; i++){
                num[n-1] += num[n+i];
                tag = 1;
            }
            sum += num[n-1];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
*/
/*
void Six(void){
    long int num[9];
    while (scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld",
                    num, num+1, num+2, num+3, num+4, num+5, num+6, num+7, num+8) != EOF){
        int i, j, k;
        for(i = 0; i < 9; i++)
            for(j = i; j < 9; j++)

    }

int main(void){
    return 0;
}
*/
/*
// five
void hash(char str[], int ch);
int  find(char str[], int ch);
int main(void){
    char str_1[100000], str_2[100000];
    while(scanf("%s %s", str_1, str_2) != EOF){
        char str[257] = {'\0'};
        int i, tag = 0;
        for(i = 0; str_2[i] != '\0'; i++)
            hash(str, str_2[i]);
        for(i = 0; str_1[i] != '\0'; i++){
            if (!find(str, str_1[i])){
                tag = 1;
                putchar(str_1[i]);
            }
        }
        if (tag)
            putchar('\n');
        else
            puts("EMPTY");
    }
    return 0;
}

void hash(char str[], int ch){
    str[ch] = ch;
    return;
}

int find(char str[], int ch){
    if (str[ch] == ch)
        return 1;
    else
        return 0;
}
*/
/*
// four
int main(void){
    long x, y, a, remainder;
    while(scanf("%ld %ld %ld", &x, &y, &a) != EOF){
        remainder = a % (x + y);
        if (remainder != 0 && remainder <= x)
            printf("wanshen\n");
        else
            printf("light\n");
    }
    return 0;
}
*/
/*
// three

int main(void){
    int n;
    char *string, *current;
    char *substr = "wanshen";
    int size = 7;
    string = malloc(sizeof(char) * 10000000);
    while(scanf("%d", &n) != EOF){
        int i, start, sum=0;
        if (string == NULL)
            exit(-1);
        for(i=0, start=0; i < n; i++, start=strlen(string)){
            scanf("%s", &string[start]);
        }
        current = string;
        while (True) {
            current = strstr(current, substr);
            if (current != NULL){
                current += size;
                sum += 1;
                if(strlen(current) < size)
                    break;
            }
            else
                break;
        }
        printf("%d\n", sum);
    }
    free(string);
    return 0;
}*/
/*
// one
int main(void){
    long long x=0, y=0, a=0, b=0;
    while(scanf("%lld+%lldi %lld+%lldi", &x, &y, &a, &b) != EOF) {
        printf("%lld+%lldi\n", x+a, y+b);
    }
    return 0;
}
*/

/*
// two
void result(long long total){
    long long position=0, reminder; // position is a's position
    long long a=0, b=1, tmp=0, sum=1; // sum: b <<
    if (total < 4){
        printf("1 1\n");
        return;
    }
    while(sum < total){
        position += 1;
        tmp = a + b;
        a = b;
        b = tmp;
        sum += b;
    }
    reminder = total - (sum -b);
    if (reminder > a)
        position += 1;
    else
        reminder = a;
    printf("%lld %lld\n", position, reminder);
    return;
}

int main(void){
    long long sum;
    while(scanf("%lld", &sum) !=EOF){
        result(sum);
    }
    return 0;
}
*/
