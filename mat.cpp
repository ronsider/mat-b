#include "mat.hpp"
#include <vector>

using std::vector;
using std::pair;
using std::string;

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

vector<vector<char>> area(int c,int r,char sym1,char sym2)
{
  vector<vector<char>>vs(r , vector<char> (c, sym1));
  int frame=0;//with each frame switch signs
  pair<int,int>upper(0,0);
  pair<int,int>lower(r,c);
  while(upper.first<lower.first && upper.second<lower.second)
    {
      if(frame%2==0)
      {
        fill_mat(vs,upper,lower,sym1);
        frame++;
      }
      else
      {
        fill_mat(vs,upper,lower,sym2);
        frame++;
      }
      ++upper.first;
      ++upper.second;
      --lower.first;
      --lower.second;
    }
 
  return vs;
}

string mat_to_str(const vector<vector<char>>& vv)
{
  string s{};
  for(const auto& i:vv)
    {
      for(const auto& j:i)
        {
          s+=j;
        }
      s+='\n';
    }
  return s;
}


std::string ariel::mat(int c,int r,char s1,char s2)
{
  if((c%2==0 || r%2==0) )
  {
      throw "dimensions do not satisfy conditions";
  }
  if (c<1 || r<1)
  {
    throw "dimensions do not satisfy conditions";
  }
  
  vector<vector<char>>vt = area(c,r,s1,s2);
  std::string s_r = mat_to_str(vt);
  return s_r;

}