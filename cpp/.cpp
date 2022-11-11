class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string s="";
        for(int i=0;i<n;){
            if(command[i]=='G'){
                s+="G";
                i++;
            }else if(command[i]=='('){
                if(command[i+1]==')'){
                    s+='o';
                    i+=2;
                    continue;
                }else if(command[i+1]=='a'){
                    s+="al";
                    i+=4;
                    continue;
                }
            }
        }
        return s;
    }
};