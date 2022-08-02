class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //if the lengths are not equal, they cannot be isomorphic
        if(t.length() != s.length()) return false;
        
        int maxLength = 50000; //5*10^4
        //an array for s to t (could also use vector)
        int st[maxLength];
        // an array for t to s
        int ts[maxLength];
        
        // instantiate each array slot to 0;
        for(int i = 0; i<maxLength; i++){
            st[i] = 0;
            ts[i] = 0;
        }
        
        
        //could also use t.length since they are equivelent
        //We're typecasting char to int and creating our own map
        for (int i = 0; i < s.length(); i++) {
            
            if (st[s[i]] == 0 && ts[t[i]] == 0) {
                
                st[s[i]] = t[i];
               

                ts[t[i]] = s[i];
                
            } else if (st[s[i]] != t[i]) return false;
            
            
        }
        

        return true;
    }
};
