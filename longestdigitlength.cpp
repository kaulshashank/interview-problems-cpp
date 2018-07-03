#include<iostream>
#include<string>

using namespace std;

void longestString(string str, int l) {
  int count = 0, max = 0, pos = -1, pre_pos, pre_len, len = 0;

  for(int i=0; i<l;i++) {
    pre_pos = pos;
    pre_len = len;

    len = 0;
    count = 0;
    if(isdigit(str[i]))
      pos = i;
    while(isdigit(str[i])) {
      count++;
      i++;
    }
  }
  cout<<count;
}


int main() {
  string str = "heythere100theresmore1234";
  int length = str.length();
  longestString(str, length);
  return 0;
}
