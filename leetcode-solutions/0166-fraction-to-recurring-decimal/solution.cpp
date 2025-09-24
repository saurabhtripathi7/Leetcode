class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        string result;
        if((long long)numerator*(long long)denominator<0){
            result += "-";
        }
        long long absnumerator = labs(numerator);
        long long absdenominator = labs(denominator);

        long long decimalPart = absnumerator / absdenominator;
        result += to_string(decimalPart);
        if(absnumerator % absdenominator==0){
            return result;
        }
        result +=".";
        long long remainder = absnumerator % absdenominator;
        unordered_map<long long,int>mpp;
        while(remainder!=0){
            if(mpp.find(remainder)!=mpp.end()){
                int pos = mpp[remainder];
                result.insert(pos,"(");
                result +=")";
                break;
            }
            mpp[remainder] = result.size();
            remainder *= 10;
            int digit = (remainder/absdenominator);
            result += to_string(digit);
            remainder %= absdenominator;
        }
        return result;
    }
};
