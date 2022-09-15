class Countprime {
    int period_arr[] = new int[10000000];
    int iterations = 0;

    void add_bid(int bid) {
        period_arr[this.iterations] = bid;
        this.iterations++;
        return;
    }

    int gcd_of_bids() {
        if (this.iterations == 1)
            return period_arr[0];
        int temp = gcd(period_arr[0], period_arr[1]);
        if (this.iterations == 2)
            return temp;
        for (int i = 1; i < this.iterations - 1; i++) {
            temp = gcd(temp, period_arr[i + 1]);
        }
        return temp;
    }

    int getAP(int a, int d, int n) {
        int terms = ((n - a) / d) + 1;
        return terms;
    }

    int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        else if (b % a == 0)
            return a;
        else if (b > a)
            return gcd(b % a, a);
        else
            return gcd(a % b, b);
    }

    int totalprime(int n) {
        int count = 0;
        int period = 2;
        count += getAP(2, 2, n);
        for (int i = 2; i < n; i += 2) {
            if (gcd(period, (i + 1)) == 1) {
                period = period * (i + 1);
                if (iterations >= 1) {
                    if (gcd(gcd_of_bids(), period) == 1) {
                        count++;
                    }
                } else
                    count += getAP(i + 1, period, n);
            }
            if (period >= 100000) {
                add_bid(period);
                period = i + 2;
            }

        }
        return n - count - 1;
    }
}

class Prime {
    public static void main(String[] args) {
        // Random rand = new Random();
        // int n = rand.nextInt(100000);
        Countprime P = new Countprime();
        System.out.println(P.totalprime(15));

        // System.out.println(P.totalprime(n));
        // P.print_prime(n);
    }
}
