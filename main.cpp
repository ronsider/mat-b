#include <iostream>
#include <vector>
#include <string>

using std::pair;
using std::vector;
using std::cout;


void fill_mat(vector<vector<char>>& vv,const pair<int,int>& p1,
                                        const pair<int,int>& p2,const char& s)
{
   for(int i=p1.first;i<p2.first;i++)
     {
       for(int j=p1.second;j<p2.second;j++)
         {
           vv[i][j]=s;
         }
     }
}
/////////////
////////////

void prt_mat(const vector<vector<char>>& vv)
{
  for(auto i:vv)
    {
      for(auto j:i)
        {
          cout<<j<<" ";
        }
      cout<<'\n';
    }
}
///////////////
//////////////


int main()
{
    vector<char>v(5,'@');
    vector<vector<char>>vv(7,v);

     fill_mat(vv,std::make_pair(0,0),std::make_pair(7,5),'&');
     fill_mat(vv,std::make_pair(1,1),std::make_pair(6,4),'*');
     fill_mat(vv,std::make_pair(2,2),std::make_pair(5,3),'&');

     prt_mat(vv);
    return 0;
}