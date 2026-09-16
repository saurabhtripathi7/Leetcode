class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        // answer array ko -1 se initialize kiya.
        // -1 ka matlab hai: "Yeh car kabhi kisi se nahi takrayegi (infinitely akeli chalegi)"
        vector<double> answer(cars.size(), -1);  
        
        // Stack hamesha un gaadiyon ke indices store karega jo humare AAGE chal rahi hain.
        // Stack ka top hamesha hamara immediate "potential target" hoga.
        stack<int> st;  
        
        // Right to Left traverse kar rahe hain (Sabse aage wali car se sabse peeche wali car tak).
        // Kyunki ek car sirf apne se aage wali car se hi takra sakti hai.
        for(int i = cars.size() - 1; i >= 0; --i) {
            
            // ==========================================
            // CONDITION 1: SPEED CHECK (Useless cars ko hatao)
            // ==========================================
            // Agar aage wali car (st.top()) hamari current car (i) se TEZ (>) ya BARABAR (==) speed ki hai,
            // toh hum (current car) zindagi mein kabhi usey catch nahi kar payenge.
            // Isliye usko stack se nikal do, woh hamare kisi kaam ki nahi hai.
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }
            
            // ==========================================
            // CONDITION 2: TIME CHECK & FLEET MERGE CHECK (Asli target dhundo)
            // ==========================================
            while(!st.empty()) {
                // Potential target car ka data
                int target_idx = st.top();
                
                // Time = Distance / Relative Speed
                // Distance = (Target_Position - My_Position)
                // Relative Speed = (My_Speed - Target_Speed)  <- Denominator hamesha >0 hoga kyunki Condition 1 ne <= speed wale hata diye.
                double collTime = (double)(cars[target_idx][0] - cars[i][0]) / (cars[i][1] - cars[target_idx][1]);
                
                // Kya yeh collision waqai valid hai? Ya target car pehle hi kisi aur se jud jayegi?
                // 1. answer[target_idx] == -1 : Target car aage kisi se nahi takrayegi, hamesha is speed se chalegi. (Valid)
                // 2. collTime <= answer[target_idx] : Hum target car ko tab pakad lenge, jab woh akeli thi (kisi aur se takrane se pehle). (Valid)
                if(answer[target_idx] == -1 || collTime <= answer[target_idx]) {
                    
                    answer[i] = collTime;  // Valid collision time mil gaya!
                    break;                 // Aage check karne ki zaroorat nahi, loop tod do.
                
                }
                
                // Agar code yahan pohocha, iska matlab (collTime > answer[target_idx])
                // Yaani hum jab tak target car tak pohochte, woh pehle hi kisi aur se takrakar "Fleet" ban chuki hogi.
                // Aur takrane ke baad uski speed slow ho jayegi.
                // Isliye yeh "Ghost" car ban chuki hai, ise pop kardo aur us leader car ko check karo jisme yeh merge hui hai.
                st.pop();  
            }
            
            // Current car ki calculation puri ho gayi, ab ise stack mein daal do 
            // taaki jo cars iske peeche hain, woh ise apna target bana sakein.
            st.push(i);  
        }
        
        return answer;  
    }
};