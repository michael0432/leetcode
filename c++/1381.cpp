class CustomStack {
public:
    CustomStack(int maxSize) {
        maxsize = maxSize;
        nowsize = 0;
    }
    
    void push(int x) {
        if(nowsize < maxsize){
            v.push_back(x);
            nowsize++;
        }
    }
    
    int pop() {
        if(nowsize == 0)
            return -1;
        else{
            int back = v[nowsize - 1];
            v.pop_back();
            nowsize--;
            return back;
        }
            
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, nowsize); i++){
            v[i] += val;
        }
    }
private:
    int maxsize;
    int nowsize;
    vector<int> v;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */