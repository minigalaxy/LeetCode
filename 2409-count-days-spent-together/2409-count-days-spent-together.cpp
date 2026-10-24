int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date
{
    int M, D;

    Date(string d) : M(stoi(d.substr(0, 2))), D(stoi(d.substr(3, 2))) {}

    short operator-(const Date& other) const {
        return accumulate(days, days + M - 1, D) - accumulate(days, days + other.M - 1, other.D) + 1;
    }

    bool operator<(const Date& other) const {
        if(M == other.M) return D < other.D;
        return M < other.M;
    }
};

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        Date a1(arriveAlice), a2(leaveAlice), b1(arriveBob), b2(leaveBob);

        if(a2 < b1 || b2 < a1) return 0;
        else if(a1 < b1 && b2 < a2) return b2 - b1;
        else if(b1 < a1 && a2 < b2) return a2 - a1;
        else return min(a2 - b1, b2 - a1);
    }
};