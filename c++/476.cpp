class Solution {
public:
    int findComplement(int num) {
        bool first_one = false;
        for(int i=31 ; i>=0 ; i--){
            int shift_num = 1<<i;
            int and_num = shift_num & num;
            if(first_one){
                if(and_num != 0){
                    num -= shift_num;
                }
                else{
                    num += shift_num;
                }
            }
            else{
                if(and_num != 0){
                    first_one = true;
                    num -= shift_num;
                } 
            }

        }
        return num;
    }
};