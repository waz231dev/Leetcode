class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int reqEnergy = 0;
        for(int i = 0 ; i < energy.size() ; i++){
            reqEnergy += energy[i];
        }
        reqEnergy = max(0,reqEnergy+1-initialEnergy);
        int reqExp = 0;
        for(int i = 0 ; i < experience.size() ; i++){
            if(initialExperience <= experience[i]){
                reqExp += max(0,experience[i]-initialExperience+1);
                initialExperience = experience[i]+1;
            }
            initialExperience += experience[i];
        }
        
        return reqExp+reqEnergy;
    }
};