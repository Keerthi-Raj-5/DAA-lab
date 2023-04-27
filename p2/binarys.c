#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define inc 10
int cnt;
void bs(int *a,int key,int b,int e){
	int mid;
	cnt=0;
	while(b<=e){cnt++;
		mid=(b+e)/2;
		if(a[mid]==key)return;
		else if(a[mid]>key) e=mid-1;
		else b=mid+1;
	}
}

void main(){
	int n,key,i;
	int *a;
	FILE *arr,*b,*w,*avg;
	arr=fopen("bsarr.txt","w");
	b=fopen("bsb.txt","w");
	w=fopen("bsw.txt","w");
	avg=fopen("bsavg.txt","w");
	srand(time(0));
	for(n=x;n<=y;n+=inc){
		a=(int*)malloc(n*sizeof(int));
		fprintf(arr,"\nArray :");
		*(a+0)=rand()%100;
		for(i=1;i<n;i++)		
			a[i]=a[i-1]+rand()%100;
		for(i=0;i<n;i++)
		fprintf(arr," %d",a[i]);
		key=a[(n-1)/2];
		bs(a,key,0,n-1);
		fprintf(b,"%d\t%d\n",n,cnt);		
		fprintf(arr,"\nKey for best case :%d\n",key);
		
		key=9999;
		bs(a,key,0,n-1);
		fprintf(w,"%d\t%d\n",n,cnt);		
		fprintf(arr,"\nKey for worst case :%d\n",key);

		key=a[3*(n-1)/4];
		bs(a,key,0,n-1);
		fprintf(avg,"%d\t%d\n",n,cnt);		
		fprintf(arr,"\nKey for average case :%d\n",key);
	}
fclose(avg);
fclose(arr);
fclose(b);
fclose(w);
free(a);
FILE *g=fopen("plot.gnu","w");
fprintf(g,"set yrange [0:10]\nset xlabel \"Input\"\nset ylabel \"output\"\nset term png\nset output \"Bsearch.png\"\nplot \"bsb.txt\" w l ti \"Best case\",\"bsavg.txt\" w l ti \"Average case\",\"bsw.txt\" w l ti \"worst case\"\nset term x11");
fclose(g);
system("gnuplot plot.gnu");
system("eog Bsearch.png");

//system("gedit bsarr.txt bsb.txt bsw.txt bsavg.txt");

}
