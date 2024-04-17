class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       int pickP=0;
       int pickM=0;
       int pickG=0;

       int lastP=0;
       int lastM=0;
       int lastG=0;

// callculating pickup time (pickP) and last house index jaha tak ka time nikalna hai (lastP)
        for(int i=0; i < garbage.size(); i++ ){
            string current= garbage[i];

            for(int j=0; j<current.length(); j++){
                char ch = current[j];

                if(ch == 'P'){
                    pickP++;
                    lastP=i;
                }
                else if(ch == 'M'){
                    pickM++;
                    lastM=i;
                }
                else if(ch == 'G'){
                    pickG++;
                    lastG=i;
                }
            }
        }

        // calulating the travel time for each truck 

       int travelM=0;
       int travelG=0;
       int travelP=0;

        for(int i=0; i<lastP; i++){
            travelP = travelP + travel[i];
        }
        for(int i=0; i<lastM; i++){
            travelM = travelM + travel[i];
        }
        for(int i=0; i<lastG; i++){
            travelG = travelG + travel[i];
        }
        // final ans

        int ans= (pickP + travelP) + (pickG + travelG) + (pickM + travelM);

        return ans;
    }
};
