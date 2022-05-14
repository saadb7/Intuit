bool dfs (string str , int idx , int prev , int &missing){
    
    if (idx >= str.length()){
        if (missing > 0)
            return true;
        return false;
    }
    for (int len = 1 ; len <= 6 and idx + len <= str.length() ; ++len){
        string next = str.substr(idx ,len);
        int can = stoi(next);
        if (can == prev + 1){
            if (dfs(str , idx + len , can , missing))
                return true;
        }
        else if (can == prev + 2){
            if (missing == -1){
                missing = prev+1;
                if (dfs (str, idx + len , can , missing))
                    return true;
            }
            else return false;
        }
        else if (can > prev + 2)
            return false;
    }
    
    return false;
    
}
int missingNumber(const string& str)
{
    // Code here
    for (int len = 1 ; len <= 6 and len <= str.length() ; ++len){
        string next = str.substr(0 , len);
        int can = stoi(next);
        int missing = -1;
        if(dfs (str , len , can , missing)) return missing;
        
    }
    return -1;
}
