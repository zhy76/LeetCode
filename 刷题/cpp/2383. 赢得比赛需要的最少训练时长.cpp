// class Solution {
// public:
//     int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
//         int res=0,n=energy.size();
//         int e=0;
//         for(int i=0;i<n;i++){
//             e+=energy[i];
//         }
//         res=e>initialEnergy?e-initialEnergy+1:0;
//         for(int i=0;i<n;i++){
//             if(initialEnergy<=experience[i]){
//                 res+=(experience[i]-initialExperience+1);
//                 initialExperience=2*experience[i]+1;
//             }else{
//                 initialExperience+=experience[i];
//             }
//         }
        
//         return res;
//     }
// };
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum = 0;
        for (int e : energy) {
            sum += e;
        }
        int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
        for (int e : experience) {
            if (initialExperience <= e) {
                trainingHours += 1 + (e - initialExperience);
                initialExperience = 2 * e + 1;
            } else {
                initialExperience += e;
            }
        }
        return trainingHours;
    }
};