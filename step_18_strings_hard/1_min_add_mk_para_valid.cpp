class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int len = s.length();
        

        int open_len = 0;
        int close_len = 0;

        for(int i=0; i<len; i++){
            
            if(s[i]==')'){
                if(open_len){
                    open_len-=1;
                    
                }
                else{
                    close_len+=1;
                }
            }
            else{
                open_len+=1;
            }
        }
        return open_len+close_len;
    }
};