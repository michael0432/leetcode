class ProductOfNumbers {
public:
    ProductOfNumbers() {
        v = {1};
    }
    
    void add(int num) {
        if(num == 0){
            v = {1};
        }
        else{
            v.push_back(num*v[v.size()-1]);
        }
    }
    
    int getProduct(int k) {
        if(k >= v.size()) return 0;
        return v[v.size()-1] / v[v.size()-1-k];
    }
private:
    vector<long long> v;
};