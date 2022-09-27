class Solution {
public:
    string pushDominoes(string dom) {
        int l=-1, r=-1, len=dom.length(), tmp;
        
        for(int i=0; i<len; i++){
            
            if(l==-1 && dom[i]!='.'){
                if(dom[i]=='L'){
                    for(int j=0; j<i; j++) dom[j]='L';
                    l=i;
                }
                else {l=i;}
            }
            else if(dom[i]!='.'){
                if(dom[l]=='L' && dom[i]=='L'){
                    for(int j=l; j<i; j++) dom[j]='L';
                    l=i;
                }
                else if(dom[l]=='R' && dom[i]=='R'){
                    for(int j=l; j<i; j++) dom[j]='R';
                    l=i;
                }
                else if(dom[l]=='L' && dom[i]=='R'){
                    l=i;
                }
                else{ // R - L
                    r=i;
                    while(l<r){
                        dom[l++]='R';
                        dom[r--]='L';
                    }
                    l=i;
                }
            } 
        }
        
        if(l<len && l!=-1 && dom[l]=='R'){
            while(l<len) dom[l++]='R';
        }

        return dom;
    }
};