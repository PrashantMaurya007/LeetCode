#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Handle edge case overflow: INT_MIN / -1 = 2^31, which exceeds INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // 2. Early return if dividend is divisor
        if (dividend == divisor) return 1;

        // 3. Determine sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // 4. Convert to unsigned long long to safely handle abs(INT_MIN) without overflow
        unsigned long long n = std::abs((long long)dividend);
        unsigned long long d = std::abs((long long)divisor);
        
        unsigned int quotient = 0;

        // 5. Single-pass bitwise division (from most significant bit to least)
        for (int i = 31; i >= 0; --i) {
            if ((n >> i) >= d) {
                quotient += (1U << i);
                n -= (d << i);
            }
        }

        return isNegative ? -quotient : quotient;
    }
};