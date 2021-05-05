#include<bits/stdc++.h>
using namespace std;
 bool searchforword(vector<vector<char>>&grid,string str,int i,int j,int m,int n,int index)
{
     if(i<0||i>=m||j<0||j>=n)
            return false;
    
    else if(grid[i][j]!=str[index])
    return false;
        
    else if(index==str.size()-1)
        return true;
        
    grid[i][j]='$';
    bool a=searchforword(grid,str,i+1,j,m,n,index+1);
    bool b=searchforword(grid,str,i-1,j,m,n,index+1);
    bool c=searchforword(grid,str,i,j+1,m,n,index+1);
    bool d=searchforword(grid,str,i,j-1,m,n,index+1);
    grid[i][j]=str[index];
    return (a||b||c||d);
}
bool searchword(vector<vector<char>>&grid,string str,int r,int c)
{
   for(int i=0;i<r;i++)
   for(int j=0;j<c;j++)
   {
       if(searchforword(grid,str,i,j,r,c,0))
       return true;
   }
   return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
    #endif

    int r,c;
    cin>>r>>c;

    string word;
    cin>>word;
   
    vector<vector<char>>grid(r,vector<char>(c));
    char ch;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           cin>>grid[i][j];
        }
    }
  
  if(searchword(grid,word,r,c))
  cout<<"word is present in grid";
  else
  cout<<"Not present";
    return 0;
}