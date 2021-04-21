#include<iostream>
#include<cmath>
using namespace std;
void printBar(int n){
  for(int i=0;i<n;i++){
    cout<<'-';
  }
  cout<<endl;
}
int main(int argc,char *argv[]){
  if(argc!=3){
    printf("usage: %s [base number] [exponent number]\n",argv[0]);
    return 0;
  }
  const int BASE=atoi(argv[1]),EXP=atoi(argv[2]),DEVIDED_MAX=pow(BASE,EXP-1),
            TURN=round(sqrt(DEVIDED_MAX)),N_WIDTH=to_string(DEVIDED_MAX*BASE-1).length();
  int i,j,k,b,s;
  for(i=BASE-1;i>0;i--){
    for(j=DEVIDED_MAX;j>=1;j/=BASE){
      printf("%+*d\n",TURN*(N_WIDTH+1)-1,i*j);
      for(k=0;k<DEVIDED_MAX;k++){
        b=k/j;s=k%j;
        printf("%*d ",N_WIDTH,b*j*BASE+i*j+s);
        if(k%TURN==TURN-1||k==DEVIDED_MAX-1){
          cout<<endl;
        }
      }
      if(i!=1||j!=1)printBar(TURN*(N_WIDTH+1)-1);
    }
  }
  return 0;
}
