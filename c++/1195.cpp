class FizzBuzz {
private:
    int n;
    bool lock;

public:
    FizzBuzz(int n) {
        this->n = n;
        lock = false;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        lock = true;
        cout << "fizz";
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        lock = true;
        cout << "fizz";
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        lock = true;
        cout << "fizzbuzz";
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        lock = true;
        cout << to_string(x);
    }
};