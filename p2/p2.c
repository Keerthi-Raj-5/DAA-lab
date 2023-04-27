#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define inc 10

void main(){
	FILE *f1;
	FILE *f2;
	FILE *f3;
   	FILE *f4;
	int *a;
	int key,i,j,k,n,cnt;
	f1=fopen("ls.txt","w");
	f2=fopen("lsb.txt","w");
	f3=fopen("lsw.txt","w");	
	f4=fopen("lsavg.txt","w");
	srand(time(0));
	for(n=x;n<=y;n=n+10){ cnt=0;
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			a[i]=rand()%100;
			fprintf(f1,"Array :");
			for(k=0;k<n;k++)
			fprintf(f1,"%d\t",a[k]);
			key=a[0];
			for(j=0;j<n;j++){
				cnt++;
				if(a[j]==key) break;}
		fprintf(f1,"\nBest case=%d\n",key);
		fprintf(f2,"%d\t%d\n",n,cnt);
			cnt=0;
			key=9999;
			for(j=0;j<n;j++){
				cnt++;
				if(a[j]==key) break;}
		fprintf(f1,"\nWorst case=%d\n",key);
		fprintf(f3,"%d\t%d\n",n,cnt);
			cnt=0;
			key=a[n/2];
			for(j=0;j<n;j++){
				cnt++;
				if(a[j]==key) break;}
		fprintf(f1,"\nAverage case=%d\n",key);
		fprintf(f4,"%d\t%d\n",n,cnt);
	}
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
system("gedit ls.txt lsb.txt lsw.txt lsavg.txt");
}
			




		
		
	

