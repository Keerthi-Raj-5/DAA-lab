#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *f1;
FILE *f2;
void gcde(int m,int n){
	int cnt=0,r;
	while(n!=0){
		cnt++;
		r=m%n;
		m=n;
		n=r;}
	fprintf(f1,"%d",m);
	fprintf(f2,"%d",cnt);
	}
void gcds(int m,int n){
	int cnt=0;
	while(m!=n){ cnt++;
		if(m>n) m=m-n;
		else n=n-m;}
	fprintf(f1,"%d",m);
	fprintf(f2,"%d",cnt);
}
void gcdc(int m,int n){
	int cnt=0;
	int min=(m<n)?m:n;
	while(min!=1){ cnt++;
		if(m%min==0)
			if(n%min==0)break;
		min--;}
	fprintf(f1,"%d",min);
	fprintf(f2,"%d",cnt);
}

void main(){
	int m,n;
	f1=fopen("gcd.txt","w");
	f2=fopen("gcdcnt.txt","w");
	srand(0);
	fprintf(f1,"m\tn\tgcde\tgcds\tgcdc\n");
		fprintf(f2,"m\tn\tcnte\tcnts\tcntc\n");
	for(int i=0;i<10;i++){
		m=rand()%100+1;
		n=rand()%100+1;
		fprintf(f1,"%d\t%d\t",m,n);
		fprintf(f2,"%d\t%d\t",m,n);
		gcde(m,n);
		fprintf(f1,"\t");
		fprintf(f2,"\t");
		gcds(m,n);
		fprintf(f1,"\t");
		fprintf(f2,"\t");
		gcdc(m,n);
		fprintf(f1,"\n");
		fprintf(f2,"\n");
	}
	fclose(f1);
	fclose(f2);
}
		






		
