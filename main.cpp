#include <iostream>
#include <ctime>
using namespace std;
int bmp[4][4];
void initmas(int u[4]){
    for(int i=0;i<4;i++){u[i]=0;}
}
void initmas(int u[4][4]){
    for(int i=0;i<4;i++){for(int j=0;j<4;j++){u[i][j]=0;}}
}

bool comp(int a,int a1[4][4],int a2[4],char op){
	bool res=true;
	if(op=='x'){
		for(int i=0;i<4;i++){if(a1[a][i]!=a2[i]){res=false;}}
	}
	if(op=='y'){
		for(int i=0;i<4;i++){if(a1[i][a]!=a2[i]){res=false;}}
	}
	return res;
}
int ran2(int p){
    int l=0;
    int z=rand()%p;
    if(z!=0){l=1;}
    for(int i=0;i<z;i++){

        l+=l;

    }
    return l;
}


void init(){
    initmas(bmp);
    srand(time(NULL));
   bmp[1][0]=ran2(5);
    bmp[1][1]=ran2(5);
    bmp[1][2]=ran2(5);
    bmp[1][3]=ran2(5);
    bmp[2][3]=ran2(5);
    bmp[0][3]=ran2(5);
    bmp[2][2]=ran2(5);
}
bool  up(int uper[4][4]){
    bool any=false;
    

    for(int j=0;j<4;j++){int y[4];initmas(y);int n=0;
        for(int i=0;i<4;i++){if(uper[j][i]!=0){y[n]=uper[j][i];n++;}}
          if(!comp(j,uper,y,'x')){any=true;}
        for(int z=0;z<4;z++){if((y[z]==y[z+1])&&(y[z]!=0)){y[z]+=y[z+1];y[z+1]=0;any=true;}}

        for(int w=0;w<3;w++){if(y[w]==0){y[w]=y[w+1];y[w+1]=0;}}

        for(int i=0;i<4;i++){uper[j][i]=y[i];};
    }

   return any;
}

bool down(int uper[4][4]){
     bool any=false;

    for(int j=0;j<4;j++){int y[4];initmas(y);int n=3;
        for(int i=3;i>-1;i--){if(uper[j][i]!=0){y[n]=uper[j][i];n--;}}
      if(!comp(j,uper,y,'x')){any=true;}
        for(int z=3;z>0;z--){if((y[z]==y[z-1])&&(y[z]!=0)){y[z]+=y[z-1];y[z-1]=0;any=true;}}

        for(int w=3;w>0;w--){if(y[w]==0){y[w]=y[w-1];y[w-1]=0;}}

        for(int i=0;i<4;i++){uper[j][i]=y[i];};
    }

  return any;
}
bool left(int uper[4][4]){
     bool any=false;
    for(int j=0;j<4;j++){int y[4];initmas(y);int n=0;
        for(int i=0;i<4;i++){if(uper[i][j]!=0){y[n]=uper[i][j];n++;}}
           if(!comp(j,uper,y,'y')){any=true;}
        for(int z=0;z<4;z++){if((y[z]==y[z+1])&&(y[z]!=0)){y[z]+=y[z+1];y[z+1]=0;any=true;}}

        for(int w=0;w<3;w++){if(y[w]==0){y[w]=y[w+1];y[w+1]=0;}}

        for(int i=0;i<4;i++){uper[i][j]=y[i];};
    }
 return any;


}
bool right(int uper[4][4]){
    bool any=false;
    for(int j=0;j<4;j++){int y[4];initmas(y);int n=3;
        for(int i=3;i>-1;i--){if(uper[i][j]!=0){y[n]=uper[i][j];n--;}}
          if(!comp(j,uper,y,'y')){any=true;}
        for(int z=3;z>0;z--){if((y[z]==y[z-1])&&(y[z]!=0)){y[z]+=y[z-1];y[z-1]=0;any=true;}}

        for(int w=3;w>0;w--){if(y[w]==0){y[w]=y[w-1];y[w-1]=0;}}

        for(int i=0;i<4;i++){uper[i][j]=y[i];};
    }
   return any;
   
}
void bmpout(){
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            if(bmp[i][j]==0){cout<<"*"<<"\t";continue;}cout<<bmp[i][j]<<"\t";
        } cout<<"\n";
    }
    cout<<"\n";
}

void update(int fbmp[4][4]){
      for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
        	fbmp[j][i]=bmp[j][i];
        }}
}
void gameOver(int fbmp[4][4]){
      if(!up(fbmp)){ update(fbmp);
      	if(!down(fbmp)){ update(fbmp);
      		if(!left(fbmp)){ update(fbmp);
      			if(!right(fbmp)){
      				cout<<"\n game over"; exit(0);
      			}
      		}
      	}
      }	
}
void generate(){
	int n=0;
	int y[16][2];
bool need=false;
srand(time(NULL));
long int t=rand();
  for(int i=0;i<4;i++){for(int j=0;j<4;j++){if(bmp[i][j]==0){y[n][0]=i;y[n][1]=j;
  	n++;need=true;
  }}}if(need){
  int h=rand()%n;
  
if ((99<t)&&(t<=9090909000)){
	bmp[y[h][0]][y[h][1]]=2;
}else if (t>9090909000){
	bmp[y[h][0]][y[h][1]]=4;
}else if(t==0){}}
}
int main() {char com=' ';

    init();
    int vbmp[4][4];
    initmas(vbmp);
    bool norm=true;
    while(com!='q'){
       bool dobav=false;
        switch(com){
            case 'j':
              dobav=down(bmp);
              norm=true;
                break;
            case 'k':
                dobav=up(bmp);
                norm=true;
                break;
            case 'h':
                dobav=left(bmp);
                norm=true;
                break;
            case 'l':
                dobav=right(bmp);
                norm=true;
                break;

        }if(norm){
        update(vbmp);if(dobav){
        generate();}
        bmpout();
        gameOver(vbmp);}
        cin>>com;
        norm=false;
        
    }
    return 0;
}
