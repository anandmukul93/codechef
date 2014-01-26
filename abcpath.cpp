#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<int>iindex;
queue<int>jindex;
char array[51][51];
bool status[51][51];
int arr[51][51];
int ans;
int h , w;

void initialize(){
ans=0;
for(int i =1;i<=h;i++)
	{
	for(int j=1 ;j<=w;j++)
		{
			status[i][j]=false;
		}
	}
}

void bfsvisit(int itemp  , int jtemp , int value){
int i ,j;
for(i=-1;i<2;i++) 
			{
				for(j=-1;j<2;j++)
				{
				if(itemp+i<=h && itemp+i>=1 && j+jtemp<=w && j+jtemp>=1)
					{
					if(!status[i+itemp][j+jtemp] && (array[i+itemp][j+jtemp]-array[itemp][jtemp])==1 )
					{	
						arr[itemp+i][jtemp+j]=value+1;
						status[i+itemp][j+jtemp]=true;
						iindex.push(i+itemp);
						jindex.push(j+jtemp);
						
					}
				}
			}
		}


}


void bfs(){
	int itemp,jtemp;
	while(!iindex.empty()){
		itemp=iindex.front();
		jtemp=jindex.front();
			bfsvisit(itemp,jtemp,arr[itemp][jtemp]);
		jindex.pop();
		iindex.pop();		
	}
ans=arr[itemp][jtemp];
}

int main() {
	// your code goes here
int count=1;
 cin>>h>>w;

while(!(h==0 && w==0))
{
	initialize();
	for(int i =1;i<=h;i++)
		{
			for(int j =1; j<=w;j++)
			{
				cin>>array[i][j];
				if(array[i][j]=='A')
						{status[i][j]=true;
							arr[i][j]=1;
							ans=1;
							iindex.push(i);
						jindex.push(j);
						}
			}

		}

	bfs();
cout<<"Case "<<count<<": "<<ans<<endl;
cin>>h>>w;
count++;
}
	return 0;
}
