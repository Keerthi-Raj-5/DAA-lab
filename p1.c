#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void gcde(int,int);
void gcds(int,int);
void gcdc(int,int);
void main(){
	int a,b;
	//printf("Enter two numbers\n");
	//scanf("%d%d",&a,&b);
	srand(time(0));
	a=(rand()+1)%15;
	b=(rand()+1)%15;
	if(a<0||b<0){
		printf("Invalid inputs\n");
		exit(0);}
	gcde(a,b);
	gcds(a,b);
	gcdc(a,b);
	}
void gcde(int m,int n){
	int count=0,r;
	printf("GCD of (%d,%d) using Euclid method is ",m,n);
	while(n!=0){
		count++;
		r=m%n;
		m=n;
		n=r;
		}
	printf("%d\n",m);
	printf("Count is %d\n",count);
	}
void gcds(int m,int n){
	int count=0;
	if(m==0||n==0){
		printf("Gcd cannot be found\n");
		return;}
	printf("GCD of (%d,%d) using Subtraction method is ",m,n);
	while(m!=n){
		count++;
		if(m>n)m=m-n;
		else n=n-m;
		}
	printf("%d\n",m);
	printf("Count is %d\n",count);
}
void gcdc(int m,int n){
	int g,min,count=0;
	if(m>n)min=n;
	else min=m;
	if(m==0||n==0){
		printf("Gcd cannot be found\n");
		return;}
	printf("GCD of (%d,%d) using consecutive integers  method is ",m,n);
	while(min!=1){
		count++;
		g=m%min;
		if(g==0){
			if(n%min==0) break;}
		min--;
	}
	printf("%d\n",min);
	printf("count is %d\n",count);
	}
