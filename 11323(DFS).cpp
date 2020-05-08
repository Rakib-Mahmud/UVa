#include <bits/stdc++.h>
#define N (1 << 14)
#define K 0x80
#define MAXE 10100
typedef long long i64;
#define within(x) (1<=(x)&&(x)<=L)

int n,m,Cnt[K][N],ts,card[N];
i64 L;

i64 gcd(i64 x,i64 y){return (!y)?x:gcd(y,x%y);}
void ext_euclid(i64 *a,i64 *b,i64 x,i64 y,i64 *d) {!y?(*a=1,*b=0,*d=x):(ext_euclid(b,a,y,x%y,d),*b-=(*a)*(x/y));}

int dioph( i64 *x, i64 *y, i64 a, i64 b, i64 c ) {
	if ( !b ) {
		if ( c && !a )
			return 0;
		if ( !c && !a ) {
			*x = 1, *y = 1;
			return 1;
		}
		if ( c % a )
			return 0;
		*x = c/a, *y = 1;
		return 1;
	}
	if ( !dioph(y,x,b,a%b,c) )
		return 0;
	*y -= (*x)*(a/b);
	return 1;
}

int main() {
	int i,j,k,l,t,ok;
	i64 a,b,c,g,x,y;
#ifndef ONLINE_JUDGE
	//freopen("in.txt","r",stdin);
#endif
	for( scanf("%d",&ts); ts--; ) {
		scanf("%d %d %lld",&n,&m,&L);
		for ( i = 0; i < n; ++i )
			for ( card[i] = 0, j = 0; j <= L; ++j )
				Cnt[j][i] = 0;
		for ( ok = 1, l = 0; l < m; ++l ) {
			scanf("%lld %d %lld %d %lld",&a,&i,&b,&j,&c);
			if ( !ok ) continue ;
			--i, --j;
			if ( !a && !b ) { if ( c ) ok = 0; continue; }
			if ( i == j ) {
				g = a+b;
				if ( !g && c ) {
					ok = 0;
					continue ;
				}
				if ( !g && !c ) continue ;
				if ( c % g ) {
					ok = 0;
					continue ;
				}
				++card[i];
				if ( within(c/g) )
					++Cnt[c/g][i];
				else ok = 0;
				continue ;
			}
			if ( !ok ) continue ;
			g = gcd(a,b);
			if ( c && !g ) {
				ok = 0;
				continue ;
			}
			if ( !c && !g )
				continue ;
			if ( c % g ) {
				ok = 0;
				continue ;
			}
			a /= g, b /= g, c /= g;
			++card[i], ++card[j];
			if ( !dioph(&x,&y,a,b,c) ) {
				ok = 0;
				continue ;
			}
			if ( b > 0 ) {
				for ( t = (x-L)/b-3; t <= (x-1)/b+3; ++t )
					if ( within(x-t*b) )
						++Cnt[x-t*b][i];
			}
			else if ( b < 0 ) {
				for ( t = (x-L)/b+3; t >= (x-1)/b-3; --t )
					if ( within(x-t*b) )
						++Cnt[x-t*b][i];
			}
			else {
				if ( within(x) )
					++Cnt[x][i];
				else ok = 0;
			}
			if ( a > 0 ) {
				for ( t = (1-y)/a-3; t <= (L-y)/a+3; ++t )
					if ( within(y+t*a) )
						++Cnt[y+t*a][j];
			}
			else if ( a < 0 ) {
				for ( t = (1-y)/a+3; t >= (L-y)/a-3; --t )
					if ( within(y+t*a) )
						++Cnt[y+t*a][j];
			}
			else {
				if ( within(y) )
					++Cnt[y][j];
				else ok = 0;
			}
		}
		if ( !ok ) goto NO;
		for ( i = 0; i < n; ++i ) {
			for ( k = 1; k <= L; ++k )
				if ( Cnt[k][i] == card[i] )
					goto nx;
			goto NO;
			nx: continue ;
		}
		YES: puts("yes");
		continue ;
		NO:  puts("no");
	}
	return 0;
}
