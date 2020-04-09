class FizzBuzz {
private:
    int n;
    int i;
    mutex glock;
    condition_variable g_cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n){
            unique_lock<mutex> lock(glock);
            g_cv.wait(lock, [this]() {
                if(i%3 == 0 && i%5 != 0)
                    return true;
                if(i > n)
                    return true;
                return false;
            });
            if(i <= n){
                printFizz();
                i++;
            }
            g_cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i <= n){
            unique_lock<mutex> lock(glock);
            g_cv.wait(lock, [this]() {
                if(i%5 == 0 && i%3 != 0)
                    return true;
                if(i > n)
                    return true;
                return false;
            });
            if(i <= n){
                printBuzz();
                i++;
            }
            g_cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i <= n){
            unique_lock<mutex> lock(glock);
            g_cv.wait(lock, [this]() {
                if(i%3 == 0 && i%5 == 0)
                    return true;
                if(i > n)
                    return true;
                return false;
            });
            if(i <= n){
                printFizzBuzz();
                i++;
            }
            g_cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n){
            unique_lock<mutex> lock(glock);
            g_cv.wait(lock, [this]() {
                if(i%3 != 0 && i%5 != 0)
                    return true;
                if(i > n)
                    return true;
                return false;
            });
            if(i <= n){
                printNumber(i);
                i++;
            }
            g_cv.notify_all();
        }
    }
};