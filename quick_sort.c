#include<stdio.h>
int partition(int a[],int p,int r);
void quick_sort(int a[],int p,int r);

int partition(int a[],int p,int r){
	int i,temp,temp1,k;
	k=r;
	temp=a[r];
	int l=p-1;
	for(i=p;i<r;i++){
		if(a[i]<=temp){
			l=l+1;
			temp1=a[i];
			a[i]=a[l];
			a[l]=temp1;
		
		}
		
	}
	l=l+1;
	temp1=a[r];
	a[r]=a[l];
	a[l]=temp1;
	
	
	return l;
} 
void quick_sort(int a[],int p,int r){
	
	int i; 
	if(p<r){
		i=partition(a,p,r);
		quick_sort(a,p,i-1);
		quick_sort(a,i+1,r);
}

}
int main(){
	
	int a[]={1,9,4,7,3,6,2,8,10,19,13,16};
	int i;
	quick_sort(a,0,11);
	
	for(i=0;i<12;i++){
		
		printf("%d ",a[i]);
	}
	
	return 0;
	
}

