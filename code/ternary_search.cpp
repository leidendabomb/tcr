template<class T, class Comparator = less<T>>
T ternary_search(const function<T(T)>& f, T min, T max, const T precision = 1) {
    Comparator compare;
    while (true) {
        if (abs(max - min) < precision) {
            return (max + min) / 2;
        }

        T leftThird = min + (max - min) / 3;
        T rightThird = max - (max - min) / 3;

        if (compare(f(leftThird), f(rightThird))) {
            max = rightThird;
        } else {
            min = leftThird;
        }
    }
}
