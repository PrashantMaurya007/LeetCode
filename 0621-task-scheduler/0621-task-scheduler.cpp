class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);

        for(char &ch : tasks)
        {
            mpp[ch-'A']++;
        }

        priority_queue<int> pq;

        for(int i=0; i<26; i++)
        {
            if(mpp[i] > 0) pq.push(mpp[i]);
        }

        int time = 0;

        while(!pq.empty())
        {
            // Current cycle me execute hui tasks ki remaining frequencies
            vector<int> temp;

            // Ek cycle me maximum n+1 alag tasks chala sakte hain
            // Taaki same task dobara aane se pehle cooling complete ho jaye
            for(int i=1; i<=n+1; i++)
            {
                if(!pq.empty())
                {
                    // Sabse zyada frequency wali task uthao
                    int freq = pq.top();
                    pq.pop();

                    // Ek baar execute kar diya
                    freq--;

                    // Agar aur occurrences bachi hongi to baad me heap me wapas daalenge
                    temp.push_back(freq);
                }
            }

            // Jo task abhi bhi pending hai, use next cycle ke liye wapas heap me daal do
            for(int &f : temp)
            {
                if(f > 0) pq.push(f);
            }

            // Agar heap empty ho gaya:
            // Matlab saare tasks complete ho gaye
            // To sirf jitne tasks execute hue utna hi time add karo
            if(pq.empty()) time += (temp.size());

            // Tasks abhi bhi pending hain
            // Cooling maintain karne ke liye poora cycle count hoga
            else time += (n+1);
        }

        return time;
    }
};