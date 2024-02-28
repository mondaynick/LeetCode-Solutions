/*
  給定一個absolute path，將其轉換成canonical path，如：
    "/home/" -> "/home"
    "/../" -> "/"
    "/home//foo/" -> "/home/foo"
    "/a/./b/../../c/" -> "/c"
    "/a/../../b/../c//.//" -> "/c"
    "/a//b////c/d//././/.." -> "/a/b/c"

  利用堆疊對字串做操作
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> S;
        for (int i = 0 ; i < path.length() ; i++) {
            if (path[i] == '/') continue;
            
            string temp;
            while (path[i] != '/' && i < path.length()) {
                temp += path[i];
                i++;
            }
            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!S.empty()) S.pop();
            } else {
                S.push(temp);
            }
        }

        path = "";
        while (!S.empty()) {
            path = "/" + S.top() + path;
            S.pop();
        }
        if (path.length() == 0) return "/";
        return path;
    }
};
