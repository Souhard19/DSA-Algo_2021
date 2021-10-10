#include <bits/stdc++.h>
using namespace std;

namespace subStr {
     vector<string> ans;
     void subStrs (string s, int subStrFrom=0, string curr="") {

          if (subStrFrom==s.size()) {
               ans.push_back(curr);
               return;
          }
          subStrs (s, subStrFrom+1, curr+s[subStrFrom]);
          subStrs (s, subStrFrom+1, curr);
     }
}


namespace permutation {
     vector<string> ans;
     void permutation (string permuThis, string addThis="") {
          if (permuThis.size() == 1) {
               ans.push_back(addThis+permuThis);
               return;
          }
          for (int j=0; j<permuThis.size(); j++) {
               permutation(permuThis.substr(0,j)+permuThis.substr(j+1), addThis+permuThis[j]);
          }
     }
}

int main() {

     string s;
     cin >> s;
     subStr :: subStrs(s);
     permutation :: permutation(s);

     cout << "Sub String :\n";
     for (auto i: subStr::ans)
          cout << i << "\n";
     cout << "\n";

     cout << "Permutations :\n";
     for (auto i: permutation::ans)
          cout << i << "\n";
    
    return 0;
}
