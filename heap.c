#include<stdio.h>
void  heapadjust(int a[],int len ,int i){

  int index=2*i+1;
  int temp =a[i];
  int k=i;
  while(index<len){

    if(index+1<len){
      if(a[index]<a[index+1])
      index=index+1;
    }
    if(a[index]>temp){
      a[k]=a[index];
      k=index;
      index=2*index+1;
      
    }
    else{
      break;
    }
  }
  a[k]=temp;
}
//
//void heap(int a[],int len){
//	int i;
//	for(i=len/2-1;i>=0;i--){
//		heapadjust(a,len,i);
//	}
//}

int main(){
	
	int i;
	int a[]={3,7,9,4,6,1,10,2,5,8,18,12,16};
	int len=13;
	int temp;
	for(i=len/2-1;i>=0;i--){
		heapadjust(a,len,i);
	}
	for(i=len;i>1;i--){
		temp=a[0];
		a[0]=a[i-1];
		a[i-1]=temp;
		heapadjust(a,i-1,0);
	}
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
} 


