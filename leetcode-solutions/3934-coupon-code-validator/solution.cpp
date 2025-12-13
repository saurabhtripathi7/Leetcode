class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<string,string>> v;
        int n = code.size();

        auto isValid = [](const string& s) {
            for (char c : s) {
                if (!((c == '_') ||
                      (c >= 'a' && c <= 'z') ||
                      (c >= 'A' && c <= 'Z') ||
                      (c >= '0' && c <= '9')))
                    return false;
            }
            return true;
        };

        auto businessCheck = [](const string& s) {
            return s == "electronics" || s == "grocery" ||
                   s == "pharmacy"   || s == "restaurant";
        };

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (code[i].empty()) continue;

            if (isValid(code[i]) && businessCheck(businessLine[i])) {
                v.push_back({businessLine[i], code[i]});
            }
        }

        sort(v.begin(), v.end(),
             [](const pair<string,string>& a,
                const pair<string,string>& b) {

            auto rank = [](const string& c) {
                if (c == "electronics") return 0;
                if (c == "grocery")     return 1;
                if (c == "pharmacy")    return 2;
                if (c == "restaurant")  return 3;
                return 4;
            };

            int ra = rank(a.first);
            int rb = rank(b.first);

            if (ra != rb) return ra < rb;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto &p : v)
            ans.push_back(p.second);

        return ans;
    }
};

