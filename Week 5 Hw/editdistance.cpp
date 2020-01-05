#include <iostream>
#include <string>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) 
{
  //write your code here

  int distance[str1.length()+1][str2.length()+1];

  for(int i = 0; i < str1.length(); i++)
  {
      distance[i][0] = i;
  }
  
  for(int j = 0; j < str2.length(); j++)
  {
      distance[0][j] = j;
  }
  
  for (int i=1; i<str1.length()+1; i++)
  {
      for(int j=1; j<str2.length()+1; j++)
      {
          int insertion=distance[i][j-1]+1;
          int deletion=distance[i-1][j]+1;
          int match=distance[i-1][j-1];
          int mismatch=distance[i-1][j-1]+1;
         
          if (str1.at(i-1)==str2.at(j-1))
          {
              distance[i][j]=std::min(std::min(insertion, deletion),match);
          }
          
          else
          {
              distance[i][j]=std::min(std::min(insertion, deletion),mismatch);
          }
        }
  }
  
  return distance[str1.length()][str2.length()];
}


int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
