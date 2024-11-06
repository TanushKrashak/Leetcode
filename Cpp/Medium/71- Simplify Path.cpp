class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int size = path.size();
        string temp = "";
        int ansSize = 0;
        for (int i =0; i<size; i++) {
            cout << ans << endl;
            if (path[i] == '/' || i == size-1) {
                if (i==size-1 && path[i] != '/') {
                    temp += path[i];
                }
                if (temp == "") {                                      
                    continue;
                }
                if (temp == ".") { 
                    temp = "";
                    continue;                   
                }
                if (temp == "..") {
                    int counter = 0;
                    while (ansSize > 1 && counter < 1) {
                        counter += (ans[ansSize-1] == '/') ? 1:0;
                        ans.erase(ansSize-1, 1);
                        ansSize -= (counter==1) ? 0:1;
                    }   
                    temp = ""; 
                    continue;
                }    
                ans += (ansSize > 0 && ans[ansSize-1] =='/') ? "":"/";
                ansSize += (ansSize > 0 && ans[ansSize-1] =='/') ? 0:1;                             
                ans += temp;                
                ansSize += temp.size();
                temp = "";
                continue;
            }
            temp += path[i];
        }
        if (ansSize > 1 && ans[ansSize-1] == '/')
            ans.erase(ansSize-1, 1);
        ans += (ansSize==0)? "/":"";
        return ans;
    }
};
