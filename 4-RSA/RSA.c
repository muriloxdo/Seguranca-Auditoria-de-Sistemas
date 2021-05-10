// Murilo Xavier de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int _phi(int);
int inv_mod(int, int);
ll fast_exp(ll, ll, ll);
void euclid_ext(int, int);

int x, y, d;


int _phi(int num) {
    int i = 2;
    int result = num;
    
    for (i = 2; i * i <= num; i++){
        if(num % i == 0){
            while(num % i == 0)
                num /= i;
            
            result -= result / i;
        }
    }

    if(num > 1)
        result -= result / num;

    return result;
}

ll fast_exp(ll p, ll q, ll m){
    ll r = 1;

    while (q){
        if (q & 1)
            r = (r * p) % m;
        
        p = (p * p) % m;
        q >>= 1;
    }

    return r;
}


void euclid_ext(int a, int b){
    int x1, y1;

    if (!b){
        x = 1;
        y = 0;
        d = a;

        return;
    }

    euclid_ext(b, a % b);
    
    x1 = y, y1 = x - (a / b) * y;
    x = x1, y = y1;
}

int inv_mod(int a, int md){
    euclid_ext(a, md);
    return (x % md + md) % md;
}

int main(int argc, char **argv){
    int phi, n, e, c, d;

    scanf("%d %d %d", &n, &e, &c);
    phi = _phi(n);

    d = inv_mod(e, phi);

    printf("%lld\n", fast_exp(c, d, n));

    return 0;
}
